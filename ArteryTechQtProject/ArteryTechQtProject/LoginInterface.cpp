#include "LoginInterface.h"

//==========================DES加密解密===================================================
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

// 对迭代后的L16,R16执行IP逆置换,输出密文
const char IPR_Table[64] = {
	40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25
};

/*--------------------------- 迭代法则 ----------------------------*/

// F函数,32位的R0进行E变换,扩为48位输出 (R1~R16)        [备用A]  [明文操作]
static char E_Table[48] = {
	32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1
};

// 子密钥K(i)的获取 密钥为K 抛弃第6,16,24,32,40,48,64位          [密钥操作]
// 用PC1选位 分为 前28位C0,后28位D0 两部分
static char PC1_Table[56] = {
	57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
};

// 对C0,D0分别进行左移,共16次,左移位数与下面对应                 [密钥操作]
static char Move_Table[16] = {
	1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

// C1,D1为第一次左移后得到,进行PC2选位,得到48位输出K1   [备用B]   [密钥操作]
static char PC2_Table[48] = {
	14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40, 51, 34, 33, 48,
	44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

/*------------- F函数 备用A和备用B 异或 得到48位输出 ---------------*/

// 异或后的结果48位分为8组,每组6位,作为8个S盒的输入             [组合操作]
// S盒以6位作为输入(8组),4位作为输出(4*(8组)=32位)
// S工作原理 假设输入为A=abcdef ,则bcde所代表的数是0-15之间的
// 一个数记为 X=bcde ,af代表的是0-3之间的一个数,记为 Y=af
// 在S1的X列,Y行找到一个数Value,它在0-15之间,可以用二进制表示
// 所以为4bit (共32位)
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

// F函数 最后第二步,对S盒输出的32进行P置换                     [组合操作]
// 输出的值参与一次迭代:
// L(i)=R(i-1)
// R(i)=L(i-1)^f(R(i-1),K(i)) 异或
static char P_Table[32] = {
	16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
	2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25
};

typedef unsigned long DWORD;
typedef unsigned short WORD;


char g_str[31];
static DWORD g_eax;   // 存储返回的eax
static DWORD g_ebx;   // 存储返回的ebx
static DWORD g_ecx;   // 存储返回的ecx
static DWORD g_edx;   // 存储返回的edx
int g_isSupport;

// 16个子密钥K(1~16)
static bool SubKey[16][48] = { { 0, 0 } };

void BitsCopy(bool *DatOut, bool *DatIn, int Len);  // 数组复制

void ByteToBit(bool *DatOut, char *DatIn, int Num); // 字节到位
void BitToByte(char *DatOut, bool *DatIn, int Num); // 位到字节

void BitToHex(char *DatOut, bool *DatIn, int Num);  // 二进制到十六进制 64位 to 4*16字符
void HexToBit(bool *DatOut, char *DatIn, int Num);  // 十六进制到二进制

void TablePermute(bool *DatOut, bool *DatIn, const char *Table, int Num); // 位表置换函数
void LoopMove(bool *DatIn, int Len, int Num);     // 循环左移 Len长度 Num移动位数
void Xor(bool *DatA, bool *DatB, int Num);         // 异或函数

void S_Change(bool DatOut[32], bool DatIn[48]);   // S盒变换
void F_Change(bool DatIn[32], bool DatKi[48]);    // F函数

void SetKey(char KeyIn[8]);                         // 设置密钥
void PlayDes(char MesOut[8], char MesIn[8]);       // 执行DES加密
void KickDes(char MesOut[8], char MesIn[8]);             // 执行DES解密

QString decode_str(char *inputstr);//解密函数
QString encrypt_str(char *inputstr);//加密函数
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
int get_cpuid(char *cpuid);//获取CPUID processer id
int get_mac(char* mac);//获取MAC地址
void creat_licensefile(char *filename, char *num);//获取CPUID和MAC地址的总入口函数
												  //static int myread(int fd, u8 *buf, size_t count, const char *prefix);
int myread(int fd, u8 *buf, size_t count, const char *prefix);

//===================================================================


/*-------------------------------
把DatIn开始的长度位Len位的二进制
复制到DatOut后
--------------------------------*/
void BitsCopy(bool *DatOut, bool *DatIn, int Len)     // 数组复制 OK
{
	int i = 0;
	for (i = 0; i < Len; i++)
	{
		DatOut[i] = DatIn[i];
	}
}

/*-------------------------------
字节转换成位函数
每8次换一个字节 每次向右移一位
和1与取最后一位 共64位
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
位转换成字节函数
字节数组每8次移一位
位每次向左移 与上一次或
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
二进制密文转换为十六进制
需要16个字符表示
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
			DatOut[i] = DatOut[i] % 16 + '7';       //  余数大于9时处理 10-15 to A-F
		}                                     //  输出字符
		else
		{
			DatOut[i] = DatOut[i] % 16 + '0';       //  输出字符
		}
	}

}

/*---------------------------------------------
十六进制字符转二进制
----------------------------------------------*/
void HexToBit(bool *DatOut, char *DatIn, int Num)
{
	int i = 0;                        // 字符型输入
	for (i = 0; i<Num; i++)
	{
		if ((DatIn[i / 4])>'9')         //  大于9
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

// 表置换函数  OK
void TablePermute(bool *DatOut, bool *DatIn, const char *Table, int Num)
{
	int i = 0;
	static bool Temp[256] = { 0 };
	for (i = 0; i < Num; i++)                // Num为置换的长度
	{
		Temp[i] = DatIn[Table[i] - 1];  // 原来的数据按对应的表上的位置排列
	}
	BitsCopy(DatOut, Temp, Num);       // 把缓存Temp的值输出
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// 子密钥的移位
void LoopMove(bool *DatIn, int Len, int Num) // 循环左移 Len数据长度 Num移动位数
{
	static bool Temp[256] = { 0 };    // 缓存   OK
	BitsCopy(Temp, DatIn, Num);       // 将数据最左边的Num位(被移出去的)存入Temp
	BitsCopy(DatIn, DatIn + Num, Len - Num); // 将数据左边开始的第Num移入原来的空间
	BitsCopy(DatIn + Len - Num, Temp, Num);  // 将缓存中移出去的数据加到最右边
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// 按位异或
void Xor(bool *DatA, bool *DatB, int Num)           // 异或函数
{
	int i = 0;
	for (i = 0; i < Num; i++)
	{
		DatA[i] = DatA[i] ^ DatB[i];                  // 异或
	}
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// 输入48位 输出32位 与Ri异或
void S_Change(bool DatOut[32], bool DatIn[48])     // S盒变换
{
	int i, X, Y;                                    // i为8个S盒
	for (i = 0, Y = 0, X = 0; i < 8; i++, DatIn += 6, DatOut += 4)   // 每执行一次,输入数据偏移6位
	{    										  // 每执行一次,输出数据偏移4位
		Y = (DatIn[0] << 1) + DatIn[5];                          // af代表第几行
		X = (DatIn[1] << 3) + (DatIn[2] << 2) + (DatIn[3] << 1) + DatIn[4]; // bcde代表第几列
		ByteToBit(DatOut, &S_Box[i][Y][X], 4);      // 把找到的点数据换为二进制
	}
}

/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

// F函数
void F_Change(bool DatIn[32], bool DatKi[48])       // F函数
{
	static bool MiR[48] = { 0 };             // 输入32位通过E选位变为48位
	TablePermute(MiR, DatIn, E_Table, 48);
	Xor(MiR, DatKi, 48);                   // 和子密钥异或
	S_Change(DatIn, MiR);                 // S盒变换
	TablePermute(DatIn, DatIn, P_Table, 32);   // P置换后输出
}


/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

void SetKey(char KeyIn[8])               // 设置密钥 获取子密钥Ki
{
	int i = 0;
	static bool KeyBit[64] = { 0 };                // 密钥二进制存储空间
	static bool *KiL = &KeyBit[0], *KiR = &KeyBit[28];  // 前28,后28共56
	ByteToBit(KeyBit, KeyIn, 64);                    // 把密钥转为二进制存入KeyBit
	TablePermute(KeyBit, KeyBit, PC1_Table, 56);      // PC1表置换 56次
	for (i = 0; i < 16; i++)
	{
		LoopMove(KiL, 28, Move_Table[i]);       // 前28位左移
		LoopMove(KiR, 28, Move_Table[i]);	      // 后28位左移
		TablePermute(SubKey[i], KeyBit, PC2_Table, 48);
		// 二维数组 SubKey[i]为每一行起始地址
		// 每移一次位进行PC2置换得 Ki 48位
	}
}
/*==================================================================================
function:
param:
return:
author:
==================================================================================*/

void PlayDes(char MesOut[8], char MesIn[8])  // 执行DES加密
{                                           // 字节输入 Bin运算 Hex输出
	int i = 0;
	static bool MesBit[64] = { 0 };        // 明文二进制存储空间 64位
	static bool Temp[32] = { 0 };
	static bool *MiL = &MesBit[0], *MiR = &MesBit[32]; // 前32位 后32位
	ByteToBit(MesBit, MesIn, 64);                 // 把明文换成二进制存入MesBit
	TablePermute(MesBit, MesBit, IP_Table, 64);    // IP置换
	for (i = 0; i < 16; i++)                       // 迭代16次
	{
		BitsCopy(Temp, MiR, 32);            // 临时存储
		F_Change(MiR, SubKey[i]);           // F函数变换
		Xor(MiR, MiL, 32);                  // 得到Ri
		BitsCopy(MiL, Temp, 32);            // 得到Li
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

void KickDes(char MesOut[8], char MesIn[8])       // 执行DES解密
{												// Hex输入 Bin运算 字节输出
	int i = 0;
	static bool MesBit[64] = { 0 };        // 密文二进制存储空间 64位
	static bool Temp[32] = { 0 };
	static bool *MiL = &MesBit[0], *MiR = &MesBit[32]; // 前32位 后32位
	HexToBit(MesBit, MesIn, 64);                 // 把密文换成二进制存入MesBit
	TablePermute(MesBit, MesBit, IP_Table, 64);    // IP置换
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

//解密函数，根据CPU的SN和MAC的加密信息进行解密
QString decode_str(char *inputstr)
{
	int i = 0;
	char MesHex[16] = { 0 };         // 16个字符数组用于存放 64位16进制的密文
	QString MyKeystr = "asd!@#$%";
	//char *MyKey = "12345678"; // 初始密钥 8字节*8
	char *MyKey = MyKeystr.toLocal8Bit().data(); // 初始密钥 8字节*8
	char MyMessage[16] = { 0 };       // 初始明文

	int size;
	int len = 0;
	char *outfilestr;
	//char *retstr = NULL;
	int count = 0;
	char num = 0;


	size = strlen(inputstr);

	//filestr分配空间用来存取文件的内容
	outfilestr = (char *)malloc(sizeof(char)*size);
	memset(outfilestr, 0, strlen(outfilestr));


	//先将fp1中的内容读取到filestr中
	//fread(filestr, 1, size, fp1);

	//printf("filestr = %s\n",filestr);
	SetKey(MyKey);
	//如果是对文件进行加密，将filestr分成八个char一段，如果是对filestr进行解密分成16char一段
	for (i = 0; i < size;)
	{
		i = i + 16;
		if (i <= size)
		{
			memset(MesHex, 0, 16);
			memset(MyMessage, 0, 8);
			memcpy(MesHex, inputstr + (i - 16), 16);
			//printf("MesHex = %s\n",MesHex);
			// 设置密钥 得到子密钥Ki
			KickDes(MyMessage, MesHex);     // 执行DES加密
											//加密
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

//加密函数对字符串进行加密
QString encrypt_str(char *inputstr)
{
	//char *retstr = NULL;
	//char *inputstr = "11253017-F8-32-E4-74-10-8A";
	QString MyKeystr = "asd!@#$%";
	//char *MyKey = "12345678"; // 初始密钥 8字节*8
	char *MyKey = MyKeystr.toLocal8Bit().data(); // 初始密钥 8字节*8
	int i = 0;
	int size = 0;
	int len = 0, count = 0;
	char MesHex[16] = { 0 };         // 16个字符数组用于存放 64位16进制的密文
	char MyMessage[16] = { 0 };       // 初始明文
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
			// 设置密钥 得到子密钥Ki
			PlayDes(MesHex, MyMessage);   // 执行DES加密
										  //加密
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
			// 设置密钥 得到子密钥Ki
			PlayDes(MesHex, MyMessage);   // 执行DES加密
										  //加密
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
	//修改返回值，C语言中返回retstr，修改后返回results
	//memset(retstr, 0, len);
	//memcpy(retstr, enoutfilestr, count * 16);
	//qDebug()<<"enoutfilestr len  = "<<strlen(enoutfilestr);
	//memcpy(retstr, enoutfilestr, g_count);
	QString results = enoutfilestr;
	//qDebug() << "enoutfilestr:" << enoutfilestr;
	return results;
}
//==========================DES加密解密===================================================

LoginInterface::LoginInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	//this->setMaximumSize(500, 300);
	//this->setMinimumSize(500, 300);
	this->resize(500, 300);//设置窗口的尺寸
	//设置窗口的默认显示位置在屏幕的中间
	QDesktopWidget *deskdop = QApplication::desktop();
	move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);

	ui.BackgroundLabel->setAlignment(Qt::AlignCenter);
	ui.BackgroundLabel->setText("软件型号规格：HBFlows \n软件版本号：01.00.00\n软件发布版本号：01");
	this->setWindowTitle("CT无创血流储备分数测量系统");
	ui.PasswordLineEdit->setEchoMode(QLineEdit::Password);//输入的时候就显示圆点
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
	//信号与槽函数的连接
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
	//根据窗口的大小绘制背景图片
	QPainter painter(this);
	painter.drawPixmap(10, 10, ui.BackgroundLabel->width(), ui.BackgroundLabel->height(), QPixmap("images/background.png"));
}

//找回密码槽函数
void LoginInterface::RetPasswordPushButtonSlot()//找回密码槽函数
{
	RetrievePasswordInterface *retrievePasswordInterface = new RetrievePasswordInterface();
	retrievePasswordInterface->show();
}
void LoginInterface::RegisterPushButtonSlot()//注册槽函数
{
	RegisterInterface *registerInterface = new RegisterInterface();
	QMessageBox::information(this,"消息","注册账号！");
	registerInterface->show();
	//QObject::connect(registerInterface, SIGNAL(registerSignal()), this, SLOT(getRegisterSignal()));
}

void LoginInterface::LoginPushButtonSlot()
{
	//先判断用户名和密码输入是否符合规范
	bool checkStatus = CheckedLoginUserInfo();
	if (checkStatus)
	{
		//数据库链接成功，下面判断用户名和密码是否在数据库表中
		QString username = ui.UsernameLineEdit->text().trimmed();
		QString password = ui.PasswordLineEdit->text().trimmed();
		//需要先验证账号是否已被锁定进行校验
		bool lockStatus = LockAccountsStatus(username);
		if (lockStatus)
		{
			QMessageBox::warning(this, "警告:", "您的账号已被锁。\n如需解锁，请联系软件厂商，厂商电话：057185165173！");
			return;
		}
		int findStatus = FindInfoFromUserInfo(username, password);//从用户信息表文件中查找信息
		if (findStatus == 0)
		{
			m_errorCount = 0;
			QMessageBox::information(this, "消息:", "恭喜你登录成功！");
			//创建用户名时间文件
			QString timeStr = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
			QString accoutStr = ui.UsernameLineEdit->text().trimmed();
			QString tmpFileName = timeStr + "_" + accoutStr + ".txt";
			QFile tmpFile(tmpFileName);
			bool tmpFileOpen = tmpFile.open(QIODevice::WriteOnly | QIODevice::Text);
			if (!tmpFileOpen)
			{
				QMessageBox::information(this, "消息:", "临时文件创建失败！");
				return;
			}
			tmpFile.close();
			//登录成功之后显示主界面
			ArteryTechQtProject *arteryTechQtProject = new ArteryTechQtProject(tmpFileName);
			arteryTechQtProject->show();
			hide();
			//发送登录成功的信号
			//sendLoginSuccessSignal();
		}
		else if(findStatus == 3)
		{
			//判断登录次数是不是大于5次，如果是的，直接锁死文件
			if (m_errorCount < 5)
			{
				m_errorCount++;
				int residualTimes = 5 - m_errorCount;
				QMessageBox::information(this, "消息：", "您的账号密码在连续输入" + QString::number(residualTimes) + "次错误之后，会被锁定。\n请确定密码正确之后慎重操作！");
				return;
			}
			else
			{
				QMessageBox::warning(this, "警告:", "由于您连续输入密码的错误次数过多，您的登录账号已被锁。\n如需解锁，请联系软件厂商，厂商电话：057185165173！");
				//将需要锁定的账号信息写入到文件
				CreateLockFile();
				return;
			}
		}
		else
		{
			//拓展功能
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
		QMessageBox::warning(this, "警告:", "输入的账号不能为空, 请重新输入！");
		return false;
	}
	if (password == NULL)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Enter the password can not be empty, please re-enter!";
		QMessageBox::warning(this, "警告:", "输入的密码不能为空，请重新输入！");
		return false;
	}
	if (password.length() < 8)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Enter the password can not be empty, please re-enter!";
		QMessageBox::warning(this, "警告:", "密码长度不能小于8位，请重新输入！");
		return false;
	}

	if (userName.compare(password) == 0)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "登录时账号和密码一致!";
		QMessageBox::warning(this, "警告:", "账号和密码不能一致，请重新输入！");
		return false;
	}
	int userNamelength = userName.length();
	int passwordlength = password.length();
	if (userNamelength <= 20 && passwordlength <= 30)
	{
		//判断账号中是否存在特殊字符
		for (int i = 0; i < userNamelength; i++)
		{
			if ((userName[i] >= '0' && userName[i] <= '9') || (userName[i] >= 'a' && userName[i] <= 'z') || (userName[i] >= 'A' && userName[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account cannot have special characters except numbers and characters. Please re-enter!";
				QMessageBox::warning(this, "警告:", "账号不能包含除数字和字母以外的其他特殊字符，请重新输入！");
				return false;
			}
		}
	}
	else
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Account length can not exceed 20 characters, password length can not exceed 30 characters, please re-enter!";
		QMessageBox::warning(this, "警告:", "账号长度不能超过20个字符，密码长度不能超过30个字符，请重新输入！");
		return false;
	}
	return true;
}

/*
函数名：FindInfoFromUserInfo
参数：QString usernamePar, QString passwordPar
功能：查找用户名，确定用户名和密码是否正确
返回值为int
	0 用户名和密码正确，登录成功。
	1 账号没有被注册
	2 用户信息文件解密出现了BUG
	3 密码输入不正确，用来判断密码的错误次数
	4 临时文件打开失败
*/
int LoginInterface::FindInfoFromUserInfo(QString usernamePar, QString passwordPar)
{
	//登录序列码验证的时候，需要先将隐藏的信息文件userInfo.db解密，解密成临时文件userInfo.db
	QString qstrpath = QDir::currentPath();
	QString qstrUserInfo = qstrpath + QString("/UserInfo/userInfo.db");
	QString temporaryFile = "userInfo.db";
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);

	//先判断音场的信息文件时否存在，如果不存在，说明还没有注册过账号
	QFile userFile(qstrUserInfo);
	bool existStatus = userFile.exists(qstrUserInfo);
	if (!existStatus)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "第一次使用系统，还没有注册过账号！";
		QMessageBox::information(this, "消息:", "账号没有被注册，请先注册之后再登录！");
		return 1;
	}
	//对文件进行解密，生成临时文件
	bool decryptionStatus = encryptedFileDialog->DecryptionFile(qstrUserInfo, temporaryFile);
	if (!decryptionStatus)
	{
		//解密失败，可能时解密程序有问题，需联系官方解决bug
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "用户信息文件解密失败，无法登录系统！";
		QMessageBox::information(this, "消息:", "软件登录有误，请反馈厂商解决\n厂商电话：057185165173");
		return 2;
	}

	//解密成功，操作临时文件
	QFile tmpfile(temporaryFile);

	bool openStatus = tmpfile.open(QIODevice::ReadOnly | QIODevice::Text);
	if (!openStatus)
	{
		QMessageBox::information(this, "消息:", "账号没有被注册，请重新登陆！");
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
				QMessageBox::information(this, "消息:", "密码输入不正确，请重新输入！");
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
	QMessageBox::information(this, "消息:", "账号没有被注册，请重新输入！");
	return 1;
}


bool LoginInterface::GetSerialNumber()
{
	//把加密字符串进行解密，然后与serialnumber进行比较看是不是完全相同
	//获取机器序列码
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
		//可读打开该软件
		ok = licfile.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!ok)
		{
			qCritical() << "授权文件打开失败，授权失败！";
			QMessageBox::critical(this, "Critical", "授权文件打开失败，授权失败！");
			return false;
		}
		else
		{
			QByteArray readfileByte = licfile.readAll();//全部读取文件的内容
			qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "readfileByte:" << readfileByte;
			licfile.close();
			//先对读到的字符串进行解密，readFileDecodestr解密之后的字符串
			//将文件内容进行解密
			QString readFileDecodestr = decode_str(readfileByte.data());
			//qDebug() << "解密之后的字符串:" << readFileDecodestr;

			//获取当前时间
			QDateTime currentTime = QDateTime::currentDateTime();
			QString currentTimeStr = currentTime.toString("yyyyMMdd");
			int IntcurrentTime = currentTimeStr.toInt();
			//qDebug() << "当前时间:" << IntcurrentTime;
			//将解密之后的序列码分解成几个部分，注册时间，电脑序列码，到期时间
			QString startTimeStr = readFileDecodestr.split("|").at(0);//注册时间
			if (!startTimeStr.startsWith("start:"))
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "授权文件已经被修改，授权验证失败！";
				QMessageBox::critical(this, "错误", "授权文件已经被修改，授权验证失败！");
				return false;
			}
			else
			{
				//如果当前的时间小于注册时间，则认为文件已经被修改了
				int IntStartTime = startTimeStr.split(":").at(1).toInt();
				if (IntcurrentTime < IntStartTime)
				{
					qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "授权文件已经被修改，授权验证失败！";
					QMessageBox::critical(this, "错误", "授权文件已经被修改，授权验证失败！");
					return false;
				}
			}
			//qDebug() << "注册时间：" << startTimeStr;

			QString inputSerialNumber = readFileDecodestr.split("|").at(1);//解密字符串中的序列码
			if (!inputSerialNumber.startsWith("serialnumber:"))
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "授权文件已经被修改，授权验证失败！";
				QMessageBox::critical(this, "错误", "授权文件已经被修改，授权验证失败！");
				return false;
			}
			else if (inputSerialNumber.compare(serialnumber) != 0)
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "授权文件已经被修改，授权验证失败！";
				QMessageBox::critical(this, "错误", "授权文件已经被修改，授权验证失败！");
				return false;
			}
			//qDebug() << "解密字符串中的序列码：" << inputSerialNumber;

			QString endTimeStr = readFileDecodestr.split("|").at(2);//到期时间
			if (!endTimeStr.endsWith(":end"))
			{
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "授权文件已经被修改，授权验证失败！";
				QMessageBox::critical(this, "错误", "授权文件已经被修改，授权验证失败！");
				return false;
			}
			else
			{
				int IntEndTime = endTimeStr.split(":").at(0).toInt();
				int diffTime = IntEndTime - IntcurrentTime;//时间差
														   //qDebug() << "时间差：" << diffTime;
				if (diffTime < 0)
				{
					QMessageBox::critical(this, "错误", "对不起，授权文件已经到期，软件不能继续使用！请联系官方续费！");
					return false;
				}
				if (diffTime <= 30)
				{
					QMessageBox::information(this, "警告", "软件还有 " + QString::number(diffTime) + " 天到期，请联系官方进行续费！");
				}
			}
			//qDebug() << "到期时间：" << endTimeStr;
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
	//把加密字符串进行解密，然后与serialnumber进行比较看是不是完全相同
	//获取机器序列码
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
		//可读打开该软件
		ok = licfile.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!ok)
		{
			qCritical() << "license.lic file open fail !";
			QMessageBox::critical(this, "Critical", "license.lic 文件打开失败！");
			return false;
		}
		else
		{
			QByteArray readfileByte;
			QString readfileLine;
			while (!licfile.atEnd())
			{
				//如果没有读到文件尾，一行行的读取
				//readfileLine是文件中加密的字符串
				QByteArray readfileByte = licfile.readLine();
				readfileLine = readfileByte;
				//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "readfileLine:" << readfileLine;
				//先对读到的字符串进行解密，readFileDecodestr解密之后的字符串
				QString readFileDecodestr = decode_str(readfileLine.toLocal8Bit().data());
				//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "readFileDecodestr:" << readFileDecodestr;
				if (readFileDecodestr.contains("InstallationTime:"))
				{
					//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "InstallationTime:" << readFileDecodestr;
					continue;
				}
				else if (readFileDecodestr.contains("serialnumber:"))
				{
					//从文件里面读出来的序列码readFileDecodestr解密后直接与serialnumber比较就可以确定序列码是否被修改
					//qDebug() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "serialnumber:" << readFileDecodestr;

					//解密之后与电脑序列码进行比较，如果相同则不作任何提示，如果不同则提示license.lic 文件被更改
					if (serialnumber.compare(readFileDecodestr) == 0)
					{
						continue;
					}
					else
					{
						qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The license file has been modified to render the program unavailable !";
						QMessageBox::critical(this, "错误：", "授权文件已经被修改，授权验证失败！");
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
						QMessageBox::information(this, "警告", "对不起，授权文件已经到期，软件不能继续使用！请联系官方续费！");
						return false;
					}
					if (timeDiff < 30)
					{
						//提示软件还有timeDiff多天到期，请联系官方进行续期
						QMessageBox::information(this, "警告：", "软件还有  " + QString::number(timeDiff) + " 天到期，请联系官方进行续费。");
					}
					break;
				}
				else
				{
					qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The license file has been modified to render the program unavailable !";
					QMessageBox::critical(this, "错误：", "授权文件已经被修改，授权验证失败！");
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

//按注册按钮会进行注册
/******************************************************************************
函数名：saveLicenseFile
参数：QString serialNumber 序列号
返回值：bool
功能：更具输入的序列号，然后判断是否正确，正确生成license文件
步骤：
	1.先执行wmic bios get serialnumber命令获取本机的序列号serialnumberstr，获取的是未加密的序列号SerialNumber\nM705URC8\n
	2.将serialnumberstr用\n分解，然后与serialnumber:字符串拼接成加密文件中的加密的序列号serialnumber
	3.先判断licence文件是否存在，如果存在则判断是否正确，如果不存在，则生成license文件
******************************************************************************/
bool LoginInterface::SaveLicenseFile(QString ParamSerialNumber)
{
	qDebug() << "参数传入的序列码：" << ParamSerialNumber;
	//把加密字符串进行解密，然后与serialnumber进行比较看是不是完全相同
	//获取机器序列码
	QString runPath = QCoreApplication::applicationDirPath();
	QString filepath = runPath + "/license.lic";
	this->process = new QProcess(this);
	process->start("wmic bios get serialnumber");
	process->waitForFinished();
	QByteArray output = process->readAllStandardOutput();
	QString serialnumberstr = output;
	QStringList serialnumberlist = serialnumberstr.split("\n");
	QString serialnumber = "serialnumber:" + serialnumberlist.at(1).trimmed();//获取安装电脑的序列码
	qDebug() << "安装电脑的序列码：" << serialnumber;
	QFile licfile(filepath);
	bool ok = licfile.exists();
	if (ok)
	{
		qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "授权文件已经存在，再次授权！";
	}
	//如果验证文件不存在，说明是首次注册则需要输入序列码进行验证
	//将参数传入的序列码赋值给lineEditstr
	QString lineEditstr = ParamSerialNumber;
	//qDebug() << "参数传入的序列码2：" << lineEditstr;
	//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "lineEditstr:" << lineEditstr;
	QString decode_str1 = decode_str(lineEditstr.toLocal8Bit().data());
	//qDebug() << "解密之后的参数传入的序列码decode_str1:" << decode_str1;
	//将解密之后的序列码分解成几个部分，注册时间，电脑序列码，到期时间
	QString startTimeStr = decode_str1.split("|").at(0);//注册时间
														//qDebug() << "注册时间：" << startTimeStr;
	QString inputSerialNumber = decode_str1.split("|").at(1);//解密字符串中的序列码
															 //qDebug() << "解密字符串中的序列码：" << inputSerialNumber;
	QString endTimeStr = decode_str1.split("|").at(2);//到期时间
													  //qDebug() << "到期时间：" << inputSerialNumber;
	if (serialnumber.compare(inputSerialNumber) == 0)
	{
		//序列号验证成功，将序列号写入到文件
		//QFile *licenseFile = new QFile(filepath);
		QFile *licenseFile = new QFile(filepath);//"D:\\license.lic"
		bool openWriteStatus = licenseFile->open(QIODevice::WriteOnly | QIODevice::Text);//WriteOnly不行，ReadWrite也不行
		if (!openWriteStatus)
		{
			//QMessageBox::information(this, "information:", filepath + licenseFile->errorString());
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "license.lic file creat fail !";
			QMessageBox::information(this, "消息", "授权文件创建失败！");
			return false;
		}
		else
		{
			licenseFile->write(lineEditstr.toStdString().c_str(), lineEditstr.length());
			//licenseFile->write(DueTimeText.toStdString().c_str(), DueTimeText.length());
			licfile.waitForBytesWritten(500);
			licenseFile->close();

			//隐藏注册界面
			//displayUi(true);

			qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Register successfully, thank you for using the genuine software, welcome to use!";
			QMessageBox::information(this, "消息", "注册成功，多谢您使用正版的软件，欢迎使用！");
			return true;
		}
	}

	else
	{
		qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Registration is unsuccessful, please contact the official to obtain the serial number, thank you for supporting the genuine software!";
		QMessageBox::information(this, "警告：", "注册失败，请联系官方获取正确的序列码，多谢支持正版软件！");
		return false;
	}
}
#if 0
bool LoginInterface::SaveLicenseFile(QString serialNumber)
{
	//把加密字符串进行解密，然后与serialnumber进行比较看是不是完全相同
	//获取机器序列码
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
		//可读打开该文件
		ok = licfile.open(QIODevice::ReadOnly | QIODevice::Text);
		if (!ok)
		{
			qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "license.lic file open fail !";
			QMessageBox::information(this, "错误", "授权文件打开失败！");
			return false;
		}
		else
		{
			QByteArray readfileByte;
			QString readfileLine;
			while (!licfile.atEnd())
			{
				//如果没有读到文件尾，一行行的读取
				//readfileLine是文件中加密的字符串
				QByteArray readfileByte = licfile.readLine();
				readfileLine = readfileByte;
				//qDebug() << "readfileLine:" << readfileLine;
				//先对读到的字符串进行解密，readFileDecodestr解密之后的字符串
				QString readFileDecodestr = decode_str(readfileLine.toLocal8Bit().data());
				//qDebug() << "readFileDecodestr:" << readFileDecodestr;
				if (readFileDecodestr.contains("InstallationTime:"))
				{
					continue;
				}
				else if (readFileDecodestr.contains("serialnumber:"))
				{
					//从文件里面读出来的序列码readFileDecodestr解密后直接与serialnumber比较就可以确定序列码是否被修改
					//qDebug() << "serialnumber:" << readFileDecodestr;
					//解密之后与电脑序列码进行比较，如果相同则不作任何提示，如果不同则提示license.lic 文件被更改
					if (serialnumber.compare(readFileDecodestr) == 0)
					{
						continue;
					}
					else
					{
						//qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "The license file has been modified to render the program unavailable !";
						QMessageBox::critical(this, "错误：", "授权文件已经被修改，授权验证失败！");
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
						QMessageBox::information(this, "警告：", "对不起，授权文件已经到期，软件不能继续使用！请联系官方续费！");
						return false;
					}
					if (timeDiff < 30)
					{
						//提示软件还有timeDiff多天到期，请联系官方进行续期
						QMessageBox::information(this, "警告", "软件还有 " + QString::number(timeDiff) + " 天到期，请联系官方进行续费！");
					}
					break;
				}
				else
				{
					qCritical() << "The license file has been modified to render the program unavailable !";
					QMessageBox::critical(this, "错误", "授权文件已经被修改，授权验证失败！");
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
		//如果验证文件不存在，说明是首次注册则需要输入序列码进行验证
		if (serialnumber.compare(decode_str1) == 0)
		{
			//序列号验证成功，将序列号写入到文件
			//QFile *licenseFile = new QFile(filepath);
			QFile *licenseFile = new QFile(filepath);//"D:\\license.lic"
			bool openWriteStatus = licenseFile->open(QIODevice::WriteOnly | QIODevice::Text);//WriteOnly不行，ReadWrite也不行
			if (!openWriteStatus)
			{
				//QMessageBox::information(this, "information:", filepath + licenseFile->errorString());
				qCritical() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "license.lic file creat fail !";
				QMessageBox::information(this, "消息", "授权文件创建失败！");
				return false;
			}
			else
			{
				//将安装日期写入到文件
				QDateTime currentTime = QDateTime::currentDateTime();
				QString currentTimeStr = currentTime.toString("yyyyMMdd");
				//qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "currentTimeStr:" << currentTimeStr;
				QString InstallationTime = "InstallationTime:" + currentTimeStr;
				//将序列码写入到文件
				//QString SerialText = "serialnumber:" + lineEditstr + "\n";
				QString SerialText = lineEditstr + "\n";
				//将到期日期写入到文件
				//到期日期为安装日期往后加一年即可
				int DueTime = currentTimeStr.toInt() + 10000;
				QString DueTimeStr = "DueTime:" + QString::number(DueTime);
				//先分别将安装时间，到期时间加密然后再写入到文件
				QString InstallationTimeText = encrypt_str(InstallationTime.toLocal8Bit().data()) + "\n";
				QString DueTimeText = encrypt_str(DueTimeStr.toLocal8Bit().data()) + "\n";
				licenseFile->write(InstallationTimeText.toStdString().c_str(), InstallationTimeText.length());
				licenseFile->write(SerialText.toStdString().c_str(), SerialText.length());
				licenseFile->write(DueTimeText.toStdString().c_str(), DueTimeText.length());
				licfile.waitForBytesWritten(500);
				licenseFile->close();

				//隐藏注册界面
				//displayUi(true);

				qInfo() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Register successfully, thank you for using the genuine software, welcome to use!";
				QMessageBox::information(this, "消息", "注册成功，多谢您使用正版的软件，欢迎使用！");
				return true;
			}
		}
		else
		{
			qWarning() << "filename:" << __FILE__ << " line:" << __LINE__ << " functionName:" << __FUNCTION__ << " LOG:" << "Registration is unsuccessful, please contact the official to obtain the serial number, thank you for supporting the genuine software!";
			QMessageBox::information(this, "警告：", "注册失败，请联系官方获取正确的序列码，多谢支持正版软件！");
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
	if (!lockFile.exists())//如果文件不存在,说明文件没有被锁
	{
		return false;
	}
	EncryptedFileDialog *encryptedFileDialog = new EncryptedFileDialog(this);
	bool decryptionStatus= encryptedFileDialog->DecryptionFile(qstrFilePathFileName, "temporaryFile");
	if (decryptionStatus)
	{
		//加密文件解密成功
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


//先创建一个名为LockUserInfo的隐藏文件夹，然后将信息保存在对应的文件里面
void LoginInterface::CreateLockFile()
{
	// 获取当前的路径
	QString qstrpath = QDir::currentPath();
	QString qstrFilePathHide = qstrpath + QString("/LockUserInfo");
	// 这个文件夹需要隐藏
	QDir dir_path_hide(qstrFilePathHide);
	if (!dir_path_hide.exists())
	{
		dir_path_hide.mkdir(qstrFilePathHide);
		//如果文件夹创建成功，将内容写入到文件
		SaveLockInfo();
	}
	// windows API需要将 QString 转化为 LPCWSTR
	// 将文件夹设置为隐藏
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
	//需要加密的字符
	QString plaintext = ui.UsernameLineEdit->text().trimmed() + "|" + ui.PasswordLineEdit->text().trimmed() + "|1|" + timeStr;
	//QMessageBox::information(this,"内容:", plaintext);
	file.write(plaintext.toStdString().c_str());

	file.close();
	//将文件进行加密
	bool encryptedStatus = encryptedFileDialog->EncryptionFile("temporaryFile", qstrFilePathFileName);
	if (encryptedStatus)
	{
		remove("temporaryFile");
	}

	//encryptedFileDialog->DecryptionFile(qstrFilePathFileName,"testcfg2.txt");
	//将文件进行解密
	//将加密字符用解密方法解密然后显示
	SetFileAttributes((LPCWSTR)qstrFilePathFileName.unicode(), FILE_ATTRIBUTE_HIDDEN);
}