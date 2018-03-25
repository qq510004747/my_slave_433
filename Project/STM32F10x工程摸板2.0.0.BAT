SET PATH=F:\keil5-22\ARM\ARMCC\Bin;F:\stm8\asm;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\PTC\Creo Elements\Pro5.0\bin;C:\Users\Administrator\Desktop\新重刷固件文件\sam-ba_2.12\drv\;C:\Users\Administrator\Desktop\新重刷固件文件\sam-ba_2.12;E:\altera\13.1\modelsim_ase\win32aloem;E:\altera\13.1\modelsim_ae\win32aloem
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F103ZG
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=STM32F10x工程摸板2.0.0
SET CPU_CLOCK=0x00B71B00
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\main.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\stm32f10x_it.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\segger_rtt_printf.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\segger_rtt.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\apptask.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\bsp.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\bsp_input.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\bsp_output.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\bsp_usart.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\bsp_sst25vf016b.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\bsp_sst25vf016b_demo.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\core_cm3.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\system_stm32f10x.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmAsm" --Via ".\obj\startup_stm32f10x_hd_freertos._ia"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\croutine.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\event_groups.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\list.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\queue.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\tasks.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\timers.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\heap_2.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\port.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\misc.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\stm32f10x_gpio.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\stm32f10x_rcc.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\stm32f10x_spi.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmCC" --Via ".\obj\stm32f10x_usart.__i"
"F:\keil5-22\ARM\ARMCC\Bin\ArmLink" --Via ".\Obj\output.lnp"
"F:\keil5-22\ARM\ARMCC\Bin\fromelf.exe" ".\Obj\output.axf" --i32combined --output ".\Obj\output.hex"
