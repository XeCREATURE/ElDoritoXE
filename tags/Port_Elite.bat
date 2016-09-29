@echo off
title Get Elite Assets
echo.
echo.
Type 01_PortBiped.cmds | TagTool.exe HO_MS30\tags.dat
Type 02_PortArmor.cmds | TagTool.exe HO_MS25\tags.dat
Type 03_FixupTags.cmds | TagTool.exe maps\tags.dat
echo.
echo.
