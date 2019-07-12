#include "LoginInterface.h"

//==========================DES���ܽ���===================================================
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>


const char IP_Table[64] = {
	58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
};

// �Ե������L16,R16ִ��IP���û�,�������
const char IPR_Table[64] = {
	40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
};

/*--------------------------- �������� ----------------------------*/

// F����,32λ��R0����E�任,��Ϊ48λ��� (R1~R16)        [����A]  [���Ĳ���]
static char E_Table[48] = {
	32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1
};

// ����ԿK(i)�Ļ�ȡ ��ԿΪK ������6,16,24,32,40,48,64λ          [��Կ����]
// ��PC1ѡλ ��Ϊ ǰ28λC0,��28λD0 ������
static char PC1_Table[56] = {
	57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
};

// ��C0,D0�ֱ��������,��16��,����λ���������Ӧ                 [��Կ����]
static char Move_Table[16] = {
	1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

// C1,D1Ϊ��һ�����ƺ�õ�,����PC2ѡλ,�õ�48λ���K1   [����B]   [��Կ����]
static char PC2_Table[48] = {
	14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40, 51, 34, 33, 48,
	44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

/*------------- F���� ����A�ͱ���B ��� �õ�48λ��� ---------------*/

// ����Ľ��48λ��Ϊ8��,ÿ��6λ,��Ϊ8��S�е�����             [��ϲ���]
// S����6λ��Ϊ����(8��),4λ��Ϊ���(4*(8��)=32λ)
// S����ԭ�� ��������ΪA=abcdef ,��bcde�����������0-15֮���
// һ������Ϊ X=bcde ,af�������0-3֮���һ����,��Ϊ Y=af
// ��S1��X��,Y���ҵ�һ����Value,����0-15֮��,�����ö����Ʊ�ʾ
// ����Ϊ4bit (��32λ)
static char S_Box[8][4][16] = {
	//S1
	{
		{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
		{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
		{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
		{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }
	},
	//S2
	{
		{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
		{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
		{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
		{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }
	},
	//S3
	{
		{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
		{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
		{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
		{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }
	},
	//S4
	{
		{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
		{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
		{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
		{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }
	},
	//S5
	{
		{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
		{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
		{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
		{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }
	},
	//S6
	{
		{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
		{ 10, 15, 4, 2, 7, 12, 0, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
		{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
		{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }
	},
	//S7
	{
		{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
		{ 13, 0, 11, 7, 4, 0, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
		{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
		{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }
	},
	//S8
	{
		{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
		{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
		{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
		{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
	}
};

// F���� ���ڶ���,��S�������32����P�û�                     [��ϲ���]
// �����ֵ����һ�ε���:
// L(i)=R(i-1)
// R(i)=L(i-1)^f(R(i-1),K(i)) ���
static char P_Table[32] = {
	16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
	2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25
};

typedef unsigned long DWORD;
typedef unsigned short WORD;


char g_str[31];
static DWORD g_eax;   // �洢���ص�eax
static DWORD g_ebx;   // �洢���ص�ebx
static DWORD g_ecx;   // �洢���ص�ecx
static DWORD g_edx;   // �洢���ص�edx
int g_isSupport;

// 16������ԿK(1~16)
static bool SubKey[16][48] = { { 0, 0 } };

void BitsCopy(bool *DatOut, bool *DatIn, int Len);  // ���鸴��

void ByteToBit(bool *DatOut, char *DatIn, int Num); // �ֽڵ�λ
void BitToByte(char *DatOut, bool *DatIn, int Num); // λ���ֽ�

void BitToHex(char *DatOut, bool *DatIn, int Num);  // �����Ƶ�ʮ������ 64λ to 4*16�ַ�
void HexToBit(bool *DatOut, char *DatIn, int Num);  // ʮ�����Ƶ�������

void TablePermute(bool *DatOut, bool *DatIn, const char *Table, int Num); // λ���û�����
void LoopMove(bool *DatIn, int Len, int Num);     // ѭ������ Len���� Num�ƶ�λ��
void Xor(bool *DatA, bool *DatB, int Num);         // �����

void S_Change(bool DatOut[32], bool DatIn[48]);   // S�б任
void F_Change(bool DatIn[32], bool DatKi[48]);    // F����

void SetKey(char KeyIn[8]);                         // ������Կ
void PlayDes(char MesOut[8], char MesIn[8]);       // ִ��DES����
void KickDes(char MesOut[8], char MesIn[8]);             // ִ��DES����

QString decode_str(char *inputstr);//���ܺ���
QString encrypt_str(char *inputstr);//���ܺ���
int get_mac_addr();
void GetSerialNumber(WORD nibble[6]);
void GetCpuSn();
struct tm * get_sys_time(struct tm *tmp_ptr);
void hdparm_get_diskid();
void smartctl_get_diskid(char *diskid);

//====================================================================
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
char g_cpuid[20] = { 0 };
char g_macadd[20] = { 0 };
char g_diskid[20] = { 0 };
int g_count = 0;


#ifdef BIGENDIAN
typedef struct {
	u32 h;
	u32 l;
} u64;
#else
typedef struct {
	u32 l;
	u32 h;
} u64;
#endif

#ifdef ALIGNMENT_WORKAROUND
static inline u64 U64(u32 low, u32 high)
{
	u64 self;

	self.l = low;
	self.h = high;

	return self;
}
#endif

#ifdef ALIGNMENT_WORKAROUND
#    ifdef BIGENDIAN
#    define WORD(x) (u16)((x)[1] + ((x)[0] << 8))
#    define DWORD(x) (u32)((x)[3] + ((x)[2] << 8) + ((x)[1] << 16) + ((x)[0] << 24))
#    define QWORD(x) (U64(DWORD(x + 4), DWORD(x)))
#    else /* BIGENDIAN */
#    define WORD(x) (u16)((x)[0] + ((x)[1] << 8))
#    define DWORD(x) (u32)((x)[0] + ((x)[1] << 8) + ((x)[2] << 16) + ((x)[3] << 24))
#    define QWORD(x) (U64(DWORD(x), DWORD(x + 4)))
#    endif /* BIGENDIAN */
#else /* ALIGNMENT_WORKAROUND */
#define WORD(x) (u16)(*(const u16 *)(x))
#define DWORD(x) (u32)(*(const u32 *)(x))
#define QWORD(x) (*(const u64 *)(x))
#endif /* ALIGNMENT_WORKAROUND */
//#define USE_MMAP

struct dmi_header
{
	u8 type;
	u8 length;
	u16 handle;
	u8 *data;
};

int checksum(const u8 *buf, size_t len);
void *mem_chunk(size_t base, size_t len, const char *devmem);
u64 u64_range(u64 start, u64 end);
void to_dmi_header(struct dmi_header *h, u8 *data);
int get_cpuid(char *cpuid);//��ȡCPUID processer id
int get_mac(char* mac);//��ȡMAC��ַ
void creat_licensefile(char *filename, char *num);//��ȡCPUID��MAC��ַ������ں���
												  //static int myread(int fd, u8 *buf, size_t count, const char *prefix);
int myread(int fd, u8 *buf, size_t count, const char *prefix);

//===================================================================


/*-------------------------------
��DatIn��ʼ�ĳ���λLenλ�Ķ�����
���Ƶ�DatOut��
--------------------------------*/
void BitsCopy(bool *DatOut, bool *DatIn, int Len)     // ���鸴�� OK
{
	int i = 0;
	for (i = 0; i < Len; i++)
	{
		DatOut[i] = DatIn[i];
	}
}

/*-------------------------------
�ֽ�ת����λ����
ÿ8�λ�һ���ֽ� ÿ��������һλ
��1��ȡ���һλ ��64λ
--------------------------------*/
void ByteToBit(bool *DatOut, char *DatIn, int Num)       // OK
{
	int i = 0;
	for (i = 0; i < Num; i++)
	{
		DatOut[i] = (DatIn[i / 8] >> (i % 8)) & 0x01;
	}
}

/*-------------------------------
λת�����ֽں���
�ֽ�����ÿ8����һλ
λÿ�������� ����һ�λ�
---------------------------------*/
void BitToByte(char *DatOut, bool *DatIn, int Num)        // OK
{
	int i = 0;
	for (i = 0; i < (Num / 8); i++)
	{
		DatOut[i] = 0;
	}
	for (i = 0; i < Num; i++)
	{
		DatOut[i / 8] |= DatIn[i] << (i % 8);
	}
}


/*----------------------------------
����������ת��Ϊʮ������
��Ҫ16���ַ���ʾ
-----------------------------------*/
void BitToHex(char *DatOut, bool *DatIn, int Num)
{
	int i = 0;
	for (i = 0; i < Num / 4; i++)
	{
		DatOut[i] = 0;
	}
	for (i = 0; i<Num / 4; i++)
	{
		DatOut[i] = DatIn[i * 4] + (DatIn[i * 4 + 1] << 1)
			+ (DatIn[i * 4 + 2] << 2) + (DatIn[i * 4 + 3] << 3);
		if ((DatOut[i] % 16)>9)
		{
			DatOut[i] = DatOut[i] % 16 + '7';       //  ��������9ʱ���� 10-15 to A-F
		}                                     //  ����ַ�
		else
		{
			DatOut[i] = DatOut[i] % 16 + '0';       //  ����ַ�
		}
	}

}

/*---------------------------------------------
ʮ�������ַ�ת������
----------------------------------------------*/
void HexToBit(bool *DatOut, char *DatIn, int Num)
{
	int i = 0;                        // �ַ�������
	for (i = 0; i<Num; i++)
	{
		if ((DatIn[i / 4])>'9')         //  ����9
		{
			DatOut[i] = ((DatIn[i / 4] - '7') >> (i % 4)) & 0x01;
		}
		else
		{
			DatOut[i] = ((DatIn[i / 4] - '0') >> (i % 4)) & 0x01;
		}
	}
}
/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// ���û�����  OK
void TablePermute(bool *DatOut, bool *DatIn, const char *Table, int Num)
{
	int i = 0;
	static bool Temp[256] = { 0 };
	for (i = 0; i < Num; i++)                // NumΪ�û��ĳ���
	{
		Temp[i] = DatIn[Table[i] - 1];  // ԭ�������ݰ���Ӧ�ı��ϵ�λ������
	}
	BitsCopy(DatOut, Temp, Num);       // �ѻ���Temp��ֵ���
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// ����Կ����λ
void LoopMove(bool *DatIn, int Len, int Num) // ѭ������ Len���ݳ��� Num�ƶ�λ��
{
	static bool Temp[256] = { 0 };    // ����   OK
	BitsCopy(Temp, DatIn, Num);       // ����������ߵ�Numλ(���Ƴ�ȥ��)����Temp
	BitsCopy(DatIn, DatIn + Num, Len - Num); // ��������߿�ʼ�ĵ�Num����ԭ���Ŀռ�
	BitsCopy(DatIn + Len - Num, Temp, Num);  // ���������Ƴ�ȥ�����ݼӵ����ұ�
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// ��λ���
void Xor(bool *DatA, bool *DatB, int Num)           // �����
{
	int i = 0;
	for (i = 0; i < Num; i++)
	{
		DatA[i] = DatA[i] ^ DatB[i];                  // ���
	}
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// ����48λ ���32λ ��Ri���
void S_Change(bool DatOut[32], bool DatIn[48])     // S�б任
{
	int i, X, Y;                                    // iΪ8��S��
	for (i = 0, Y = 0, X = 0; i < 8; i++, DatIn += 6, DatOut += 4)   // ÿִ��һ��,��������ƫ��6λ
	{    										  // ÿִ��һ��,�������ƫ��4λ
		Y = (DatIn[0] << 1) + DatIn[5];                          // af����ڼ���
		X = (DatIn[1] << 3) + (DatIn[2] << 2) + (DatIn[3] << 1) + DatIn[4]; // bcde����ڼ���
		ByteToBit(DatOut, &S_Box[i][Y][X], 4);      // ���ҵ��ĵ����ݻ�Ϊ������
	}
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// F����
void F_Change(bool DatIn[32], bool DatKi[48])       // F����
{
	static bool MiR[48] = { 0 };             // ����32λͨ��Eѡλ��Ϊ48λ
	TablePermute(MiR, DatIn, E_Table, 48);
	Xor(MiR, DatKi, 48);                   // ������Կ���
	S_Change(DatIn, MiR);                 // S�б任
	TablePermute(DatIn, DatIn, P_Table, 32);   // P�û������
}


/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

void SetKey(char KeyIn[8])               // ������Կ ��ȡ����ԿKi
{
	int i = 0;
	static bool KeyBit[64] = { 0 };                // ��Կ�����ƴ洢�ռ�
	static bool *KiL = &KeyBit[0], *KiR = &KeyBit[28];  // ǰ28,��28��56
	ByteToBit(KeyBit, KeyIn, 64);                    // ����ԿתΪ�����ƴ���KeyBit
	TablePermute(KeyBit, KeyBit, PC1_Table, 56);      // PC1���û� 56��
	for (i = 0; i < 16; i++)
	{
		LoopMove(KiL, 28, Move_Table[i]);       // ǰ28λ����
		LoopMove(KiR, 28, Move_Table[i]);	      // ��28λ����
		TablePermute(SubKey[i], KeyBit, PC2_Table, 48);
		// ��ά���� SubKey[i]Ϊÿһ����ʼ��ַ
		// ÿ��һ��λ����PC2�û��� Ki 48λ
	}
}
/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

void PlayDes(char MesOut[8], char MesIn[8])  // ִ��DES����
{                                           // �ֽ����� Bin���� Hex���
	int i = 0;
	static bool MesBit[64] = { 0 };        // ���Ķ����ƴ洢�ռ� 64λ
	static bool Temp[32] = { 0 };
	static bool *MiL = &MesBit[0], *MiR = &MesBit[32]; // ǰ32λ ��32λ
	ByteToBit(MesBit, MesIn, 64);                 // �����Ļ��ɶ����ƴ���MesBit
	TablePermute(MesBit, MesBit, IP_Table, 64);    // IP�û�
	for (i = 0; i < 16; i++)                       // ����16��
	{
		BitsCopy(Temp, MiR, 32);            // ��ʱ�洢
		F_Change(MiR, SubKey[i]);           // F�����任
		Xor(MiR, MiL, 32);                  // �õ�Ri
		BitsCopy(MiL, Temp, 32);            // �õ�Li
	}
	TablePermute(MesBit, MesBit, IPR_Table, 64);
	BitToHex(MesOut, MesBit, 64);
}
/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

void KickDes(char MesOut[8], char MesIn[8])       // ִ��DES����
{												// Hex���� Bin���� �ֽ����
	int i = 0;
	static bool MesBit[64] = { 0 };        // ���Ķ����ƴ洢�ռ� 64λ
	static bool Temp[32] = { 0 };
	static bool *MiL = &MesBit[0], *MiR = &MesBit[32]; // ǰ32λ ��32λ
	HexToBit(MesBit, MesIn, 64);                 // �����Ļ��ɶ����ƴ���MesBit
	TablePermute(MesBit, MesBit, IP_Table, 64);    // IP�û�
	for (i = 15; i >= 0; i--)
	{
		BitsCopy(Temp, MiL, 32);
		F_Change(MiL, SubKey[i]);
		Xor(MiL, MiR, 32);
		BitsCopy(MiR, Temp, 32);
	}
	TablePermute(MesBit, MesBit, IPR_Table, 64);
	BitToByte(MesOut, MesBit, 64);
}
/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

//���ܺ���������CPU��SN��MAC�ļ�����Ϣ���н���
QString decode_str(char *inputstr)
{
	int i = 0;
	char MesHex[16] = { 0 };         // 16���ַ��������ڴ�� 64λ16���Ƶ�����
	QString MyKeystr = "asd!@#$%";
	//char *MyKey = "12345678"; // ��ʼ��Կ 8�ֽ�*8
	char *MyKey = MyKeystr.toLocal8Bit().data(); // ��ʼ��Կ 8�ֽ�*8
	char MyMessage[16] = { 0 };       // ��ʼ����

	int size;
	int len = 0;
	char *outfilestr;
	//char *retstr = NULL;
	int count = 0;
	char num = 0;


	size = strlen(inputstr);

	//filestr����ռ�������ȡ�ļ�������
	outfilestr = (char *)malloc(sizeof(char)*size);
	memset(outfilestr, 0, strlen(outfilestr));


	//�Ƚ�fp1�е����ݶ�ȡ��filestr��
	//fread(filestr, 1, size, fp1);

	//printf("filestr = %s\n",filestr);
	SetKey(MyKey);
	//����Ƕ��ļ����м��ܣ���filestr�ֳɰ˸�charһ�Σ�����Ƕ�filestr���н��ֳܷ�16charһ��
	for (i = 0; i < size;)
	{
		i = i + 16;
		if (i <= size)
		{
			memset(MesHex, 0, 16);
			memset(MyMessage, 0, 8);
			memcpy(MesHex, inputstr + (i - 16), 16);
			//printf("MesHex = %s\n",MesHex);
			// ������Կ �õ�����ԿKi
			KickDes(MyMessage, MesHex);     // ִ��DES����
											//����
											//printf("MyMessage = %s\n",MyMessage);
			len = strlen(MyMessage);
			if (len == 8)
			{
				num = num + len;
				//memcpy(outfilestr + (count * 8), MyMessage, len);
				sprintf(outfilestr, "%s%s", outfilestr, MyMessage);
				count++;
			}
			else
			{
				num = num + len;
				//memcpy(outfilestr + (count * 8), MyMessage, len);
				sprintf(outfilestr, "%s%s", outfilestr, MyMessage);
			}

		}

	}

	QString results = outfilestr;
	//qDebug() << "outfilestr:" << outfilestr; 
	return results;
}
/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

//���ܺ������ַ������м���
QString encrypt_str(char *inputstr)
{
	//char *retstr = NULL;
	//char *inputstr = "11253017-F8-32-E4-74-10-8A";
	QString MyKeystr = "asd!@#$%";
	//char *MyKey = "12345678"; // ��ʼ��Կ 8�ֽ�*8
	char *MyKey = MyKeystr.toLocal8Bit().data(); // ��ʼ��Կ 8�ֽ�*8
	int i = 0;
	int size = 0;
	int len = 0, count = 0;
	char MesHex[16] = { 0 };         // 16���ַ��������ڴ�� 64λ16���Ƶ�����
	char MyMessage[16] = { 0 };       // ��ʼ����
	char enoutfilestr[2048] = { 0 };
	//char *retstr = NULL;
	int num = 0;

	size = strlen(inputstr);

	SetKey(MyKey);
	for (i = 0; i < size;)
	{
		if ((i + 8) <= size)
		{
			memset(MyMessage, 0, 8);
			memset(MesHex, 0, 16);
			memcpy(MyMessage, inputstr + i, 8);
			// ������Կ �õ�����ԿKi
			PlayDes(MesHex, MyMessage);   // ִ��DES����
										  //����
			len = strlen(MesHex);
			memcpy(enoutfilestr + (count * 16), MesHex, 16);
			count++;
			num = num + len;
			i = i + 8;
		}
		else
		{
			memset(MyMessage, 0, 8);
			memset(MesHex, 0, 16);
			memcpy(MyMessage, inputstr + i, (size - i));
			// ������Կ �õ�����ԿKi
			PlayDes(MesHex, MyMessage);   // ִ��DES����
										  //����
			len = strlen(MesHex);
			memcpy(enoutfilestr + (count * 16), MesHex, 16);
			num = num + len;
			count++;
			i = i + 8;
		}
	}

	len = strlen(enoutfilestr);
	//retstr = (char*)malloc(sizeof(char)*len);

	//qDebug() << "retstr len1  = " << len;
	g_count = count * 16;
	//�޸ķ���ֵ��C�����з���retstr���޸ĺ󷵻�results
	//memset(retstr, 0, len);
	//memcpy(retstr, enoutfilestr, count * 16);
	//qDebug()<<"enoutfilestr len  = "<<strlen(enoutfilestr);
	//memcpy(retstr, enoutfilestr, g_count);
	QString results = enoutfilestr;
	//qDebug() << "enoutfilestr:" << enoutfilestr;
	return results;
}
//==========================DES���ܽ���===================================================

LoginInterface::LoginInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	//this->setMaximumSize(500, 300);
	//this->setMinimumSize(500, 300);
	this->resize(500, 300);//���ô��ڵĳߴ�
	//���ô��ڵ�Ĭ����ʾλ������Ļ���м�
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	ui.BackgroundLabel->setAlignment(Qt::AlignCenter);
	ui.BackgroundLabel->setText("����ͺŹ��HBFlows \n����汾�ţ�01.00.00\n��������汾�ţ�01");
	this->setWindowTitle("CT�޴�Ѫ��������������ϵͳ");
	ui.PasswordLineEdit->setEchoMode(QLineEdit::Password);//�����ʱ�����ʾԲ��
	/*bool getStatus = GetSerialNumber();
	if (!getStatus)
	{
		installationAlignment = new InstallationAlignment(this);
		installationAlignment->show();
		QObject::connect(installationAlignment,SIGNAL(InstallAlignmentSignal(QString)),this,SLOT(GetInstallationAlignmentSlot(QString)));
	}
	else
	{
		show();
	}*/
	show();
	ui.LoginPushButton->setFocus();
	//�ź���ۺ���������
	QObject::connect(ui.LoginPushButton, SIGNAL(clicked(bool)), this, SLOT(LoginPushButtonSlot()));
	QObject::connect(ui.PasswordLineEdit, SIGNAL(returnPressed()), this, SLOT(LoginPushButtonSlot()));
	QObject::connect(ui.RetrievePasswordPushButton, SIGNAL(clicked(bool)), this, SLOT(RetPasswordPushButtonSlot()));
	QObject::connect(ui.RegisterPushButton, SIGNAL(clicked(bool)), this, SLOT(RegisterPushButtonSlot()));
}

LoginInterface::~LoginInterface()
{
}

void LoginInterface::paintEvent(QPaintEvent *event)
{
	//���ݴ��ڵĴ�С���Ʊ���ͼƬ
	QPainter painter(this);
	painter.drawPixmap(10, 10, ui.BackgroundLabel->width(), ui.BackgroundLabel->height(), QPixmap("images/background.png"));
}

//�һ�����ۺ���
void LoginInterface::RetPasswordPushButtonSlot()//�һ�����ۺ���
{
	RetrievePasswordInterface *retrievePasswordInterface = new RetrievePasswordInterface();
	retrievePasswordInterface->show();
}
void LoginInterface::RegisterPushButtonSlot()//ע��ۺ���
{
	RegisterInterface *registerInterface = new RegisterInterface();
	QMessageBox::information(this,"��Ϣ","ע���˺ţ�");
	registerInterface->show();
	//QObject::connect(registerInterface, SIGNAL(registerSignal()), this, SLOT(getRegisterSignal()));
}

void LoginInterface::LoginPushButtonSlot()
{
	//���ж��û��������������Ƿ���Ϲ淶
	bool checkStatus = CheckedLoginUserInfo();
	if (checkStatus)
	{
		//���ݿ����ӳɹ��������ж��û����������Ƿ������ݿ����
		QString username = ui.UsernameLineEdit->text().trimmed();
		QString password = ui.PasswordLineEdit->text().trimmed();
		//��Ҫ����֤�˺��Ƿ��ѱ���������У��
		bool lockStatus = LockAccountsStatus(username);
		if (lockStatus)
		{
			QMessageBox::warning(this, "����:", "�����˺��ѱ�����\n�������������ϵ������̣����̵绰��057185165173��");
			return;
		}
		int findStatus = FindInfoFromUserInfo(username, password);//���û���Ϣ���ļ��в�����Ϣ
		if (findStatus == 0)
		{
			m_errorCount = 0;
			QMessageBox::information(this, "��Ϣ:", "��ϲ���¼�ɹ���");
			//�����û���ʱ���ļ�
			QString timeStr = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
			QString accoutStr = ui.UsernameLineEdit->text().trimmed();
			QString tmpFileName = timeStr + "_" + accoutStr + ".txt";
			QFile tmpFile(tmpFileName);
			bool tmpFileOpen = tmpFile.open(QIODevice::WriteOnly | QIODevice::Text);
			if (!tmpFileOpen)
			{
				QMessageBox::information(this, "��Ϣ:", "��ʱ�ļ�����ʧ�ܣ�");
				return;
			}
			tmpFile.close();
			//��¼�ɹ�֮����ʾ������
			ArteryTechQtProject *arteryTechQtProject = new ArteryTechQtProject(tmpFileName);
			arteryTechQtProject->show();
			hide();
			//���͵�¼�ɹ����ź�
			//sendLoginSuccessSignal();
		}
		else if(findStatus == 3)
		{
			//�жϵ�¼�����ǲ��Ǵ���5�Σ�����ǵģ�ֱ�������ļ�
			if (m_errorCount < 5)
			{
				m_errorCount++;
				int residualTimes = 5 - m_errorCount;
				QMessageBox::information(this, "��Ϣ��", "�����˺���������������" + QString::number(residualTimes) + "�δ���֮�󣬻ᱻ������\n��ȷ��������ȷ֮�����ز�����");
				return;
			}
			else
			{
				QMessageBox::warning(this, "����:", "������������������Ĵ���������࣬���ĵ�¼�˺��ѱ�����\n�������������ϵ������̣����̵绰��057185165173��");
				//����Ҫ�������˺���Ϣд�뵽�ļ�
				CreateLockFile();
				return;
			}
		}
		else
		{
			//��չ����
			m_errorCount = 0;
			return;
		}
	}
}

bool LoginInterface::CheckedLoginUserInfo()
{
	QString userName = ui.UsernameLineEdit->text().trimmed();
	QString password = ui.PasswordLineEdit->text().trimmed();
	if (userName == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Input account number cannot be empty, please re-enter!";
		QMessageBox::warning(this, "����:", "������˺Ų���Ϊ��, ���������룡");
		return false;
	}
	if (password == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Enter the password can not be empty, please re-enter!";
		QMessageBox::warning(this, "����:", "��������벻��Ϊ�գ����������룡");
		return false;
	}
	if (password.length() < 8)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Enter the password can not be empty, please re-enter!";
		QMessageBox::warning(this, "����:", "���볤�Ȳ���С��8λ�����������룡");
		return false;
	}

	if (userName.compare(password) == 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��¼ʱ�˺ź�����һ��!";
		QMessageBox::warning(this, "����:", "�˺ź����벻��һ�£����������룡");
		return false;
	}
	int userNamelength = userName.length();
	int passwordlength = password.length();
	if (userNamelength <= 20 && passwordlength <= 30)
	{
		//�ж��˺����Ƿ���������ַ�
		for (int i = 0; i < userNamelength; i++)
		{
			if ((userName[i] >= '0' && userName[i] <= '9') || (userName[i] >= 'a' && userName[i] <= 'z') || (userName[i] >= 'A' && userName[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account cannot have special characters except numbers and characters. Please re-enter!";
				QMessageBox::warning(this, "����:", "�˺Ų��ܰ��������ֺ���ĸ��������������ַ������������룡");
				return false;
			}
		}
	}
	else
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters, password length can not exceed 30 characters, please re-enter!";
		QMessageBox::warning(this, "����:", "�˺ų��Ȳ��ܳ���20���ַ������볤�Ȳ��ܳ���30���ַ������������룡");
		return false;
	}
	return true;
}

/*
��������FindInfoFromUserInfo
������QString usernamePar, QString passwordPar
���ܣ������û�����ȷ���û����������Ƿ���ȷ
����ֵΪint
	0 �û�����������ȷ����¼�ɹ���
	1 �˺�û�б�ע��
	2 �û���Ϣ�ļ����ܳ�����BUG
	3 �������벻��ȷ�������ж�����Ĵ������
	4 ��ʱ�ļ���ʧ��
*/
int LoginInterface::FindInfoFromUserInfo(QString usernamePar, QString passwordPar)
{
	//��¼��������֤��ʱ����Ҫ�Ƚ����ص���Ϣ�ļ�userInfo.db���ܣ����ܳ���ʱ�ļ�userInfo.db
	QString qstrpath = QDir::currentPath();
	QString qstrUserInfo = qstrpath + QString("/UserInfo/userInfo.db");
	QString temporaryFile = "userInfo.db";
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);

	//���ж���������Ϣ�ļ�ʱ����ڣ���������ڣ�˵����û��ע����˺�
	QFile userFile(qstrUserInfo);
	bool existStatus = userFile.exists(qstrUserInfo);
	if (!existStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��һ��ʹ��ϵͳ����û��ע����˺ţ�";
		QMessageBox::information(this, "��Ϣ:", "�˺�û�б�ע�ᣬ����ע��֮���ٵ�¼��");
		return 1;
	}
	//���ļ����н��ܣ�������ʱ�ļ�
	bool decryptionStatus = encryptedFileDialog->DecryptionFile(qstrUserInfo, temporaryFile);
	if (!decryptionStatus)
	{
		//����ʧ�ܣ�����ʱ���ܳ��������⣬����ϵ�ٷ����bug
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "�û���Ϣ�ļ�����ʧ�ܣ��޷���¼ϵͳ��";
		QMessageBox::information(this, "��Ϣ:", "�����¼�����뷴�����̽��\n���̵绰��057185165173");
		return 2;
	}

	//���ܳɹ���������ʱ�ļ�
	QFile tmpfile(temporaryFile);

	bool openStatus = tmpfile.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!openStatus)
	{
		QMessageBox::information(this, "��Ϣ:", "�˺�û�б�ע�ᣬ�����µ�½��");
		return 4;
	}
	QString fileContent = NULL;
	QString username = NULL;
	QString password = NULL;
	while (!tmpfile.atEnd())
	{
		fileContent = tmpfile.readLine();
		if (NULL == fileContent.trimmed())
		{
			continue;
		}
		username = fileContent.split("|").at(0).trimmed();
		password = fileContent.split("|").at(1).trimmed();
		if (username.compare(usernamePar.trimmed()) == 0)
		{
			if (password.compare(passwordPar.trimmed()) == 0)
			{
				tmpfile.close();
				remove(temporaryFile.toStdString().c_str());
				return 0;
			}
			else
			{
				QMessageBox::information(this, "��Ϣ:", "�������벻��ȷ�����������룡");
				tmpfile.close();
				remove(temporaryFile.toStdString().c_str());
				return 3;
			}
		}
		else
		{
			continue;
		}
	}
	tmpfile.close();
	remove(temporaryFile.toStdString().c_str());
	QMessageBox::information(this, "��Ϣ:", "�˺�û�б�ע�ᣬ���������룡");
	return 1;
}


bool LoginInterface::GetSerialNumber()
{
	//�Ѽ����ַ������н��ܣ�Ȼ����serialnumber���бȽϿ��ǲ�����ȫ��ͬ
	//��ȡ����������
	QString runPath = QCoreApplication::applicationDirPath();
	QString filepath = runPath + "/license.lic";
	this->process = new QProcess(this);
	process->start("wmic bios get serialnumber");
	process->waitForFinished();
	QByteArray output = process->readAllStandardOutput();
	QString serialnumberstr = output;
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "serialnumberstr:" << serialnumberstr;
	QStringList serialnumberlist = serialnumberstr.split("\n");
	QString serialnumber = "serialnumber:" + serialnumberlist.at(1).trimmed();
	qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "serialnumber:" << serialnumber;
	//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "encrypt_str after str:" << encrypt_str(serialnumber.toLocal8Bit().data());
	//QFile licfile("license.lic");
	QFile licfile(filepath);
	bool ok = licfile.exists();
	if (ok)
	{
		//�ɶ��򿪸����
		ok = licfile.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!ok)
		{
			qCritical() << "��Ȩ�ļ���ʧ�ܣ���Ȩʧ�ܣ�";
			QMessageBox::critical(this, "Critical", "��Ȩ�ļ���ʧ�ܣ���Ȩʧ�ܣ�");
			return false;
		}
		else
		{
			QByteArray readfileByte = licfile.readAll();//ȫ����ȡ�ļ�������
			qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "readfileByte:" << readfileByte;
			licfile.close();
			//�ȶԶ������ַ������н��ܣ�readFileDecodestr����֮����ַ���
			//���ļ����ݽ��н���
			QString readFileDecodestr = decode_str(readfileByte.data());
			//qDebug() << "����֮����ַ���:" << readFileDecodestr;

			//��ȡ��ǰʱ��
			QDateTime currentTime = QDateTime::currentDateTime();
			QString currentTimeStr = currentTime.toString("yyyyMMdd");
			int IntcurrentTime = currentTimeStr.toInt();
			//qDebug() << "��ǰʱ��:" << IntcurrentTime;
			//������֮���������ֽ�ɼ������֣�ע��ʱ�䣬���������룬����ʱ��
			QString startTimeStr = readFileDecodestr.split("|").at(0);//ע��ʱ��
			if (!startTimeStr.startsWith("start:"))
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�";
				QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
				return false;
			}
			else
			{
				//�����ǰ��ʱ��С��ע��ʱ�䣬����Ϊ�ļ��Ѿ����޸���
				int IntStartTime = startTimeStr.split(":").at(1).toInt();
				if (IntcurrentTime < IntStartTime)
				{
					qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�";
					QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
					return false;
				}
			}
			//qDebug() << "ע��ʱ�䣺" << startTimeStr;

			QString inputSerialNumber = readFileDecodestr.split("|").at(1);//�����ַ����е�������
			if (!inputSerialNumber.startsWith("serialnumber:"))
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�";
				QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
				return false;
			}
			else if (inputSerialNumber.compare(serialnumber) != 0)
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�";
				QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
				return false;
			}
			//qDebug() << "�����ַ����е������룺" << inputSerialNumber;

			QString endTimeStr = readFileDecodestr.split("|").at(2);//����ʱ��
			if (!endTimeStr.endsWith(":end"))
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�";
				QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
				return false;
			}
			else
			{
				int IntEndTime = endTimeStr.split(":").at(0).toInt();
				int diffTime = IntEndTime - IntcurrentTime;//ʱ���
														   //qDebug() << "ʱ��" << diffTime;
				if (diffTime < 0)
				{
					QMessageBox::critical(this, "����", "�Բ�����Ȩ�ļ��Ѿ����ڣ�������ܼ���ʹ�ã�����ϵ�ٷ����ѣ�");
					return false;
				}
				if (diffTime <= 30)
				{
					QMessageBox::information(this, "����", "������� " + QString::number(diffTime) + " �쵽�ڣ�����ϵ�ٷ��������ѣ�");
				}
			}
			//qDebug() << "����ʱ�䣺" << endTimeStr;
		}
	}
	else
	{
		return false;
	}
	return true;
}
#if 0
bool LoginInterface::GetSerialNumber()
{
	//�Ѽ����ַ������н��ܣ�Ȼ����serialnumber���бȽϿ��ǲ�����ȫ��ͬ
	//��ȡ����������
	QString runPath = QCoreApplication::applicationDirPath();
	QString filepath = runPath + "/license.lic";
	this->process = new QProcess(this);
	process->start("wmic bios get serialnumber");
	process->waitForFinished();
	QByteArray output = process->readAllStandardOutput();
	QString serialnumberstr = output;
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "serialnumberstr:" << serialnumberstr;
	QStringList serialnumberlist = serialnumberstr.split("\n");
	QString serialnumber = "serialnumber:" + serialnumberlist.at(1).trimmed();
	//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "serialnumber:" << serialnumber;
	//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "encrypt_str after str:" << encrypt_str(serialnumber.toLocal8Bit().data());
	//QFile licfile("license.lic");
	QFile licfile(filepath);
	bool ok = licfile.exists();
	if (ok)
	{
		//�ɶ��򿪸����
		ok = licfile.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!ok)
		{
			qCritical() << "license.lic file open fail !";
			QMessageBox::critical(this, "Critical", "license.lic �ļ���ʧ�ܣ�");
			return false;
		}
		else
		{
			QByteArray readfileByte;
			QString readfileLine;
			while (!licfile.atEnd())
			{
				//���û�ж����ļ�β��һ���еĶ�ȡ
				//readfileLine���ļ��м��ܵ��ַ���
				QByteArray readfileByte = licfile.readLine();
				readfileLine = readfileByte;
				//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "readfileLine:" << readfileLine;
				//�ȶԶ������ַ������н��ܣ�readFileDecodestr����֮����ַ���
				QString readFileDecodestr = decode_str(readfileLine.toLocal8Bit().data());
				//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "readFileDecodestr:" << readFileDecodestr;
				if (readFileDecodestr.contains("InstallationTime:"))
				{
					//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "InstallationTime:" << readFileDecodestr;
					continue;
				}
				else if (readFileDecodestr.contains("serialnumber:"))
				{
					//���ļ������������������readFileDecodestr���ܺ�ֱ����serialnumber�ȽϾͿ���ȷ���������Ƿ��޸�
					//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "serialnumber:" << readFileDecodestr;

					//����֮���������������бȽϣ������ͬ�����κ���ʾ�������ͬ����ʾlicense.lic �ļ�������
					if (serialnumber.compare(readFileDecodestr) == 0)
					{
						continue;
					}
					else
					{
						qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The license file has been modified to render the program unavailable !";
						QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
						licfile.close();
						return false;
					}

				}
				else if (readFileDecodestr.contains("DueTime:"))
				{
					QString DueTime = readFileDecodestr.split(":").at(1).trimmed();
					//qDebug() << "DueTime:" << DueTime;
					int IntDueTime = DueTime.toInt();
					QDateTime currentTime = QDateTime::currentDateTime();
					QString currentTimeStr = currentTime.toString("yyyyMMdd");
					int IntcurrentTime = currentTimeStr.toInt();
					int timeDiff = IntDueTime - IntcurrentTime;
					if (timeDiff < 0)
					{
						qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Sorry, the license of this software has expired and can't continue to use.";
						QMessageBox::information(this, "����", "�Բ�����Ȩ�ļ��Ѿ����ڣ�������ܼ���ʹ�ã�����ϵ�ٷ����ѣ�");
						return false;
					}
					if (timeDiff < 30)
					{
						//��ʾ�������timeDiff���쵽�ڣ�����ϵ�ٷ���������
						QMessageBox::information(this, "���棺", "�������  " + QString::number(timeDiff) + " �쵽�ڣ�����ϵ�ٷ��������ѡ�");
					}
					break;
				}
				else
				{
					qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The license file has been modified to render the program unavailable !";
					QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
					licfile.close();
					return false;
				}
			}
			licfile.close();

		}
	}
	else
	{
		return false;
	}
	return true;
}
#endif

void LoginInterface::GetInstallationAlignmentSlot(QString serialNumber)
{
	bool saveStatus = SaveLicenseFile(serialNumber);
	//qDebug() << "saveStatus:" << saveStatus;

	if (false == saveStatus)
	{
		return;
	}
	else
	{
		this->show();
		installationAlignment->close();
	}
}

//��ע�ᰴť�����ע��
/******************************************************************************
��������saveLicenseFile
������QString serialNumber ���к�
����ֵ��bool
���ܣ�������������кţ�Ȼ���ж��Ƿ���ȷ����ȷ����license�ļ�
���裺
	1.��ִ��wmic bios get serialnumber�����ȡ���������к�serialnumberstr����ȡ����δ���ܵ����к�SerialNumber\nM705URC8\n
	2.��serialnumberstr��\n�ֽ⣬Ȼ����serialnumber:�ַ���ƴ�ӳɼ����ļ��еļ��ܵ����к�serialnumber
	3.���ж�licence�ļ��Ƿ���ڣ�����������ж��Ƿ���ȷ����������ڣ�������license�ļ�
******************************************************************************/
bool LoginInterface::SaveLicenseFile(QString ParamSerialNumber)
{
	qDebug() << "��������������룺" << ParamSerialNumber;
	//�Ѽ����ַ������н��ܣ�Ȼ����serialnumber���бȽϿ��ǲ�����ȫ��ͬ
	//��ȡ����������
	QString runPath = QCoreApplication::applicationDirPath();
	QString filepath = runPath + "/license.lic";
	this->process = new QProcess(this);
	process->start("wmic bios get serialnumber");
	process->waitForFinished();
	QByteArray output = process->readAllStandardOutput();
	QString serialnumberstr = output;
	QStringList serialnumberlist = serialnumberstr.split("\n");
	QString serialnumber = "serialnumber:" + serialnumberlist.at(1).trimmed();//��ȡ��װ���Ե�������
	qDebug() << "��װ���Ե������룺" << serialnumber;
	QFile licfile(filepath);
	bool ok = licfile.exists();
	if (ok)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "��Ȩ�ļ��Ѿ����ڣ��ٴ���Ȩ��";
	}
	//�����֤�ļ������ڣ�˵�����״�ע������Ҫ���������������֤
	//����������������븳ֵ��lineEditstr
	QString lineEditstr = ParamSerialNumber;
	//qDebug() << "���������������2��" << lineEditstr;
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "lineEditstr:" << lineEditstr;
	QString decode_str1 = decode_str(lineEditstr.toLocal8Bit().data());
	//qDebug() << "����֮��Ĳ��������������decode_str1:" << decode_str1;
	//������֮���������ֽ�ɼ������֣�ע��ʱ�䣬���������룬����ʱ��
	QString startTimeStr = decode_str1.split("|").at(0);//ע��ʱ��
														//qDebug() << "ע��ʱ�䣺" << startTimeStr;
	QString inputSerialNumber = decode_str1.split("|").at(1);//�����ַ����е�������
															 //qDebug() << "�����ַ����е������룺" << inputSerialNumber;
	QString endTimeStr = decode_str1.split("|").at(2);//����ʱ��
													  //qDebug() << "����ʱ�䣺" << inputSerialNumber;
	if (serialnumber.compare(inputSerialNumber) == 0)
	{
		//���к���֤�ɹ��������к�д�뵽�ļ�
		//QFile *licenseFile = new QFile(filepath);
		QFile *licenseFile = new QFile(filepath);//"D:\\license.lic"
		bool openWriteStatus = licenseFile->open(QIODevice::WriteOnly | QIODevice::Text);//WriteOnly���У�ReadWriteҲ����
		if (!openWriteStatus)
		{
			//QMessageBox::information(this, "information:", filepath + licenseFile->errorString());
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "license.lic file creat fail !";
			QMessageBox::information(this, "��Ϣ", "��Ȩ�ļ�����ʧ�ܣ�");
			return false;
		}
		else
		{
			licenseFile->write(lineEditstr.toStdString().c_str(), lineEditstr.length());
			//licenseFile->write(DueTimeText.toStdString().c_str(), DueTimeText.length());
			licfile.waitForBytesWritten(500);
			licenseFile->close();

			//����ע�����
			//displayUi(true);

			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Register successfully, thank you for using the genuine software, welcome to use!";
			QMessageBox::information(this, "��Ϣ", "ע��ɹ�����л��ʹ��������������ӭʹ�ã�");
			return true;
		}
	}

	else
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Registration is unsuccessful, please contact the official to obtain the serial number, thank you for supporting the genuine software!";
		QMessageBox::information(this, "���棺", "ע��ʧ�ܣ�����ϵ�ٷ���ȡ��ȷ�������룬��л֧�����������");
		return false;
	}
}
#if 0
bool LoginInterface::SaveLicenseFile(QString serialNumber)
{
	//�Ѽ����ַ������н��ܣ�Ȼ����serialnumber���бȽϿ��ǲ�����ȫ��ͬ
	//��ȡ����������
	QString runPath = QCoreApplication::applicationDirPath();
	QString filepath = runPath + "/license.lic";
	this->process = new QProcess(this);
	process->start("wmic bios get serialnumber");
	process->waitForFinished();
	QByteArray output = process->readAllStandardOutput();
	QString serialnumberstr = output;
	QStringList serialnumberlist = serialnumberstr.split("\n");
	QString serialnumber = "serialnumber:" + serialnumberlist.at(1).trimmed();
	QFile licfile(filepath);
	bool ok = licfile.exists();
	if (ok)
	{
		//�ɶ��򿪸��ļ�
		ok = licfile.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!ok)
		{
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "license.lic file open fail !";
			QMessageBox::information(this, "����", "��Ȩ�ļ���ʧ�ܣ�");
			return false;
		}
		else
		{
			QByteArray readfileByte;
			QString readfileLine;
			while (!licfile.atEnd())
			{
				//���û�ж����ļ�β��һ���еĶ�ȡ
				//readfileLine���ļ��м��ܵ��ַ���
				QByteArray readfileByte = licfile.readLine();
				readfileLine = readfileByte;
				//qDebug() << "readfileLine:" << readfileLine;
				//�ȶԶ������ַ������н��ܣ�readFileDecodestr����֮����ַ���
				QString readFileDecodestr = decode_str(readfileLine.toLocal8Bit().data());
				//qDebug() << "readFileDecodestr:" << readFileDecodestr;
				if (readFileDecodestr.contains("InstallationTime:"))
				{
					continue;
				}
				else if (readFileDecodestr.contains("serialnumber:"))
				{
					//���ļ������������������readFileDecodestr���ܺ�ֱ����serialnumber�ȽϾͿ���ȷ���������Ƿ��޸�
					//qDebug() << "serialnumber:" << readFileDecodestr;
					//����֮���������������бȽϣ������ͬ�����κ���ʾ�������ͬ����ʾlicense.lic �ļ�������
					if (serialnumber.compare(readFileDecodestr) == 0)
					{
						continue;
					}
					else
					{
						//qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The license file has been modified to render the program unavailable !";
						QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
						licfile.close();
						return false;
					}

				}
				else if (readFileDecodestr.contains("DueTime:"))
				{
					QString DueTime = readFileDecodestr.split(":").at(1).trimmed();
					//qDebug() << "DueTime:" << DueTime;
					int IntDueTime = DueTime.toInt();
					QDateTime currentTime = QDateTime::currentDateTime();
					QString currentTimeStr = currentTime.toString("yyyyMMdd");
					int IntcurrentTime = currentTimeStr.toInt();
					int timeDiff = IntDueTime - IntcurrentTime;
					if (timeDiff < 0)
					{
						qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Sorry, the license of this software has expired and can't continue to use.";
						QMessageBox::information(this, "���棺", "�Բ�����Ȩ�ļ��Ѿ����ڣ�������ܼ���ʹ�ã�����ϵ�ٷ����ѣ�");
						return false;
					}
					if (timeDiff < 30)
					{
						//��ʾ�������timeDiff���쵽�ڣ�����ϵ�ٷ���������
						QMessageBox::information(this, "����", "������� " + QString::number(timeDiff) + " �쵽�ڣ�����ϵ�ٷ��������ѣ�");
					}
					break;
				}
				else
				{
					qCritical() << "The license file has been modified to render the program unavailable !";
					QMessageBox::critical(this, "����", "��Ȩ�ļ��Ѿ����޸ģ���Ȩ��֤ʧ�ܣ�");
					licfile.close();
					return false;
				}
			}
			licfile.close();
			return true;

		}
	}
	else
	{
		QString lineEditstr = serialNumber;
		//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "lineEditstr:" << lineEditstr;
		QString decode_str1 = decode_str(lineEditstr.toLocal8Bit().data());

		//qDebug() << "decode_str1:" << decode_str1;
		//�����֤�ļ������ڣ�˵�����״�ע������Ҫ���������������֤
		if (serialnumber.compare(decode_str1) == 0)
		{
			//���к���֤�ɹ��������к�д�뵽�ļ�
			//QFile *licenseFile = new QFile(filepath);
			QFile *licenseFile = new QFile(filepath);//"D:\\license.lic"
			bool openWriteStatus = licenseFile->open(QIODevice::WriteOnly | QIODevice::Text);//WriteOnly���У�ReadWriteҲ����
			if (!openWriteStatus)
			{
				//QMessageBox::information(this, "information:", filepath + licenseFile->errorString());
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "license.lic file creat fail !";
				QMessageBox::information(this, "��Ϣ", "��Ȩ�ļ�����ʧ�ܣ�");
				return false;
			}
			else
			{
				//����װ����д�뵽�ļ�
				QDateTime currentTime = QDateTime::currentDateTime();
				QString currentTimeStr = currentTime.toString("yyyyMMdd");
				//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "currentTimeStr:" << currentTimeStr;
				QString InstallationTime = "InstallationTime:" + currentTimeStr;
				//��������д�뵽�ļ�
				//QString SerialText = "serialnumber:" + lineEditstr + "\n";
				QString SerialText = lineEditstr + "\n";
				//����������д�뵽�ļ�
				//��������Ϊ��װ���������һ�꼴��
				int DueTime = currentTimeStr.toInt() + 10000;
				QString DueTimeStr = "DueTime:" + QString::number(DueTime);
				//�ȷֱ𽫰�װʱ�䣬����ʱ�����Ȼ����д�뵽�ļ�
				QString InstallationTimeText = encrypt_str(InstallationTime.toLocal8Bit().data()) + "\n";
				QString DueTimeText = encrypt_str(DueTimeStr.toLocal8Bit().data()) + "\n";
				licenseFile->write(InstallationTimeText.toStdString().c_str(), InstallationTimeText.length());
				licenseFile->write(SerialText.toStdString().c_str(), SerialText.length());
				licenseFile->write(DueTimeText.toStdString().c_str(), DueTimeText.length());
				licfile.waitForBytesWritten(500);
				licenseFile->close();

				//����ע�����
				//displayUi(true);

				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Register successfully, thank you for using the genuine software, welcome to use!";
				QMessageBox::information(this, "��Ϣ", "ע��ɹ�����л��ʹ��������������ӭʹ�ã�");
				return true;
			}
		}
		else
		{
			qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Registration is unsuccessful, please contact the official to obtain the serial number, thank you for supporting the genuine software!";
			QMessageBox::information(this, "���棺", "ע��ʧ�ܣ�����ϵ�ٷ���ȡ��ȷ�������룬��л֧�����������");
			return false;
		}
	}
}
#endif

bool LoginInterface::LockAccountsStatus(QString userNamePar)
{
	QString qstrpath = QDir::currentPath();
	QString qstrFilePathFileName = qstrpath + QString("/LockUserInfo/") + ui.UsernameLineEdit->text().trimmed() + ".db";
	QFile lockFile(qstrFilePathFileName);
	if (!lockFile.exists())//����ļ�������,˵���ļ�û�б���
	{
		return false;
	}
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);
	bool decryptionStatus= encryptedFileDialog->DecryptionFile(qstrFilePathFileName, "temporaryFile");
	if (decryptionStatus)
	{
		//�����ļ����ܳɹ�
		QFile file("temporaryFile");
		bool openStatus = file.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!openStatus)
		{
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "temporaryFile file open fail!";
			return false;
		}
		QString fileContext = file.readLine();
		QString lockStatu = fileContext.split("|").at(2);
		if (lockStatu.compare("0") == 0)
		{
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "lock flag : " + lockStatu;
			remove("temporaryFile");
			return false;
		}
		else
		{
			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "lock flag : " + lockStatu;
			remove("temporaryFile");
			return true;
		}
	}
	else
	{
		return false;
	}
}


//�ȴ���һ����ΪLockUserInfo�������ļ��У�Ȼ����Ϣ�����ڶ�Ӧ���ļ�����
void LoginInterface::CreateLockFile()
{
	// ��ȡ��ǰ��·��
	QString qstrpath = QDir::currentPath();
	QString qstrFilePathHide = qstrpath + QString("/LockUserInfo");
	// ����ļ�����Ҫ����
	QDir dir_path_hide(qstrFilePathHide);
	if (!dir_path_hide.exists())
	{
		dir_path_hide.mkdir(qstrFilePathHide);
		//����ļ��д����ɹ���������д�뵽�ļ�
		SaveLockInfo();
	}
	// windows API��Ҫ�� QString ת��Ϊ LPCWSTR
	// ���ļ�������Ϊ����
	SetFileAttributes((LPCWSTR)qstrFilePathHide.unicode(), FILE_ATTRIBUTE_HIDDEN);
	SaveLockInfo();
}

void LoginInterface::SaveLockInfo()
{
	QString qstrpath = QDir::currentPath();
	QString qstrFilePathFileName = qstrpath + QString("/LockUserInfo/") + ui.UsernameLineEdit->text().trimmed() + ".db";
	QFile file("temporaryFile");
	bool openStatus = file.open(QIODevice::WriteOnly | QIODevice::Text);
	if (!openStatus)
	{
		qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Lock file write fail!";
		return;
	}

	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);
	QString timeStr = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
	//��Ҫ���ܵ��ַ�
	QString plaintext = ui.UsernameLineEdit->text().trimmed() + "|" + ui.PasswordLineEdit->text().trimmed() + "|1|" + timeStr;
	//QMessageBox::information(this,"����:", plaintext);
	file.write(plaintext.toStdString().c_str());

	file.close();
	//���ļ����м���
	bool encryptedStatus = encryptedFileDialog->EncryptionFile("temporaryFile", qstrFilePathFileName);
	if (encryptedStatus)
	{
		remove("temporaryFile");
	}

	//encryptedFileDialog->DecryptionFile(qstrFilePathFileName,"testcfg2.txt");
	//���ļ����н���
	//�������ַ��ý��ܷ�������Ȼ����ʾ
	SetFileAttributes((LPCWSTR)qstrFilePathFileName.unicode(), FILE_ATTRIBUTE_HIDDEN);
}