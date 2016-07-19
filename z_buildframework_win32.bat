set DIR=%~dp0
%DIR%/bin/compile_scripts.bat -jit 0 -i %DIR%framework -o %DIR%lib/framework_precompiled/framework_precompiled.zip
pause