SET PATH=C:\Keil_v5\ARM\ARMCC\bin\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\ATI Technologies\ATI.ACE\Core-Static;C:\Program Files\Altium Designer Winter 09\System
SET CPU_TYPE=STM32F103VE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Flash
SET CPU_CLOCK=0x044AA200
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\main.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_it.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\segger_rtt_printf.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\segger_rtt.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\bsp.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\bsp_input.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\bsp_output.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\bsp_sst25vf016b.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\bsp_sst25vf016b_demo.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\bsp_usart.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\core_cm3.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\system_stm32f10x.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmAsm" --Via ".\obj\startup_stm32f10x_hd._ia"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\misc.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_rcc.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_spi.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via ".\obj\stm32f10x_usart.__i"
"C:\Keil_v5\ARM\ARMCC\bin\ArmLink" --Via ".\Obj\output.lnp"
"C:\Keil_v5\ARM\ARMCC\bin\fromelf.exe" ".\Obj\output.axf" --i32combined --output ".\Obj\output.hex"
