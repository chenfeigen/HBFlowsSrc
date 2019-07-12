@echo off
set input="F:\bat file\data.bat"
cls   
echo   %1 %2 %3 %4 %5 %6 %7 %8 %9 
e:
cd Program Files/MATLAB/R2017b/bin/
matlab -nojvm -nodesktop -nodisplay -r caculateboundarypar('C:\Users\Administrator\Desktop\CT无创血流储备分数\陈老师\sdz00011000117520114100')