@echo off
setlocal enabledelayedexpansion

set EXT_LIST=.c .cpp .cc .cxx .h .hpp .hh .hxx

echo Running clang-format (excluding build folder)...

for /r %%f in (*) do (
    set "file=%%f"

    echo !file! | findstr /i "\\build\\" >nul
    if errorlevel 1 (

        set "ext=%%~xf"
        set "match="

        for %%e in (%EXT_LIST%) do (
            if /i "!ext!"=="%%e" set "match=1"
        )

        if defined match (
            echo Formatting !file!
            clang-format -i "!file!"
        )
    )
)

echo Done.
endlocal
