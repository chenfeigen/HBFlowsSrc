@echo off
e:
cd Program Files/MATLAB/R2017b/bin/
matlab -nojvm -nodesktop -nodisplay -r %1('%2')
pause