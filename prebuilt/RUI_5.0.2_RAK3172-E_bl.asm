
/home/jenkins/workspace/RUI_Release/rui-v3/image/RUI_5.0.2_RAK3172-E_bl:     file format elf32-littlearm


Disassembly of section .text:

08000138 <__do_global_dtors_aux>:
 8000138:	b510      	push	{r4, lr}
 800013a:	4c05      	ldr	r4, [pc, #20]	; (8000150 <__do_global_dtors_aux+0x18>)
 800013c:	7823      	ldrb	r3, [r4, #0]
 800013e:	b933      	cbnz	r3, 800014e <__do_global_dtors_aux+0x16>
 8000140:	4b04      	ldr	r3, [pc, #16]	; (8000154 <__do_global_dtors_aux+0x1c>)
 8000142:	b113      	cbz	r3, 800014a <__do_global_dtors_aux+0x12>
 8000144:	4804      	ldr	r0, [pc, #16]	; (8000158 <__do_global_dtors_aux+0x20>)
 8000146:	f3af 8000 	nop.w
 800014a:	2301      	movs	r3, #1
 800014c:	7023      	strb	r3, [r4, #0]
 800014e:	bd10      	pop	{r4, pc}
 8000150:	20006068 	.word	0x20006068
 8000154:	00000000 	.word	0x00000000
 8000158:	080028f0 	.word	0x080028f0

0800015c <frame_dummy>:
 800015c:	b508      	push	{r3, lr}
 800015e:	4b03      	ldr	r3, [pc, #12]	; (800016c <frame_dummy+0x10>)
 8000160:	b11b      	cbz	r3, 800016a <frame_dummy+0xe>
 8000162:	4903      	ldr	r1, [pc, #12]	; (8000170 <frame_dummy+0x14>)
 8000164:	4803      	ldr	r0, [pc, #12]	; (8000174 <frame_dummy+0x18>)
 8000166:	f3af 8000 	nop.w
 800016a:	bd08      	pop	{r3, pc}
 800016c:	00000000 	.word	0x00000000
 8000170:	2000606c 	.word	0x2000606c
 8000174:	080028f0 	.word	0x080028f0

08000178 <__libc_init_array>:
 8000178:	b570      	push	{r4, r5, r6, lr}
 800017a:	4d0d      	ldr	r5, [pc, #52]	; (80001b0 <__libc_init_array+0x38>)
 800017c:	4c0d      	ldr	r4, [pc, #52]	; (80001b4 <__libc_init_array+0x3c>)
 800017e:	1b64      	subs	r4, r4, r5
 8000180:	10a4      	asrs	r4, r4, #2
 8000182:	2600      	movs	r6, #0
 8000184:	42a6      	cmp	r6, r4
 8000186:	d109      	bne.n	800019c <__libc_init_array+0x24>
 8000188:	4d0b      	ldr	r5, [pc, #44]	; (80001b8 <__libc_init_array+0x40>)
 800018a:	4c0c      	ldr	r4, [pc, #48]	; (80001bc <__libc_init_array+0x44>)
 800018c:	f002 fbb0 	bl	80028f0 <_init>
 8000190:	1b64      	subs	r4, r4, r5
 8000192:	10a4      	asrs	r4, r4, #2
 8000194:	2600      	movs	r6, #0
 8000196:	42a6      	cmp	r6, r4
 8000198:	d105      	bne.n	80001a6 <__libc_init_array+0x2e>
 800019a:	bd70      	pop	{r4, r5, r6, pc}
 800019c:	f855 3b04 	ldr.w	r3, [r5], #4
 80001a0:	4798      	blx	r3
 80001a2:	3601      	adds	r6, #1
 80001a4:	e7ee      	b.n	8000184 <__libc_init_array+0xc>
 80001a6:	f855 3b04 	ldr.w	r3, [r5], #4
 80001aa:	4798      	blx	r3
 80001ac:	3601      	adds	r6, #1
 80001ae:	e7f2      	b.n	8000196 <__libc_init_array+0x1e>
 80001b0:	08002cd0 	.word	0x08002cd0
 80001b4:	08002cd0 	.word	0x08002cd0
 80001b8:	08002cd0 	.word	0x08002cd0
 80001bc:	08002cd4 	.word	0x08002cd4

080001c0 <memset>:
 80001c0:	4402      	add	r2, r0
 80001c2:	4603      	mov	r3, r0
 80001c4:	4293      	cmp	r3, r2
 80001c6:	d100      	bne.n	80001ca <memset+0xa>
 80001c8:	4770      	bx	lr
 80001ca:	f803 1b01 	strb.w	r1, [r3], #1
 80001ce:	e7f9      	b.n	80001c4 <memset+0x4>

080001d0 <at_process>:
 80001d0:	b530      	push	{r4, r5, lr}
 80001d2:	b093      	sub	sp, #76	; 0x4c
 80001d4:	2100      	movs	r1, #0
 80001d6:	9102      	str	r1, [sp, #8]
 80001d8:	223c      	movs	r2, #60	; 0x3c
 80001da:	a803      	add	r0, sp, #12
 80001dc:	f7ff fff0 	bl	80001c0 <memset>
 80001e0:	2201      	movs	r2, #1
 80001e2:	4963      	ldr	r1, [pc, #396]	; (8000370 <at_process+0x1a0>)
 80001e4:	4863      	ldr	r0, [pc, #396]	; (8000374 <at_process+0x1a4>)
 80001e6:	f002 fa87 	bl	80026f8 <HAL_UART_Receive_IT>
 80001ea:	2800      	cmp	r0, #0
 80001ec:	d063      	beq.n	80002b6 <at_process+0xe6>
 80001ee:	4862      	ldr	r0, [pc, #392]	; (8000378 <at_process+0x1a8>)
 80001f0:	f000 fa62 	bl	80006b8 <Serial_PutString>
 80001f4:	e05f      	b.n	80002b6 <at_process+0xe6>
 80001f6:	2400      	movs	r4, #0
 80001f8:	e018      	b.n	800022c <at_process+0x5c>
 80001fa:	2501      	movs	r5, #1
 80001fc:	4b5f      	ldr	r3, [pc, #380]	; (800037c <at_process+0x1ac>)
 80001fe:	2200      	movs	r2, #0
 8000200:	701a      	strb	r2, [r3, #0]
 8000202:	4b5f      	ldr	r3, [pc, #380]	; (8000380 <at_process+0x1b0>)
 8000204:	781b      	ldrb	r3, [r3, #0]
 8000206:	2b01      	cmp	r3, #1
 8000208:	d030      	beq.n	800026c <at_process+0x9c>
 800020a:	2d00      	cmp	r5, #0
 800020c:	d133      	bne.n	8000276 <at_process+0xa6>
 800020e:	4b5b      	ldr	r3, [pc, #364]	; (800037c <at_process+0x1ac>)
 8000210:	781b      	ldrb	r3, [r3, #0]
 8000212:	2b00      	cmp	r3, #0
 8000214:	d0f5      	beq.n	8000202 <at_process+0x32>
 8000216:	1c63      	adds	r3, r4, #1
 8000218:	b29b      	uxth	r3, r3
 800021a:	aa12      	add	r2, sp, #72	; 0x48
 800021c:	4414      	add	r4, r2
 800021e:	4a54      	ldr	r2, [pc, #336]	; (8000370 <at_process+0x1a0>)
 8000220:	7812      	ldrb	r2, [r2, #0]
 8000222:	f804 2c40 	strb.w	r2, [r4, #-64]
 8000226:	2b3f      	cmp	r3, #63	; 0x3f
 8000228:	d8e5      	bhi.n	80001f6 <at_process+0x26>
 800022a:	461c      	mov	r4, r3
 800022c:	1e63      	subs	r3, r4, #1
 800022e:	aa12      	add	r2, sp, #72	; 0x48
 8000230:	4413      	add	r3, r2
 8000232:	f813 3c40 	ldrb.w	r3, [r3, #-64]
 8000236:	2b0d      	cmp	r3, #13
 8000238:	d001      	beq.n	800023e <at_process+0x6e>
 800023a:	2b0a      	cmp	r3, #10
 800023c:	d1de      	bne.n	80001fc <at_process+0x2c>
 800023e:	4a51      	ldr	r2, [pc, #324]	; (8000384 <at_process+0x1b4>)
 8000240:	466b      	mov	r3, sp
 8000242:	e892 0003 	ldmia.w	r2, {r0, r1}
 8000246:	e883 0003 	stmia.w	r3, {r0, r1}
 800024a:	2203      	movs	r2, #3
 800024c:	494e      	ldr	r1, [pc, #312]	; (8000388 <at_process+0x1b8>)
 800024e:	a802      	add	r0, sp, #8
 8000250:	f03b f94a 	bl	803b4e8 <memcmp>
 8000254:	2800      	cmp	r0, #0
 8000256:	d0d0      	beq.n	80001fa <at_process+0x2a>
 8000258:	2203      	movs	r2, #3
 800025a:	494c      	ldr	r1, [pc, #304]	; (800038c <at_process+0x1bc>)
 800025c:	a802      	add	r0, sp, #8
 800025e:	f03b f943 	bl	803b4e8 <memcmp>
 8000262:	b908      	cbnz	r0, 8000268 <at_process+0x98>
 8000264:	2501      	movs	r5, #1
 8000266:	e7c9      	b.n	80001fc <at_process+0x2c>
 8000268:	2400      	movs	r4, #0
 800026a:	e7c7      	b.n	80001fc <at_process+0x2c>
 800026c:	f02f fd86 	bl	802fd7c <LoRaMacProcess>
 8000270:	f01f ffa4 	bl	80201bc <LmHandlerPackagesProcess>
 8000274:	e7c9      	b.n	800020a <at_process+0x3a>
 8000276:	3c01      	subs	r4, #1
 8000278:	ab12      	add	r3, sp, #72	; 0x48
 800027a:	441c      	add	r4, r3
 800027c:	2300      	movs	r3, #0
 800027e:	f804 3c40 	strb.w	r3, [r4, #-64]
 8000282:	4943      	ldr	r1, [pc, #268]	; (8000390 <at_process+0x1c0>)
 8000284:	a802      	add	r0, sp, #8
 8000286:	f002 fb19 	bl	80028bc <strcasecmp>
 800028a:	b148      	cbz	r0, 80002a0 <at_process+0xd0>
 800028c:	4941      	ldr	r1, [pc, #260]	; (8000394 <at_process+0x1c4>)
 800028e:	a802      	add	r0, sp, #8
 8000290:	f002 fb14 	bl	80028bc <strcasecmp>
 8000294:	b120      	cbz	r0, 80002a0 <at_process+0xd0>
 8000296:	4940      	ldr	r1, [pc, #256]	; (8000398 <at_process+0x1c8>)
 8000298:	a802      	add	r0, sp, #8
 800029a:	f002 fb0f 	bl	80028bc <strcasecmp>
 800029e:	b968      	cbnz	r0, 80002bc <at_process+0xec>
 80002a0:	483e      	ldr	r0, [pc, #248]	; (800039c <at_process+0x1cc>)
 80002a2:	f000 fa09 	bl	80006b8 <Serial_PutString>
 80002a6:	483e      	ldr	r0, [pc, #248]	; (80003a0 <at_process+0x1d0>)
 80002a8:	f000 fa06 	bl	80006b8 <Serial_PutString>
 80002ac:	2240      	movs	r2, #64	; 0x40
 80002ae:	2100      	movs	r1, #0
 80002b0:	a802      	add	r0, sp, #8
 80002b2:	f7ff ff85 	bl	80001c0 <memset>
 80002b6:	2500      	movs	r5, #0
 80002b8:	462c      	mov	r4, r5
 80002ba:	e7a8      	b.n	800020e <at_process+0x3e>
 80002bc:	4939      	ldr	r1, [pc, #228]	; (80003a4 <at_process+0x1d4>)
 80002be:	a802      	add	r0, sp, #8
 80002c0:	f002 fafc 	bl	80028bc <strcasecmp>
 80002c4:	b1e8      	cbz	r0, 8000302 <at_process+0x132>
 80002c6:	4938      	ldr	r1, [pc, #224]	; (80003a8 <at_process+0x1d8>)
 80002c8:	a802      	add	r0, sp, #8
 80002ca:	f002 faf7 	bl	80028bc <strcasecmp>
 80002ce:	b328      	cbz	r0, 800031c <at_process+0x14c>
 80002d0:	4936      	ldr	r1, [pc, #216]	; (80003ac <at_process+0x1dc>)
 80002d2:	a802      	add	r0, sp, #8
 80002d4:	f002 faf2 	bl	80028bc <strcasecmp>
 80002d8:	b348      	cbz	r0, 800032e <at_process+0x15e>
 80002da:	4935      	ldr	r1, [pc, #212]	; (80003b0 <at_process+0x1e0>)
 80002dc:	a802      	add	r0, sp, #8
 80002de:	f002 faed 	bl	80028bc <strcasecmp>
 80002e2:	2800      	cmp	r0, #0
 80002e4:	d030      	beq.n	8000348 <at_process+0x178>
 80002e6:	4933      	ldr	r1, [pc, #204]	; (80003b4 <at_process+0x1e4>)
 80002e8:	a802      	add	r0, sp, #8
 80002ea:	f002 fae7 	bl	80028bc <strcasecmp>
 80002ee:	b378      	cbz	r0, 8000350 <at_process+0x180>
 80002f0:	4931      	ldr	r1, [pc, #196]	; (80003b8 <at_process+0x1e8>)
 80002f2:	a802      	add	r0, sp, #8
 80002f4:	f002 fae2 	bl	80028bc <strcasecmp>
 80002f8:	2800      	cmp	r0, #0
 80002fa:	d134      	bne.n	8000366 <at_process+0x196>
 80002fc:	f01f fb16 	bl	801f92c <service_lora_fuota_join>
 8000300:	e7d4      	b.n	80002ac <at_process+0xdc>
 8000302:	4b2e      	ldr	r3, [pc, #184]	; (80003bc <at_process+0x1ec>)
 8000304:	2201      	movs	r2, #1
 8000306:	701a      	strb	r2, [r3, #0]
 8000308:	f04f 3101 	mov.w	r1, #16843009	; 0x1010101
 800030c:	482c      	ldr	r0, [pc, #176]	; (80003c0 <at_process+0x1f0>)
 800030e:	f000 fa8b 	bl	8000828 <HAL_FLASH_Program_Flag>
 8000312:	4818      	ldr	r0, [pc, #96]	; (8000374 <at_process+0x1a4>)
 8000314:	f001 f946 	bl	80015a4 <HAL_UART_AbortReceive_IT>
 8000318:	b013      	add	sp, #76	; 0x4c
 800031a:	bd30      	pop	{r4, r5, pc}
 800031c:	4829      	ldr	r0, [pc, #164]	; (80003c4 <at_process+0x1f4>)
 800031e:	f000 f9cb 	bl	80006b8 <Serial_PutString>
 8000322:	f000 fadd 	bl	80008e0 <app_jump>
 8000326:	4828      	ldr	r0, [pc, #160]	; (80003c8 <at_process+0x1f8>)
 8000328:	f000 f9c6 	bl	80006b8 <Serial_PutString>
 800032c:	e7be      	b.n	80002ac <at_process+0xdc>
 800032e:	f3bf 8f4f 	dsb	sy
 8000332:	4926      	ldr	r1, [pc, #152]	; (80003cc <at_process+0x1fc>)
 8000334:	68ca      	ldr	r2, [r1, #12]
 8000336:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 800033a:	4b25      	ldr	r3, [pc, #148]	; (80003d0 <at_process+0x200>)
 800033c:	4313      	orrs	r3, r2
 800033e:	60cb      	str	r3, [r1, #12]
 8000340:	f3bf 8f4f 	dsb	sy
 8000344:	bf00      	nop
 8000346:	e7fd      	b.n	8000344 <at_process+0x174>
 8000348:	4822      	ldr	r0, [pc, #136]	; (80003d4 <at_process+0x204>)
 800034a:	f000 f9b5 	bl	80006b8 <Serial_PutString>
 800034e:	e7ad      	b.n	80002ac <at_process+0xdc>
 8000350:	4821      	ldr	r0, [pc, #132]	; (80003d8 <at_process+0x208>)
 8000352:	f000 f9b1 	bl	80006b8 <Serial_PutString>
 8000356:	f000 ffd7 	bl	8001308 <bootloader_fuota_start>
 800035a:	2301      	movs	r3, #1
 800035c:	4a08      	ldr	r2, [pc, #32]	; (8000380 <at_process+0x1b0>)
 800035e:	7013      	strb	r3, [r2, #0]
 8000360:	4a1e      	ldr	r2, [pc, #120]	; (80003dc <at_process+0x20c>)
 8000362:	7013      	strb	r3, [r2, #0]
 8000364:	e7a2      	b.n	80002ac <at_process+0xdc>
 8000366:	481e      	ldr	r0, [pc, #120]	; (80003e0 <at_process+0x210>)
 8000368:	f000 f9a6 	bl	80006b8 <Serial_PutString>
 800036c:	e79e      	b.n	80002ac <at_process+0xdc>
 800036e:	bf00      	nop
 8000370:	20006086 	.word	0x20006086
 8000374:	200060d4 	.word	0x200060d4
 8000378:	08002920 	.word	0x08002920
 800037c:	20006088 	.word	0x20006088
 8000380:	20006084 	.word	0x20006084
 8000384:	08002908 	.word	0x08002908
 8000388:	08002918 	.word	0x08002918
 800038c:	0800291c 	.word	0x0800291c
 8000390:	0800293c 	.word	0x0800293c
 8000394:	08002948 	.word	0x08002948
 8000398:	08002954 	.word	0x08002954
 800039c:	08005000 	.word	0x08005000
 80003a0:	08002b10 	.word	0x08002b10
 80003a4:	08002964 	.word	0x08002964
 80003a8:	08002970 	.word	0x08002970
 80003ac:	080029bc 	.word	0x080029bc
 80003b0:	080029c8 	.word	0x080029c8
 80003b4:	080029e4 	.word	0x080029e4
 80003b8:	08002a00 	.word	0x08002a00
 80003bc:	20006087 	.word	0x20006087
 80003c0:	08004004 	.word	0x08004004
 80003c4:	08002978 	.word	0x08002978
 80003c8:	0800298c 	.word	0x0800298c
 80003cc:	e000ed00 	.word	0xe000ed00
 80003d0:	05fa0004 	.word	0x05fa0004
 80003d4:	080029d8 	.word	0x080029d8
 80003d8:	080029f0 	.word	0x080029f0
 80003dc:	20006085 	.word	0x20006085
 80003e0:	08002a08 	.word	0x08002a08

080003e4 <IAP_Task>:
 80003e4:	b508      	push	{r3, lr}
 80003e6:	4b06      	ldr	r3, [pc, #24]	; (8000400 <IAP_Task+0x1c>)
 80003e8:	781b      	ldrb	r3, [r3, #0]
 80003ea:	b113      	cbz	r3, 80003f2 <IAP_Task+0xe>
 80003ec:	2b01      	cmp	r3, #1
 80003ee:	d003      	beq.n	80003f8 <IAP_Task+0x14>
 80003f0:	bd08      	pop	{r3, pc}
 80003f2:	f7ff feed 	bl	80001d0 <at_process>
 80003f6:	e7fb      	b.n	80003f0 <IAP_Task+0xc>
 80003f8:	f000 fa48 	bl	800088c <SerialDownload>
 80003fc:	e7f8      	b.n	80003f0 <IAP_Task+0xc>
 80003fe:	bf00      	nop
 8000400:	20006087 	.word	0x20006087

08000404 <SystemClock_Config>:
 8000404:	b510      	push	{r4, lr}
 8000406:	b09a      	sub	sp, #104	; 0x68
 8000408:	2248      	movs	r2, #72	; 0x48
 800040a:	2100      	movs	r1, #0
 800040c:	a808      	add	r0, sp, #32
 800040e:	f7ff fed7 	bl	80001c0 <memset>
 8000412:	2400      	movs	r4, #0
 8000414:	9402      	str	r4, [sp, #8]
 8000416:	9403      	str	r4, [sp, #12]
 8000418:	9404      	str	r4, [sp, #16]
 800041a:	9405      	str	r4, [sp, #20]
 800041c:	9406      	str	r4, [sp, #24]
 800041e:	9407      	str	r4, [sp, #28]
 8000420:	f028 f810 	bl	8028444 <HAL_PWR_EnableBkUpAccess>
 8000424:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8000428:	f8d2 3090 	ldr.w	r3, [r2, #144]	; 0x90
 800042c:	f023 0318 	bic.w	r3, r3, #24
 8000430:	f8c2 3090 	str.w	r3, [r2, #144]	; 0x90
 8000434:	f502 6280 	add.w	r2, r2, #1024	; 0x400
 8000438:	6813      	ldr	r3, [r2, #0]
 800043a:	f423 63c0 	bic.w	r3, r3, #1536	; 0x600
 800043e:	f443 7300 	orr.w	r3, r3, #512	; 0x200
 8000442:	6013      	str	r3, [r2, #0]
 8000444:	6813      	ldr	r3, [r2, #0]
 8000446:	f403 63c0 	and.w	r3, r3, #1536	; 0x600
 800044a:	9301      	str	r3, [sp, #4]
 800044c:	9b01      	ldr	r3, [sp, #4]
 800044e:	232e      	movs	r3, #46	; 0x2e
 8000450:	9308      	str	r3, [sp, #32]
 8000452:	2381      	movs	r3, #129	; 0x81
 8000454:	930b      	str	r3, [sp, #44]	; 0x2c
 8000456:	2301      	movs	r3, #1
 8000458:	9310      	str	r3, [sp, #64]	; 0x40
 800045a:	f44f 7280 	mov.w	r2, #256	; 0x100
 800045e:	920c      	str	r2, [sp, #48]	; 0x30
 8000460:	9411      	str	r4, [sp, #68]	; 0x44
 8000462:	2240      	movs	r2, #64	; 0x40
 8000464:	920d      	str	r2, [sp, #52]	; 0x34
 8000466:	22b0      	movs	r2, #176	; 0xb0
 8000468:	9212      	str	r2, [sp, #72]	; 0x48
 800046a:	9413      	str	r4, [sp, #76]	; 0x4c
 800046c:	940f      	str	r4, [sp, #60]	; 0x3c
 800046e:	930e      	str	r3, [sp, #56]	; 0x38
 8000470:	a808      	add	r0, sp, #32
 8000472:	f025 fc99 	bl	8025da8 <HAL_RCC_OscConfig>
 8000476:	b970      	cbnz	r0, 8000496 <SystemClock_Config+0x92>
 8000478:	234f      	movs	r3, #79	; 0x4f
 800047a:	9302      	str	r3, [sp, #8]
 800047c:	2300      	movs	r3, #0
 800047e:	9303      	str	r3, [sp, #12]
 8000480:	9304      	str	r3, [sp, #16]
 8000482:	9305      	str	r3, [sp, #20]
 8000484:	9306      	str	r3, [sp, #24]
 8000486:	9307      	str	r3, [sp, #28]
 8000488:	2102      	movs	r1, #2
 800048a:	a802      	add	r0, sp, #8
 800048c:	f025 ff2e 	bl	80262ec <HAL_RCC_ClockConfig>
 8000490:	b918      	cbnz	r0, 800049a <SystemClock_Config+0x96>
 8000492:	b01a      	add	sp, #104	; 0x68
 8000494:	bd10      	pop	{r4, pc}
 8000496:	f021 f8eb 	bl	8021670 <Error_Handler>
 800049a:	f021 f8e9 	bl	8021670 <Error_Handler>
	...

080004a0 <main>:
 80004a0:	b508      	push	{r3, lr}
 80004a2:	4b3e      	ldr	r3, [pc, #248]	; (800059c <main+0xfc>)
 80004a4:	685b      	ldr	r3, [r3, #4]
 80004a6:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 80004aa:	d004      	beq.n	80004b6 <main+0x16>
 80004ac:	4b3b      	ldr	r3, [pc, #236]	; (800059c <main+0xfc>)
 80004ae:	685b      	ldr	r3, [r3, #4]
 80004b0:	f1b3 3f05 	cmp.w	r3, #84215045	; 0x5050505
 80004b4:	d134      	bne.n	8000520 <main+0x80>
 80004b6:	4b39      	ldr	r3, [pc, #228]	; (800059c <main+0xfc>)
 80004b8:	685b      	ldr	r3, [r3, #4]
 80004ba:	f1b3 3f05 	cmp.w	r3, #84215045	; 0x5050505
 80004be:	d036      	beq.n	800052e <main+0x8e>
 80004c0:	4b37      	ldr	r3, [pc, #220]	; (80005a0 <main+0x100>)
 80004c2:	f04f 6200 	mov.w	r2, #134217728	; 0x8000000
 80004c6:	609a      	str	r2, [r3, #8]
 80004c8:	4b36      	ldr	r3, [pc, #216]	; (80005a4 <main+0x104>)
 80004ca:	2201      	movs	r2, #1
 80004cc:	701a      	strb	r2, [r3, #0]
 80004ce:	4b36      	ldr	r3, [pc, #216]	; (80005a8 <main+0x108>)
 80004d0:	2200      	movs	r2, #0
 80004d2:	701a      	strb	r2, [r3, #0]
 80004d4:	f000 fa98 	bl	8000a08 <MX_USART2_UART_Init>
 80004d8:	4b30      	ldr	r3, [pc, #192]	; (800059c <main+0xfc>)
 80004da:	681b      	ldr	r3, [r3, #0]
 80004dc:	f1b3 3f5a 	cmp.w	r3, #1515870810	; 0x5a5a5a5a
 80004e0:	d02c      	beq.n	800053c <main+0x9c>
 80004e2:	4b2e      	ldr	r3, [pc, #184]	; (800059c <main+0xfc>)
 80004e4:	681b      	ldr	r3, [r3, #0]
 80004e6:	f1b3 3f5a 	cmp.w	r3, #1515870810	; 0x5a5a5a5a
 80004ea:	d009      	beq.n	8000500 <main+0x60>
 80004ec:	4b2b      	ldr	r3, [pc, #172]	; (800059c <main+0xfc>)
 80004ee:	685b      	ldr	r3, [r3, #4]
 80004f0:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 80004f4:	d004      	beq.n	8000500 <main+0x60>
 80004f6:	4b29      	ldr	r3, [pc, #164]	; (800059c <main+0xfc>)
 80004f8:	685b      	ldr	r3, [r3, #4]
 80004fa:	f1b3 3f05 	cmp.w	r3, #84215045	; 0x5050505
 80004fe:	d12e      	bne.n	800055e <main+0xbe>
 8000500:	482a      	ldr	r0, [pc, #168]	; (80005ac <main+0x10c>)
 8000502:	f000 f8d9 	bl	80006b8 <Serial_PutString>
 8000506:	4b25      	ldr	r3, [pc, #148]	; (800059c <main+0xfc>)
 8000508:	685b      	ldr	r3, [r3, #4]
 800050a:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 800050e:	d02c      	beq.n	800056a <main+0xca>
 8000510:	4b22      	ldr	r3, [pc, #136]	; (800059c <main+0xfc>)
 8000512:	685b      	ldr	r3, [r3, #4]
 8000514:	f1b3 3f05 	cmp.w	r3, #84215045	; 0x5050505
 8000518:	d027      	beq.n	800056a <main+0xca>
 800051a:	f7ff ff63 	bl	80003e4 <IAP_Task>
 800051e:	e7fc      	b.n	800051a <main+0x7a>
 8000520:	f000 fde6 	bl	80010f0 <bootloader_fuota_stack_init>
 8000524:	f025 f974 	bl	8025810 <HAL_Init>
 8000528:	f7ff ff6c 	bl	8000404 <SystemClock_Config>
 800052c:	e7d2      	b.n	80004d4 <main+0x34>
 800052e:	f000 fddf 	bl	80010f0 <bootloader_fuota_stack_init>
 8000532:	f025 f96d 	bl	8025810 <HAL_Init>
 8000536:	f7ff ff65 	bl	8000404 <SystemClock_Config>
 800053a:	e7c1      	b.n	80004c0 <main+0x20>
 800053c:	4b1c      	ldr	r3, [pc, #112]	; (80005b0 <main+0x110>)
 800053e:	681a      	ldr	r2, [r3, #0]
 8000540:	4b1c      	ldr	r3, [pc, #112]	; (80005b4 <main+0x114>)
 8000542:	4013      	ands	r3, r2
 8000544:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 8000548:	d1cb      	bne.n	80004e2 <main+0x42>
 800054a:	4b14      	ldr	r3, [pc, #80]	; (800059c <main+0xfc>)
 800054c:	685b      	ldr	r3, [r3, #4]
 800054e:	f1b3 3f01 	cmp.w	r3, #16843009	; 0x1010101
 8000552:	d0c6      	beq.n	80004e2 <main+0x42>
 8000554:	f000 f94c 	bl	80007f0 <PreJump>
 8000558:	f000 f954 	bl	8000804 <JumpApp>
 800055c:	e7c1      	b.n	80004e2 <main+0x42>
 800055e:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 8000562:	480e      	ldr	r0, [pc, #56]	; (800059c <main+0xfc>)
 8000564:	f000 f960 	bl	8000828 <HAL_FLASH_Program_Flag>
 8000568:	e7ca      	b.n	8000500 <main+0x60>
 800056a:	f000 fe2f 	bl	80011cc <bootloader_fuota_init>
 800056e:	4b0b      	ldr	r3, [pc, #44]	; (800059c <main+0xfc>)
 8000570:	685b      	ldr	r3, [r3, #4]
 8000572:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 8000576:	d00b      	beq.n	8000590 <main+0xf0>
 8000578:	480f      	ldr	r0, [pc, #60]	; (80005b8 <main+0x118>)
 800057a:	f000 f89d 	bl	80006b8 <Serial_PutString>
 800057e:	f000 fec3 	bl	8001308 <bootloader_fuota_start>
 8000582:	4b0e      	ldr	r3, [pc, #56]	; (80005bc <main+0x11c>)
 8000584:	2201      	movs	r2, #1
 8000586:	701a      	strb	r2, [r3, #0]
 8000588:	4b0d      	ldr	r3, [pc, #52]	; (80005c0 <main+0x120>)
 800058a:	2200      	movs	r2, #0
 800058c:	701a      	strb	r2, [r3, #0]
 800058e:	e7c4      	b.n	800051a <main+0x7a>
 8000590:	f04f 3105 	mov.w	r1, #84215045	; 0x5050505
 8000594:	480b      	ldr	r0, [pc, #44]	; (80005c4 <main+0x124>)
 8000596:	f000 f947 	bl	8000828 <HAL_FLASH_Program_Flag>
 800059a:	e7be      	b.n	800051a <main+0x7a>
 800059c:	08004000 	.word	0x08004000
 80005a0:	e000ed00 	.word	0xe000ed00
 80005a4:	20006084 	.word	0x20006084
 80005a8:	20006087 	.word	0x20006087
 80005ac:	08002a1c 	.word	0x08002a1c
 80005b0:	08006000 	.word	0x08006000
 80005b4:	2ffe0000 	.word	0x2ffe0000
 80005b8:	08002a2c 	.word	0x08002a2c
 80005bc:	20006085 	.word	0x20006085
 80005c0:	2000665f 	.word	0x2000665f
 80005c4:	08004004 	.word	0x08004004

080005c8 <Str2Int>:
 80005c8:	b510      	push	{r4, lr}
 80005ca:	4684      	mov	ip, r0
 80005cc:	7803      	ldrb	r3, [r0, #0]
 80005ce:	2b30      	cmp	r3, #48	; 0x30
 80005d0:	d003      	beq.n	80005da <Str2Int+0x12>
 80005d2:	2400      	movs	r4, #0
 80005d4:	4620      	mov	r0, r4
 80005d6:	4623      	mov	r3, r4
 80005d8:	e054      	b.n	8000684 <Str2Int+0xbc>
 80005da:	7843      	ldrb	r3, [r0, #1]
 80005dc:	2b78      	cmp	r3, #120	; 0x78
 80005de:	d035      	beq.n	800064c <Str2Int+0x84>
 80005e0:	2b58      	cmp	r3, #88	; 0x58
 80005e2:	d036      	beq.n	8000652 <Str2Int+0x8a>
 80005e4:	2400      	movs	r4, #0
 80005e6:	4620      	mov	r0, r4
 80005e8:	4623      	mov	r3, r4
 80005ea:	e04b      	b.n	8000684 <Str2Int+0xbc>
 80005ec:	0124      	lsls	r4, r4, #4
 80005ee:	f1a3 0e30 	sub.w	lr, r3, #48	; 0x30
 80005f2:	fa5f fe8e 	uxtb.w	lr, lr
 80005f6:	f1be 0f09 	cmp.w	lr, #9
 80005fa:	d821      	bhi.n	8000640 <Str2Int+0x78>
 80005fc:	3b30      	subs	r3, #48	; 0x30
 80005fe:	441c      	add	r4, r3
 8000600:	3001      	adds	r0, #1
 8000602:	280a      	cmp	r0, #10
 8000604:	d815      	bhi.n	8000632 <Str2Int+0x6a>
 8000606:	f81c 3000 	ldrb.w	r3, [ip, r0]
 800060a:	b193      	cbz	r3, 8000632 <Str2Int+0x6a>
 800060c:	f1a3 0241 	sub.w	r2, r3, #65	; 0x41
 8000610:	b2d2      	uxtb	r2, r2
 8000612:	2a05      	cmp	r2, #5
 8000614:	d9ea      	bls.n	80005ec <Str2Int+0x24>
 8000616:	f1a3 0e61 	sub.w	lr, r3, #97	; 0x61
 800061a:	fa5f fe8e 	uxtb.w	lr, lr
 800061e:	f1be 0f05 	cmp.w	lr, #5
 8000622:	d9e3      	bls.n	80005ec <Str2Int+0x24>
 8000624:	f1a3 0e30 	sub.w	lr, r3, #48	; 0x30
 8000628:	fa5f fe8e 	uxtb.w	lr, lr
 800062c:	f1be 0f09 	cmp.w	lr, #9
 8000630:	d9dc      	bls.n	80005ec <Str2Int+0x24>
 8000632:	f81c 3000 	ldrb.w	r3, [ip, r0]
 8000636:	2b00      	cmp	r3, #0
 8000638:	d13b      	bne.n	80006b2 <Str2Int+0xea>
 800063a:	600c      	str	r4, [r1, #0]
 800063c:	2001      	movs	r0, #1
 800063e:	bd10      	pop	{r4, pc}
 8000640:	2a05      	cmp	r2, #5
 8000642:	d801      	bhi.n	8000648 <Str2Int+0x80>
 8000644:	3b37      	subs	r3, #55	; 0x37
 8000646:	e7da      	b.n	80005fe <Str2Int+0x36>
 8000648:	3b57      	subs	r3, #87	; 0x57
 800064a:	e7d8      	b.n	80005fe <Str2Int+0x36>
 800064c:	2400      	movs	r4, #0
 800064e:	2002      	movs	r0, #2
 8000650:	e7d7      	b.n	8000602 <Str2Int+0x3a>
 8000652:	2400      	movs	r4, #0
 8000654:	2002      	movs	r0, #2
 8000656:	e7d4      	b.n	8000602 <Str2Int+0x3a>
 8000658:	2a6b      	cmp	r2, #107	; 0x6b
 800065a:	d01e      	beq.n	800069a <Str2Int+0xd2>
 800065c:	2a4b      	cmp	r2, #75	; 0x4b
 800065e:	d01c      	beq.n	800069a <Str2Int+0xd2>
 8000660:	2a6d      	cmp	r2, #109	; 0x6d
 8000662:	d020      	beq.n	80006a6 <Str2Int+0xde>
 8000664:	2a4d      	cmp	r2, #77	; 0x4d
 8000666:	d01e      	beq.n	80006a6 <Str2Int+0xde>
 8000668:	f1a2 0e30 	sub.w	lr, r2, #48	; 0x30
 800066c:	fa5f fe8e 	uxtb.w	lr, lr
 8000670:	f1be 0f09 	cmp.w	lr, #9
 8000674:	d8e3      	bhi.n	800063e <Str2Int+0x76>
 8000676:	eb04 0484 	add.w	r4, r4, r4, lsl #2
 800067a:	eb02 0244 	add.w	r2, r2, r4, lsl #1
 800067e:	f1a2 0430 	sub.w	r4, r2, #48	; 0x30
 8000682:	3301      	adds	r3, #1
 8000684:	2b0a      	cmp	r3, #10
 8000686:	d8da      	bhi.n	800063e <Str2Int+0x76>
 8000688:	2800      	cmp	r0, #0
 800068a:	d1d8      	bne.n	800063e <Str2Int+0x76>
 800068c:	f81c 2003 	ldrb.w	r2, [ip, r3]
 8000690:	2a00      	cmp	r2, #0
 8000692:	d1e1      	bne.n	8000658 <Str2Int+0x90>
 8000694:	600c      	str	r4, [r1, #0]
 8000696:	2001      	movs	r0, #1
 8000698:	e7f3      	b.n	8000682 <Str2Int+0xba>
 800069a:	2b00      	cmp	r3, #0
 800069c:	d0e0      	beq.n	8000660 <Str2Int+0x98>
 800069e:	02a4      	lsls	r4, r4, #10
 80006a0:	600c      	str	r4, [r1, #0]
 80006a2:	2001      	movs	r0, #1
 80006a4:	e7ed      	b.n	8000682 <Str2Int+0xba>
 80006a6:	2b00      	cmp	r3, #0
 80006a8:	d0de      	beq.n	8000668 <Str2Int+0xa0>
 80006aa:	0524      	lsls	r4, r4, #20
 80006ac:	600c      	str	r4, [r1, #0]
 80006ae:	2001      	movs	r0, #1
 80006b0:	e7e7      	b.n	8000682 <Str2Int+0xba>
 80006b2:	2000      	movs	r0, #0
 80006b4:	e7c3      	b.n	800063e <Str2Int+0x76>
	...

080006b8 <Serial_PutString>:
 80006b8:	b508      	push	{r3, lr}
 80006ba:	4601      	mov	r1, r0
 80006bc:	2200      	movs	r2, #0
 80006be:	e001      	b.n	80006c4 <Serial_PutString+0xc>
 80006c0:	3201      	adds	r2, #1
 80006c2:	b292      	uxth	r2, r2
 80006c4:	5c8b      	ldrb	r3, [r1, r2]
 80006c6:	2b00      	cmp	r3, #0
 80006c8:	d1fa      	bne.n	80006c0 <Serial_PutString+0x8>
 80006ca:	2364      	movs	r3, #100	; 0x64
 80006cc:	4801      	ldr	r0, [pc, #4]	; (80006d4 <Serial_PutString+0x1c>)
 80006ce:	f001 fe0c 	bl	80022ea <HAL_UART_Transmit>
 80006d2:	bd08      	pop	{r3, pc}
 80006d4:	200060d4 	.word	0x200060d4

080006d8 <Serial_PutByte>:
 80006d8:	b500      	push	{lr}
 80006da:	b083      	sub	sp, #12
 80006dc:	f88d 0007 	strb.w	r0, [sp, #7]
 80006e0:	4b09      	ldr	r3, [pc, #36]	; (8000708 <Serial_PutByte+0x30>)
 80006e2:	f8d3 3084 	ldr.w	r3, [r3, #132]	; 0x84
 80006e6:	2ba0      	cmp	r3, #160	; 0xa0
 80006e8:	d009      	beq.n	80006fe <Serial_PutByte+0x26>
 80006ea:	2364      	movs	r3, #100	; 0x64
 80006ec:	2201      	movs	r2, #1
 80006ee:	f10d 0107 	add.w	r1, sp, #7
 80006f2:	4805      	ldr	r0, [pc, #20]	; (8000708 <Serial_PutByte+0x30>)
 80006f4:	f001 fdf9 	bl	80022ea <HAL_UART_Transmit>
 80006f8:	b003      	add	sp, #12
 80006fa:	f85d fb04 	ldr.w	pc, [sp], #4
 80006fe:	4b02      	ldr	r3, [pc, #8]	; (8000708 <Serial_PutByte+0x30>)
 8000700:	2220      	movs	r2, #32
 8000702:	f8c3 2084 	str.w	r2, [r3, #132]	; 0x84
 8000706:	e7f0      	b.n	80006ea <Serial_PutByte+0x12>
 8000708:	200060d4 	.word	0x200060d4

0800070c <Serial_Printf>:
 800070c:	b40f      	push	{r0, r1, r2, r3}
 800070e:	b500      	push	{lr}
 8000710:	f5ad 7d03 	sub.w	sp, sp, #524	; 0x20c
 8000714:	ab84      	add	r3, sp, #528	; 0x210
 8000716:	f853 2b04 	ldr.w	r2, [r3], #4
 800071a:	9301      	str	r3, [sp, #4]
 800071c:	f44f 7100 	mov.w	r1, #512	; 0x200
 8000720:	a802      	add	r0, sp, #8
 8000722:	f024 fd21 	bl	8025168 <tiny_vsnprintf_like>
 8000726:	a802      	add	r0, sp, #8
 8000728:	f01d fc6a 	bl	801e000 <strlen>
 800072c:	2364      	movs	r3, #100	; 0x64
 800072e:	b282      	uxth	r2, r0
 8000730:	a902      	add	r1, sp, #8
 8000732:	4804      	ldr	r0, [pc, #16]	; (8000744 <Serial_Printf+0x38>)
 8000734:	f001 fdd9 	bl	80022ea <HAL_UART_Transmit>
 8000738:	f50d 7d03 	add.w	sp, sp, #524	; 0x20c
 800073c:	f85d eb04 	ldr.w	lr, [sp], #4
 8000740:	b004      	add	sp, #16
 8000742:	4770      	bx	lr
 8000744:	200060d4 	.word	0x200060d4

08000748 <GetPage>:
 8000748:	f100 4078 	add.w	r0, r0, #4160749568	; 0xf8000000
 800074c:	0ac0      	lsrs	r0, r0, #11
 800074e:	4770      	bx	lr

08000750 <FLASH_If_Erase>:
 8000750:	b510      	push	{r4, lr}
 8000752:	b084      	sub	sp, #16
 8000754:	4604      	mov	r4, r0
 8000756:	2300      	movs	r3, #0
 8000758:	9303      	str	r3, [sp, #12]
 800075a:	f028 fa4d 	bl	8028bf8 <HAL_FLASH_Unlock>
 800075e:	4b0e      	ldr	r3, [pc, #56]	; (8000798 <FLASH_If_Erase+0x48>)
 8000760:	f44f 4200 	mov.w	r2, #32768	; 0x8000
 8000764:	611a      	str	r2, [r3, #16]
 8000766:	4620      	mov	r0, r4
 8000768:	f7ff ffee 	bl	8000748 <GetPage>
 800076c:	f1c4 6300 	rsb	r3, r4, #134217728	; 0x8000000
 8000770:	f503 33e8 	add.w	r3, r3, #118784	; 0x1d000
 8000774:	0adb      	lsrs	r3, r3, #11
 8000776:	2202      	movs	r2, #2
 8000778:	9200      	str	r2, [sp, #0]
 800077a:	9001      	str	r0, [sp, #4]
 800077c:	9302      	str	r3, [sp, #8]
 800077e:	a903      	add	r1, sp, #12
 8000780:	4668      	mov	r0, sp
 8000782:	f028 fc4d 	bl	8029020 <HAL_FLASHEx_Erase>
 8000786:	b928      	cbnz	r0, 8000794 <FLASH_If_Erase+0x44>
 8000788:	2400      	movs	r4, #0
 800078a:	f028 fa47 	bl	8028c1c <HAL_FLASH_Lock>
 800078e:	4620      	mov	r0, r4
 8000790:	b004      	add	sp, #16
 8000792:	bd10      	pop	{r4, pc}
 8000794:	2401      	movs	r4, #1
 8000796:	e7f8      	b.n	800078a <FLASH_If_Erase+0x3a>
 8000798:	58004000 	.word	0x58004000

0800079c <FLASH_If_Write>:
 800079c:	b5f0      	push	{r4, r5, r6, r7, lr}
 800079e:	b083      	sub	sp, #12
 80007a0:	4605      	mov	r5, r0
 80007a2:	460c      	mov	r4, r1
 80007a4:	4617      	mov	r7, r2
 80007a6:	f028 fa27 	bl	8028bf8 <HAL_FLASH_Unlock>
 80007aa:	2600      	movs	r6, #0
 80007ac:	e002      	b.n	80007b4 <FLASH_If_Write+0x18>
 80007ae:	3508      	adds	r5, #8
 80007b0:	3408      	adds	r4, #8
 80007b2:	3602      	adds	r6, #2
 80007b4:	42be      	cmp	r6, r7
 80007b6:	d215      	bcs.n	80007e4 <FLASH_If_Write+0x48>
 80007b8:	466b      	mov	r3, sp
 80007ba:	6820      	ldr	r0, [r4, #0]
 80007bc:	6861      	ldr	r1, [r4, #4]
 80007be:	c303      	stmia	r3!, {r0, r1}
 80007c0:	e9dd 2300 	ldrd	r2, r3, [sp]
 80007c4:	4629      	mov	r1, r5
 80007c6:	2001      	movs	r0, #1
 80007c8:	f028 fa94 	bl	8028cf4 <HAL_FLASH_Program>
 80007cc:	2800      	cmp	r0, #0
 80007ce:	d1f0      	bne.n	80007b2 <FLASH_If_Write+0x16>
 80007d0:	6828      	ldr	r0, [r5, #0]
 80007d2:	686a      	ldr	r2, [r5, #4]
 80007d4:	9900      	ldr	r1, [sp, #0]
 80007d6:	9b01      	ldr	r3, [sp, #4]
 80007d8:	429a      	cmp	r2, r3
 80007da:	bf08      	it	eq
 80007dc:	4288      	cmpeq	r0, r1
 80007de:	d0e6      	beq.n	80007ae <FLASH_If_Write+0x12>
 80007e0:	2403      	movs	r4, #3
 80007e2:	e000      	b.n	80007e6 <FLASH_If_Write+0x4a>
 80007e4:	2400      	movs	r4, #0
 80007e6:	f028 fa19 	bl	8028c1c <HAL_FLASH_Lock>
 80007ea:	4620      	mov	r0, r4
 80007ec:	b003      	add	sp, #12
 80007ee:	bdf0      	pop	{r4, r5, r6, r7, pc}

080007f0 <PreJump>:
 80007f0:	b508      	push	{r3, lr}
 80007f2:	4803      	ldr	r0, [pc, #12]	; (8000800 <PreJump+0x10>)
 80007f4:	f000 fe95 	bl	8001522 <HAL_UART_DeInit>
 80007f8:	f024 ffbe 	bl	8025778 <HAL_DeInit>
 80007fc:	bd08      	pop	{r3, pc}
 80007fe:	bf00      	nop
 8000800:	200060d4 	.word	0x200060d4

08000804 <JumpApp>:
 8000804:	b508      	push	{r3, lr}
 8000806:	4a05      	ldr	r2, [pc, #20]	; (800081c <JumpApp+0x18>)
 8000808:	6853      	ldr	r3, [r2, #4]
 800080a:	4905      	ldr	r1, [pc, #20]	; (8000820 <JumpApp+0x1c>)
 800080c:	600b      	str	r3, [r1, #0]
 800080e:	4905      	ldr	r1, [pc, #20]	; (8000824 <JumpApp+0x20>)
 8000810:	600b      	str	r3, [r1, #0]
 8000812:	6812      	ldr	r2, [r2, #0]
 8000814:	f382 8808 	msr	MSP, r2
 8000818:	4798      	blx	r3
 800081a:	bd08      	pop	{r3, pc}
 800081c:	08006000 	.word	0x08006000
 8000820:	2000608c 	.word	0x2000608c
 8000824:	20006090 	.word	0x20006090

08000828 <HAL_FLASH_Program_Flag>:
 8000828:	b570      	push	{r4, r5, r6, lr}
 800082a:	b088      	sub	sp, #32
 800082c:	4604      	mov	r4, r0
 800082e:	460d      	mov	r5, r1
 8000830:	2300      	movs	r3, #0
 8000832:	9307      	str	r3, [sp, #28]
 8000834:	4e13      	ldr	r6, [pc, #76]	; (8000884 <HAL_FLASH_Program_Flag+0x5c>)
 8000836:	e9d6 2300 	ldrd	r2, r3, [r6]
 800083a:	e9cd 2304 	strd	r2, r3, [sp, #16]
 800083e:	f028 f9db 	bl	8028bf8 <HAL_FLASH_Unlock>
 8000842:	4b11      	ldr	r3, [pc, #68]	; (8000888 <HAL_FLASH_Program_Flag+0x60>)
 8000844:	f44f 4200 	mov.w	r2, #32768	; 0x8000
 8000848:	611a      	str	r2, [r3, #16]
 800084a:	4630      	mov	r0, r6
 800084c:	f7ff ff7c 	bl	8000748 <GetPage>
 8000850:	2302      	movs	r3, #2
 8000852:	9301      	str	r3, [sp, #4]
 8000854:	9002      	str	r0, [sp, #8]
 8000856:	2301      	movs	r3, #1
 8000858:	9303      	str	r3, [sp, #12]
 800085a:	a907      	add	r1, sp, #28
 800085c:	a801      	add	r0, sp, #4
 800085e:	f028 fbdf 	bl	8029020 <HAL_FLASHEx_Erase>
 8000862:	b950      	cbnz	r0, 800087a <HAL_FLASH_Program_Flag+0x52>
 8000864:	42b4      	cmp	r4, r6
 8000866:	d00a      	beq.n	800087e <HAL_FLASH_Program_Flag+0x56>
 8000868:	9505      	str	r5, [sp, #20]
 800086a:	e9dd 2304 	ldrd	r2, r3, [sp, #16]
 800086e:	4905      	ldr	r1, [pc, #20]	; (8000884 <HAL_FLASH_Program_Flag+0x5c>)
 8000870:	2001      	movs	r0, #1
 8000872:	f028 fa3f 	bl	8028cf4 <HAL_FLASH_Program>
 8000876:	f028 f9d1 	bl	8028c1c <HAL_FLASH_Lock>
 800087a:	b008      	add	sp, #32
 800087c:	bd70      	pop	{r4, r5, r6, pc}
 800087e:	9504      	str	r5, [sp, #16]
 8000880:	e7f3      	b.n	800086a <HAL_FLASH_Program_Flag+0x42>
 8000882:	bf00      	nop
 8000884:	08004000 	.word	0x08004000
 8000888:	58004000 	.word	0x58004000

0800088c <SerialDownload>:
 800088c:	b500      	push	{lr}
 800088e:	b083      	sub	sp, #12
 8000890:	2300      	movs	r3, #0
 8000892:	9301      	str	r3, [sp, #4]
 8000894:	a801      	add	r0, sp, #4
 8000896:	f000 fa2d 	bl	8000cf4 <Ymodem_Receive>
 800089a:	b110      	cbz	r0, 80008a2 <SerialDownload+0x16>
 800089c:	b003      	add	sp, #12
 800089e:	f85d fb04 	ldr.w	pc, [sp], #4
 80008a2:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 80008a6:	480a      	ldr	r0, [pc, #40]	; (80008d0 <SerialDownload+0x44>)
 80008a8:	f7ff ffbe 	bl	8000828 <HAL_FLASH_Program_Flag>
 80008ac:	f04f 3102 	mov.w	r1, #33686018	; 0x2020202
 80008b0:	4808      	ldr	r0, [pc, #32]	; (80008d4 <SerialDownload+0x48>)
 80008b2:	f7ff ffb9 	bl	8000828 <HAL_FLASH_Program_Flag>
 80008b6:	4b08      	ldr	r3, [pc, #32]	; (80008d8 <SerialDownload+0x4c>)
 80008b8:	681a      	ldr	r2, [r3, #0]
 80008ba:	4b08      	ldr	r3, [pc, #32]	; (80008dc <SerialDownload+0x50>)
 80008bc:	4013      	ands	r3, r2
 80008be:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 80008c2:	d1eb      	bne.n	800089c <SerialDownload+0x10>
 80008c4:	f7ff ff94 	bl	80007f0 <PreJump>
 80008c8:	f7ff ff9c 	bl	8000804 <JumpApp>
 80008cc:	e7e6      	b.n	800089c <SerialDownload+0x10>
 80008ce:	bf00      	nop
 80008d0:	08004000 	.word	0x08004000
 80008d4:	08004004 	.word	0x08004004
 80008d8:	08006000 	.word	0x08006000
 80008dc:	2ffe0000 	.word	0x2ffe0000

080008e0 <app_jump>:
 80008e0:	b508      	push	{r3, lr}
 80008e2:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 80008e6:	480a      	ldr	r0, [pc, #40]	; (8000910 <app_jump+0x30>)
 80008e8:	f7ff ff9e 	bl	8000828 <HAL_FLASH_Program_Flag>
 80008ec:	4b09      	ldr	r3, [pc, #36]	; (8000914 <app_jump+0x34>)
 80008ee:	681a      	ldr	r2, [r3, #0]
 80008f0:	4b09      	ldr	r3, [pc, #36]	; (8000918 <app_jump+0x38>)
 80008f2:	4013      	ands	r3, r2
 80008f4:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 80008f8:	d000      	beq.n	80008fc <app_jump+0x1c>
 80008fa:	bd08      	pop	{r3, pc}
 80008fc:	4b04      	ldr	r3, [pc, #16]	; (8000910 <app_jump+0x30>)
 80008fe:	685b      	ldr	r3, [r3, #4]
 8000900:	f1b3 3f01 	cmp.w	r3, #16843009	; 0x1010101
 8000904:	d0f9      	beq.n	80008fa <app_jump+0x1a>
 8000906:	f7ff ff73 	bl	80007f0 <PreJump>
 800090a:	f7ff ff7b 	bl	8000804 <JumpApp>
 800090e:	e7f4      	b.n	80008fa <app_jump+0x1a>
 8000910:	08004000 	.word	0x08004000
 8000914:	08006000 	.word	0x08006000
 8000918:	2ffe0000 	.word	0x2ffe0000

0800091c <NMI_Handler>:
 800091c:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 8000920:	6b9a      	ldr	r2, [r3, #56]	; 0x38
 8000922:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
 8000926:	6399      	str	r1, [r3, #56]	; 0x38
 8000928:	6bda      	ldr	r2, [r3, #60]	; 0x3c
 800092a:	63d9      	str	r1, [r3, #60]	; 0x3c
 800092c:	6b9a      	ldr	r2, [r3, #56]	; 0x38
 800092e:	2200      	movs	r2, #0
 8000930:	639a      	str	r2, [r3, #56]	; 0x38
 8000932:	6bd8      	ldr	r0, [r3, #60]	; 0x3c
 8000934:	63da      	str	r2, [r3, #60]	; 0x3c
 8000936:	6c18      	ldr	r0, [r3, #64]	; 0x40
 8000938:	6419      	str	r1, [r3, #64]	; 0x40
 800093a:	6c18      	ldr	r0, [r3, #64]	; 0x40
 800093c:	641a      	str	r2, [r3, #64]	; 0x40
 800093e:	6c58      	ldr	r0, [r3, #68]	; 0x44
 8000940:	6459      	str	r1, [r3, #68]	; 0x44
 8000942:	6c58      	ldr	r0, [r3, #68]	; 0x44
 8000944:	645a      	str	r2, [r3, #68]	; 0x44
 8000946:	6a98      	ldr	r0, [r3, #40]	; 0x28
 8000948:	6299      	str	r1, [r3, #40]	; 0x28
 800094a:	6a98      	ldr	r0, [r3, #40]	; 0x28
 800094c:	629a      	str	r2, [r3, #40]	; 0x28
 800094e:	6ad8      	ldr	r0, [r3, #44]	; 0x2c
 8000950:	62d9      	str	r1, [r3, #44]	; 0x2c
 8000952:	6ad8      	ldr	r0, [r3, #44]	; 0x2c
 8000954:	62da      	str	r2, [r3, #44]	; 0x2c
 8000956:	6b18      	ldr	r0, [r3, #48]	; 0x30
 8000958:	6319      	str	r1, [r3, #48]	; 0x30
 800095a:	6b19      	ldr	r1, [r3, #48]	; 0x30
 800095c:	631a      	str	r2, [r3, #48]	; 0x30
 800095e:	6c5a      	ldr	r2, [r3, #68]	; 0x44
 8000960:	f042 0201 	orr.w	r2, r2, #1
 8000964:	645a      	str	r2, [r3, #68]	; 0x44
 8000966:	6c5a      	ldr	r2, [r3, #68]	; 0x44
 8000968:	f022 0201 	bic.w	r2, r2, #1
 800096c:	645a      	str	r2, [r3, #68]	; 0x44
 800096e:	f8d3 2090 	ldr.w	r2, [r3, #144]	; 0x90
 8000972:	f442 3280 	orr.w	r2, r2, #65536	; 0x10000
 8000976:	f8c3 2090 	str.w	r2, [r3, #144]	; 0x90
 800097a:	f8d3 2090 	ldr.w	r2, [r3, #144]	; 0x90
 800097e:	f422 3280 	bic.w	r2, r2, #65536	; 0x10000
 8000982:	f8c3 2090 	str.w	r2, [r3, #144]	; 0x90
 8000986:	f3bf 8f4f 	dsb	sy
 800098a:	4905      	ldr	r1, [pc, #20]	; (80009a0 <NMI_Handler+0x84>)
 800098c:	68ca      	ldr	r2, [r1, #12]
 800098e:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000992:	4b04      	ldr	r3, [pc, #16]	; (80009a4 <NMI_Handler+0x88>)
 8000994:	4313      	orrs	r3, r2
 8000996:	60cb      	str	r3, [r1, #12]
 8000998:	f3bf 8f4f 	dsb	sy
 800099c:	bf00      	nop
 800099e:	e7fd      	b.n	800099c <NMI_Handler+0x80>
 80009a0:	e000ed00 	.word	0xe000ed00
 80009a4:	05fa0004 	.word	0x05fa0004

080009a8 <HardFault_Handler>:
 80009a8:	4770      	bx	lr

080009aa <MemManage_Handler>:
 80009aa:	4770      	bx	lr

080009ac <BusFault_Handler>:
 80009ac:	4770      	bx	lr

080009ae <UsageFault_Handler>:
 80009ae:	e7fe      	b.n	80009ae <UsageFault_Handler>

080009b0 <SVC_Handler>:
 80009b0:	4770      	bx	lr

080009b2 <DebugMon_Handler>:
 80009b2:	4770      	bx	lr

080009b4 <PendSV_Handler>:
 80009b4:	4770      	bx	lr

080009b6 <SysTick_Handler>:
 80009b6:	b508      	push	{r3, lr}
 80009b8:	f024 ff40 	bl	802583c <HAL_IncTick>
 80009bc:	f024 ff4a 	bl	8025854 <HAL_GetTick>
 80009c0:	f000 fa70 	bl	8000ea4 <upgrade_process_callback>
 80009c4:	bd08      	pop	{r3, pc}
	...

080009c8 <RTC_Alarm_IRQHandler>:
 80009c8:	b508      	push	{r3, lr}
 80009ca:	4802      	ldr	r0, [pc, #8]	; (80009d4 <RTC_Alarm_IRQHandler+0xc>)
 80009cc:	f026 fb2c 	bl	8027028 <HAL_RTC_AlarmIRQHandler>
 80009d0:	bd08      	pop	{r3, pc}
 80009d2:	bf00      	nop
 80009d4:	200044d8 	.word	0x200044d8

080009d8 <SUBGHZ_Radio_IRQHandler>:
 80009d8:	b508      	push	{r3, lr}
 80009da:	4802      	ldr	r0, [pc, #8]	; (80009e4 <SUBGHZ_Radio_IRQHandler+0xc>)
 80009dc:	f028 fe09 	bl	80295f2 <HAL_SUBGHZ_IRQHandler>
 80009e0:	bd08      	pop	{r3, pc}
 80009e2:	bf00      	nop
 80009e4:	200002d0 	.word	0x200002d0

080009e8 <TAMP_STAMP_LSECSS_SSRU_IRQHandler>:
 80009e8:	b508      	push	{r3, lr}
 80009ea:	4802      	ldr	r0, [pc, #8]	; (80009f4 <TAMP_STAMP_LSECSS_SSRU_IRQHandler+0xc>)
 80009ec:	f027 fb56 	bl	802809c <HAL_RTCEx_SSRUIRQHandler>
 80009f0:	bd08      	pop	{r3, pc}
 80009f2:	bf00      	nop
 80009f4:	200044d8 	.word	0x200044d8

080009f8 <USART2_IRQHandler>:
 80009f8:	b508      	push	{r3, lr}
 80009fa:	4802      	ldr	r0, [pc, #8]	; (8000a04 <USART2_IRQHandler+0xc>)
 80009fc:	f000 fe50 	bl	80016a0 <HAL_UART_IRQHandler>
 8000a00:	bd08      	pop	{r3, pc}
 8000a02:	bf00      	nop
 8000a04:	200060d4 	.word	0x200060d4

08000a08 <MX_USART2_UART_Init>:
 8000a08:	b508      	push	{r3, lr}
 8000a0a:	4817      	ldr	r0, [pc, #92]	; (8000a68 <MX_USART2_UART_Init+0x60>)
 8000a0c:	4b17      	ldr	r3, [pc, #92]	; (8000a6c <MX_USART2_UART_Init+0x64>)
 8000a0e:	6003      	str	r3, [r0, #0]
 8000a10:	f44f 33e1 	mov.w	r3, #115200	; 0x1c200
 8000a14:	6043      	str	r3, [r0, #4]
 8000a16:	2300      	movs	r3, #0
 8000a18:	6083      	str	r3, [r0, #8]
 8000a1a:	60c3      	str	r3, [r0, #12]
 8000a1c:	6103      	str	r3, [r0, #16]
 8000a1e:	220c      	movs	r2, #12
 8000a20:	6142      	str	r2, [r0, #20]
 8000a22:	6183      	str	r3, [r0, #24]
 8000a24:	61c3      	str	r3, [r0, #28]
 8000a26:	6203      	str	r3, [r0, #32]
 8000a28:	6243      	str	r3, [r0, #36]	; 0x24
 8000a2a:	6283      	str	r3, [r0, #40]	; 0x28
 8000a2c:	f001 fd9c 	bl	8002568 <HAL_UART_Init>
 8000a30:	b970      	cbnz	r0, 8000a50 <MX_USART2_UART_Init+0x48>
 8000a32:	2100      	movs	r1, #0
 8000a34:	480c      	ldr	r0, [pc, #48]	; (8000a68 <MX_USART2_UART_Init+0x60>)
 8000a36:	f001 fecd 	bl	80027d4 <HAL_UARTEx_SetTxFifoThreshold>
 8000a3a:	b960      	cbnz	r0, 8000a56 <MX_USART2_UART_Init+0x4e>
 8000a3c:	2100      	movs	r1, #0
 8000a3e:	480a      	ldr	r0, [pc, #40]	; (8000a68 <MX_USART2_UART_Init+0x60>)
 8000a40:	f001 feed 	bl	800281e <HAL_UARTEx_SetRxFifoThreshold>
 8000a44:	b950      	cbnz	r0, 8000a5c <MX_USART2_UART_Init+0x54>
 8000a46:	4808      	ldr	r0, [pc, #32]	; (8000a68 <MX_USART2_UART_Init+0x60>)
 8000a48:	f001 fea5 	bl	8002796 <HAL_UARTEx_DisableFifoMode>
 8000a4c:	b948      	cbnz	r0, 8000a62 <MX_USART2_UART_Init+0x5a>
 8000a4e:	bd08      	pop	{r3, pc}
 8000a50:	f020 fe0e 	bl	8021670 <Error_Handler>
 8000a54:	e7ed      	b.n	8000a32 <MX_USART2_UART_Init+0x2a>
 8000a56:	f020 fe0b 	bl	8021670 <Error_Handler>
 8000a5a:	e7ef      	b.n	8000a3c <MX_USART2_UART_Init+0x34>
 8000a5c:	f020 fe08 	bl	8021670 <Error_Handler>
 8000a60:	e7f1      	b.n	8000a46 <MX_USART2_UART_Init+0x3e>
 8000a62:	f020 fe05 	bl	8021670 <Error_Handler>
 8000a66:	e7f2      	b.n	8000a4e <MX_USART2_UART_Init+0x46>
 8000a68:	200060d4 	.word	0x200060d4
 8000a6c:	40004400 	.word	0x40004400

08000a70 <HAL_UART_RxCpltCallback>:
 8000a70:	b508      	push	{r3, lr}
 8000a72:	2201      	movs	r2, #1
 8000a74:	4903      	ldr	r1, [pc, #12]	; (8000a84 <HAL_UART_RxCpltCallback+0x14>)
 8000a76:	4804      	ldr	r0, [pc, #16]	; (8000a88 <HAL_UART_RxCpltCallback+0x18>)
 8000a78:	f001 fe3e 	bl	80026f8 <HAL_UART_Receive_IT>
 8000a7c:	4b03      	ldr	r3, [pc, #12]	; (8000a8c <HAL_UART_RxCpltCallback+0x1c>)
 8000a7e:	2201      	movs	r2, #1
 8000a80:	701a      	strb	r2, [r3, #0]
 8000a82:	bd08      	pop	{r3, pc}
 8000a84:	20006086 	.word	0x20006086
 8000a88:	200060d4 	.word	0x200060d4
 8000a8c:	20006088 	.word	0x20006088

08000a90 <HAL_UART_MspInit>:
 8000a90:	b510      	push	{r4, lr}
 8000a92:	b096      	sub	sp, #88	; 0x58
 8000a94:	4604      	mov	r4, r0
 8000a96:	2100      	movs	r1, #0
 8000a98:	9111      	str	r1, [sp, #68]	; 0x44
 8000a9a:	9112      	str	r1, [sp, #72]	; 0x48
 8000a9c:	9113      	str	r1, [sp, #76]	; 0x4c
 8000a9e:	9114      	str	r1, [sp, #80]	; 0x50
 8000aa0:	9115      	str	r1, [sp, #84]	; 0x54
 8000aa2:	2238      	movs	r2, #56	; 0x38
 8000aa4:	a803      	add	r0, sp, #12
 8000aa6:	f7ff fb8b 	bl	80001c0 <memset>
 8000aaa:	6822      	ldr	r2, [r4, #0]
 8000aac:	4b1e      	ldr	r3, [pc, #120]	; (8000b28 <HAL_UART_MspInit+0x98>)
 8000aae:	429a      	cmp	r2, r3
 8000ab0:	d001      	beq.n	8000ab6 <HAL_UART_MspInit+0x26>
 8000ab2:	b016      	add	sp, #88	; 0x58
 8000ab4:	bd10      	pop	{r4, pc}
 8000ab6:	2302      	movs	r3, #2
 8000ab8:	9303      	str	r3, [sp, #12]
 8000aba:	f44f 2340 	mov.w	r3, #786432	; 0xc0000
 8000abe:	9305      	str	r3, [sp, #20]
 8000ac0:	a803      	add	r0, sp, #12
 8000ac2:	f025 fe5b 	bl	802677c <HAL_RCCEx_PeriphCLKConfig>
 8000ac6:	bb58      	cbnz	r0, 8000b20 <HAL_UART_MspInit+0x90>
 8000ac8:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 8000acc:	6d9a      	ldr	r2, [r3, #88]	; 0x58
 8000ace:	f442 3200 	orr.w	r2, r2, #131072	; 0x20000
 8000ad2:	659a      	str	r2, [r3, #88]	; 0x58
 8000ad4:	6d9a      	ldr	r2, [r3, #88]	; 0x58
 8000ad6:	f402 3200 	and.w	r2, r2, #131072	; 0x20000
 8000ada:	9202      	str	r2, [sp, #8]
 8000adc:	9a02      	ldr	r2, [sp, #8]
 8000ade:	6cda      	ldr	r2, [r3, #76]	; 0x4c
 8000ae0:	f042 0201 	orr.w	r2, r2, #1
 8000ae4:	64da      	str	r2, [r3, #76]	; 0x4c
 8000ae6:	6cdb      	ldr	r3, [r3, #76]	; 0x4c
 8000ae8:	f003 0301 	and.w	r3, r3, #1
 8000aec:	9301      	str	r3, [sp, #4]
 8000aee:	9b01      	ldr	r3, [sp, #4]
 8000af0:	230c      	movs	r3, #12
 8000af2:	9311      	str	r3, [sp, #68]	; 0x44
 8000af4:	2302      	movs	r3, #2
 8000af6:	9312      	str	r3, [sp, #72]	; 0x48
 8000af8:	2301      	movs	r3, #1
 8000afa:	9313      	str	r3, [sp, #76]	; 0x4c
 8000afc:	2400      	movs	r4, #0
 8000afe:	9414      	str	r4, [sp, #80]	; 0x50
 8000b00:	2307      	movs	r3, #7
 8000b02:	9315      	str	r3, [sp, #84]	; 0x54
 8000b04:	a911      	add	r1, sp, #68	; 0x44
 8000b06:	f04f 4090 	mov.w	r0, #1207959552	; 0x48000000
 8000b0a:	f028 fe25 	bl	8029758 <HAL_GPIO_Init>
 8000b0e:	4622      	mov	r2, r4
 8000b10:	4621      	mov	r1, r4
 8000b12:	2025      	movs	r0, #37	; 0x25
 8000b14:	f022 f982 	bl	8022e1c <HAL_NVIC_SetPriority>
 8000b18:	2025      	movs	r0, #37	; 0x25
 8000b1a:	f022 f9b1 	bl	8022e80 <HAL_NVIC_EnableIRQ>
 8000b1e:	e7c8      	b.n	8000ab2 <HAL_UART_MspInit+0x22>
 8000b20:	f020 fda6 	bl	8021670 <Error_Handler>
 8000b24:	e7d0      	b.n	8000ac8 <HAL_UART_MspInit+0x38>
 8000b26:	bf00      	nop
 8000b28:	40004400 	.word	0x40004400

08000b2c <HAL_UART_MspDeInit>:
 8000b2c:	b508      	push	{r3, lr}
 8000b2e:	6802      	ldr	r2, [r0, #0]
 8000b30:	4b09      	ldr	r3, [pc, #36]	; (8000b58 <HAL_UART_MspDeInit+0x2c>)
 8000b32:	429a      	cmp	r2, r3
 8000b34:	d000      	beq.n	8000b38 <HAL_UART_MspDeInit+0xc>
 8000b36:	bd08      	pop	{r3, pc}
 8000b38:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8000b3c:	6d93      	ldr	r3, [r2, #88]	; 0x58
 8000b3e:	f423 3300 	bic.w	r3, r3, #131072	; 0x20000
 8000b42:	6593      	str	r3, [r2, #88]	; 0x58
 8000b44:	210c      	movs	r1, #12
 8000b46:	f04f 4090 	mov.w	r0, #1207959552	; 0x48000000
 8000b4a:	f028 feb7 	bl	80298bc <HAL_GPIO_DeInit>
 8000b4e:	2025      	movs	r0, #37	; 0x25
 8000b50:	f022 f9a4 	bl	8022e9c <HAL_NVIC_DisableIRQ>
 8000b54:	e7ef      	b.n	8000b36 <HAL_UART_MspDeInit+0xa>
 8000b56:	bf00      	nop
 8000b58:	40004400 	.word	0x40004400

08000b5c <__NVIC_SystemReset>:
 8000b5c:	f3bf 8f4f 	dsb	sy
 8000b60:	4905      	ldr	r1, [pc, #20]	; (8000b78 <__NVIC_SystemReset+0x1c>)
 8000b62:	68ca      	ldr	r2, [r1, #12]
 8000b64:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000b68:	4b04      	ldr	r3, [pc, #16]	; (8000b7c <__NVIC_SystemReset+0x20>)
 8000b6a:	4313      	orrs	r3, r2
 8000b6c:	60cb      	str	r3, [r1, #12]
 8000b6e:	f3bf 8f4f 	dsb	sy
 8000b72:	bf00      	nop
 8000b74:	e7fd      	b.n	8000b72 <__NVIC_SystemReset+0x16>
 8000b76:	bf00      	nop
 8000b78:	e000ed00 	.word	0xe000ed00
 8000b7c:	05fa0004 	.word	0x05fa0004

08000b80 <UpdateCRC16>:
 8000b80:	f441 7180 	orr.w	r1, r1, #256	; 0x100
 8000b84:	e006      	b.n	8000b94 <UpdateCRC16+0x14>
 8000b86:	f480 5081 	eor.w	r0, r0, #4128	; 0x1020
 8000b8a:	f080 0001 	eor.w	r0, r0, #1
 8000b8e:	f411 3f80 	tst.w	r1, #65536	; 0x10000
 8000b92:	d109      	bne.n	8000ba8 <UpdateCRC16+0x28>
 8000b94:	0040      	lsls	r0, r0, #1
 8000b96:	0049      	lsls	r1, r1, #1
 8000b98:	f411 7f80 	tst.w	r1, #256	; 0x100
 8000b9c:	d000      	beq.n	8000ba0 <UpdateCRC16+0x20>
 8000b9e:	3001      	adds	r0, #1
 8000ba0:	f410 3f80 	tst.w	r0, #65536	; 0x10000
 8000ba4:	d0f3      	beq.n	8000b8e <UpdateCRC16+0xe>
 8000ba6:	e7ee      	b.n	8000b86 <UpdateCRC16+0x6>
 8000ba8:	b280      	uxth	r0, r0
 8000baa:	4770      	bx	lr

08000bac <Cal_CRC16>:
 8000bac:	b538      	push	{r3, r4, r5, lr}
 8000bae:	4604      	mov	r4, r0
 8000bb0:	1845      	adds	r5, r0, r1
 8000bb2:	2000      	movs	r0, #0
 8000bb4:	e004      	b.n	8000bc0 <Cal_CRC16+0x14>
 8000bb6:	f814 1b01 	ldrb.w	r1, [r4], #1
 8000bba:	b280      	uxth	r0, r0
 8000bbc:	f7ff ffe0 	bl	8000b80 <UpdateCRC16>
 8000bc0:	42ac      	cmp	r4, r5
 8000bc2:	d3f8      	bcc.n	8000bb6 <Cal_CRC16+0xa>
 8000bc4:	2100      	movs	r1, #0
 8000bc6:	b280      	uxth	r0, r0
 8000bc8:	f7ff ffda 	bl	8000b80 <UpdateCRC16>
 8000bcc:	2100      	movs	r1, #0
 8000bce:	f7ff ffd7 	bl	8000b80 <UpdateCRC16>
 8000bd2:	bd38      	pop	{r3, r4, r5, pc}

08000bd4 <ReceivePacket>:
 8000bd4:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 8000bd8:	b082      	sub	sp, #8
 8000bda:	4606      	mov	r6, r0
 8000bdc:	460c      	mov	r4, r1
 8000bde:	4615      	mov	r5, r2
 8000be0:	2300      	movs	r3, #0
 8000be2:	600b      	str	r3, [r1, #0]
 8000be4:	4613      	mov	r3, r2
 8000be6:	2201      	movs	r2, #1
 8000be8:	f10d 0107 	add.w	r1, sp, #7
 8000bec:	4840      	ldr	r0, [pc, #256]	; (8000cf0 <ReceivePacket+0x11c>)
 8000bee:	f001 fbeb 	bl	80023c8 <HAL_UART_Receive>
 8000bf2:	4680      	mov	r8, r0
 8000bf4:	2800      	cmp	r0, #0
 8000bf6:	d172      	bne.n	8000cde <ReceivePacket+0x10a>
 8000bf8:	f89d 1007 	ldrb.w	r1, [sp, #7]
 8000bfc:	2918      	cmp	r1, #24
 8000bfe:	d819      	bhi.n	8000c34 <ReceivePacket+0x60>
 8000c00:	b24b      	sxtb	r3, r1
 8000c02:	2b00      	cmp	r3, #0
 8000c04:	d048      	beq.n	8000c98 <ReceivePacket+0xc4>
 8000c06:	3901      	subs	r1, #1
 8000c08:	2917      	cmp	r1, #23
 8000c0a:	d80f      	bhi.n	8000c2c <ReceivePacket+0x58>
 8000c0c:	e8df f001 	tbb	[pc, r1]
 8000c10:	0c0e3148 	.word	0x0c0e3148
 8000c14:	0e0e0e0e 	.word	0x0e0e0e0e
 8000c18:	0e0e0e0e 	.word	0x0e0e0e0e
 8000c1c:	0e0e0e0e 	.word	0x0e0e0e0e
 8000c20:	0e0e0e0e 	.word	0x0e0e0e0e
 8000c24:	340e0e0e 	.word	0x340e0e0e
 8000c28:	2700      	movs	r7, #0
 8000c2a:	e00a      	b.n	8000c42 <ReceivePacket+0x6e>
 8000c2c:	f04f 0801 	mov.w	r8, #1
 8000c30:	2700      	movs	r7, #0
 8000c32:	e006      	b.n	8000c42 <ReceivePacket+0x6e>
 8000c34:	2941      	cmp	r1, #65	; 0x41
 8000c36:	d035      	beq.n	8000ca4 <ReceivePacket+0xd0>
 8000c38:	2961      	cmp	r1, #97	; 0x61
 8000c3a:	d137      	bne.n	8000cac <ReceivePacket+0xd8>
 8000c3c:	f04f 0802 	mov.w	r8, #2
 8000c40:	2700      	movs	r7, #0
 8000c42:	f89d 3007 	ldrb.w	r3, [sp, #7]
 8000c46:	7033      	strb	r3, [r6, #0]
 8000c48:	2f7f      	cmp	r7, #127	; 0x7f
 8000c4a:	d949      	bls.n	8000ce0 <ReceivePacket+0x10c>
 8000c4c:	462b      	mov	r3, r5
 8000c4e:	1d3a      	adds	r2, r7, #4
 8000c50:	1cb1      	adds	r1, r6, #2
 8000c52:	4827      	ldr	r0, [pc, #156]	; (8000cf0 <ReceivePacket+0x11c>)
 8000c54:	f001 fbb8 	bl	80023c8 <HAL_UART_Receive>
 8000c58:	4680      	mov	r8, r0
 8000c5a:	2800      	cmp	r0, #0
 8000c5c:	d145      	bne.n	8000cea <ReceivePacket+0x116>
 8000c5e:	78b2      	ldrb	r2, [r6, #2]
 8000c60:	78f3      	ldrb	r3, [r6, #3]
 8000c62:	43db      	mvns	r3, r3
 8000c64:	b2db      	uxtb	r3, r3
 8000c66:	429a      	cmp	r2, r3
 8000c68:	d02a      	beq.n	8000cc0 <ReceivePacket+0xec>
 8000c6a:	f04f 0801 	mov.w	r8, #1
 8000c6e:	2700      	movs	r7, #0
 8000c70:	e036      	b.n	8000ce0 <ReceivePacket+0x10c>
 8000c72:	f44f 6780 	mov.w	r7, #1024	; 0x400
 8000c76:	e7e4      	b.n	8000c42 <ReceivePacket+0x6e>
 8000c78:	462b      	mov	r3, r5
 8000c7a:	2201      	movs	r2, #1
 8000c7c:	f10d 0107 	add.w	r1, sp, #7
 8000c80:	481b      	ldr	r0, [pc, #108]	; (8000cf0 <ReceivePacket+0x11c>)
 8000c82:	f001 fba1 	bl	80023c8 <HAL_UART_Receive>
 8000c86:	b9a8      	cbnz	r0, 8000cb4 <ReceivePacket+0xe0>
 8000c88:	f89d 3007 	ldrb.w	r3, [sp, #7]
 8000c8c:	2b18      	cmp	r3, #24
 8000c8e:	d015      	beq.n	8000cbc <ReceivePacket+0xe8>
 8000c90:	f04f 0801 	mov.w	r8, #1
 8000c94:	2700      	movs	r7, #0
 8000c96:	e7d4      	b.n	8000c42 <ReceivePacket+0x6e>
 8000c98:	f04f 0801 	mov.w	r8, #1
 8000c9c:	2700      	movs	r7, #0
 8000c9e:	e7d0      	b.n	8000c42 <ReceivePacket+0x6e>
 8000ca0:	2780      	movs	r7, #128	; 0x80
 8000ca2:	e7ce      	b.n	8000c42 <ReceivePacket+0x6e>
 8000ca4:	f04f 0802 	mov.w	r8, #2
 8000ca8:	2700      	movs	r7, #0
 8000caa:	e7ca      	b.n	8000c42 <ReceivePacket+0x6e>
 8000cac:	f04f 0801 	mov.w	r8, #1
 8000cb0:	2700      	movs	r7, #0
 8000cb2:	e7c6      	b.n	8000c42 <ReceivePacket+0x6e>
 8000cb4:	f04f 0801 	mov.w	r8, #1
 8000cb8:	2700      	movs	r7, #0
 8000cba:	e7c2      	b.n	8000c42 <ReceivePacket+0x6e>
 8000cbc:	2702      	movs	r7, #2
 8000cbe:	e7c0      	b.n	8000c42 <ReceivePacket+0x6e>
 8000cc0:	19f3      	adds	r3, r6, r7
 8000cc2:	791a      	ldrb	r2, [r3, #4]
 8000cc4:	795d      	ldrb	r5, [r3, #5]
 8000cc6:	eb05 2502 	add.w	r5, r5, r2, lsl #8
 8000cca:	4639      	mov	r1, r7
 8000ccc:	1d30      	adds	r0, r6, #4
 8000cce:	f7ff ff6d 	bl	8000bac <Cal_CRC16>
 8000cd2:	42a8      	cmp	r0, r5
 8000cd4:	d004      	beq.n	8000ce0 <ReceivePacket+0x10c>
 8000cd6:	f04f 0801 	mov.w	r8, #1
 8000cda:	2700      	movs	r7, #0
 8000cdc:	e000      	b.n	8000ce0 <ReceivePacket+0x10c>
 8000cde:	2700      	movs	r7, #0
 8000ce0:	6027      	str	r7, [r4, #0]
 8000ce2:	4640      	mov	r0, r8
 8000ce4:	b002      	add	sp, #8
 8000ce6:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 8000cea:	2700      	movs	r7, #0
 8000cec:	e7f8      	b.n	8000ce0 <ReceivePacket+0x10c>
 8000cee:	bf00      	nop
 8000cf0:	200060d4 	.word	0x200060d4

08000cf4 <Ymodem_Receive>:
 8000cf4:	e92d 4ff0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
 8000cf8:	b089      	sub	sp, #36	; 0x24
 8000cfa:	9001      	str	r0, [sp, #4]
 8000cfc:	f04f 0800 	mov.w	r8, #0
 8000d00:	4646      	mov	r6, r8
 8000d02:	f8df b188 	ldr.w	fp, [pc, #392]	; 8000e8c <Ymodem_Receive+0x198>
 8000d06:	46c1      	mov	r9, r8
 8000d08:	4645      	mov	r5, r8
 8000d0a:	46c2      	mov	sl, r8
 8000d0c:	f1ba 0f00 	cmp.w	sl, #0
 8000d10:	f040 80b8 	bne.w	8000e84 <Ymodem_Receive+0x190>
 8000d14:	2e00      	cmp	r6, #0
 8000d16:	f040 80b5 	bne.w	8000e84 <Ymodem_Receive+0x190>
 8000d1a:	4b5d      	ldr	r3, [pc, #372]	; (8000e90 <Ymodem_Receive+0x19c>)
 8000d1c:	2200      	movs	r2, #0
 8000d1e:	701a      	strb	r2, [r3, #0]
 8000d20:	4657      	mov	r7, sl
 8000d22:	e085      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000d24:	9d07      	ldr	r5, [sp, #28]
 8000d26:	b13d      	cbz	r5, 8000d38 <Ymodem_Receive+0x44>
 8000d28:	2d02      	cmp	r5, #2
 8000d2a:	d10a      	bne.n	8000d42 <Ymodem_Receive+0x4e>
 8000d2c:	2006      	movs	r0, #6
 8000d2e:	f7ff fcd3 	bl	80006d8 <Serial_PutByte>
 8000d32:	463d      	mov	r5, r7
 8000d34:	2602      	movs	r6, #2
 8000d36:	e07b      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000d38:	2006      	movs	r0, #6
 8000d3a:	f7ff fccd 	bl	80006d8 <Serial_PutByte>
 8000d3e:	2701      	movs	r7, #1
 8000d40:	e076      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000d42:	4b54      	ldr	r3, [pc, #336]	; (8000e94 <Ymodem_Receive+0x1a0>)
 8000d44:	789a      	ldrb	r2, [r3, #2]
 8000d46:	4b52      	ldr	r3, [pc, #328]	; (8000e90 <Ymodem_Receive+0x19c>)
 8000d48:	781b      	ldrb	r3, [r3, #0]
 8000d4a:	429a      	cmp	r2, r3
 8000d4c:	d10b      	bne.n	8000d66 <Ymodem_Receive+0x72>
 8000d4e:	2b00      	cmp	r3, #0
 8000d50:	d153      	bne.n	8000dfa <Ymodem_Receive+0x106>
 8000d52:	4b50      	ldr	r3, [pc, #320]	; (8000e94 <Ymodem_Receive+0x1a0>)
 8000d54:	791b      	ldrb	r3, [r3, #4]
 8000d56:	b9cb      	cbnz	r3, 8000d8c <Ymodem_Receive+0x98>
 8000d58:	2006      	movs	r0, #6
 8000d5a:	f7ff fcbd 	bl	80006d8 <Serial_PutByte>
 8000d5e:	463d      	mov	r5, r7
 8000d60:	2701      	movs	r7, #1
 8000d62:	46ba      	mov	sl, r7
 8000d64:	e064      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000d66:	2015      	movs	r0, #21
 8000d68:	f7ff fcb6 	bl	80006d8 <Serial_PutByte>
 8000d6c:	463d      	mov	r5, r7
 8000d6e:	e05f      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000d70:	3301      	adds	r3, #1
 8000d72:	4849      	ldr	r0, [pc, #292]	; (8000e98 <Ymodem_Receive+0x1a4>)
 8000d74:	5481      	strb	r1, [r0, r2]
 8000d76:	3201      	adds	r2, #1
 8000d78:	7819      	ldrb	r1, [r3, #0]
 8000d7a:	b109      	cbz	r1, 8000d80 <Ymodem_Receive+0x8c>
 8000d7c:	2a3f      	cmp	r2, #63	; 0x3f
 8000d7e:	d9f7      	bls.n	8000d70 <Ymodem_Receive+0x7c>
 8000d80:	4945      	ldr	r1, [pc, #276]	; (8000e98 <Ymodem_Receive+0x1a4>)
 8000d82:	2000      	movs	r0, #0
 8000d84:	5488      	strb	r0, [r1, r2]
 8000d86:	3301      	adds	r3, #1
 8000d88:	463a      	mov	r2, r7
 8000d8a:	e008      	b.n	8000d9e <Ymodem_Receive+0xaa>
 8000d8c:	463a      	mov	r2, r7
 8000d8e:	4b43      	ldr	r3, [pc, #268]	; (8000e9c <Ymodem_Receive+0x1a8>)
 8000d90:	e7f2      	b.n	8000d78 <Ymodem_Receive+0x84>
 8000d92:	3301      	adds	r3, #1
 8000d94:	a808      	add	r0, sp, #32
 8000d96:	4410      	add	r0, r2
 8000d98:	f800 1c18 	strb.w	r1, [r0, #-24]
 8000d9c:	3201      	adds	r2, #1
 8000d9e:	7819      	ldrb	r1, [r3, #0]
 8000da0:	2920      	cmp	r1, #32
 8000da2:	d001      	beq.n	8000da8 <Ymodem_Receive+0xb4>
 8000da4:	2a0f      	cmp	r2, #15
 8000da6:	d9f4      	bls.n	8000d92 <Ymodem_Receive+0x9e>
 8000da8:	ab08      	add	r3, sp, #32
 8000daa:	441a      	add	r2, r3
 8000dac:	2300      	movs	r3, #0
 8000dae:	f802 3c18 	strb.w	r3, [r2, #-24]
 8000db2:	a906      	add	r1, sp, #24
 8000db4:	a802      	add	r0, sp, #8
 8000db6:	f7ff fc07 	bl	80005c8 <Str2Int>
 8000dba:	9a06      	ldr	r2, [sp, #24]
 8000dbc:	4b38      	ldr	r3, [pc, #224]	; (8000ea0 <Ymodem_Receive+0x1ac>)
 8000dbe:	429a      	cmp	r2, r3
 8000dc0:	d813      	bhi.n	8000dea <Ymodem_Receive+0xf6>
 8000dc2:	4832      	ldr	r0, [pc, #200]	; (8000e8c <Ymodem_Receive+0x198>)
 8000dc4:	f7ff fcc4 	bl	8000750 <FLASH_If_Erase>
 8000dc8:	9b06      	ldr	r3, [sp, #24]
 8000dca:	9a01      	ldr	r2, [sp, #4]
 8000dcc:	6013      	str	r3, [r2, #0]
 8000dce:	2006      	movs	r0, #6
 8000dd0:	f7ff fc82 	bl	80006d8 <Serial_PutByte>
 8000dd4:	2043      	movs	r0, #67	; 0x43
 8000dd6:	f7ff fc7f 	bl	80006d8 <Serial_PutByte>
 8000dda:	4a2d      	ldr	r2, [pc, #180]	; (8000e90 <Ymodem_Receive+0x19c>)
 8000ddc:	7813      	ldrb	r3, [r2, #0]
 8000dde:	3301      	adds	r3, #1
 8000de0:	7013      	strb	r3, [r2, #0]
 8000de2:	463d      	mov	r5, r7
 8000de4:	f04f 0901 	mov.w	r9, #1
 8000de8:	e022      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000dea:	2018      	movs	r0, #24
 8000dec:	f7ff fc74 	bl	80006d8 <Serial_PutByte>
 8000df0:	2018      	movs	r0, #24
 8000df2:	f7ff fc71 	bl	80006d8 <Serial_PutByte>
 8000df6:	2605      	movs	r6, #5
 8000df8:	e7e3      	b.n	8000dc2 <Ymodem_Receive+0xce>
 8000dfa:	08aa      	lsrs	r2, r5, #2
 8000dfc:	4927      	ldr	r1, [pc, #156]	; (8000e9c <Ymodem_Receive+0x1a8>)
 8000dfe:	4658      	mov	r0, fp
 8000e00:	f7ff fccc 	bl	800079c <FLASH_If_Write>
 8000e04:	b928      	cbnz	r0, 8000e12 <Ymodem_Receive+0x11e>
 8000e06:	9b07      	ldr	r3, [sp, #28]
 8000e08:	449b      	add	fp, r3
 8000e0a:	2006      	movs	r0, #6
 8000e0c:	f7ff fc64 	bl	80006d8 <Serial_PutByte>
 8000e10:	e7e3      	b.n	8000dda <Ymodem_Receive+0xe6>
 8000e12:	2018      	movs	r0, #24
 8000e14:	f7ff fc60 	bl	80006d8 <Serial_PutByte>
 8000e18:	2018      	movs	r0, #24
 8000e1a:	f7ff fc5d 	bl	80006d8 <Serial_PutByte>
 8000e1e:	2604      	movs	r6, #4
 8000e20:	e7db      	b.n	8000dda <Ymodem_Receive+0xe6>
 8000e22:	2018      	movs	r0, #24
 8000e24:	f7ff fc58 	bl	80006d8 <Serial_PutByte>
 8000e28:	2018      	movs	r0, #24
 8000e2a:	f7ff fc55 	bl	80006d8 <Serial_PutByte>
 8000e2e:	4626      	mov	r6, r4
 8000e30:	2f00      	cmp	r7, #0
 8000e32:	f47f af6b 	bne.w	8000d0c <Ymodem_Receive+0x18>
 8000e36:	2e00      	cmp	r6, #0
 8000e38:	f47f af68 	bne.w	8000d0c <Ymodem_Receive+0x18>
 8000e3c:	f44f 72fa 	mov.w	r2, #500	; 0x1f4
 8000e40:	a907      	add	r1, sp, #28
 8000e42:	4814      	ldr	r0, [pc, #80]	; (8000e94 <Ymodem_Receive+0x1a0>)
 8000e44:	f7ff fec6 	bl	8000bd4 <ReceivePacket>
 8000e48:	4604      	mov	r4, r0
 8000e4a:	2800      	cmp	r0, #0
 8000e4c:	f43f af6a 	beq.w	8000d24 <Ymodem_Receive+0x30>
 8000e50:	2802      	cmp	r0, #2
 8000e52:	d0e6      	beq.n	8000e22 <Ymodem_Receive+0x12e>
 8000e54:	f1b9 0f00 	cmp.w	r9, #0
 8000e58:	d000      	beq.n	8000e5c <Ymodem_Receive+0x168>
 8000e5a:	3501      	adds	r5, #1
 8000e5c:	2d05      	cmp	r5, #5
 8000e5e:	d907      	bls.n	8000e70 <Ymodem_Receive+0x17c>
 8000e60:	2018      	movs	r0, #24
 8000e62:	f7ff fc39 	bl	80006d8 <Serial_PutByte>
 8000e66:	2018      	movs	r0, #24
 8000e68:	f7ff fc36 	bl	80006d8 <Serial_PutByte>
 8000e6c:	2602      	movs	r6, #2
 8000e6e:	e7df      	b.n	8000e30 <Ymodem_Receive+0x13c>
 8000e70:	2043      	movs	r0, #67	; 0x43
 8000e72:	f7ff fc31 	bl	80006d8 <Serial_PutByte>
 8000e76:	f108 0801 	add.w	r8, r8, #1
 8000e7a:	f1b8 0f3b 	cmp.w	r8, #59	; 0x3b
 8000e7e:	d9d7      	bls.n	8000e30 <Ymodem_Receive+0x13c>
 8000e80:	f7ff fe6c 	bl	8000b5c <__NVIC_SystemReset>
 8000e84:	4630      	mov	r0, r6
 8000e86:	b009      	add	sp, #36	; 0x24
 8000e88:	e8bd 8ff0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, pc}
 8000e8c:	08006000 	.word	0x08006000
 8000e90:	2000656a 	.word	0x2000656a
 8000e94:	20006164 	.word	0x20006164
 8000e98:	20006094 	.word	0x20006094
 8000e9c:	20006168 	.word	0x20006168
 8000ea0:	00031001 	.word	0x00031001

08000ea4 <upgrade_process_callback>:
 8000ea4:	b508      	push	{r3, lr}
 8000ea6:	4b0a      	ldr	r3, [pc, #40]	; (8000ed0 <upgrade_process_callback+0x2c>)
 8000ea8:	fba3 2300 	umull	r2, r3, r3, r0
 8000eac:	0b1b      	lsrs	r3, r3, #12
 8000eae:	f643 2298 	movw	r2, #15000	; 0x3a98
 8000eb2:	fb02 0313 	mls	r3, r2, r3, r0
 8000eb6:	b943      	cbnz	r3, 8000eca <upgrade_process_callback+0x26>
 8000eb8:	4b06      	ldr	r3, [pc, #24]	; (8000ed4 <upgrade_process_callback+0x30>)
 8000eba:	781b      	ldrb	r3, [r3, #0]
 8000ebc:	b12b      	cbz	r3, 8000eca <upgrade_process_callback+0x26>
 8000ebe:	4a06      	ldr	r2, [pc, #24]	; (8000ed8 <upgrade_process_callback+0x34>)
 8000ec0:	7812      	ldrb	r2, [r2, #0]
 8000ec2:	4293      	cmp	r3, r2
 8000ec4:	d002      	beq.n	8000ecc <upgrade_process_callback+0x28>
 8000ec6:	4a04      	ldr	r2, [pc, #16]	; (8000ed8 <upgrade_process_callback+0x34>)
 8000ec8:	7013      	strb	r3, [r2, #0]
 8000eca:	bd08      	pop	{r3, pc}
 8000ecc:	f7ff fe46 	bl	8000b5c <__NVIC_SystemReset>
 8000ed0:	45e7b273 	.word	0x45e7b273
 8000ed4:	2000656a 	.word	0x2000656a
 8000ed8:	2000656b 	.word	0x2000656b

08000edc <__NVIC_SystemReset>:
 8000edc:	f3bf 8f4f 	dsb	sy
 8000ee0:	4905      	ldr	r1, [pc, #20]	; (8000ef8 <__NVIC_SystemReset+0x1c>)
 8000ee2:	68ca      	ldr	r2, [r1, #12]
 8000ee4:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000ee8:	4b04      	ldr	r3, [pc, #16]	; (8000efc <__NVIC_SystemReset+0x20>)
 8000eea:	4313      	orrs	r3, r2
 8000eec:	60cb      	str	r3, [r1, #12]
 8000eee:	f3bf 8f4f 	dsb	sy
 8000ef2:	bf00      	nop
 8000ef4:	e7fd      	b.n	8000ef2 <__NVIC_SystemReset+0x16>
 8000ef6:	bf00      	nop
 8000ef8:	e000ed00 	.word	0xe000ed00
 8000efc:	05fa0004 	.word	0x05fa0004

08000f00 <OnNvmDataChange_fuota>:
 8000f00:	4770      	bx	lr

08000f02 <OnMacProcessNotify_fuota>:
 8000f02:	4770      	bx	lr

08000f04 <fuota_OnMacMcpsRequest>:
 8000f04:	4770      	bx	lr

08000f06 <fuota_OnMacMlmeRequest>:
 8000f06:	4770      	bx	lr

08000f08 <fuota_LmHandlerJoinRequest>:
 8000f08:	4770      	bx	lr

08000f0a <OnNetworkParametersChange>:
 8000f0a:	4770      	bx	lr

08000f0c <OnMacMcpsRequest>:
 8000f0c:	4770      	bx	lr

08000f0e <OnMacMlmeRequest>:
 8000f0e:	4770      	bx	lr

08000f10 <OnJoinRequest>:
 8000f10:	4770      	bx	lr

08000f12 <OnTxData>:
 8000f12:	4770      	bx	lr

08000f14 <OnRxData>:
 8000f14:	4770      	bx	lr

08000f16 <OnBeaconStatusChange>:
 8000f16:	4770      	bx	lr

08000f18 <OnSysTimeUpdate>:
 8000f18:	4b01      	ldr	r3, [pc, #4]	; (8000f20 <OnSysTimeUpdate+0x8>)
 8000f1a:	2201      	movs	r2, #1
 8000f1c:	701a      	strb	r2, [r3, #0]
 8000f1e:	4770      	bx	lr
 8000f20:	200002e4 	.word	0x200002e4

08000f24 <LmHandlerPackagesNotify>:
 8000f24:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000f26:	4605      	mov	r5, r0
 8000f28:	460f      	mov	r7, r1
 8000f2a:	2400      	movs	r4, #0
 8000f2c:	e016      	b.n	8000f5c <LmHandlerPackagesNotify+0x38>
 8000f2e:	695b      	ldr	r3, [r3, #20]
 8000f30:	b193      	cbz	r3, 8000f58 <LmHandlerPackagesNotify+0x34>
 8000f32:	4638      	mov	r0, r7
 8000f34:	4798      	blx	r3
 8000f36:	e00f      	b.n	8000f58 <LmHandlerPackagesNotify+0x34>
 8000f38:	699b      	ldr	r3, [r3, #24]
 8000f3a:	b16b      	cbz	r3, 8000f58 <LmHandlerPackagesNotify+0x34>
 8000f3c:	4638      	mov	r0, r7
 8000f3e:	4798      	blx	r3
 8000f40:	e00a      	b.n	8000f58 <LmHandlerPackagesNotify+0x34>
 8000f42:	69db      	ldr	r3, [r3, #28]
 8000f44:	b10b      	cbz	r3, 8000f4a <LmHandlerPackagesNotify+0x26>
 8000f46:	4638      	mov	r0, r7
 8000f48:	4798      	blx	r3
 8000f4a:	4b10      	ldr	r3, [pc, #64]	; (8000f8c <LmHandlerPackagesNotify+0x68>)
 8000f4c:	f853 3026 	ldr.w	r3, [r3, r6, lsl #2]
 8000f50:	6a1b      	ldr	r3, [r3, #32]
 8000f52:	b10b      	cbz	r3, 8000f58 <LmHandlerPackagesNotify+0x34>
 8000f54:	4638      	mov	r0, r7
 8000f56:	4798      	blx	r3
 8000f58:	3401      	adds	r4, #1
 8000f5a:	b264      	sxtb	r4, r4
 8000f5c:	2c03      	cmp	r4, #3
 8000f5e:	dc13      	bgt.n	8000f88 <LmHandlerPackagesNotify+0x64>
 8000f60:	4626      	mov	r6, r4
 8000f62:	4b0a      	ldr	r3, [pc, #40]	; (8000f8c <LmHandlerPackagesNotify+0x68>)
 8000f64:	f853 3024 	ldr.w	r3, [r3, r4, lsl #2]
 8000f68:	2b00      	cmp	r3, #0
 8000f6a:	d0f5      	beq.n	8000f58 <LmHandlerPackagesNotify+0x34>
 8000f6c:	2d03      	cmp	r5, #3
 8000f6e:	d8f3      	bhi.n	8000f58 <LmHandlerPackagesNotify+0x34>
 8000f70:	a201      	add	r2, pc, #4	; (adr r2, 8000f78 <LmHandlerPackagesNotify+0x54>)
 8000f72:	f852 f025 	ldr.w	pc, [r2, r5, lsl #2]
 8000f76:	bf00      	nop
 8000f78:	08000f2f 	.word	0x08000f2f
 8000f7c:	08000f39 	.word	0x08000f39
 8000f80:	08000f43 	.word	0x08000f43
 8000f84:	08000f4b 	.word	0x08000f4b
 8000f88:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}
 8000f8a:	bf00      	nop
 8000f8c:	200003d0 	.word	0x200003d0

08000f90 <MlmeIndication_fuota>:
 8000f90:	b508      	push	{r3, lr}
 8000f92:	4601      	mov	r1, r0
 8000f94:	2003      	movs	r0, #3
 8000f96:	f7ff ffc5 	bl	8000f24 <LmHandlerPackagesNotify>
 8000f9a:	bd08      	pop	{r3, pc}

08000f9c <McpsConfirm_fuota>:
 8000f9c:	b508      	push	{r3, lr}
 8000f9e:	4601      	mov	r1, r0
 8000fa0:	2000      	movs	r0, #0
 8000fa2:	f7ff ffbf 	bl	8000f24 <LmHandlerPackagesNotify>
 8000fa6:	bd08      	pop	{r3, pc}

08000fa8 <fuota_OnFragProgress>:
 8000fa8:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000faa:	4604      	mov	r4, r0
 8000fac:	460e      	mov	r6, r1
 8000fae:	4615      	mov	r5, r2
 8000fb0:	461f      	mov	r7, r3
 8000fb2:	460a      	mov	r2, r1
 8000fb4:	4601      	mov	r1, r0
 8000fb6:	4807      	ldr	r0, [pc, #28]	; (8000fd4 <fuota_OnFragProgress+0x2c>)
 8000fb8:	f7ff fba8 	bl	800070c <Serial_Printf>
 8000fbc:	fb05 f206 	mul.w	r2, r5, r6
 8000fc0:	fb05 f104 	mul.w	r1, r5, r4
 8000fc4:	4804      	ldr	r0, [pc, #16]	; (8000fd8 <fuota_OnFragProgress+0x30>)
 8000fc6:	f7ff fba1 	bl	800070c <Serial_Printf>
 8000fca:	4639      	mov	r1, r7
 8000fcc:	4803      	ldr	r0, [pc, #12]	; (8000fdc <fuota_OnFragProgress+0x34>)
 8000fce:	f7ff fb9d 	bl	800070c <Serial_Printf>
 8000fd2:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}
 8000fd4:	08002a4c 	.word	0x08002a4c
 8000fd8:	08002a70 	.word	0x08002a70
 8000fdc:	08002a90 	.word	0x08002a90

08000fe0 <fuota_OnFragDone>:
 8000fe0:	b508      	push	{r3, lr}
 8000fe2:	4808      	ldr	r0, [pc, #32]	; (8001004 <fuota_OnFragDone+0x24>)
 8000fe4:	f7ff fb92 	bl	800070c <Serial_Printf>
 8000fe8:	4b07      	ldr	r3, [pc, #28]	; (8001008 <fuota_OnFragDone+0x28>)
 8000fea:	2201      	movs	r2, #1
 8000fec:	701a      	strb	r2, [r3, #0]
 8000fee:	f04f 3102 	mov.w	r1, #33686018	; 0x2020202
 8000ff2:	4806      	ldr	r0, [pc, #24]	; (800100c <fuota_OnFragDone+0x2c>)
 8000ff4:	f7ff fc18 	bl	8000828 <HAL_FLASH_Program_Flag>
 8000ff8:	4805      	ldr	r0, [pc, #20]	; (8001010 <fuota_OnFragDone+0x30>)
 8000ffa:	f7ff fb87 	bl	800070c <Serial_Printf>
 8000ffe:	f7ff ff6d 	bl	8000edc <__NVIC_SystemReset>
 8001002:	bf00      	nop
 8001004:	08002ab4 	.word	0x08002ab4
 8001008:	2000665e 	.word	0x2000665e
 800100c:	08004004 	.word	0x08004004
 8001010:	08002ac4 	.word	0x08002ac4

08001014 <fuota_FragDecoderRead>:
 8001014:	b508      	push	{r3, lr}
 8001016:	4613      	mov	r3, r2
 8001018:	460a      	mov	r2, r1
 800101a:	4619      	mov	r1, r3
 800101c:	f100 6000 	add.w	r0, r0, #134217728	; 0x8000000
 8001020:	f500 40c0 	add.w	r0, r0, #24576	; 0x6000
 8001024:	f020 f9da 	bl	80213dc <udrv_flash_read>
 8001028:	2000      	movs	r0, #0
 800102a:	bd08      	pop	{r3, pc}

0800102c <fuota_FragDecoderWrite>:
 800102c:	b508      	push	{r3, lr}
 800102e:	4613      	mov	r3, r2
 8001030:	460a      	mov	r2, r1
 8001032:	4619      	mov	r1, r3
 8001034:	f100 6000 	add.w	r0, r0, #134217728	; 0x8000000
 8001038:	f500 40c0 	add.w	r0, r0, #24576	; 0x6000
 800103c:	f020 fa78 	bl	8021530 <udrv_flash_write>
 8001040:	2000      	movs	r0, #0
 8001042:	bd08      	pop	{r3, pc}

08001044 <MlmeConfirm_fuota>:
 8001044:	b538      	push	{r3, r4, r5, lr}
 8001046:	4604      	mov	r4, r0
 8001048:	4814      	ldr	r0, [pc, #80]	; (800109c <MlmeConfirm_fuota+0x58>)
 800104a:	f023 ff1f 	bl	8024e8c <UTIL_TIMER_IsRunning>
 800104e:	b938      	cbnz	r0, 8001060 <MlmeConfirm_fuota+0x1c>
 8001050:	7823      	ldrb	r3, [r4, #0]
 8001052:	2b01      	cmp	r3, #1
 8001054:	d011      	beq.n	800107a <MlmeConfirm_fuota+0x36>
 8001056:	4621      	mov	r1, r4
 8001058:	2002      	movs	r0, #2
 800105a:	f7ff ff63 	bl	8000f24 <LmHandlerPackagesNotify>
 800105e:	bd38      	pop	{r3, r4, r5, pc}
 8001060:	4d0e      	ldr	r5, [pc, #56]	; (800109c <MlmeConfirm_fuota+0x58>)
 8001062:	4628      	mov	r0, r5
 8001064:	f023 ff82 	bl	8024f6c <UTIL_TIMER_Stop>
 8001068:	f644 6120 	movw	r1, #20000	; 0x4e20
 800106c:	4628      	mov	r0, r5
 800106e:	f024 f81f 	bl	80250b0 <UTIL_TIMER_SetPeriod>
 8001072:	4628      	mov	r0, r5
 8001074:	f023 ffca 	bl	802500c <UTIL_TIMER_Start>
 8001078:	e7ea      	b.n	8001050 <MlmeConfirm_fuota+0xc>
 800107a:	7863      	ldrb	r3, [r4, #1]
 800107c:	b933      	cbnz	r3, 800108c <MlmeConfirm_fuota+0x48>
 800107e:	4b08      	ldr	r3, [pc, #32]	; (80010a0 <MlmeConfirm_fuota+0x5c>)
 8001080:	2201      	movs	r2, #1
 8001082:	701a      	strb	r2, [r3, #0]
 8001084:	4807      	ldr	r0, [pc, #28]	; (80010a4 <MlmeConfirm_fuota+0x60>)
 8001086:	f7ff fb41 	bl	800070c <Serial_Printf>
 800108a:	e7e4      	b.n	8001056 <MlmeConfirm_fuota+0x12>
 800108c:	4b04      	ldr	r3, [pc, #16]	; (80010a0 <MlmeConfirm_fuota+0x5c>)
 800108e:	2200      	movs	r2, #0
 8001090:	701a      	strb	r2, [r3, #0]
 8001092:	4805      	ldr	r0, [pc, #20]	; (80010a8 <MlmeConfirm_fuota+0x64>)
 8001094:	f7ff fb3a 	bl	800070c <Serial_Printf>
 8001098:	e7dd      	b.n	8001056 <MlmeConfirm_fuota+0x12>
 800109a:	bf00      	nop
 800109c:	20006678 	.word	0x20006678
 80010a0:	20006674 	.word	0x20006674
 80010a4:	08002ad0 	.word	0x08002ad0
 80010a8:	08002ae0 	.word	0x08002ae0

080010ac <McpsIndication_fuota>:
 80010ac:	b538      	push	{r3, r4, r5, lr}
 80010ae:	4604      	mov	r4, r0
 80010b0:	480d      	ldr	r0, [pc, #52]	; (80010e8 <McpsIndication_fuota+0x3c>)
 80010b2:	f023 feeb 	bl	8024e8c <UTIL_TIMER_IsRunning>
 80010b6:	b950      	cbnz	r0, 80010ce <McpsIndication_fuota+0x22>
 80010b8:	7f23      	ldrb	r3, [r4, #28]
 80010ba:	b11b      	cbz	r3, 80010c4 <McpsIndication_fuota+0x18>
 80010bc:	4b0b      	ldr	r3, [pc, #44]	; (80010ec <McpsIndication_fuota+0x40>)
 80010be:	6b5b      	ldr	r3, [r3, #52]	; 0x34
 80010c0:	b103      	cbz	r3, 80010c4 <McpsIndication_fuota+0x18>
 80010c2:	4798      	blx	r3
 80010c4:	4621      	mov	r1, r4
 80010c6:	2001      	movs	r0, #1
 80010c8:	f7ff ff2c 	bl	8000f24 <LmHandlerPackagesNotify>
 80010cc:	bd38      	pop	{r3, r4, r5, pc}
 80010ce:	4d06      	ldr	r5, [pc, #24]	; (80010e8 <McpsIndication_fuota+0x3c>)
 80010d0:	4628      	mov	r0, r5
 80010d2:	f023 ff4b 	bl	8024f6c <UTIL_TIMER_Stop>
 80010d6:	f644 6120 	movw	r1, #20000	; 0x4e20
 80010da:	4628      	mov	r0, r5
 80010dc:	f023 ffe8 	bl	80250b0 <UTIL_TIMER_SetPeriod>
 80010e0:	4628      	mov	r0, r5
 80010e2:	f023 ff93 	bl	802500c <UTIL_TIMER_Start>
 80010e6:	e7e7      	b.n	80010b8 <McpsIndication_fuota+0xc>
 80010e8:	20006678 	.word	0x20006678
 80010ec:	20006000 	.word	0x20006000

080010f0 <bootloader_fuota_stack_init>:
 80010f0:	b508      	push	{r3, lr}
 80010f2:	4806      	ldr	r0, [pc, #24]	; (800110c <bootloader_fuota_stack_init+0x1c>)
 80010f4:	4a06      	ldr	r2, [pc, #24]	; (8001110 <bootloader_fuota_stack_init+0x20>)
 80010f6:	1a12      	subs	r2, r2, r0
 80010f8:	4906      	ldr	r1, [pc, #24]	; (8001114 <bootloader_fuota_stack_init+0x24>)
 80010fa:	f03a fa05 	bl	803b508 <memcpy>
 80010fe:	4806      	ldr	r0, [pc, #24]	; (8001118 <bootloader_fuota_stack_init+0x28>)
 8001100:	4a06      	ldr	r2, [pc, #24]	; (800111c <bootloader_fuota_stack_init+0x2c>)
 8001102:	1a12      	subs	r2, r2, r0
 8001104:	2100      	movs	r1, #0
 8001106:	f7ff f85b 	bl	80001c0 <memset>
 800110a:	bd08      	pop	{r3, pc}
 800110c:	20000000 	.word	0x20000000
 8001110:	200002d0 	.word	0x200002d0
 8001114:	0803c010 	.word	0x0803c010
 8001118:	200002d0 	.word	0x200002d0
 800111c:	20005e98 	.word	0x20005e98

08001120 <fuota_LmHandlerPackageRegister>:
 8001120:	b508      	push	{r3, lr}
 8001122:	4b12      	ldr	r3, [pc, #72]	; (800116c <fuota_LmHandlerPackageRegister+0x4c>)
 8001124:	f843 1020 	str.w	r1, [r3, r0, lsl #2]
 8001128:	4a11      	ldr	r2, [pc, #68]	; (8001170 <fuota_LmHandlerPackageRegister+0x50>)
 800112a:	624a      	str	r2, [r1, #36]	; 0x24
 800112c:	f853 2020 	ldr.w	r2, [r3, r0, lsl #2]
 8001130:	4910      	ldr	r1, [pc, #64]	; (8001174 <fuota_LmHandlerPackageRegister+0x54>)
 8001132:	6291      	str	r1, [r2, #40]	; 0x28
 8001134:	f853 2020 	ldr.w	r2, [r3, r0, lsl #2]
 8001138:	490f      	ldr	r1, [pc, #60]	; (8001178 <fuota_LmHandlerPackageRegister+0x58>)
 800113a:	62d1      	str	r1, [r2, #44]	; 0x2c
 800113c:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 8001140:	4a0e      	ldr	r2, [pc, #56]	; (800117c <fuota_LmHandlerPackageRegister+0x5c>)
 8001142:	631a      	str	r2, [r3, #48]	; 0x30
 8001144:	2803      	cmp	r0, #3
 8001146:	d008      	beq.n	800115a <fuota_LmHandlerPackageRegister+0x3a>
 8001148:	4b08      	ldr	r3, [pc, #32]	; (800116c <fuota_LmHandlerPackageRegister+0x4c>)
 800114a:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 800114e:	685b      	ldr	r3, [r3, #4]
 8001150:	22f2      	movs	r2, #242	; 0xf2
 8001152:	490b      	ldr	r1, [pc, #44]	; (8001180 <fuota_LmHandlerPackageRegister+0x60>)
 8001154:	2000      	movs	r0, #0
 8001156:	4798      	blx	r3
 8001158:	bd08      	pop	{r3, pc}
 800115a:	4b04      	ldr	r3, [pc, #16]	; (800116c <fuota_LmHandlerPackageRegister+0x4c>)
 800115c:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 8001160:	685b      	ldr	r3, [r3, #4]
 8001162:	22f2      	movs	r2, #242	; 0xf2
 8001164:	4906      	ldr	r1, [pc, #24]	; (8001180 <fuota_LmHandlerPackageRegister+0x60>)
 8001166:	4807      	ldr	r0, [pc, #28]	; (8001184 <fuota_LmHandlerPackageRegister+0x64>)
 8001168:	4798      	blx	r3
 800116a:	e7f5      	b.n	8001158 <fuota_LmHandlerPackageRegister+0x38>
 800116c:	200003d0 	.word	0x200003d0
 8001170:	08000f05 	.word	0x08000f05
 8001174:	08000f07 	.word	0x08000f07
 8001178:	08000f09 	.word	0x08000f09
 800117c:	08020021 	.word	0x08020021
 8001180:	2000656c 	.word	0x2000656c
 8001184:	20006038 	.word	0x20006038

08001188 <fuota_LmHandlerRegister>:
 8001188:	b510      	push	{r4, lr}
 800118a:	f01f f963 	bl	8020454 <LmphClockSyncPackageFactory>
 800118e:	4604      	mov	r4, r0
 8001190:	2001      	movs	r0, #1
 8001192:	f01f f859 	bl	8020248 <LmHandlerFuotaStackPackageRegister>
 8001196:	4621      	mov	r1, r4
 8001198:	2001      	movs	r0, #1
 800119a:	f7ff ffc1 	bl	8001120 <fuota_LmHandlerPackageRegister>
 800119e:	f01f fc09 	bl	80209b4 <LmhpRemoteMcastSetupPackageFactory>
 80011a2:	4604      	mov	r4, r0
 80011a4:	2002      	movs	r0, #2
 80011a6:	f01f f84f 	bl	8020248 <LmHandlerFuotaStackPackageRegister>
 80011aa:	4621      	mov	r1, r4
 80011ac:	2002      	movs	r0, #2
 80011ae:	f7ff ffb7 	bl	8001120 <fuota_LmHandlerPackageRegister>
 80011b2:	f01f fe23 	bl	8020dfc <LmhpFragmentationPackageFactory>
 80011b6:	4604      	mov	r4, r0
 80011b8:	2003      	movs	r0, #3
 80011ba:	f01f f845 	bl	8020248 <LmHandlerFuotaStackPackageRegister>
 80011be:	4621      	mov	r1, r4
 80011c0:	2003      	movs	r0, #3
 80011c2:	f7ff ffad 	bl	8001120 <fuota_LmHandlerPackageRegister>
 80011c6:	2000      	movs	r0, #0
 80011c8:	bd10      	pop	{r4, pc}
	...

080011cc <bootloader_fuota_init>:
 80011cc:	b538      	push	{r3, r4, r5, lr}
 80011ce:	4916      	ldr	r1, [pc, #88]	; (8001228 <bootloader_fuota_init+0x5c>)
 80011d0:	4816      	ldr	r0, [pc, #88]	; (800122c <bootloader_fuota_init+0x60>)
 80011d2:	f02f fcd7 	bl	8030b84 <LoRaMacUpdateCallbacks>
 80011d6:	f01e fbc8 	bl	801f96a <service_lora_fuota_get_band>
 80011da:	4c15      	ldr	r4, [pc, #84]	; (8001230 <bootloader_fuota_init+0x64>)
 80011dc:	7020      	strb	r0, [r4, #0]
 80011de:	f020 ff3f 	bl	8022060 <service_nvm_get_adr_from_nvm>
 80011e2:	3800      	subs	r0, #0
 80011e4:	bf18      	it	ne
 80011e6:	2001      	movne	r0, #1
 80011e8:	7060      	strb	r0, [r4, #1]
 80011ea:	f020 ff03 	bl	8021ff4 <service_nvm_get_cfm_from_nvm>
 80011ee:	70a0      	strb	r0, [r4, #2]
 80011f0:	f020 ff5a 	bl	80220a8 <service_nvm_get_dr_from_nvm>
 80011f4:	70e0      	strb	r0, [r4, #3]
 80011f6:	2501      	movs	r5, #1
 80011f8:	7125      	strb	r5, [r4, #4]
 80011fa:	f021 fa89 	bl	8022710 <service_nvm_get_dcs_from_nvm>
 80011fe:	3800      	subs	r0, #0
 8001200:	bf18      	it	ne
 8001202:	2001      	movne	r0, #1
 8001204:	7160      	strb	r0, [r4, #5]
 8001206:	23f2      	movs	r3, #242	; 0xf2
 8001208:	71a3      	strb	r3, [r4, #6]
 800120a:	4b0a      	ldr	r3, [pc, #40]	; (8001234 <bootloader_fuota_init+0x68>)
 800120c:	60a3      	str	r3, [r4, #8]
 800120e:	4621      	mov	r1, r4
 8001210:	4809      	ldr	r0, [pc, #36]	; (8001238 <bootloader_fuota_init+0x6c>)
 8001212:	f01e feb5 	bl	801ff80 <LmHandlerInit>
 8001216:	f7ff ffb7 	bl	8001188 <fuota_LmHandlerRegister>
 800121a:	4808      	ldr	r0, [pc, #32]	; (800123c <bootloader_fuota_init+0x70>)
 800121c:	f01f fee0 	bl	8020fe0 <FragDecoderUpdateCallback>
 8001220:	4b07      	ldr	r3, [pc, #28]	; (8001240 <bootloader_fuota_init+0x74>)
 8001222:	701d      	strb	r5, [r3, #0]
 8001224:	bd38      	pop	{r3, r4, r5, pc}
 8001226:	bf00      	nop
 8001228:	20006048 	.word	0x20006048
 800122c:	20006058 	.word	0x20006058
 8001230:	20006664 	.word	0x20006664
 8001234:	2000656c 	.word	0x2000656c
 8001238:	20006000 	.word	0x20006000
 800123c:	20006038 	.word	0x20006038
 8001240:	2000665f 	.word	0x2000665f

08001244 <fuota_init>:
 8001244:	b510      	push	{r4, lr}
 8001246:	f01d fe68 	bl	801ef1a <BoardInitMcu>
 800124a:	f01e fb65 	bl	801f918 <service_fuota_nvm_init>
 800124e:	f020 fd77 	bl	8021d40 <service_nvm_get_band_from_nvm>
 8001252:	f010 04ff 	ands.w	r4, r0, #255	; 0xff
 8001256:	d035      	beq.n	80012c4 <fuota_init+0x80>
 8001258:	2c14      	cmp	r4, #20
 800125a:	d037      	beq.n	80012cc <fuota_init+0x88>
 800125c:	2c15      	cmp	r4, #21
 800125e:	d039      	beq.n	80012d4 <fuota_init+0x90>
 8001260:	2c16      	cmp	r4, #22
 8001262:	d03b      	beq.n	80012dc <fuota_init+0x98>
 8001264:	f01e fb81 	bl	801f96a <service_lora_fuota_get_band>
 8001268:	b2c2      	uxtb	r2, r0
 800126a:	4921      	ldr	r1, [pc, #132]	; (80012f0 <fuota_init+0xac>)
 800126c:	4821      	ldr	r0, [pc, #132]	; (80012f4 <fuota_init+0xb0>)
 800126e:	f02d fbc5 	bl	802e9fc <LoRaMacInitialization>
 8001272:	bbb8      	cbnz	r0, 80012e4 <fuota_init+0xa0>
 8001274:	f01e fb79 	bl	801f96a <service_lora_fuota_get_band>
 8001278:	4c1f      	ldr	r4, [pc, #124]	; (80012f8 <fuota_init+0xb4>)
 800127a:	7020      	strb	r0, [r4, #0]
 800127c:	f020 fef0 	bl	8022060 <service_nvm_get_adr_from_nvm>
 8001280:	3800      	subs	r0, #0
 8001282:	bf18      	it	ne
 8001284:	2001      	movne	r0, #1
 8001286:	7060      	strb	r0, [r4, #1]
 8001288:	f020 feb4 	bl	8021ff4 <service_nvm_get_cfm_from_nvm>
 800128c:	70a0      	strb	r0, [r4, #2]
 800128e:	f020 ff0b 	bl	80220a8 <service_nvm_get_dr_from_nvm>
 8001292:	70e0      	strb	r0, [r4, #3]
 8001294:	2301      	movs	r3, #1
 8001296:	7123      	strb	r3, [r4, #4]
 8001298:	f021 fa3a 	bl	8022710 <service_nvm_get_dcs_from_nvm>
 800129c:	3800      	subs	r0, #0
 800129e:	bf18      	it	ne
 80012a0:	2001      	movne	r0, #1
 80012a2:	7160      	strb	r0, [r4, #5]
 80012a4:	23f2      	movs	r3, #242	; 0xf2
 80012a6:	71a3      	strb	r3, [r4, #6]
 80012a8:	4b14      	ldr	r3, [pc, #80]	; (80012fc <fuota_init+0xb8>)
 80012aa:	60a3      	str	r3, [r4, #8]
 80012ac:	4621      	mov	r1, r4
 80012ae:	4814      	ldr	r0, [pc, #80]	; (8001300 <fuota_init+0xbc>)
 80012b0:	f01e fe66 	bl	801ff80 <LmHandlerInit>
 80012b4:	f7ff ff68 	bl	8001188 <fuota_LmHandlerRegister>
 80012b8:	f01e fb62 	bl	801f980 <service_fuota_lora_config>
 80012bc:	f02d fd7a 	bl	802edb4 <LoRaMacStart>
 80012c0:	2000      	movs	r0, #0
 80012c2:	bd10      	pop	{r4, pc}
 80012c4:	2001      	movs	r0, #1
 80012c6:	f031 ff6b 	bl	80331a0 <RegionAS923SubBandSet>
 80012ca:	e7c5      	b.n	8001258 <fuota_init+0x14>
 80012cc:	2002      	movs	r0, #2
 80012ce:	f031 ff67 	bl	80331a0 <RegionAS923SubBandSet>
 80012d2:	e7c3      	b.n	800125c <fuota_init+0x18>
 80012d4:	2003      	movs	r0, #3
 80012d6:	f031 ff63 	bl	80331a0 <RegionAS923SubBandSet>
 80012da:	e7c1      	b.n	8001260 <fuota_init+0x1c>
 80012dc:	2004      	movs	r0, #4
 80012de:	f031 ff5f 	bl	80331a0 <RegionAS923SubBandSet>
 80012e2:	e7bf      	b.n	8001264 <fuota_init+0x20>
 80012e4:	4807      	ldr	r0, [pc, #28]	; (8001304 <fuota_init+0xc0>)
 80012e6:	f7ff f9e7 	bl	80006b8 <Serial_PutString>
 80012ea:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
 80012ee:	e7e8      	b.n	80012c2 <fuota_init+0x7e>
 80012f0:	20006048 	.word	0x20006048
 80012f4:	20006058 	.word	0x20006058
 80012f8:	20006664 	.word	0x20006664
 80012fc:	2000656c 	.word	0x2000656c
 8001300:	20006000 	.word	0x20006000
 8001304:	08002af4 	.word	0x08002af4

08001308 <bootloader_fuota_start>:
 8001308:	b510      	push	{r4, lr}
 800130a:	b084      	sub	sp, #16
 800130c:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 8001310:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 8001312:	f042 0204 	orr.w	r2, r2, #4
 8001316:	649a      	str	r2, [r3, #72]	; 0x48
 8001318:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 800131a:	f002 0204 	and.w	r2, r2, #4
 800131e:	9203      	str	r2, [sp, #12]
 8001320:	9a03      	ldr	r2, [sp, #12]
 8001322:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 8001324:	f042 0201 	orr.w	r2, r2, #1
 8001328:	649a      	str	r2, [r3, #72]	; 0x48
 800132a:	6c9b      	ldr	r3, [r3, #72]	; 0x48
 800132c:	f003 0301 	and.w	r3, r3, #1
 8001330:	9302      	str	r3, [sp, #8]
 8001332:	9b02      	ldr	r3, [sp, #8]
 8001334:	2200      	movs	r2, #0
 8001336:	4611      	mov	r1, r2
 8001338:	200b      	movs	r0, #11
 800133a:	f021 fd6f 	bl	8022e1c <HAL_NVIC_SetPriority>
 800133e:	200b      	movs	r0, #11
 8001340:	f021 fd9e 	bl	8022e80 <HAL_NVIC_EnableIRQ>
 8001344:	f023 fd72 	bl	8024e2c <UTIL_TIMER_Init>
 8001348:	f7ff ff7c 	bl	8001244 <fuota_init>
 800134c:	f01e faee 	bl	801f92c <service_lora_fuota_join>
 8001350:	4c09      	ldr	r4, [pc, #36]	; (8001378 <bootloader_fuota_start+0x70>)
 8001352:	2300      	movs	r3, #0
 8001354:	9300      	str	r3, [sp, #0]
 8001356:	4b09      	ldr	r3, [pc, #36]	; (800137c <bootloader_fuota_start+0x74>)
 8001358:	2201      	movs	r2, #1
 800135a:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
 800135e:	4620      	mov	r0, r4
 8001360:	f023 fd74 	bl	8024e4c <UTIL_TIMER_Create>
 8001364:	f644 6120 	movw	r1, #20000	; 0x4e20
 8001368:	4620      	mov	r0, r4
 800136a:	f023 fea1 	bl	80250b0 <UTIL_TIMER_SetPeriod>
 800136e:	4620      	mov	r0, r4
 8001370:	f023 fe4c 	bl	802500c <UTIL_TIMER_Start>
 8001374:	b004      	add	sp, #16
 8001376:	bd10      	pop	{r4, pc}
 8001378:	20006678 	.word	0x20006678
 800137c:	0800148d 	.word	0x0800148d

08001380 <OnClassChange>:
 8001380:	b500      	push	{lr}
 8001382:	b083      	sub	sp, #12
 8001384:	2801      	cmp	r0, #1
 8001386:	d013      	beq.n	80013b0 <OnClassChange+0x30>
 8001388:	2802      	cmp	r0, #2
 800138a:	d023      	beq.n	80013d4 <OnClassChange+0x54>
 800138c:	4b15      	ldr	r3, [pc, #84]	; (80013e4 <OnClassChange+0x64>)
 800138e:	2200      	movs	r2, #0
 8001390:	701a      	strb	r2, [r3, #0]
 8001392:	4b15      	ldr	r3, [pc, #84]	; (80013e8 <OnClassChange+0x68>)
 8001394:	781b      	ldrb	r3, [r3, #0]
 8001396:	b9d3      	cbnz	r3, 80013ce <OnClassChange+0x4e>
 8001398:	4814      	ldr	r0, [pc, #80]	; (80013ec <OnClassChange+0x6c>)
 800139a:	f7ff f9b7 	bl	800070c <Serial_Printf>
 800139e:	4814      	ldr	r0, [pc, #80]	; (80013f0 <OnClassChange+0x70>)
 80013a0:	f7ff f9b4 	bl	800070c <Serial_Printf>
 80013a4:	f7ff ffb0 	bl	8001308 <bootloader_fuota_start>
 80013a8:	4b12      	ldr	r3, [pc, #72]	; (80013f4 <OnClassChange+0x74>)
 80013aa:	2201      	movs	r2, #1
 80013ac:	701a      	strb	r2, [r3, #0]
 80013ae:	e00e      	b.n	80013ce <OnClassChange+0x4e>
 80013b0:	2100      	movs	r1, #0
 80013b2:	f88d 1000 	strb.w	r1, [sp]
 80013b6:	f88d 1001 	strb.w	r1, [sp, #1]
 80013ba:	9101      	str	r1, [sp, #4]
 80013bc:	4668      	mov	r0, sp
 80013be:	f01e fbdf 	bl	801fb80 <LmHandlerSend>
 80013c2:	4b08      	ldr	r3, [pc, #32]	; (80013e4 <OnClassChange+0x64>)
 80013c4:	2201      	movs	r2, #1
 80013c6:	701a      	strb	r2, [r3, #0]
 80013c8:	480b      	ldr	r0, [pc, #44]	; (80013f8 <OnClassChange+0x78>)
 80013ca:	f7ff f99f 	bl	800070c <Serial_Printf>
 80013ce:	b003      	add	sp, #12
 80013d0:	f85d fb04 	ldr.w	pc, [sp], #4
 80013d4:	4b03      	ldr	r3, [pc, #12]	; (80013e4 <OnClassChange+0x64>)
 80013d6:	2201      	movs	r2, #1
 80013d8:	701a      	strb	r2, [r3, #0]
 80013da:	4808      	ldr	r0, [pc, #32]	; (80013fc <OnClassChange+0x7c>)
 80013dc:	f7ff f996 	bl	800070c <Serial_Printf>
 80013e0:	e7f5      	b.n	80013ce <OnClassChange+0x4e>
 80013e2:	bf00      	nop
 80013e4:	2000665f 	.word	0x2000665f
 80013e8:	2000665e 	.word	0x2000665e
 80013ec:	08002b14 	.word	0x08002b14
 80013f0:	08002b24 	.word	0x08002b24
 80013f4:	20006085 	.word	0x20006085
 80013f8:	08002b34 	.word	0x08002b34
 80013fc:	08002b48 	.word	0x08002b48

08001400 <UplinkProcess>:
 8001400:	b500      	push	{lr}
 8001402:	b083      	sub	sp, #12
 8001404:	f01e fdc6 	bl	801ff94 <LmHandlerIsBusy>
 8001408:	b930      	cbnz	r0, 8001418 <UplinkProcess+0x18>
 800140a:	4a18      	ldr	r2, [pc, #96]	; (800146c <UplinkProcess+0x6c>)
 800140c:	7813      	ldrb	r3, [r2, #0]
 800140e:	b2db      	uxtb	r3, r3
 8001410:	2100      	movs	r1, #0
 8001412:	7011      	strb	r1, [r2, #0]
 8001414:	2b01      	cmp	r3, #1
 8001416:	d002      	beq.n	800141e <UplinkProcess+0x1e>
 8001418:	b003      	add	sp, #12
 800141a:	f85d fb04 	ldr.w	pc, [sp], #4
 800141e:	4b14      	ldr	r3, [pc, #80]	; (8001470 <UplinkProcess+0x70>)
 8001420:	781b      	ldrb	r3, [r3, #0]
 8001422:	2b00      	cmp	r3, #0
 8001424:	d1f8      	bne.n	8001418 <UplinkProcess+0x18>
 8001426:	4b13      	ldr	r3, [pc, #76]	; (8001474 <UplinkProcess+0x74>)
 8001428:	781b      	ldrb	r3, [r3, #0]
 800142a:	b9cb      	cbnz	r3, 8001460 <UplinkProcess+0x60>
 800142c:	4b12      	ldr	r3, [pc, #72]	; (8001478 <UplinkProcess+0x78>)
 800142e:	781b      	ldrb	r3, [r3, #0]
 8001430:	b913      	cbnz	r3, 8001438 <UplinkProcess+0x38>
 8001432:	f01f f813 	bl	802045c <LmhpClockSyncAppTimeReq>
 8001436:	e7ef      	b.n	8001418 <UplinkProcess+0x18>
 8001438:	21ff      	movs	r1, #255	; 0xff
 800143a:	2000      	movs	r0, #0
 800143c:	f02b fae0 	bl	802ca00 <randr>
 8001440:	4b0e      	ldr	r3, [pc, #56]	; (800147c <UplinkProcess+0x7c>)
 8001442:	7018      	strb	r0, [r3, #0]
 8001444:	480e      	ldr	r0, [pc, #56]	; (8001480 <UplinkProcess+0x80>)
 8001446:	f7ff f937 	bl	80006b8 <Serial_PutString>
 800144a:	4a0e      	ldr	r2, [pc, #56]	; (8001484 <UplinkProcess+0x84>)
 800144c:	466b      	mov	r3, sp
 800144e:	e892 0003 	ldmia.w	r2, {r0, r1}
 8001452:	e883 0003 	stmia.w	r3, {r0, r1}
 8001456:	2100      	movs	r1, #0
 8001458:	4618      	mov	r0, r3
 800145a:	f01e fb91 	bl	801fb80 <LmHandlerSend>
 800145e:	e7db      	b.n	8001418 <UplinkProcess+0x18>
 8001460:	4809      	ldr	r0, [pc, #36]	; (8001488 <UplinkProcess+0x88>)
 8001462:	f7ff f929 	bl	80006b8 <Serial_PutString>
 8001466:	f7ff fd39 	bl	8000edc <__NVIC_SystemReset>
 800146a:	bf00      	nop
 800146c:	20006660 	.word	0x20006660
 8001470:	2000665f 	.word	0x2000665f
 8001474:	2000665e 	.word	0x2000665e
 8001478:	200002e4 	.word	0x200002e4
 800147c:	2000656c 	.word	0x2000656c
 8001480:	08002b5c 	.word	0x08002b5c
 8001484:	08002910 	.word	0x08002910
 8001488:	08002b70 	.word	0x08002b70

0800148c <timer_callback>:
 800148c:	b508      	push	{r3, lr}
 800148e:	f02c fecd 	bl	802e22c <LoRaMacIsBusy>
 8001492:	b988      	cbnz	r0, 80014b8 <timer_callback+0x2c>
 8001494:	4b09      	ldr	r3, [pc, #36]	; (80014bc <timer_callback+0x30>)
 8001496:	781b      	ldrb	r3, [r3, #0]
 8001498:	b14b      	cbz	r3, 80014ae <timer_callback+0x22>
 800149a:	4b09      	ldr	r3, [pc, #36]	; (80014c0 <timer_callback+0x34>)
 800149c:	2201      	movs	r2, #1
 800149e:	701a      	strb	r2, [r3, #0]
 80014a0:	4b08      	ldr	r3, [pc, #32]	; (80014c4 <timer_callback+0x38>)
 80014a2:	781b      	ldrb	r3, [r3, #0]
 80014a4:	4293      	cmp	r3, r2
 80014a6:	d107      	bne.n	80014b8 <timer_callback+0x2c>
 80014a8:	f7ff ffaa 	bl	8001400 <UplinkProcess>
 80014ac:	e004      	b.n	80014b8 <timer_callback+0x2c>
 80014ae:	4806      	ldr	r0, [pc, #24]	; (80014c8 <timer_callback+0x3c>)
 80014b0:	f7ff f902 	bl	80006b8 <Serial_PutString>
 80014b4:	f01e fa3a 	bl	801f92c <service_lora_fuota_join>
 80014b8:	bd08      	pop	{r3, pc}
 80014ba:	bf00      	nop
 80014bc:	20006674 	.word	0x20006674
 80014c0:	20006660 	.word	0x20006660
 80014c4:	20006085 	.word	0x20006085
 80014c8:	08002b90 	.word	0x08002b90

080014cc <UART_EndRxTransfer>:
 80014cc:	6802      	ldr	r2, [r0, #0]
 80014ce:	e852 3f00 	ldrex	r3, [r2]
 80014d2:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 80014d6:	e842 3100 	strex	r1, r3, [r2]
 80014da:	2900      	cmp	r1, #0
 80014dc:	d1f6      	bne.n	80014cc <UART_EndRxTransfer>
 80014de:	6802      	ldr	r2, [r0, #0]
 80014e0:	f102 0308 	add.w	r3, r2, #8
 80014e4:	e853 3f00 	ldrex	r3, [r3]
 80014e8:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 80014ec:	f023 0301 	bic.w	r3, r3, #1
 80014f0:	3208      	adds	r2, #8
 80014f2:	e842 3100 	strex	r1, r3, [r2]
 80014f6:	2900      	cmp	r1, #0
 80014f8:	d1f1      	bne.n	80014de <UART_EndRxTransfer+0x12>
 80014fa:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 80014fc:	2b01      	cmp	r3, #1
 80014fe:	d006      	beq.n	800150e <UART_EndRxTransfer+0x42>
 8001500:	2320      	movs	r3, #32
 8001502:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001506:	2300      	movs	r3, #0
 8001508:	66c3      	str	r3, [r0, #108]	; 0x6c
 800150a:	6703      	str	r3, [r0, #112]	; 0x70
 800150c:	4770      	bx	lr
 800150e:	6802      	ldr	r2, [r0, #0]
 8001510:	e852 3f00 	ldrex	r3, [r2]
 8001514:	f023 0310 	bic.w	r3, r3, #16
 8001518:	e842 3100 	strex	r1, r3, [r2]
 800151c:	2900      	cmp	r1, #0
 800151e:	d1f6      	bne.n	800150e <UART_EndRxTransfer+0x42>
 8001520:	e7ee      	b.n	8001500 <UART_EndRxTransfer+0x34>

08001522 <HAL_UART_DeInit>:
 8001522:	b1e8      	cbz	r0, 8001560 <HAL_UART_DeInit+0x3e>
 8001524:	b538      	push	{r3, r4, r5, lr}
 8001526:	4605      	mov	r5, r0
 8001528:	2324      	movs	r3, #36	; 0x24
 800152a:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 800152e:	6802      	ldr	r2, [r0, #0]
 8001530:	6813      	ldr	r3, [r2, #0]
 8001532:	f023 0301 	bic.w	r3, r3, #1
 8001536:	6013      	str	r3, [r2, #0]
 8001538:	6803      	ldr	r3, [r0, #0]
 800153a:	2400      	movs	r4, #0
 800153c:	601c      	str	r4, [r3, #0]
 800153e:	6803      	ldr	r3, [r0, #0]
 8001540:	605c      	str	r4, [r3, #4]
 8001542:	6803      	ldr	r3, [r0, #0]
 8001544:	609c      	str	r4, [r3, #8]
 8001546:	f7ff faf1 	bl	8000b2c <HAL_UART_MspDeInit>
 800154a:	f8c5 408c 	str.w	r4, [r5, #140]	; 0x8c
 800154e:	f8c5 4084 	str.w	r4, [r5, #132]	; 0x84
 8001552:	f8c5 4088 	str.w	r4, [r5, #136]	; 0x88
 8001556:	66ec      	str	r4, [r5, #108]	; 0x6c
 8001558:	f885 4080 	strb.w	r4, [r5, #128]	; 0x80
 800155c:	4620      	mov	r0, r4
 800155e:	bd38      	pop	{r3, r4, r5, pc}
 8001560:	2001      	movs	r0, #1
 8001562:	4770      	bx	lr

08001564 <HAL_UART_TxCpltCallback>:
 8001564:	4770      	bx	lr

08001566 <UART_EndTransmit_IT>:
 8001566:	b508      	push	{r3, lr}
 8001568:	6802      	ldr	r2, [r0, #0]
 800156a:	e852 3f00 	ldrex	r3, [r2]
 800156e:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 8001572:	e842 3100 	strex	r1, r3, [r2]
 8001576:	2900      	cmp	r1, #0
 8001578:	d1f6      	bne.n	8001568 <UART_EndTransmit_IT+0x2>
 800157a:	2320      	movs	r3, #32
 800157c:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8001580:	2300      	movs	r3, #0
 8001582:	6743      	str	r3, [r0, #116]	; 0x74
 8001584:	f7ff ffee 	bl	8001564 <HAL_UART_TxCpltCallback>
 8001588:	bd08      	pop	{r3, pc}

0800158a <HAL_UART_ErrorCallback>:
 800158a:	4770      	bx	lr

0800158c <UART_DMAAbortOnError>:
 800158c:	b508      	push	{r3, lr}
 800158e:	6a80      	ldr	r0, [r0, #40]	; 0x28
 8001590:	2300      	movs	r3, #0
 8001592:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 8001596:	f8a0 3056 	strh.w	r3, [r0, #86]	; 0x56
 800159a:	f7ff fff6 	bl	800158a <HAL_UART_ErrorCallback>
 800159e:	bd08      	pop	{r3, pc}

080015a0 <HAL_UART_AbortReceiveCpltCallback>:
 80015a0:	4770      	bx	lr
	...

080015a4 <HAL_UART_AbortReceive_IT>:
 80015a4:	b510      	push	{r4, lr}
 80015a6:	4604      	mov	r4, r0
 80015a8:	6822      	ldr	r2, [r4, #0]
 80015aa:	e852 3f00 	ldrex	r3, [r2]
 80015ae:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 80015b2:	e842 3100 	strex	r1, r3, [r2]
 80015b6:	2900      	cmp	r1, #0
 80015b8:	d1f6      	bne.n	80015a8 <HAL_UART_AbortReceive_IT+0x4>
 80015ba:	6822      	ldr	r2, [r4, #0]
 80015bc:	f102 0308 	add.w	r3, r2, #8
 80015c0:	e853 3f00 	ldrex	r3, [r3]
 80015c4:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 80015c8:	f023 0301 	bic.w	r3, r3, #1
 80015cc:	3208      	adds	r2, #8
 80015ce:	e842 3100 	strex	r1, r3, [r2]
 80015d2:	2900      	cmp	r1, #0
 80015d4:	d1f1      	bne.n	80015ba <HAL_UART_AbortReceive_IT+0x16>
 80015d6:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 80015d8:	2b01      	cmp	r3, #1
 80015da:	d01c      	beq.n	8001616 <HAL_UART_AbortReceive_IT+0x72>
 80015dc:	6823      	ldr	r3, [r4, #0]
 80015de:	689a      	ldr	r2, [r3, #8]
 80015e0:	f012 0f40 	tst.w	r2, #64	; 0x40
 80015e4:	d035      	beq.n	8001652 <HAL_UART_AbortReceive_IT+0xae>
 80015e6:	6822      	ldr	r2, [r4, #0]
 80015e8:	f102 0308 	add.w	r3, r2, #8
 80015ec:	e853 3f00 	ldrex	r3, [r3]
 80015f0:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 80015f4:	3208      	adds	r2, #8
 80015f6:	e842 3100 	strex	r1, r3, [r2]
 80015fa:	2900      	cmp	r1, #0
 80015fc:	d1f3      	bne.n	80015e6 <HAL_UART_AbortReceive_IT+0x42>
 80015fe:	6fe3      	ldr	r3, [r4, #124]	; 0x7c
 8001600:	b19b      	cbz	r3, 800162a <HAL_UART_AbortReceive_IT+0x86>
 8001602:	4a1b      	ldr	r2, [pc, #108]	; (8001670 <HAL_UART_AbortReceive_IT+0xcc>)
 8001604:	639a      	str	r2, [r3, #56]	; 0x38
 8001606:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 8001608:	f02b f86a 	bl	802c6e0 <HAL_DMA_Abort_IT>
 800160c:	b370      	cbz	r0, 800166c <HAL_UART_AbortReceive_IT+0xc8>
 800160e:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 8001610:	6b83      	ldr	r3, [r0, #56]	; 0x38
 8001612:	4798      	blx	r3
 8001614:	e02a      	b.n	800166c <HAL_UART_AbortReceive_IT+0xc8>
 8001616:	6822      	ldr	r2, [r4, #0]
 8001618:	e852 3f00 	ldrex	r3, [r2]
 800161c:	f023 0310 	bic.w	r3, r3, #16
 8001620:	e842 3100 	strex	r1, r3, [r2]
 8001624:	2900      	cmp	r1, #0
 8001626:	d1f6      	bne.n	8001616 <HAL_UART_AbortReceive_IT+0x72>
 8001628:	e7d8      	b.n	80015dc <HAL_UART_AbortReceive_IT+0x38>
 800162a:	2300      	movs	r3, #0
 800162c:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001630:	65a3      	str	r3, [r4, #88]	; 0x58
 8001632:	6822      	ldr	r2, [r4, #0]
 8001634:	210f      	movs	r1, #15
 8001636:	6211      	str	r1, [r2, #32]
 8001638:	6821      	ldr	r1, [r4, #0]
 800163a:	698a      	ldr	r2, [r1, #24]
 800163c:	f042 0208 	orr.w	r2, r2, #8
 8001640:	618a      	str	r2, [r1, #24]
 8001642:	2220      	movs	r2, #32
 8001644:	f8c4 2088 	str.w	r2, [r4, #136]	; 0x88
 8001648:	66e3      	str	r3, [r4, #108]	; 0x6c
 800164a:	4620      	mov	r0, r4
 800164c:	f7ff ffa8 	bl	80015a0 <HAL_UART_AbortReceiveCpltCallback>
 8001650:	e00c      	b.n	800166c <HAL_UART_AbortReceive_IT+0xc8>
 8001652:	2200      	movs	r2, #0
 8001654:	f8a4 205e 	strh.w	r2, [r4, #94]	; 0x5e
 8001658:	65a2      	str	r2, [r4, #88]	; 0x58
 800165a:	210f      	movs	r1, #15
 800165c:	6219      	str	r1, [r3, #32]
 800165e:	2320      	movs	r3, #32
 8001660:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001664:	66e2      	str	r2, [r4, #108]	; 0x6c
 8001666:	4620      	mov	r0, r4
 8001668:	f7ff ff9a 	bl	80015a0 <HAL_UART_AbortReceiveCpltCallback>
 800166c:	2000      	movs	r0, #0
 800166e:	bd10      	pop	{r4, pc}
 8001670:	08001675 	.word	0x08001675

08001674 <UART_DMARxOnlyAbortCallback>:
 8001674:	b508      	push	{r3, lr}
 8001676:	6a80      	ldr	r0, [r0, #40]	; 0x28
 8001678:	2200      	movs	r2, #0
 800167a:	f8a0 205e 	strh.w	r2, [r0, #94]	; 0x5e
 800167e:	6803      	ldr	r3, [r0, #0]
 8001680:	210f      	movs	r1, #15
 8001682:	6219      	str	r1, [r3, #32]
 8001684:	6801      	ldr	r1, [r0, #0]
 8001686:	698b      	ldr	r3, [r1, #24]
 8001688:	f043 0308 	orr.w	r3, r3, #8
 800168c:	618b      	str	r3, [r1, #24]
 800168e:	2320      	movs	r3, #32
 8001690:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001694:	66c2      	str	r2, [r0, #108]	; 0x6c
 8001696:	f7ff ff83 	bl	80015a0 <HAL_UART_AbortReceiveCpltCallback>
 800169a:	bd08      	pop	{r3, pc}

0800169c <HAL_UARTEx_RxEventCallback>:
 800169c:	4770      	bx	lr
	...

080016a0 <HAL_UART_IRQHandler>:
 80016a0:	b570      	push	{r4, r5, r6, lr}
 80016a2:	4604      	mov	r4, r0
 80016a4:	6801      	ldr	r1, [r0, #0]
 80016a6:	69cb      	ldr	r3, [r1, #28]
 80016a8:	6808      	ldr	r0, [r1, #0]
 80016aa:	688d      	ldr	r5, [r1, #8]
 80016ac:	f640 020f 	movw	r2, #2063	; 0x80f
 80016b0:	401a      	ands	r2, r3
 80016b2:	d108      	bne.n	80016c6 <HAL_UART_IRQHandler+0x26>
 80016b4:	f013 0f20 	tst.w	r3, #32
 80016b8:	d005      	beq.n	80016c6 <HAL_UART_IRQHandler+0x26>
 80016ba:	f010 0f20 	tst.w	r0, #32
 80016be:	d134      	bne.n	800172a <HAL_UART_IRQHandler+0x8a>
 80016c0:	f015 5f80 	tst.w	r5, #268435456	; 0x10000000
 80016c4:	d131      	bne.n	800172a <HAL_UART_IRQHandler+0x8a>
 80016c6:	b12a      	cbz	r2, 80016d4 <HAL_UART_IRQHandler+0x34>
 80016c8:	4a95      	ldr	r2, [pc, #596]	; (8001920 <HAL_UART_IRQHandler+0x280>)
 80016ca:	402a      	ands	r2, r5
 80016cc:	d133      	bne.n	8001736 <HAL_UART_IRQHandler+0x96>
 80016ce:	4e95      	ldr	r6, [pc, #596]	; (8001924 <HAL_UART_IRQHandler+0x284>)
 80016d0:	4230      	tst	r0, r6
 80016d2:	d130      	bne.n	8001736 <HAL_UART_IRQHandler+0x96>
 80016d4:	6ee2      	ldr	r2, [r4, #108]	; 0x6c
 80016d6:	2a01      	cmp	r2, #1
 80016d8:	f000 80c3 	beq.w	8001862 <HAL_UART_IRQHandler+0x1c2>
 80016dc:	f413 1f80 	tst.w	r3, #1048576	; 0x100000
 80016e0:	d003      	beq.n	80016ea <HAL_UART_IRQHandler+0x4a>
 80016e2:	f415 0f80 	tst.w	r5, #4194304	; 0x400000
 80016e6:	f040 815b 	bne.w	80019a0 <HAL_UART_IRQHandler+0x300>
 80016ea:	f013 0f80 	tst.w	r3, #128	; 0x80
 80016ee:	d007      	beq.n	8001700 <HAL_UART_IRQHandler+0x60>
 80016f0:	f010 0f80 	tst.w	r0, #128	; 0x80
 80016f4:	f040 815b 	bne.w	80019ae <HAL_UART_IRQHandler+0x30e>
 80016f8:	f415 0f00 	tst.w	r5, #8388608	; 0x800000
 80016fc:	f040 8157 	bne.w	80019ae <HAL_UART_IRQHandler+0x30e>
 8001700:	f013 0f40 	tst.w	r3, #64	; 0x40
 8001704:	d003      	beq.n	800170e <HAL_UART_IRQHandler+0x6e>
 8001706:	f010 0f40 	tst.w	r0, #64	; 0x40
 800170a:	f040 8157 	bne.w	80019bc <HAL_UART_IRQHandler+0x31c>
 800170e:	f413 0f00 	tst.w	r3, #8388608	; 0x800000
 8001712:	d003      	beq.n	800171c <HAL_UART_IRQHandler+0x7c>
 8001714:	f010 4f80 	tst.w	r0, #1073741824	; 0x40000000
 8001718:	f040 8154 	bne.w	80019c4 <HAL_UART_IRQHandler+0x324>
 800171c:	f013 7f80 	tst.w	r3, #16777216	; 0x1000000
 8001720:	d002      	beq.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001722:	2800      	cmp	r0, #0
 8001724:	f2c0 8152 	blt.w	80019cc <HAL_UART_IRQHandler+0x32c>
 8001728:	bd70      	pop	{r4, r5, r6, pc}
 800172a:	6f23      	ldr	r3, [r4, #112]	; 0x70
 800172c:	2b00      	cmp	r3, #0
 800172e:	d0fb      	beq.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001730:	4620      	mov	r0, r4
 8001732:	4798      	blx	r3
 8001734:	e7f8      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001736:	f013 0f01 	tst.w	r3, #1
 800173a:	d009      	beq.n	8001750 <HAL_UART_IRQHandler+0xb0>
 800173c:	f410 7f80 	tst.w	r0, #256	; 0x100
 8001740:	d006      	beq.n	8001750 <HAL_UART_IRQHandler+0xb0>
 8001742:	2601      	movs	r6, #1
 8001744:	620e      	str	r6, [r1, #32]
 8001746:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 800174a:	4331      	orrs	r1, r6
 800174c:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 8001750:	f013 0f02 	tst.w	r3, #2
 8001754:	d00b      	beq.n	800176e <HAL_UART_IRQHandler+0xce>
 8001756:	f015 0f01 	tst.w	r5, #1
 800175a:	d008      	beq.n	800176e <HAL_UART_IRQHandler+0xce>
 800175c:	6821      	ldr	r1, [r4, #0]
 800175e:	2602      	movs	r6, #2
 8001760:	620e      	str	r6, [r1, #32]
 8001762:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 8001766:	f041 0104 	orr.w	r1, r1, #4
 800176a:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 800176e:	f013 0f04 	tst.w	r3, #4
 8001772:	d00b      	beq.n	800178c <HAL_UART_IRQHandler+0xec>
 8001774:	f015 0f01 	tst.w	r5, #1
 8001778:	d008      	beq.n	800178c <HAL_UART_IRQHandler+0xec>
 800177a:	6821      	ldr	r1, [r4, #0]
 800177c:	2604      	movs	r6, #4
 800177e:	620e      	str	r6, [r1, #32]
 8001780:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 8001784:	f041 0102 	orr.w	r1, r1, #2
 8001788:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 800178c:	f013 0f08 	tst.w	r3, #8
 8001790:	d00b      	beq.n	80017aa <HAL_UART_IRQHandler+0x10a>
 8001792:	f010 0f20 	tst.w	r0, #32
 8001796:	d100      	bne.n	800179a <HAL_UART_IRQHandler+0xfa>
 8001798:	b13a      	cbz	r2, 80017aa <HAL_UART_IRQHandler+0x10a>
 800179a:	6822      	ldr	r2, [r4, #0]
 800179c:	2108      	movs	r1, #8
 800179e:	6211      	str	r1, [r2, #32]
 80017a0:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 80017a4:	430a      	orrs	r2, r1
 80017a6:	f8c4 208c 	str.w	r2, [r4, #140]	; 0x8c
 80017aa:	f413 6f00 	tst.w	r3, #2048	; 0x800
 80017ae:	d00c      	beq.n	80017ca <HAL_UART_IRQHandler+0x12a>
 80017b0:	f010 6f80 	tst.w	r0, #67108864	; 0x4000000
 80017b4:	d009      	beq.n	80017ca <HAL_UART_IRQHandler+0x12a>
 80017b6:	6822      	ldr	r2, [r4, #0]
 80017b8:	f44f 6100 	mov.w	r1, #2048	; 0x800
 80017bc:	6211      	str	r1, [r2, #32]
 80017be:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 80017c2:	f042 0220 	orr.w	r2, r2, #32
 80017c6:	f8c4 208c 	str.w	r2, [r4, #140]	; 0x8c
 80017ca:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 80017ce:	2a00      	cmp	r2, #0
 80017d0:	d0aa      	beq.n	8001728 <HAL_UART_IRQHandler+0x88>
 80017d2:	f013 0f20 	tst.w	r3, #32
 80017d6:	d009      	beq.n	80017ec <HAL_UART_IRQHandler+0x14c>
 80017d8:	f010 0f20 	tst.w	r0, #32
 80017dc:	d102      	bne.n	80017e4 <HAL_UART_IRQHandler+0x144>
 80017de:	f015 5f80 	tst.w	r5, #268435456	; 0x10000000
 80017e2:	d003      	beq.n	80017ec <HAL_UART_IRQHandler+0x14c>
 80017e4:	6f23      	ldr	r3, [r4, #112]	; 0x70
 80017e6:	b10b      	cbz	r3, 80017ec <HAL_UART_IRQHandler+0x14c>
 80017e8:	4620      	mov	r0, r4
 80017ea:	4798      	blx	r3
 80017ec:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 80017f0:	6823      	ldr	r3, [r4, #0]
 80017f2:	689b      	ldr	r3, [r3, #8]
 80017f4:	f013 0f40 	tst.w	r3, #64	; 0x40
 80017f8:	d102      	bne.n	8001800 <HAL_UART_IRQHandler+0x160>
 80017fa:	f012 0f28 	tst.w	r2, #40	; 0x28
 80017fe:	d029      	beq.n	8001854 <HAL_UART_IRQHandler+0x1b4>
 8001800:	4620      	mov	r0, r4
 8001802:	f7ff fe63 	bl	80014cc <UART_EndRxTransfer>
 8001806:	6823      	ldr	r3, [r4, #0]
 8001808:	689b      	ldr	r3, [r3, #8]
 800180a:	f013 0f40 	tst.w	r3, #64	; 0x40
 800180e:	d01d      	beq.n	800184c <HAL_UART_IRQHandler+0x1ac>
 8001810:	6822      	ldr	r2, [r4, #0]
 8001812:	f102 0308 	add.w	r3, r2, #8
 8001816:	e853 3f00 	ldrex	r3, [r3]
 800181a:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 800181e:	3208      	adds	r2, #8
 8001820:	e842 3100 	strex	r1, r3, [r2]
 8001824:	2900      	cmp	r1, #0
 8001826:	d1f3      	bne.n	8001810 <HAL_UART_IRQHandler+0x170>
 8001828:	6fe3      	ldr	r3, [r4, #124]	; 0x7c
 800182a:	b15b      	cbz	r3, 8001844 <HAL_UART_IRQHandler+0x1a4>
 800182c:	4a3e      	ldr	r2, [pc, #248]	; (8001928 <HAL_UART_IRQHandler+0x288>)
 800182e:	639a      	str	r2, [r3, #56]	; 0x38
 8001830:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 8001832:	f02a ff55 	bl	802c6e0 <HAL_DMA_Abort_IT>
 8001836:	2800      	cmp	r0, #0
 8001838:	f43f af76 	beq.w	8001728 <HAL_UART_IRQHandler+0x88>
 800183c:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 800183e:	6b83      	ldr	r3, [r0, #56]	; 0x38
 8001840:	4798      	blx	r3
 8001842:	e771      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001844:	4620      	mov	r0, r4
 8001846:	f7ff fea0 	bl	800158a <HAL_UART_ErrorCallback>
 800184a:	e76d      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 800184c:	4620      	mov	r0, r4
 800184e:	f7ff fe9c 	bl	800158a <HAL_UART_ErrorCallback>
 8001852:	e769      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001854:	4620      	mov	r0, r4
 8001856:	f7ff fe98 	bl	800158a <HAL_UART_ErrorCallback>
 800185a:	2300      	movs	r3, #0
 800185c:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001860:	e762      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001862:	f013 0f10 	tst.w	r3, #16
 8001866:	f43f af39 	beq.w	80016dc <HAL_UART_IRQHandler+0x3c>
 800186a:	f010 0f10 	tst.w	r0, #16
 800186e:	f43f af35 	beq.w	80016dc <HAL_UART_IRQHandler+0x3c>
 8001872:	2310      	movs	r3, #16
 8001874:	620b      	str	r3, [r1, #32]
 8001876:	6823      	ldr	r3, [r4, #0]
 8001878:	689b      	ldr	r3, [r3, #8]
 800187a:	f013 0f40 	tst.w	r3, #64	; 0x40
 800187e:	d055      	beq.n	800192c <HAL_UART_IRQHandler+0x28c>
 8001880:	6fe2      	ldr	r2, [r4, #124]	; 0x7c
 8001882:	6813      	ldr	r3, [r2, #0]
 8001884:	685b      	ldr	r3, [r3, #4]
 8001886:	b29b      	uxth	r3, r3
 8001888:	2b00      	cmp	r3, #0
 800188a:	f43f af4d 	beq.w	8001728 <HAL_UART_IRQHandler+0x88>
 800188e:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001892:	4299      	cmp	r1, r3
 8001894:	f67f af48 	bls.w	8001728 <HAL_UART_IRQHandler+0x88>
 8001898:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 800189c:	6813      	ldr	r3, [r2, #0]
 800189e:	681b      	ldr	r3, [r3, #0]
 80018a0:	f013 0f20 	tst.w	r3, #32
 80018a4:	d131      	bne.n	800190a <HAL_UART_IRQHandler+0x26a>
 80018a6:	6822      	ldr	r2, [r4, #0]
 80018a8:	e852 3f00 	ldrex	r3, [r2]
 80018ac:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 80018b0:	e842 3100 	strex	r1, r3, [r2]
 80018b4:	2900      	cmp	r1, #0
 80018b6:	d1f6      	bne.n	80018a6 <HAL_UART_IRQHandler+0x206>
 80018b8:	6822      	ldr	r2, [r4, #0]
 80018ba:	f102 0308 	add.w	r3, r2, #8
 80018be:	e853 3f00 	ldrex	r3, [r3]
 80018c2:	f023 0301 	bic.w	r3, r3, #1
 80018c6:	3208      	adds	r2, #8
 80018c8:	e842 3100 	strex	r1, r3, [r2]
 80018cc:	2900      	cmp	r1, #0
 80018ce:	d1f3      	bne.n	80018b8 <HAL_UART_IRQHandler+0x218>
 80018d0:	6822      	ldr	r2, [r4, #0]
 80018d2:	f102 0308 	add.w	r3, r2, #8
 80018d6:	e853 3f00 	ldrex	r3, [r3]
 80018da:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 80018de:	3208      	adds	r2, #8
 80018e0:	e842 3100 	strex	r1, r3, [r2]
 80018e4:	2900      	cmp	r1, #0
 80018e6:	d1f3      	bne.n	80018d0 <HAL_UART_IRQHandler+0x230>
 80018e8:	2320      	movs	r3, #32
 80018ea:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80018ee:	2300      	movs	r3, #0
 80018f0:	66e3      	str	r3, [r4, #108]	; 0x6c
 80018f2:	6822      	ldr	r2, [r4, #0]
 80018f4:	e852 3f00 	ldrex	r3, [r2]
 80018f8:	f023 0310 	bic.w	r3, r3, #16
 80018fc:	e842 3100 	strex	r1, r3, [r2]
 8001900:	2900      	cmp	r1, #0
 8001902:	d1f6      	bne.n	80018f2 <HAL_UART_IRQHandler+0x252>
 8001904:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 8001906:	f02a feb5 	bl	802c674 <HAL_DMA_Abort>
 800190a:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 800190e:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001912:	b29b      	uxth	r3, r3
 8001914:	1ac9      	subs	r1, r1, r3
 8001916:	b289      	uxth	r1, r1
 8001918:	4620      	mov	r0, r4
 800191a:	f7ff febf 	bl	800169c <HAL_UARTEx_RxEventCallback>
 800191e:	e703      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 8001920:	10000001 	.word	0x10000001
 8001924:	04000120 	.word	0x04000120
 8001928:	0800158d 	.word	0x0800158d
 800192c:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001930:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001934:	b29b      	uxth	r3, r3
 8001936:	1ac9      	subs	r1, r1, r3
 8001938:	b289      	uxth	r1, r1
 800193a:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 800193e:	b29b      	uxth	r3, r3
 8001940:	2b00      	cmp	r3, #0
 8001942:	f43f aef1 	beq.w	8001728 <HAL_UART_IRQHandler+0x88>
 8001946:	2900      	cmp	r1, #0
 8001948:	f43f aeee 	beq.w	8001728 <HAL_UART_IRQHandler+0x88>
 800194c:	6822      	ldr	r2, [r4, #0]
 800194e:	e852 3f00 	ldrex	r3, [r2]
 8001952:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001956:	e842 3000 	strex	r0, r3, [r2]
 800195a:	2800      	cmp	r0, #0
 800195c:	d1f6      	bne.n	800194c <HAL_UART_IRQHandler+0x2ac>
 800195e:	6822      	ldr	r2, [r4, #0]
 8001960:	f102 0308 	add.w	r3, r2, #8
 8001964:	e853 3f00 	ldrex	r3, [r3]
 8001968:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 800196c:	f023 0301 	bic.w	r3, r3, #1
 8001970:	3208      	adds	r2, #8
 8001972:	e842 3000 	strex	r0, r3, [r2]
 8001976:	2800      	cmp	r0, #0
 8001978:	d1f1      	bne.n	800195e <HAL_UART_IRQHandler+0x2be>
 800197a:	2320      	movs	r3, #32
 800197c:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001980:	2300      	movs	r3, #0
 8001982:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001984:	6723      	str	r3, [r4, #112]	; 0x70
 8001986:	6822      	ldr	r2, [r4, #0]
 8001988:	e852 3f00 	ldrex	r3, [r2]
 800198c:	f023 0310 	bic.w	r3, r3, #16
 8001990:	e842 3000 	strex	r0, r3, [r2]
 8001994:	2800      	cmp	r0, #0
 8001996:	d1f6      	bne.n	8001986 <HAL_UART_IRQHandler+0x2e6>
 8001998:	4620      	mov	r0, r4
 800199a:	f7ff fe7f 	bl	800169c <HAL_UARTEx_RxEventCallback>
 800199e:	e6c3      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 80019a0:	f44f 1380 	mov.w	r3, #1048576	; 0x100000
 80019a4:	620b      	str	r3, [r1, #32]
 80019a6:	4620      	mov	r0, r4
 80019a8:	f000 fef2 	bl	8002790 <HAL_UARTEx_WakeupCallback>
 80019ac:	e6bc      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 80019ae:	6f63      	ldr	r3, [r4, #116]	; 0x74
 80019b0:	2b00      	cmp	r3, #0
 80019b2:	f43f aeb9 	beq.w	8001728 <HAL_UART_IRQHandler+0x88>
 80019b6:	4620      	mov	r0, r4
 80019b8:	4798      	blx	r3
 80019ba:	e6b5      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 80019bc:	4620      	mov	r0, r4
 80019be:	f7ff fdd2 	bl	8001566 <UART_EndTransmit_IT>
 80019c2:	e6b1      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 80019c4:	4620      	mov	r0, r4
 80019c6:	f000 fee5 	bl	8002794 <HAL_UARTEx_TxFifoEmptyCallback>
 80019ca:	e6ad      	b.n	8001728 <HAL_UART_IRQHandler+0x88>
 80019cc:	4620      	mov	r0, r4
 80019ce:	f000 fee0 	bl	8002792 <HAL_UARTEx_RxFifoFullCallback>
 80019d2:	e6a9      	b.n	8001728 <HAL_UART_IRQHandler+0x88>

080019d4 <UART_RxISR_8BIT>:
 80019d4:	b508      	push	{r3, lr}
 80019d6:	f8b0 3060 	ldrh.w	r3, [r0, #96]	; 0x60
 80019da:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 80019de:	2a22      	cmp	r2, #34	; 0x22
 80019e0:	d005      	beq.n	80019ee <UART_RxISR_8BIT+0x1a>
 80019e2:	6802      	ldr	r2, [r0, #0]
 80019e4:	6993      	ldr	r3, [r2, #24]
 80019e6:	f043 0308 	orr.w	r3, r3, #8
 80019ea:	6193      	str	r3, [r2, #24]
 80019ec:	bd08      	pop	{r3, pc}
 80019ee:	6802      	ldr	r2, [r0, #0]
 80019f0:	6a51      	ldr	r1, [r2, #36]	; 0x24
 80019f2:	b2db      	uxtb	r3, r3
 80019f4:	6d82      	ldr	r2, [r0, #88]	; 0x58
 80019f6:	400b      	ands	r3, r1
 80019f8:	7013      	strb	r3, [r2, #0]
 80019fa:	6d83      	ldr	r3, [r0, #88]	; 0x58
 80019fc:	3301      	adds	r3, #1
 80019fe:	6583      	str	r3, [r0, #88]	; 0x58
 8001a00:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001a04:	b29b      	uxth	r3, r3
 8001a06:	3b01      	subs	r3, #1
 8001a08:	b29b      	uxth	r3, r3
 8001a0a:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 8001a0e:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001a12:	b29b      	uxth	r3, r3
 8001a14:	2b00      	cmp	r3, #0
 8001a16:	d1e9      	bne.n	80019ec <UART_RxISR_8BIT+0x18>
 8001a18:	6802      	ldr	r2, [r0, #0]
 8001a1a:	e852 3f00 	ldrex	r3, [r2]
 8001a1e:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001a22:	e842 3100 	strex	r1, r3, [r2]
 8001a26:	2900      	cmp	r1, #0
 8001a28:	d1f6      	bne.n	8001a18 <UART_RxISR_8BIT+0x44>
 8001a2a:	6802      	ldr	r2, [r0, #0]
 8001a2c:	f102 0308 	add.w	r3, r2, #8
 8001a30:	e853 3f00 	ldrex	r3, [r3]
 8001a34:	f023 0301 	bic.w	r3, r3, #1
 8001a38:	3208      	adds	r2, #8
 8001a3a:	e842 3100 	strex	r1, r3, [r2]
 8001a3e:	2900      	cmp	r1, #0
 8001a40:	d1f3      	bne.n	8001a2a <UART_RxISR_8BIT+0x56>
 8001a42:	2320      	movs	r3, #32
 8001a44:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001a48:	2300      	movs	r3, #0
 8001a4a:	6703      	str	r3, [r0, #112]	; 0x70
 8001a4c:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 8001a4e:	2b01      	cmp	r3, #1
 8001a50:	d116      	bne.n	8001a80 <UART_RxISR_8BIT+0xac>
 8001a52:	2300      	movs	r3, #0
 8001a54:	66c3      	str	r3, [r0, #108]	; 0x6c
 8001a56:	6802      	ldr	r2, [r0, #0]
 8001a58:	e852 3f00 	ldrex	r3, [r2]
 8001a5c:	f023 0310 	bic.w	r3, r3, #16
 8001a60:	e842 3100 	strex	r1, r3, [r2]
 8001a64:	2900      	cmp	r1, #0
 8001a66:	d1f6      	bne.n	8001a56 <UART_RxISR_8BIT+0x82>
 8001a68:	6803      	ldr	r3, [r0, #0]
 8001a6a:	69da      	ldr	r2, [r3, #28]
 8001a6c:	f012 0f10 	tst.w	r2, #16
 8001a70:	d001      	beq.n	8001a76 <UART_RxISR_8BIT+0xa2>
 8001a72:	2210      	movs	r2, #16
 8001a74:	621a      	str	r2, [r3, #32]
 8001a76:	f8b0 105c 	ldrh.w	r1, [r0, #92]	; 0x5c
 8001a7a:	f7ff fe0f 	bl	800169c <HAL_UARTEx_RxEventCallback>
 8001a7e:	e7b5      	b.n	80019ec <UART_RxISR_8BIT+0x18>
 8001a80:	f7fe fff6 	bl	8000a70 <HAL_UART_RxCpltCallback>
 8001a84:	e7b2      	b.n	80019ec <UART_RxISR_8BIT+0x18>

08001a86 <UART_RxISR_16BIT>:
 8001a86:	b508      	push	{r3, lr}
 8001a88:	f8b0 2060 	ldrh.w	r2, [r0, #96]	; 0x60
 8001a8c:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 8001a90:	2b22      	cmp	r3, #34	; 0x22
 8001a92:	d005      	beq.n	8001aa0 <UART_RxISR_16BIT+0x1a>
 8001a94:	6802      	ldr	r2, [r0, #0]
 8001a96:	6993      	ldr	r3, [r2, #24]
 8001a98:	f043 0308 	orr.w	r3, r3, #8
 8001a9c:	6193      	str	r3, [r2, #24]
 8001a9e:	bd08      	pop	{r3, pc}
 8001aa0:	6803      	ldr	r3, [r0, #0]
 8001aa2:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8001aa4:	6d81      	ldr	r1, [r0, #88]	; 0x58
 8001aa6:	4013      	ands	r3, r2
 8001aa8:	800b      	strh	r3, [r1, #0]
 8001aaa:	6d83      	ldr	r3, [r0, #88]	; 0x58
 8001aac:	3302      	adds	r3, #2
 8001aae:	6583      	str	r3, [r0, #88]	; 0x58
 8001ab0:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001ab4:	b29b      	uxth	r3, r3
 8001ab6:	3b01      	subs	r3, #1
 8001ab8:	b29b      	uxth	r3, r3
 8001aba:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 8001abe:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001ac2:	b29b      	uxth	r3, r3
 8001ac4:	2b00      	cmp	r3, #0
 8001ac6:	d1ea      	bne.n	8001a9e <UART_RxISR_16BIT+0x18>
 8001ac8:	6802      	ldr	r2, [r0, #0]
 8001aca:	e852 3f00 	ldrex	r3, [r2]
 8001ace:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001ad2:	e842 3100 	strex	r1, r3, [r2]
 8001ad6:	2900      	cmp	r1, #0
 8001ad8:	d1f6      	bne.n	8001ac8 <UART_RxISR_16BIT+0x42>
 8001ada:	6802      	ldr	r2, [r0, #0]
 8001adc:	f102 0308 	add.w	r3, r2, #8
 8001ae0:	e853 3f00 	ldrex	r3, [r3]
 8001ae4:	f023 0301 	bic.w	r3, r3, #1
 8001ae8:	3208      	adds	r2, #8
 8001aea:	e842 3100 	strex	r1, r3, [r2]
 8001aee:	2900      	cmp	r1, #0
 8001af0:	d1f3      	bne.n	8001ada <UART_RxISR_16BIT+0x54>
 8001af2:	2320      	movs	r3, #32
 8001af4:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001af8:	2300      	movs	r3, #0
 8001afa:	6703      	str	r3, [r0, #112]	; 0x70
 8001afc:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 8001afe:	2b01      	cmp	r3, #1
 8001b00:	d116      	bne.n	8001b30 <UART_RxISR_16BIT+0xaa>
 8001b02:	2300      	movs	r3, #0
 8001b04:	66c3      	str	r3, [r0, #108]	; 0x6c
 8001b06:	6802      	ldr	r2, [r0, #0]
 8001b08:	e852 3f00 	ldrex	r3, [r2]
 8001b0c:	f023 0310 	bic.w	r3, r3, #16
 8001b10:	e842 3100 	strex	r1, r3, [r2]
 8001b14:	2900      	cmp	r1, #0
 8001b16:	d1f6      	bne.n	8001b06 <UART_RxISR_16BIT+0x80>
 8001b18:	6803      	ldr	r3, [r0, #0]
 8001b1a:	69da      	ldr	r2, [r3, #28]
 8001b1c:	f012 0f10 	tst.w	r2, #16
 8001b20:	d001      	beq.n	8001b26 <UART_RxISR_16BIT+0xa0>
 8001b22:	2210      	movs	r2, #16
 8001b24:	621a      	str	r2, [r3, #32]
 8001b26:	f8b0 105c 	ldrh.w	r1, [r0, #92]	; 0x5c
 8001b2a:	f7ff fdb7 	bl	800169c <HAL_UARTEx_RxEventCallback>
 8001b2e:	e7b6      	b.n	8001a9e <UART_RxISR_16BIT+0x18>
 8001b30:	f7fe ff9e 	bl	8000a70 <HAL_UART_RxCpltCallback>
 8001b34:	e7b3      	b.n	8001a9e <UART_RxISR_16BIT+0x18>
	...

08001b38 <UART_RxISR_8BIT_FIFOEN>:
 8001b38:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001b3c:	f8b0 6060 	ldrh.w	r6, [r0, #96]	; 0x60
 8001b40:	6803      	ldr	r3, [r0, #0]
 8001b42:	69dd      	ldr	r5, [r3, #28]
 8001b44:	f8d3 9000 	ldr.w	r9, [r3]
 8001b48:	f8d3 8008 	ldr.w	r8, [r3, #8]
 8001b4c:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001b50:	2a22      	cmp	r2, #34	; 0x22
 8001b52:	d005      	beq.n	8001b60 <UART_RxISR_8BIT_FIFOEN+0x28>
 8001b54:	699a      	ldr	r2, [r3, #24]
 8001b56:	f042 0208 	orr.w	r2, r2, #8
 8001b5a:	619a      	str	r2, [r3, #24]
 8001b5c:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001b60:	4604      	mov	r4, r0
 8001b62:	f8b0 7068 	ldrh.w	r7, [r0, #104]	; 0x68
 8001b66:	e008      	b.n	8001b7a <UART_RxISR_8BIT_FIFOEN+0x42>
 8001b68:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b6c:	2b00      	cmp	r3, #0
 8001b6e:	d14c      	bne.n	8001c0a <UART_RxISR_8BIT_FIFOEN+0xd2>
 8001b70:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001b74:	b29b      	uxth	r3, r3
 8001b76:	2b00      	cmp	r3, #0
 8001b78:	d04e      	beq.n	8001c18 <UART_RxISR_8BIT_FIFOEN+0xe0>
 8001b7a:	2f00      	cmp	r7, #0
 8001b7c:	f000 8087 	beq.w	8001c8e <UART_RxISR_8BIT_FIFOEN+0x156>
 8001b80:	f015 0f20 	tst.w	r5, #32
 8001b84:	f000 8083 	beq.w	8001c8e <UART_RxISR_8BIT_FIFOEN+0x156>
 8001b88:	6823      	ldr	r3, [r4, #0]
 8001b8a:	6a59      	ldr	r1, [r3, #36]	; 0x24
 8001b8c:	b2f3      	uxtb	r3, r6
 8001b8e:	6da2      	ldr	r2, [r4, #88]	; 0x58
 8001b90:	400b      	ands	r3, r1
 8001b92:	7013      	strb	r3, [r2, #0]
 8001b94:	6da3      	ldr	r3, [r4, #88]	; 0x58
 8001b96:	3301      	adds	r3, #1
 8001b98:	65a3      	str	r3, [r4, #88]	; 0x58
 8001b9a:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001b9e:	b29b      	uxth	r3, r3
 8001ba0:	3b01      	subs	r3, #1
 8001ba2:	b29b      	uxth	r3, r3
 8001ba4:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001ba8:	6823      	ldr	r3, [r4, #0]
 8001baa:	69dd      	ldr	r5, [r3, #28]
 8001bac:	f015 0f07 	tst.w	r5, #7
 8001bb0:	d0de      	beq.n	8001b70 <UART_RxISR_8BIT_FIFOEN+0x38>
 8001bb2:	f015 0f01 	tst.w	r5, #1
 8001bb6:	d009      	beq.n	8001bcc <UART_RxISR_8BIT_FIFOEN+0x94>
 8001bb8:	f419 7f80 	tst.w	r9, #256	; 0x100
 8001bbc:	d006      	beq.n	8001bcc <UART_RxISR_8BIT_FIFOEN+0x94>
 8001bbe:	2201      	movs	r2, #1
 8001bc0:	621a      	str	r2, [r3, #32]
 8001bc2:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001bc6:	4313      	orrs	r3, r2
 8001bc8:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001bcc:	f015 0f02 	tst.w	r5, #2
 8001bd0:	d00b      	beq.n	8001bea <UART_RxISR_8BIT_FIFOEN+0xb2>
 8001bd2:	f018 0f01 	tst.w	r8, #1
 8001bd6:	d008      	beq.n	8001bea <UART_RxISR_8BIT_FIFOEN+0xb2>
 8001bd8:	6823      	ldr	r3, [r4, #0]
 8001bda:	2202      	movs	r2, #2
 8001bdc:	621a      	str	r2, [r3, #32]
 8001bde:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001be2:	f043 0304 	orr.w	r3, r3, #4
 8001be6:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001bea:	f015 0f04 	tst.w	r5, #4
 8001bee:	d0bb      	beq.n	8001b68 <UART_RxISR_8BIT_FIFOEN+0x30>
 8001bf0:	f018 0f01 	tst.w	r8, #1
 8001bf4:	d0b8      	beq.n	8001b68 <UART_RxISR_8BIT_FIFOEN+0x30>
 8001bf6:	6823      	ldr	r3, [r4, #0]
 8001bf8:	2204      	movs	r2, #4
 8001bfa:	621a      	str	r2, [r3, #32]
 8001bfc:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001c00:	f043 0302 	orr.w	r3, r3, #2
 8001c04:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001c08:	e7ae      	b.n	8001b68 <UART_RxISR_8BIT_FIFOEN+0x30>
 8001c0a:	4620      	mov	r0, r4
 8001c0c:	f7ff fcbd 	bl	800158a <HAL_UART_ErrorCallback>
 8001c10:	2300      	movs	r3, #0
 8001c12:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001c16:	e7ab      	b.n	8001b70 <UART_RxISR_8BIT_FIFOEN+0x38>
 8001c18:	6822      	ldr	r2, [r4, #0]
 8001c1a:	e852 3f00 	ldrex	r3, [r2]
 8001c1e:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001c22:	e842 3100 	strex	r1, r3, [r2]
 8001c26:	2900      	cmp	r1, #0
 8001c28:	d1f6      	bne.n	8001c18 <UART_RxISR_8BIT_FIFOEN+0xe0>
 8001c2a:	6822      	ldr	r2, [r4, #0]
 8001c2c:	f102 0308 	add.w	r3, r2, #8
 8001c30:	e853 3f00 	ldrex	r3, [r3]
 8001c34:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001c38:	f023 0301 	bic.w	r3, r3, #1
 8001c3c:	3208      	adds	r2, #8
 8001c3e:	e842 3100 	strex	r1, r3, [r2]
 8001c42:	2900      	cmp	r1, #0
 8001c44:	d1f1      	bne.n	8001c2a <UART_RxISR_8BIT_FIFOEN+0xf2>
 8001c46:	2320      	movs	r3, #32
 8001c48:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001c4c:	2300      	movs	r3, #0
 8001c4e:	6723      	str	r3, [r4, #112]	; 0x70
 8001c50:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001c52:	2b01      	cmp	r3, #1
 8001c54:	d003      	beq.n	8001c5e <UART_RxISR_8BIT_FIFOEN+0x126>
 8001c56:	4620      	mov	r0, r4
 8001c58:	f7fe ff0a 	bl	8000a70 <HAL_UART_RxCpltCallback>
 8001c5c:	e78d      	b.n	8001b7a <UART_RxISR_8BIT_FIFOEN+0x42>
 8001c5e:	2300      	movs	r3, #0
 8001c60:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001c62:	6822      	ldr	r2, [r4, #0]
 8001c64:	e852 3f00 	ldrex	r3, [r2]
 8001c68:	f023 0310 	bic.w	r3, r3, #16
 8001c6c:	e842 3100 	strex	r1, r3, [r2]
 8001c70:	2900      	cmp	r1, #0
 8001c72:	d1f6      	bne.n	8001c62 <UART_RxISR_8BIT_FIFOEN+0x12a>
 8001c74:	6823      	ldr	r3, [r4, #0]
 8001c76:	69da      	ldr	r2, [r3, #28]
 8001c78:	f012 0f10 	tst.w	r2, #16
 8001c7c:	d001      	beq.n	8001c82 <UART_RxISR_8BIT_FIFOEN+0x14a>
 8001c7e:	2210      	movs	r2, #16
 8001c80:	621a      	str	r2, [r3, #32]
 8001c82:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001c86:	4620      	mov	r0, r4
 8001c88:	f7ff fd08 	bl	800169c <HAL_UARTEx_RxEventCallback>
 8001c8c:	e775      	b.n	8001b7a <UART_RxISR_8BIT_FIFOEN+0x42>
 8001c8e:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001c92:	b29b      	uxth	r3, r3
 8001c94:	2b00      	cmp	r3, #0
 8001c96:	f43f af61 	beq.w	8001b5c <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c9a:	f8b4 2068 	ldrh.w	r2, [r4, #104]	; 0x68
 8001c9e:	429a      	cmp	r2, r3
 8001ca0:	f67f af5c 	bls.w	8001b5c <UART_RxISR_8BIT_FIFOEN+0x24>
 8001ca4:	6822      	ldr	r2, [r4, #0]
 8001ca6:	f102 0308 	add.w	r3, r2, #8
 8001caa:	e853 3f00 	ldrex	r3, [r3]
 8001cae:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001cb2:	3208      	adds	r2, #8
 8001cb4:	e842 3100 	strex	r1, r3, [r2]
 8001cb8:	2900      	cmp	r1, #0
 8001cba:	d1f3      	bne.n	8001ca4 <UART_RxISR_8BIT_FIFOEN+0x16c>
 8001cbc:	4b05      	ldr	r3, [pc, #20]	; (8001cd4 <UART_RxISR_8BIT_FIFOEN+0x19c>)
 8001cbe:	6723      	str	r3, [r4, #112]	; 0x70
 8001cc0:	6822      	ldr	r2, [r4, #0]
 8001cc2:	e852 3f00 	ldrex	r3, [r2]
 8001cc6:	f043 0320 	orr.w	r3, r3, #32
 8001cca:	e842 3100 	strex	r1, r3, [r2]
 8001cce:	2900      	cmp	r1, #0
 8001cd0:	d1f6      	bne.n	8001cc0 <UART_RxISR_8BIT_FIFOEN+0x188>
 8001cd2:	e743      	b.n	8001b5c <UART_RxISR_8BIT_FIFOEN+0x24>
 8001cd4:	080019d5 	.word	0x080019d5

08001cd8 <UART_RxISR_16BIT_FIFOEN>:
 8001cd8:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001cdc:	f8b0 6060 	ldrh.w	r6, [r0, #96]	; 0x60
 8001ce0:	6803      	ldr	r3, [r0, #0]
 8001ce2:	69dd      	ldr	r5, [r3, #28]
 8001ce4:	f8d3 9000 	ldr.w	r9, [r3]
 8001ce8:	f8d3 8008 	ldr.w	r8, [r3, #8]
 8001cec:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001cf0:	2a22      	cmp	r2, #34	; 0x22
 8001cf2:	d005      	beq.n	8001d00 <UART_RxISR_16BIT_FIFOEN+0x28>
 8001cf4:	699a      	ldr	r2, [r3, #24]
 8001cf6:	f042 0208 	orr.w	r2, r2, #8
 8001cfa:	619a      	str	r2, [r3, #24]
 8001cfc:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001d00:	4604      	mov	r4, r0
 8001d02:	f8b0 7068 	ldrh.w	r7, [r0, #104]	; 0x68
 8001d06:	e008      	b.n	8001d1a <UART_RxISR_16BIT_FIFOEN+0x42>
 8001d08:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d0c:	2b00      	cmp	r3, #0
 8001d0e:	d14b      	bne.n	8001da8 <UART_RxISR_16BIT_FIFOEN+0xd0>
 8001d10:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001d14:	b29b      	uxth	r3, r3
 8001d16:	2b00      	cmp	r3, #0
 8001d18:	d04d      	beq.n	8001db6 <UART_RxISR_16BIT_FIFOEN+0xde>
 8001d1a:	2f00      	cmp	r7, #0
 8001d1c:	f000 8086 	beq.w	8001e2c <UART_RxISR_16BIT_FIFOEN+0x154>
 8001d20:	f015 0f20 	tst.w	r5, #32
 8001d24:	f000 8082 	beq.w	8001e2c <UART_RxISR_16BIT_FIFOEN+0x154>
 8001d28:	6823      	ldr	r3, [r4, #0]
 8001d2a:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8001d2c:	6da2      	ldr	r2, [r4, #88]	; 0x58
 8001d2e:	4033      	ands	r3, r6
 8001d30:	8013      	strh	r3, [r2, #0]
 8001d32:	6da3      	ldr	r3, [r4, #88]	; 0x58
 8001d34:	3302      	adds	r3, #2
 8001d36:	65a3      	str	r3, [r4, #88]	; 0x58
 8001d38:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001d3c:	b29b      	uxth	r3, r3
 8001d3e:	3b01      	subs	r3, #1
 8001d40:	b29b      	uxth	r3, r3
 8001d42:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001d46:	6823      	ldr	r3, [r4, #0]
 8001d48:	69dd      	ldr	r5, [r3, #28]
 8001d4a:	f015 0f07 	tst.w	r5, #7
 8001d4e:	d0df      	beq.n	8001d10 <UART_RxISR_16BIT_FIFOEN+0x38>
 8001d50:	f015 0f01 	tst.w	r5, #1
 8001d54:	d009      	beq.n	8001d6a <UART_RxISR_16BIT_FIFOEN+0x92>
 8001d56:	f419 7f80 	tst.w	r9, #256	; 0x100
 8001d5a:	d006      	beq.n	8001d6a <UART_RxISR_16BIT_FIFOEN+0x92>
 8001d5c:	2201      	movs	r2, #1
 8001d5e:	621a      	str	r2, [r3, #32]
 8001d60:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d64:	4313      	orrs	r3, r2
 8001d66:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d6a:	f015 0f02 	tst.w	r5, #2
 8001d6e:	d00b      	beq.n	8001d88 <UART_RxISR_16BIT_FIFOEN+0xb0>
 8001d70:	f018 0f01 	tst.w	r8, #1
 8001d74:	d008      	beq.n	8001d88 <UART_RxISR_16BIT_FIFOEN+0xb0>
 8001d76:	6823      	ldr	r3, [r4, #0]
 8001d78:	2202      	movs	r2, #2
 8001d7a:	621a      	str	r2, [r3, #32]
 8001d7c:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d80:	f043 0304 	orr.w	r3, r3, #4
 8001d84:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d88:	f015 0f04 	tst.w	r5, #4
 8001d8c:	d0bc      	beq.n	8001d08 <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d8e:	f018 0f01 	tst.w	r8, #1
 8001d92:	d0b9      	beq.n	8001d08 <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d94:	6823      	ldr	r3, [r4, #0]
 8001d96:	2204      	movs	r2, #4
 8001d98:	621a      	str	r2, [r3, #32]
 8001d9a:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d9e:	f043 0302 	orr.w	r3, r3, #2
 8001da2:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001da6:	e7af      	b.n	8001d08 <UART_RxISR_16BIT_FIFOEN+0x30>
 8001da8:	4620      	mov	r0, r4
 8001daa:	f7ff fbee 	bl	800158a <HAL_UART_ErrorCallback>
 8001dae:	2300      	movs	r3, #0
 8001db0:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001db4:	e7ac      	b.n	8001d10 <UART_RxISR_16BIT_FIFOEN+0x38>
 8001db6:	6822      	ldr	r2, [r4, #0]
 8001db8:	e852 3f00 	ldrex	r3, [r2]
 8001dbc:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001dc0:	e842 3100 	strex	r1, r3, [r2]
 8001dc4:	2900      	cmp	r1, #0
 8001dc6:	d1f6      	bne.n	8001db6 <UART_RxISR_16BIT_FIFOEN+0xde>
 8001dc8:	6822      	ldr	r2, [r4, #0]
 8001dca:	f102 0308 	add.w	r3, r2, #8
 8001dce:	e853 3f00 	ldrex	r3, [r3]
 8001dd2:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001dd6:	f023 0301 	bic.w	r3, r3, #1
 8001dda:	3208      	adds	r2, #8
 8001ddc:	e842 3100 	strex	r1, r3, [r2]
 8001de0:	2900      	cmp	r1, #0
 8001de2:	d1f1      	bne.n	8001dc8 <UART_RxISR_16BIT_FIFOEN+0xf0>
 8001de4:	2320      	movs	r3, #32
 8001de6:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001dea:	2300      	movs	r3, #0
 8001dec:	6723      	str	r3, [r4, #112]	; 0x70
 8001dee:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001df0:	2b01      	cmp	r3, #1
 8001df2:	d003      	beq.n	8001dfc <UART_RxISR_16BIT_FIFOEN+0x124>
 8001df4:	4620      	mov	r0, r4
 8001df6:	f7fe fe3b 	bl	8000a70 <HAL_UART_RxCpltCallback>
 8001dfa:	e78e      	b.n	8001d1a <UART_RxISR_16BIT_FIFOEN+0x42>
 8001dfc:	2300      	movs	r3, #0
 8001dfe:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001e00:	6822      	ldr	r2, [r4, #0]
 8001e02:	e852 3f00 	ldrex	r3, [r2]
 8001e06:	f023 0310 	bic.w	r3, r3, #16
 8001e0a:	e842 3100 	strex	r1, r3, [r2]
 8001e0e:	2900      	cmp	r1, #0
 8001e10:	d1f6      	bne.n	8001e00 <UART_RxISR_16BIT_FIFOEN+0x128>
 8001e12:	6823      	ldr	r3, [r4, #0]
 8001e14:	69da      	ldr	r2, [r3, #28]
 8001e16:	f012 0f10 	tst.w	r2, #16
 8001e1a:	d001      	beq.n	8001e20 <UART_RxISR_16BIT_FIFOEN+0x148>
 8001e1c:	2210      	movs	r2, #16
 8001e1e:	621a      	str	r2, [r3, #32]
 8001e20:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001e24:	4620      	mov	r0, r4
 8001e26:	f7ff fc39 	bl	800169c <HAL_UARTEx_RxEventCallback>
 8001e2a:	e776      	b.n	8001d1a <UART_RxISR_16BIT_FIFOEN+0x42>
 8001e2c:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001e30:	b29b      	uxth	r3, r3
 8001e32:	2b00      	cmp	r3, #0
 8001e34:	f43f af62 	beq.w	8001cfc <UART_RxISR_16BIT_FIFOEN+0x24>
 8001e38:	f8b4 2068 	ldrh.w	r2, [r4, #104]	; 0x68
 8001e3c:	429a      	cmp	r2, r3
 8001e3e:	f67f af5d 	bls.w	8001cfc <UART_RxISR_16BIT_FIFOEN+0x24>
 8001e42:	6822      	ldr	r2, [r4, #0]
 8001e44:	f102 0308 	add.w	r3, r2, #8
 8001e48:	e853 3f00 	ldrex	r3, [r3]
 8001e4c:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001e50:	3208      	adds	r2, #8
 8001e52:	e842 3100 	strex	r1, r3, [r2]
 8001e56:	2900      	cmp	r1, #0
 8001e58:	d1f3      	bne.n	8001e42 <UART_RxISR_16BIT_FIFOEN+0x16a>
 8001e5a:	4b06      	ldr	r3, [pc, #24]	; (8001e74 <UART_RxISR_16BIT_FIFOEN+0x19c>)
 8001e5c:	6723      	str	r3, [r4, #112]	; 0x70
 8001e5e:	6822      	ldr	r2, [r4, #0]
 8001e60:	e852 3f00 	ldrex	r3, [r2]
 8001e64:	f043 0320 	orr.w	r3, r3, #32
 8001e68:	e842 3100 	strex	r1, r3, [r2]
 8001e6c:	2900      	cmp	r1, #0
 8001e6e:	d1f6      	bne.n	8001e5e <UART_RxISR_16BIT_FIFOEN+0x186>
 8001e70:	e744      	b.n	8001cfc <UART_RxISR_16BIT_FIFOEN+0x24>
 8001e72:	bf00      	nop
 8001e74:	08001a87 	.word	0x08001a87

08001e78 <UART_SetConfig>:
 8001e78:	b570      	push	{r4, r5, r6, lr}
 8001e7a:	4604      	mov	r4, r0
 8001e7c:	6801      	ldr	r1, [r0, #0]
 8001e7e:	6883      	ldr	r3, [r0, #8]
 8001e80:	6902      	ldr	r2, [r0, #16]
 8001e82:	4313      	orrs	r3, r2
 8001e84:	6942      	ldr	r2, [r0, #20]
 8001e86:	4313      	orrs	r3, r2
 8001e88:	69c2      	ldr	r2, [r0, #28]
 8001e8a:	4313      	orrs	r3, r2
 8001e8c:	6808      	ldr	r0, [r1, #0]
 8001e8e:	4a9d      	ldr	r2, [pc, #628]	; (8002104 <UART_SetConfig+0x28c>)
 8001e90:	4002      	ands	r2, r0
 8001e92:	4313      	orrs	r3, r2
 8001e94:	600b      	str	r3, [r1, #0]
 8001e96:	6822      	ldr	r2, [r4, #0]
 8001e98:	6853      	ldr	r3, [r2, #4]
 8001e9a:	f423 5340 	bic.w	r3, r3, #12288	; 0x3000
 8001e9e:	68e1      	ldr	r1, [r4, #12]
 8001ea0:	430b      	orrs	r3, r1
 8001ea2:	6053      	str	r3, [r2, #4]
 8001ea4:	69a1      	ldr	r1, [r4, #24]
 8001ea6:	6822      	ldr	r2, [r4, #0]
 8001ea8:	4b97      	ldr	r3, [pc, #604]	; (8002108 <UART_SetConfig+0x290>)
 8001eaa:	429a      	cmp	r2, r3
 8001eac:	d001      	beq.n	8001eb2 <UART_SetConfig+0x3a>
 8001eae:	6a23      	ldr	r3, [r4, #32]
 8001eb0:	4319      	orrs	r1, r3
 8001eb2:	6893      	ldr	r3, [r2, #8]
 8001eb4:	f023 436e 	bic.w	r3, r3, #3992977408	; 0xee000000
 8001eb8:	f423 6330 	bic.w	r3, r3, #2816	; 0xb00
 8001ebc:	430b      	orrs	r3, r1
 8001ebe:	6093      	str	r3, [r2, #8]
 8001ec0:	6822      	ldr	r2, [r4, #0]
 8001ec2:	6ad3      	ldr	r3, [r2, #44]	; 0x2c
 8001ec4:	f023 030f 	bic.w	r3, r3, #15
 8001ec8:	6a61      	ldr	r1, [r4, #36]	; 0x24
 8001eca:	430b      	orrs	r3, r1
 8001ecc:	62d3      	str	r3, [r2, #44]	; 0x2c
 8001ece:	6823      	ldr	r3, [r4, #0]
 8001ed0:	4a8e      	ldr	r2, [pc, #568]	; (800210c <UART_SetConfig+0x294>)
 8001ed2:	4293      	cmp	r3, r2
 8001ed4:	d01c      	beq.n	8001f10 <UART_SetConfig+0x98>
 8001ed6:	4a8e      	ldr	r2, [pc, #568]	; (8002110 <UART_SetConfig+0x298>)
 8001ed8:	4293      	cmp	r3, r2
 8001eda:	d031      	beq.n	8001f40 <UART_SetConfig+0xc8>
 8001edc:	4a8a      	ldr	r2, [pc, #552]	; (8002108 <UART_SetConfig+0x290>)
 8001ede:	4293      	cmp	r3, r2
 8001ee0:	d04b      	beq.n	8001f7a <UART_SetConfig+0x102>
 8001ee2:	2210      	movs	r2, #16
 8001ee4:	4988      	ldr	r1, [pc, #544]	; (8002108 <UART_SetConfig+0x290>)
 8001ee6:	428b      	cmp	r3, r1
 8001ee8:	d068      	beq.n	8001fbc <UART_SetConfig+0x144>
 8001eea:	69e0      	ldr	r0, [r4, #28]
 8001eec:	f5b0 4f00 	cmp.w	r0, #32768	; 0x8000
 8001ef0:	f000 80a5 	beq.w	800203e <UART_SetConfig+0x1c6>
 8001ef4:	2a08      	cmp	r2, #8
 8001ef6:	f200 811f 	bhi.w	8002138 <UART_SetConfig+0x2c0>
 8001efa:	e8df f012 	tbh	[pc, r2, lsl #1]
 8001efe:	00d3      	.short	0x00d3
 8001f00:	00d100f5 	.word	0x00d100f5
 8001f04:	00f8011d 	.word	0x00f8011d
 8001f08:	011d011d 	.word	0x011d011d
 8001f0c:	00fb011d 	.word	0x00fb011d
 8001f10:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001f14:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001f18:	f002 0203 	and.w	r2, r2, #3
 8001f1c:	f442 3240 	orr.w	r2, r2, #196608	; 0x30000
 8001f20:	f5a2 3240 	sub.w	r2, r2, #196608	; 0x30000
 8001f24:	2a03      	cmp	r2, #3
 8001f26:	d809      	bhi.n	8001f3c <UART_SetConfig+0xc4>
 8001f28:	e8df f002 	tbb	[pc, r2]
 8001f2c:	063c0402 	.word	0x063c0402
 8001f30:	2201      	movs	r2, #1
 8001f32:	e7d7      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f34:	2204      	movs	r2, #4
 8001f36:	e7d5      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f38:	2208      	movs	r2, #8
 8001f3a:	e7d3      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f3c:	2210      	movs	r2, #16
 8001f3e:	e7d1      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f40:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001f44:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001f48:	f002 020c 	and.w	r2, r2, #12
 8001f4c:	f442 2240 	orr.w	r2, r2, #786432	; 0xc0000
 8001f50:	f5a2 2240 	sub.w	r2, r2, #786432	; 0xc0000
 8001f54:	2a0c      	cmp	r2, #12
 8001f56:	d80e      	bhi.n	8001f76 <UART_SetConfig+0xfe>
 8001f58:	e8df f002 	tbb	[pc, r2]
 8001f5c:	0d0d0d07 	.word	0x0d0d0d07
 8001f60:	0d0d0d09 	.word	0x0d0d0d09
 8001f64:	0d0d0d26 	.word	0x0d0d0d26
 8001f68:	0b          	.byte	0x0b
 8001f69:	00          	.byte	0x00
 8001f6a:	2200      	movs	r2, #0
 8001f6c:	e7ba      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f6e:	2204      	movs	r2, #4
 8001f70:	e7b8      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f72:	2208      	movs	r2, #8
 8001f74:	e7b6      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f76:	2210      	movs	r2, #16
 8001f78:	e7b4      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f7a:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001f7e:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001f82:	f402 6240 	and.w	r2, r2, #3072	; 0xc00
 8001f86:	f5b2 6f00 	cmp.w	r2, #2048	; 0x800
 8001f8a:	d00f      	beq.n	8001fac <UART_SetConfig+0x134>
 8001f8c:	d805      	bhi.n	8001f9a <UART_SetConfig+0x122>
 8001f8e:	b17a      	cbz	r2, 8001fb0 <UART_SetConfig+0x138>
 8001f90:	f5b2 6f80 	cmp.w	r2, #1024	; 0x400
 8001f94:	d10e      	bne.n	8001fb4 <UART_SetConfig+0x13c>
 8001f96:	2204      	movs	r2, #4
 8001f98:	e7a4      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001f9a:	f5b2 6f40 	cmp.w	r2, #3072	; 0xc00
 8001f9e:	d10b      	bne.n	8001fb8 <UART_SetConfig+0x140>
 8001fa0:	2208      	movs	r2, #8
 8001fa2:	e79f      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fa4:	2202      	movs	r2, #2
 8001fa6:	e79d      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fa8:	2202      	movs	r2, #2
 8001faa:	e79b      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fac:	2202      	movs	r2, #2
 8001fae:	e799      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fb0:	2200      	movs	r2, #0
 8001fb2:	e797      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fb4:	2210      	movs	r2, #16
 8001fb6:	e795      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fb8:	2210      	movs	r2, #16
 8001fba:	e793      	b.n	8001ee4 <UART_SetConfig+0x6c>
 8001fbc:	2a08      	cmp	r2, #8
 8001fbe:	f200 809c 	bhi.w	80020fa <UART_SetConfig+0x282>
 8001fc2:	e8df f002 	tbb	[pc, r2]
 8001fc6:	9a08      	.short	0x9a08
 8001fc8:	9a379a3a 	.word	0x9a379a3a
 8001fcc:	9a9a      	.short	0x9a9a
 8001fce:	05          	.byte	0x05
 8001fcf:	00          	.byte	0x00
 8001fd0:	f44f 4000 	mov.w	r0, #32768	; 0x8000
 8001fd4:	e004      	b.n	8001fe0 <UART_SetConfig+0x168>
 8001fd6:	f024 fa79 	bl	80264cc <HAL_RCC_GetPCLK1Freq>
 8001fda:	2800      	cmp	r0, #0
 8001fdc:	f000 808f 	beq.w	80020fe <UART_SetConfig+0x286>
 8001fe0:	6a62      	ldr	r2, [r4, #36]	; 0x24
 8001fe2:	4b4c      	ldr	r3, [pc, #304]	; (8002114 <UART_SetConfig+0x29c>)
 8001fe4:	f833 2012 	ldrh.w	r2, [r3, r2, lsl #1]
 8001fe8:	fbb0 f3f2 	udiv	r3, r0, r2
 8001fec:	6865      	ldr	r5, [r4, #4]
 8001fee:	eb05 0145 	add.w	r1, r5, r5, lsl #1
 8001ff2:	4299      	cmp	r1, r3
 8001ff4:	f200 8094 	bhi.w	8002120 <UART_SetConfig+0x2a8>
 8001ff8:	ebb3 3f05 	cmp.w	r3, r5, lsl #12
 8001ffc:	f200 8092 	bhi.w	8002124 <UART_SetConfig+0x2ac>
 8002000:	2600      	movs	r6, #0
 8002002:	4633      	mov	r3, r6
 8002004:	4631      	mov	r1, r6
 8002006:	f01c fc43 	bl	801e890 <__aeabi_uldivmod>
 800200a:	0209      	lsls	r1, r1, #8
 800200c:	ea41 6110 	orr.w	r1, r1, r0, lsr #24
 8002010:	0200      	lsls	r0, r0, #8
 8002012:	086b      	lsrs	r3, r5, #1
 8002014:	18c0      	adds	r0, r0, r3
 8002016:	462a      	mov	r2, r5
 8002018:	4633      	mov	r3, r6
 800201a:	f141 0100 	adc.w	r1, r1, #0
 800201e:	f01c fc37 	bl	801e890 <__aeabi_uldivmod>
 8002022:	f5a0 7240 	sub.w	r2, r0, #768	; 0x300
 8002026:	4b3c      	ldr	r3, [pc, #240]	; (8002118 <UART_SetConfig+0x2a0>)
 8002028:	429a      	cmp	r2, r3
 800202a:	d87d      	bhi.n	8002128 <UART_SetConfig+0x2b0>
 800202c:	6823      	ldr	r3, [r4, #0]
 800202e:	60d8      	str	r0, [r3, #12]
 8002030:	4630      	mov	r0, r6
 8002032:	e050      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002034:	f023 fe3a 	bl	8025cac <HAL_RCC_GetSysClockFreq>
 8002038:	e7cf      	b.n	8001fda <UART_SetConfig+0x162>
 800203a:	4838      	ldr	r0, [pc, #224]	; (800211c <UART_SetConfig+0x2a4>)
 800203c:	e7d0      	b.n	8001fe0 <UART_SetConfig+0x168>
 800203e:	2a08      	cmp	r2, #8
 8002040:	d874      	bhi.n	800212c <UART_SetConfig+0x2b4>
 8002042:	e8df f002 	tbb	[pc, r2]
 8002046:	2707      	.short	0x2707
 8002048:	732a7305 	.word	0x732a7305
 800204c:	7373      	.short	0x7373
 800204e:	0b          	.byte	0x0b
 800204f:	00          	.byte	0x00
 8002050:	4832      	ldr	r0, [pc, #200]	; (800211c <UART_SetConfig+0x2a4>)
 8002052:	e003      	b.n	800205c <UART_SetConfig+0x1e4>
 8002054:	f024 fa3a 	bl	80264cc <HAL_RCC_GetPCLK1Freq>
 8002058:	2800      	cmp	r0, #0
 800205a:	d069      	beq.n	8002130 <UART_SetConfig+0x2b8>
 800205c:	6a62      	ldr	r2, [r4, #36]	; 0x24
 800205e:	4b2d      	ldr	r3, [pc, #180]	; (8002114 <UART_SetConfig+0x29c>)
 8002060:	f833 3012 	ldrh.w	r3, [r3, r2, lsl #1]
 8002064:	fbb0 f0f3 	udiv	r0, r0, r3
 8002068:	6862      	ldr	r2, [r4, #4]
 800206a:	0853      	lsrs	r3, r2, #1
 800206c:	eb03 0040 	add.w	r0, r3, r0, lsl #1
 8002070:	fbb0 f0f2 	udiv	r0, r0, r2
 8002074:	b280      	uxth	r0, r0
 8002076:	f1a0 0210 	sub.w	r2, r0, #16
 800207a:	f64f 73ef 	movw	r3, #65519	; 0xffef
 800207e:	429a      	cmp	r2, r3
 8002080:	d858      	bhi.n	8002134 <UART_SetConfig+0x2bc>
 8002082:	f020 030f 	bic.w	r3, r0, #15
 8002086:	f3c0 0042 	ubfx	r0, r0, #1, #3
 800208a:	4318      	orrs	r0, r3
 800208c:	6823      	ldr	r3, [r4, #0]
 800208e:	60d8      	str	r0, [r3, #12]
 8002090:	2000      	movs	r0, #0
 8002092:	e020      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002094:	f024 fa2a 	bl	80264ec <HAL_RCC_GetPCLK2Freq>
 8002098:	e7de      	b.n	8002058 <UART_SetConfig+0x1e0>
 800209a:	f023 fe07 	bl	8025cac <HAL_RCC_GetSysClockFreq>
 800209e:	e7db      	b.n	8002058 <UART_SetConfig+0x1e0>
 80020a0:	481e      	ldr	r0, [pc, #120]	; (800211c <UART_SetConfig+0x2a4>)
 80020a2:	e003      	b.n	80020ac <UART_SetConfig+0x234>
 80020a4:	f024 fa12 	bl	80264cc <HAL_RCC_GetPCLK1Freq>
 80020a8:	2800      	cmp	r0, #0
 80020aa:	d047      	beq.n	800213c <UART_SetConfig+0x2c4>
 80020ac:	6a62      	ldr	r2, [r4, #36]	; 0x24
 80020ae:	4b19      	ldr	r3, [pc, #100]	; (8002114 <UART_SetConfig+0x29c>)
 80020b0:	f833 3012 	ldrh.w	r3, [r3, r2, lsl #1]
 80020b4:	fbb0 f0f3 	udiv	r0, r0, r3
 80020b8:	6863      	ldr	r3, [r4, #4]
 80020ba:	eb00 0053 	add.w	r0, r0, r3, lsr #1
 80020be:	fbb0 f0f3 	udiv	r0, r0, r3
 80020c2:	b280      	uxth	r0, r0
 80020c4:	f1a0 0210 	sub.w	r2, r0, #16
 80020c8:	f64f 73ef 	movw	r3, #65519	; 0xffef
 80020cc:	429a      	cmp	r2, r3
 80020ce:	d837      	bhi.n	8002140 <UART_SetConfig+0x2c8>
 80020d0:	6823      	ldr	r3, [r4, #0]
 80020d2:	60d8      	str	r0, [r3, #12]
 80020d4:	2000      	movs	r0, #0
 80020d6:	2301      	movs	r3, #1
 80020d8:	f8a4 306a 	strh.w	r3, [r4, #106]	; 0x6a
 80020dc:	f8a4 3068 	strh.w	r3, [r4, #104]	; 0x68
 80020e0:	2300      	movs	r3, #0
 80020e2:	6723      	str	r3, [r4, #112]	; 0x70
 80020e4:	6763      	str	r3, [r4, #116]	; 0x74
 80020e6:	bd70      	pop	{r4, r5, r6, pc}
 80020e8:	f024 fa00 	bl	80264ec <HAL_RCC_GetPCLK2Freq>
 80020ec:	e7dc      	b.n	80020a8 <UART_SetConfig+0x230>
 80020ee:	f023 fddd 	bl	8025cac <HAL_RCC_GetSysClockFreq>
 80020f2:	e7d9      	b.n	80020a8 <UART_SetConfig+0x230>
 80020f4:	f44f 4000 	mov.w	r0, #32768	; 0x8000
 80020f8:	e7d8      	b.n	80020ac <UART_SetConfig+0x234>
 80020fa:	2001      	movs	r0, #1
 80020fc:	e7eb      	b.n	80020d6 <UART_SetConfig+0x25e>
 80020fe:	2000      	movs	r0, #0
 8002100:	e7e9      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002102:	bf00      	nop
 8002104:	cfff69f3 	.word	0xcfff69f3
 8002108:	40008000 	.word	0x40008000
 800210c:	40013800 	.word	0x40013800
 8002110:	40004400 	.word	0x40004400
 8002114:	08002ba0 	.word	0x08002ba0
 8002118:	000ffcff 	.word	0x000ffcff
 800211c:	00f42400 	.word	0x00f42400
 8002120:	2001      	movs	r0, #1
 8002122:	e7d8      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002124:	2001      	movs	r0, #1
 8002126:	e7d6      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002128:	2001      	movs	r0, #1
 800212a:	e7d4      	b.n	80020d6 <UART_SetConfig+0x25e>
 800212c:	2001      	movs	r0, #1
 800212e:	e7d2      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002130:	2000      	movs	r0, #0
 8002132:	e7d0      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002134:	2001      	movs	r0, #1
 8002136:	e7ce      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002138:	2001      	movs	r0, #1
 800213a:	e7cc      	b.n	80020d6 <UART_SetConfig+0x25e>
 800213c:	2000      	movs	r0, #0
 800213e:	e7ca      	b.n	80020d6 <UART_SetConfig+0x25e>
 8002140:	2001      	movs	r0, #1
 8002142:	e7c8      	b.n	80020d6 <UART_SetConfig+0x25e>

08002144 <UART_AdvFeatureConfig>:
 8002144:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002146:	f013 0f01 	tst.w	r3, #1
 800214a:	d006      	beq.n	800215a <UART_AdvFeatureConfig+0x16>
 800214c:	6802      	ldr	r2, [r0, #0]
 800214e:	6853      	ldr	r3, [r2, #4]
 8002150:	f423 3300 	bic.w	r3, r3, #131072	; 0x20000
 8002154:	6ac1      	ldr	r1, [r0, #44]	; 0x2c
 8002156:	430b      	orrs	r3, r1
 8002158:	6053      	str	r3, [r2, #4]
 800215a:	6a83      	ldr	r3, [r0, #40]	; 0x28
 800215c:	f013 0f02 	tst.w	r3, #2
 8002160:	d006      	beq.n	8002170 <UART_AdvFeatureConfig+0x2c>
 8002162:	6802      	ldr	r2, [r0, #0]
 8002164:	6853      	ldr	r3, [r2, #4]
 8002166:	f423 3380 	bic.w	r3, r3, #65536	; 0x10000
 800216a:	6b01      	ldr	r1, [r0, #48]	; 0x30
 800216c:	430b      	orrs	r3, r1
 800216e:	6053      	str	r3, [r2, #4]
 8002170:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002172:	f013 0f04 	tst.w	r3, #4
 8002176:	d006      	beq.n	8002186 <UART_AdvFeatureConfig+0x42>
 8002178:	6802      	ldr	r2, [r0, #0]
 800217a:	6853      	ldr	r3, [r2, #4]
 800217c:	f423 2380 	bic.w	r3, r3, #262144	; 0x40000
 8002180:	6b41      	ldr	r1, [r0, #52]	; 0x34
 8002182:	430b      	orrs	r3, r1
 8002184:	6053      	str	r3, [r2, #4]
 8002186:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002188:	f013 0f08 	tst.w	r3, #8
 800218c:	d006      	beq.n	800219c <UART_AdvFeatureConfig+0x58>
 800218e:	6802      	ldr	r2, [r0, #0]
 8002190:	6853      	ldr	r3, [r2, #4]
 8002192:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 8002196:	6b81      	ldr	r1, [r0, #56]	; 0x38
 8002198:	430b      	orrs	r3, r1
 800219a:	6053      	str	r3, [r2, #4]
 800219c:	6a83      	ldr	r3, [r0, #40]	; 0x28
 800219e:	f013 0f10 	tst.w	r3, #16
 80021a2:	d006      	beq.n	80021b2 <UART_AdvFeatureConfig+0x6e>
 80021a4:	6802      	ldr	r2, [r0, #0]
 80021a6:	6893      	ldr	r3, [r2, #8]
 80021a8:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
 80021ac:	6bc1      	ldr	r1, [r0, #60]	; 0x3c
 80021ae:	430b      	orrs	r3, r1
 80021b0:	6093      	str	r3, [r2, #8]
 80021b2:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80021b4:	f013 0f20 	tst.w	r3, #32
 80021b8:	d006      	beq.n	80021c8 <UART_AdvFeatureConfig+0x84>
 80021ba:	6802      	ldr	r2, [r0, #0]
 80021bc:	6893      	ldr	r3, [r2, #8]
 80021be:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 80021c2:	6c01      	ldr	r1, [r0, #64]	; 0x40
 80021c4:	430b      	orrs	r3, r1
 80021c6:	6093      	str	r3, [r2, #8]
 80021c8:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80021ca:	f013 0f40 	tst.w	r3, #64	; 0x40
 80021ce:	d00a      	beq.n	80021e6 <UART_AdvFeatureConfig+0xa2>
 80021d0:	6802      	ldr	r2, [r0, #0]
 80021d2:	6853      	ldr	r3, [r2, #4]
 80021d4:	f423 1380 	bic.w	r3, r3, #1048576	; 0x100000
 80021d8:	6c41      	ldr	r1, [r0, #68]	; 0x44
 80021da:	430b      	orrs	r3, r1
 80021dc:	6053      	str	r3, [r2, #4]
 80021de:	6c43      	ldr	r3, [r0, #68]	; 0x44
 80021e0:	f5b3 1f80 	cmp.w	r3, #1048576	; 0x100000
 80021e4:	d00b      	beq.n	80021fe <UART_AdvFeatureConfig+0xba>
 80021e6:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80021e8:	f013 0f80 	tst.w	r3, #128	; 0x80
 80021ec:	d006      	beq.n	80021fc <UART_AdvFeatureConfig+0xb8>
 80021ee:	6802      	ldr	r2, [r0, #0]
 80021f0:	6853      	ldr	r3, [r2, #4]
 80021f2:	f423 2300 	bic.w	r3, r3, #524288	; 0x80000
 80021f6:	6cc1      	ldr	r1, [r0, #76]	; 0x4c
 80021f8:	430b      	orrs	r3, r1
 80021fa:	6053      	str	r3, [r2, #4]
 80021fc:	4770      	bx	lr
 80021fe:	6802      	ldr	r2, [r0, #0]
 8002200:	6853      	ldr	r3, [r2, #4]
 8002202:	f423 03c0 	bic.w	r3, r3, #6291456	; 0x600000
 8002206:	6c81      	ldr	r1, [r0, #72]	; 0x48
 8002208:	430b      	orrs	r3, r1
 800220a:	6053      	str	r3, [r2, #4]
 800220c:	e7eb      	b.n	80021e6 <UART_AdvFeatureConfig+0xa2>

0800220e <UART_WaitOnFlagUntilTimeout>:
 800220e:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8002212:	4605      	mov	r5, r0
 8002214:	460f      	mov	r7, r1
 8002216:	4616      	mov	r6, r2
 8002218:	4699      	mov	r9, r3
 800221a:	f8dd 8020 	ldr.w	r8, [sp, #32]
 800221e:	682c      	ldr	r4, [r5, #0]
 8002220:	69e4      	ldr	r4, [r4, #28]
 8002222:	ea37 0304 	bics.w	r3, r7, r4
 8002226:	bf0c      	ite	eq
 8002228:	f04f 0c01 	moveq.w	ip, #1
 800222c:	f04f 0c00 	movne.w	ip, #0
 8002230:	45b4      	cmp	ip, r6
 8002232:	d157      	bne.n	80022e4 <UART_WaitOnFlagUntilTimeout+0xd6>
 8002234:	f1b8 3fff 	cmp.w	r8, #4294967295	; 0xffffffff
 8002238:	d0f1      	beq.n	800221e <UART_WaitOnFlagUntilTimeout+0x10>
 800223a:	f023 fb0b 	bl	8025854 <HAL_GetTick>
 800223e:	eba0 0009 	sub.w	r0, r0, r9
 8002242:	4540      	cmp	r0, r8
 8002244:	d82f      	bhi.n	80022a6 <UART_WaitOnFlagUntilTimeout+0x98>
 8002246:	f1b8 0f00 	cmp.w	r8, #0
 800224a:	d02c      	beq.n	80022a6 <UART_WaitOnFlagUntilTimeout+0x98>
 800224c:	682b      	ldr	r3, [r5, #0]
 800224e:	681a      	ldr	r2, [r3, #0]
 8002250:	f012 0f04 	tst.w	r2, #4
 8002254:	d0e3      	beq.n	800221e <UART_WaitOnFlagUntilTimeout+0x10>
 8002256:	69da      	ldr	r2, [r3, #28]
 8002258:	f412 6f00 	tst.w	r2, #2048	; 0x800
 800225c:	d0df      	beq.n	800221e <UART_WaitOnFlagUntilTimeout+0x10>
 800225e:	f44f 6200 	mov.w	r2, #2048	; 0x800
 8002262:	621a      	str	r2, [r3, #32]
 8002264:	682a      	ldr	r2, [r5, #0]
 8002266:	e852 3f00 	ldrex	r3, [r2]
 800226a:	f423 73d0 	bic.w	r3, r3, #416	; 0x1a0
 800226e:	e842 3100 	strex	r1, r3, [r2]
 8002272:	2900      	cmp	r1, #0
 8002274:	d1f6      	bne.n	8002264 <UART_WaitOnFlagUntilTimeout+0x56>
 8002276:	682a      	ldr	r2, [r5, #0]
 8002278:	f102 0308 	add.w	r3, r2, #8
 800227c:	e853 3f00 	ldrex	r3, [r3]
 8002280:	f023 0301 	bic.w	r3, r3, #1
 8002284:	3208      	adds	r2, #8
 8002286:	e842 3100 	strex	r1, r3, [r2]
 800228a:	2900      	cmp	r1, #0
 800228c:	d1f3      	bne.n	8002276 <UART_WaitOnFlagUntilTimeout+0x68>
 800228e:	2320      	movs	r3, #32
 8002290:	f8c5 3084 	str.w	r3, [r5, #132]	; 0x84
 8002294:	f8c5 3088 	str.w	r3, [r5, #136]	; 0x88
 8002298:	f8c5 308c 	str.w	r3, [r5, #140]	; 0x8c
 800229c:	2300      	movs	r3, #0
 800229e:	f885 3080 	strb.w	r3, [r5, #128]	; 0x80
 80022a2:	2003      	movs	r0, #3
 80022a4:	e01f      	b.n	80022e6 <UART_WaitOnFlagUntilTimeout+0xd8>
 80022a6:	682a      	ldr	r2, [r5, #0]
 80022a8:	e852 3f00 	ldrex	r3, [r2]
 80022ac:	f423 73d0 	bic.w	r3, r3, #416	; 0x1a0
 80022b0:	e842 3100 	strex	r1, r3, [r2]
 80022b4:	2900      	cmp	r1, #0
 80022b6:	d1f6      	bne.n	80022a6 <UART_WaitOnFlagUntilTimeout+0x98>
 80022b8:	682a      	ldr	r2, [r5, #0]
 80022ba:	f102 0308 	add.w	r3, r2, #8
 80022be:	e853 3f00 	ldrex	r3, [r3]
 80022c2:	f023 0301 	bic.w	r3, r3, #1
 80022c6:	3208      	adds	r2, #8
 80022c8:	e842 3100 	strex	r1, r3, [r2]
 80022cc:	2900      	cmp	r1, #0
 80022ce:	d1f3      	bne.n	80022b8 <UART_WaitOnFlagUntilTimeout+0xaa>
 80022d0:	2320      	movs	r3, #32
 80022d2:	f8c5 3084 	str.w	r3, [r5, #132]	; 0x84
 80022d6:	f8c5 3088 	str.w	r3, [r5, #136]	; 0x88
 80022da:	2300      	movs	r3, #0
 80022dc:	f885 3080 	strb.w	r3, [r5, #128]	; 0x80
 80022e0:	2003      	movs	r0, #3
 80022e2:	e000      	b.n	80022e6 <UART_WaitOnFlagUntilTimeout+0xd8>
 80022e4:	2000      	movs	r0, #0
 80022e6:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}

080022ea <HAL_UART_Transmit>:
 80022ea:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 80022ee:	b082      	sub	sp, #8
 80022f0:	461e      	mov	r6, r3
 80022f2:	f8d0 3084 	ldr.w	r3, [r0, #132]	; 0x84
 80022f6:	2b20      	cmp	r3, #32
 80022f8:	d158      	bne.n	80023ac <HAL_UART_Transmit+0xc2>
 80022fa:	4604      	mov	r4, r0
 80022fc:	460d      	mov	r5, r1
 80022fe:	4690      	mov	r8, r2
 8002300:	2900      	cmp	r1, #0
 8002302:	d057      	beq.n	80023b4 <HAL_UART_Transmit+0xca>
 8002304:	2a00      	cmp	r2, #0
 8002306:	d057      	beq.n	80023b8 <HAL_UART_Transmit+0xce>
 8002308:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 800230c:	2b01      	cmp	r3, #1
 800230e:	d055      	beq.n	80023bc <HAL_UART_Transmit+0xd2>
 8002310:	2301      	movs	r3, #1
 8002312:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002316:	2300      	movs	r3, #0
 8002318:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 800231c:	2321      	movs	r3, #33	; 0x21
 800231e:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8002322:	f023 fa97 	bl	8025854 <HAL_GetTick>
 8002326:	4607      	mov	r7, r0
 8002328:	f8a4 8054 	strh.w	r8, [r4, #84]	; 0x54
 800232c:	f8a4 8056 	strh.w	r8, [r4, #86]	; 0x56
 8002330:	68a3      	ldr	r3, [r4, #8]
 8002332:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002336:	d005      	beq.n	8002344 <HAL_UART_Transmit+0x5a>
 8002338:	f04f 0800 	mov.w	r8, #0
 800233c:	2300      	movs	r3, #0
 800233e:	f884 3080 	strb.w	r3, [r4, #128]	; 0x80
 8002342:	e014      	b.n	800236e <HAL_UART_Transmit+0x84>
 8002344:	6923      	ldr	r3, [r4, #16]
 8002346:	b113      	cbz	r3, 800234e <HAL_UART_Transmit+0x64>
 8002348:	f04f 0800 	mov.w	r8, #0
 800234c:	e7f6      	b.n	800233c <HAL_UART_Transmit+0x52>
 800234e:	46a8      	mov	r8, r5
 8002350:	2500      	movs	r5, #0
 8002352:	e7f3      	b.n	800233c <HAL_UART_Transmit+0x52>
 8002354:	f838 3b02 	ldrh.w	r3, [r8], #2
 8002358:	6822      	ldr	r2, [r4, #0]
 800235a:	f3c3 0308 	ubfx	r3, r3, #0, #9
 800235e:	6293      	str	r3, [r2, #40]	; 0x28
 8002360:	f8b4 2056 	ldrh.w	r2, [r4, #86]	; 0x56
 8002364:	b292      	uxth	r2, r2
 8002366:	3a01      	subs	r2, #1
 8002368:	b292      	uxth	r2, r2
 800236a:	f8a4 2056 	strh.w	r2, [r4, #86]	; 0x56
 800236e:	f8b4 3056 	ldrh.w	r3, [r4, #86]	; 0x56
 8002372:	b29b      	uxth	r3, r3
 8002374:	b173      	cbz	r3, 8002394 <HAL_UART_Transmit+0xaa>
 8002376:	9600      	str	r6, [sp, #0]
 8002378:	463b      	mov	r3, r7
 800237a:	2200      	movs	r2, #0
 800237c:	2180      	movs	r1, #128	; 0x80
 800237e:	4620      	mov	r0, r4
 8002380:	f7ff ff45 	bl	800220e <UART_WaitOnFlagUntilTimeout>
 8002384:	b9e0      	cbnz	r0, 80023c0 <HAL_UART_Transmit+0xd6>
 8002386:	2d00      	cmp	r5, #0
 8002388:	d0e4      	beq.n	8002354 <HAL_UART_Transmit+0x6a>
 800238a:	f815 2b01 	ldrb.w	r2, [r5], #1
 800238e:	6823      	ldr	r3, [r4, #0]
 8002390:	629a      	str	r2, [r3, #40]	; 0x28
 8002392:	e7e5      	b.n	8002360 <HAL_UART_Transmit+0x76>
 8002394:	9600      	str	r6, [sp, #0]
 8002396:	463b      	mov	r3, r7
 8002398:	2200      	movs	r2, #0
 800239a:	2140      	movs	r1, #64	; 0x40
 800239c:	4620      	mov	r0, r4
 800239e:	f7ff ff36 	bl	800220e <UART_WaitOnFlagUntilTimeout>
 80023a2:	b978      	cbnz	r0, 80023c4 <HAL_UART_Transmit+0xda>
 80023a4:	2320      	movs	r3, #32
 80023a6:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 80023aa:	e000      	b.n	80023ae <HAL_UART_Transmit+0xc4>
 80023ac:	2002      	movs	r0, #2
 80023ae:	b002      	add	sp, #8
 80023b0:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 80023b4:	2001      	movs	r0, #1
 80023b6:	e7fa      	b.n	80023ae <HAL_UART_Transmit+0xc4>
 80023b8:	2001      	movs	r0, #1
 80023ba:	e7f8      	b.n	80023ae <HAL_UART_Transmit+0xc4>
 80023bc:	2002      	movs	r0, #2
 80023be:	e7f6      	b.n	80023ae <HAL_UART_Transmit+0xc4>
 80023c0:	2003      	movs	r0, #3
 80023c2:	e7f4      	b.n	80023ae <HAL_UART_Transmit+0xc4>
 80023c4:	2003      	movs	r0, #3
 80023c6:	e7f2      	b.n	80023ae <HAL_UART_Transmit+0xc4>

080023c8 <HAL_UART_Receive>:
 80023c8:	e92d 43f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, lr}
 80023cc:	b083      	sub	sp, #12
 80023ce:	461e      	mov	r6, r3
 80023d0:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 80023d4:	2b20      	cmp	r3, #32
 80023d6:	f040 8081 	bne.w	80024dc <HAL_UART_Receive+0x114>
 80023da:	4604      	mov	r4, r0
 80023dc:	460d      	mov	r5, r1
 80023de:	4690      	mov	r8, r2
 80023e0:	2900      	cmp	r1, #0
 80023e2:	d07f      	beq.n	80024e4 <HAL_UART_Receive+0x11c>
 80023e4:	2a00      	cmp	r2, #0
 80023e6:	d07f      	beq.n	80024e8 <HAL_UART_Receive+0x120>
 80023e8:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 80023ec:	2b01      	cmp	r3, #1
 80023ee:	d07d      	beq.n	80024ec <HAL_UART_Receive+0x124>
 80023f0:	2301      	movs	r3, #1
 80023f2:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80023f6:	2300      	movs	r3, #0
 80023f8:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 80023fc:	2222      	movs	r2, #34	; 0x22
 80023fe:	f8c0 2088 	str.w	r2, [r0, #136]	; 0x88
 8002402:	66c3      	str	r3, [r0, #108]	; 0x6c
 8002404:	f023 fa26 	bl	8025854 <HAL_GetTick>
 8002408:	4607      	mov	r7, r0
 800240a:	f8a4 805c 	strh.w	r8, [r4, #92]	; 0x5c
 800240e:	f8a4 805e 	strh.w	r8, [r4, #94]	; 0x5e
 8002412:	68a3      	ldr	r3, [r4, #8]
 8002414:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002418:	d006      	beq.n	8002428 <HAL_UART_Receive+0x60>
 800241a:	b9a3      	cbnz	r3, 8002446 <HAL_UART_Receive+0x7e>
 800241c:	6922      	ldr	r2, [r4, #16]
 800241e:	b972      	cbnz	r2, 800243e <HAL_UART_Receive+0x76>
 8002420:	22ff      	movs	r2, #255	; 0xff
 8002422:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 8002426:	e014      	b.n	8002452 <HAL_UART_Receive+0x8a>
 8002428:	6922      	ldr	r2, [r4, #16]
 800242a:	b922      	cbnz	r2, 8002436 <HAL_UART_Receive+0x6e>
 800242c:	f240 12ff 	movw	r2, #511	; 0x1ff
 8002430:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 8002434:	e00d      	b.n	8002452 <HAL_UART_Receive+0x8a>
 8002436:	22ff      	movs	r2, #255	; 0xff
 8002438:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 800243c:	e009      	b.n	8002452 <HAL_UART_Receive+0x8a>
 800243e:	227f      	movs	r2, #127	; 0x7f
 8002440:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 8002444:	e005      	b.n	8002452 <HAL_UART_Receive+0x8a>
 8002446:	f1b3 5f80 	cmp.w	r3, #268435456	; 0x10000000
 800244a:	d00d      	beq.n	8002468 <HAL_UART_Receive+0xa0>
 800244c:	2200      	movs	r2, #0
 800244e:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 8002452:	f8b4 8060 	ldrh.w	r8, [r4, #96]	; 0x60
 8002456:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 800245a:	d00f      	beq.n	800247c <HAL_UART_Receive+0xb4>
 800245c:	f04f 0900 	mov.w	r9, #0
 8002460:	2300      	movs	r3, #0
 8002462:	f884 3080 	strb.w	r3, [r4, #128]	; 0x80
 8002466:	e01e      	b.n	80024a6 <HAL_UART_Receive+0xde>
 8002468:	6922      	ldr	r2, [r4, #16]
 800246a:	b91a      	cbnz	r2, 8002474 <HAL_UART_Receive+0xac>
 800246c:	227f      	movs	r2, #127	; 0x7f
 800246e:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 8002472:	e7ee      	b.n	8002452 <HAL_UART_Receive+0x8a>
 8002474:	223f      	movs	r2, #63	; 0x3f
 8002476:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 800247a:	e7ea      	b.n	8002452 <HAL_UART_Receive+0x8a>
 800247c:	6923      	ldr	r3, [r4, #16]
 800247e:	b113      	cbz	r3, 8002486 <HAL_UART_Receive+0xbe>
 8002480:	f04f 0900 	mov.w	r9, #0
 8002484:	e7ec      	b.n	8002460 <HAL_UART_Receive+0x98>
 8002486:	46a9      	mov	r9, r5
 8002488:	2500      	movs	r5, #0
 800248a:	e7e9      	b.n	8002460 <HAL_UART_Receive+0x98>
 800248c:	6823      	ldr	r3, [r4, #0]
 800248e:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8002490:	ea08 0303 	and.w	r3, r8, r3
 8002494:	f829 3b02 	strh.w	r3, [r9], #2
 8002498:	f8b4 205e 	ldrh.w	r2, [r4, #94]	; 0x5e
 800249c:	b292      	uxth	r2, r2
 800249e:	3a01      	subs	r2, #1
 80024a0:	b292      	uxth	r2, r2
 80024a2:	f8a4 205e 	strh.w	r2, [r4, #94]	; 0x5e
 80024a6:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 80024aa:	b29b      	uxth	r3, r3
 80024ac:	b18b      	cbz	r3, 80024d2 <HAL_UART_Receive+0x10a>
 80024ae:	9600      	str	r6, [sp, #0]
 80024b0:	463b      	mov	r3, r7
 80024b2:	2200      	movs	r2, #0
 80024b4:	2120      	movs	r1, #32
 80024b6:	4620      	mov	r0, r4
 80024b8:	f7ff fea9 	bl	800220e <UART_WaitOnFlagUntilTimeout>
 80024bc:	b9c0      	cbnz	r0, 80024f0 <HAL_UART_Receive+0x128>
 80024be:	2d00      	cmp	r5, #0
 80024c0:	d0e4      	beq.n	800248c <HAL_UART_Receive+0xc4>
 80024c2:	6823      	ldr	r3, [r4, #0]
 80024c4:	6a5a      	ldr	r2, [r3, #36]	; 0x24
 80024c6:	fa5f f388 	uxtb.w	r3, r8
 80024ca:	4013      	ands	r3, r2
 80024cc:	f805 3b01 	strb.w	r3, [r5], #1
 80024d0:	e7e2      	b.n	8002498 <HAL_UART_Receive+0xd0>
 80024d2:	2320      	movs	r3, #32
 80024d4:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80024d8:	2000      	movs	r0, #0
 80024da:	e000      	b.n	80024de <HAL_UART_Receive+0x116>
 80024dc:	2002      	movs	r0, #2
 80024de:	b003      	add	sp, #12
 80024e0:	e8bd 83f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, pc}
 80024e4:	2001      	movs	r0, #1
 80024e6:	e7fa      	b.n	80024de <HAL_UART_Receive+0x116>
 80024e8:	2001      	movs	r0, #1
 80024ea:	e7f8      	b.n	80024de <HAL_UART_Receive+0x116>
 80024ec:	2002      	movs	r0, #2
 80024ee:	e7f6      	b.n	80024de <HAL_UART_Receive+0x116>
 80024f0:	2003      	movs	r0, #3
 80024f2:	e7f4      	b.n	80024de <HAL_UART_Receive+0x116>

080024f4 <UART_CheckIdleState>:
 80024f4:	b530      	push	{r4, r5, lr}
 80024f6:	b083      	sub	sp, #12
 80024f8:	4604      	mov	r4, r0
 80024fa:	2300      	movs	r3, #0
 80024fc:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 8002500:	f023 f9a8 	bl	8025854 <HAL_GetTick>
 8002504:	4605      	mov	r5, r0
 8002506:	6822      	ldr	r2, [r4, #0]
 8002508:	6812      	ldr	r2, [r2, #0]
 800250a:	f012 0f08 	tst.w	r2, #8
 800250e:	d10f      	bne.n	8002530 <UART_CheckIdleState+0x3c>
 8002510:	6823      	ldr	r3, [r4, #0]
 8002512:	681b      	ldr	r3, [r3, #0]
 8002514:	f013 0f04 	tst.w	r3, #4
 8002518:	d118      	bne.n	800254c <UART_CheckIdleState+0x58>
 800251a:	2320      	movs	r3, #32
 800251c:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 8002520:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8002524:	2000      	movs	r0, #0
 8002526:	66e0      	str	r0, [r4, #108]	; 0x6c
 8002528:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 800252c:	b003      	add	sp, #12
 800252e:	bd30      	pop	{r4, r5, pc}
 8002530:	f06f 437e 	mvn.w	r3, #4261412864	; 0xfe000000
 8002534:	9300      	str	r3, [sp, #0]
 8002536:	4603      	mov	r3, r0
 8002538:	2200      	movs	r2, #0
 800253a:	f44f 1100 	mov.w	r1, #2097152	; 0x200000
 800253e:	4620      	mov	r0, r4
 8002540:	f7ff fe65 	bl	800220e <UART_WaitOnFlagUntilTimeout>
 8002544:	2800      	cmp	r0, #0
 8002546:	d0e3      	beq.n	8002510 <UART_CheckIdleState+0x1c>
 8002548:	2003      	movs	r0, #3
 800254a:	e7ef      	b.n	800252c <UART_CheckIdleState+0x38>
 800254c:	f06f 437e 	mvn.w	r3, #4261412864	; 0xfe000000
 8002550:	9300      	str	r3, [sp, #0]
 8002552:	462b      	mov	r3, r5
 8002554:	2200      	movs	r2, #0
 8002556:	f44f 0180 	mov.w	r1, #4194304	; 0x400000
 800255a:	4620      	mov	r0, r4
 800255c:	f7ff fe57 	bl	800220e <UART_WaitOnFlagUntilTimeout>
 8002560:	2800      	cmp	r0, #0
 8002562:	d0da      	beq.n	800251a <UART_CheckIdleState+0x26>
 8002564:	2003      	movs	r0, #3
 8002566:	e7e1      	b.n	800252c <UART_CheckIdleState+0x38>

08002568 <HAL_UART_Init>:
 8002568:	b378      	cbz	r0, 80025ca <HAL_UART_Init+0x62>
 800256a:	b510      	push	{r4, lr}
 800256c:	4604      	mov	r4, r0
 800256e:	f8d0 3084 	ldr.w	r3, [r0, #132]	; 0x84
 8002572:	b30b      	cbz	r3, 80025b8 <HAL_UART_Init+0x50>
 8002574:	2324      	movs	r3, #36	; 0x24
 8002576:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 800257a:	6822      	ldr	r2, [r4, #0]
 800257c:	6813      	ldr	r3, [r2, #0]
 800257e:	f023 0301 	bic.w	r3, r3, #1
 8002582:	6013      	str	r3, [r2, #0]
 8002584:	4620      	mov	r0, r4
 8002586:	f7ff fc77 	bl	8001e78 <UART_SetConfig>
 800258a:	2801      	cmp	r0, #1
 800258c:	d013      	beq.n	80025b6 <HAL_UART_Init+0x4e>
 800258e:	6aa3      	ldr	r3, [r4, #40]	; 0x28
 8002590:	b9bb      	cbnz	r3, 80025c2 <HAL_UART_Init+0x5a>
 8002592:	6822      	ldr	r2, [r4, #0]
 8002594:	6853      	ldr	r3, [r2, #4]
 8002596:	f423 4390 	bic.w	r3, r3, #18432	; 0x4800
 800259a:	6053      	str	r3, [r2, #4]
 800259c:	6822      	ldr	r2, [r4, #0]
 800259e:	6893      	ldr	r3, [r2, #8]
 80025a0:	f023 032a 	bic.w	r3, r3, #42	; 0x2a
 80025a4:	6093      	str	r3, [r2, #8]
 80025a6:	6822      	ldr	r2, [r4, #0]
 80025a8:	6813      	ldr	r3, [r2, #0]
 80025aa:	f043 0301 	orr.w	r3, r3, #1
 80025ae:	6013      	str	r3, [r2, #0]
 80025b0:	4620      	mov	r0, r4
 80025b2:	f7ff ff9f 	bl	80024f4 <UART_CheckIdleState>
 80025b6:	bd10      	pop	{r4, pc}
 80025b8:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80025bc:	f7fe fa68 	bl	8000a90 <HAL_UART_MspInit>
 80025c0:	e7d8      	b.n	8002574 <HAL_UART_Init+0xc>
 80025c2:	4620      	mov	r0, r4
 80025c4:	f7ff fdbe 	bl	8002144 <UART_AdvFeatureConfig>
 80025c8:	e7e3      	b.n	8002592 <HAL_UART_Init+0x2a>
 80025ca:	2001      	movs	r0, #1
 80025cc:	4770      	bx	lr
	...

080025d0 <UART_Start_Receive_IT>:
 80025d0:	b410      	push	{r4}
 80025d2:	6581      	str	r1, [r0, #88]	; 0x58
 80025d4:	f8a0 205c 	strh.w	r2, [r0, #92]	; 0x5c
 80025d8:	f8a0 205e 	strh.w	r2, [r0, #94]	; 0x5e
 80025dc:	2300      	movs	r3, #0
 80025de:	6703      	str	r3, [r0, #112]	; 0x70
 80025e0:	6883      	ldr	r3, [r0, #8]
 80025e2:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80025e6:	d006      	beq.n	80025f6 <UART_Start_Receive_IT+0x26>
 80025e8:	b9a3      	cbnz	r3, 8002614 <UART_Start_Receive_IT+0x44>
 80025ea:	6903      	ldr	r3, [r0, #16]
 80025ec:	b973      	cbnz	r3, 800260c <UART_Start_Receive_IT+0x3c>
 80025ee:	23ff      	movs	r3, #255	; 0xff
 80025f0:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 80025f4:	e014      	b.n	8002620 <UART_Start_Receive_IT+0x50>
 80025f6:	6903      	ldr	r3, [r0, #16]
 80025f8:	b923      	cbnz	r3, 8002604 <UART_Start_Receive_IT+0x34>
 80025fa:	f240 13ff 	movw	r3, #511	; 0x1ff
 80025fe:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002602:	e00d      	b.n	8002620 <UART_Start_Receive_IT+0x50>
 8002604:	23ff      	movs	r3, #255	; 0xff
 8002606:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 800260a:	e009      	b.n	8002620 <UART_Start_Receive_IT+0x50>
 800260c:	237f      	movs	r3, #127	; 0x7f
 800260e:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002612:	e005      	b.n	8002620 <UART_Start_Receive_IT+0x50>
 8002614:	f1b3 5f80 	cmp.w	r3, #268435456	; 0x10000000
 8002618:	d02d      	beq.n	8002676 <UART_Start_Receive_IT+0xa6>
 800261a:	2300      	movs	r3, #0
 800261c:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002620:	2300      	movs	r3, #0
 8002622:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 8002626:	2322      	movs	r3, #34	; 0x22
 8002628:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 800262c:	6801      	ldr	r1, [r0, #0]
 800262e:	f101 0308 	add.w	r3, r1, #8
 8002632:	e853 3f00 	ldrex	r3, [r3]
 8002636:	f043 0301 	orr.w	r3, r3, #1
 800263a:	3108      	adds	r1, #8
 800263c:	e841 3400 	strex	r4, r3, [r1]
 8002640:	2c00      	cmp	r4, #0
 8002642:	d1f3      	bne.n	800262c <UART_Start_Receive_IT+0x5c>
 8002644:	6e43      	ldr	r3, [r0, #100]	; 0x64
 8002646:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 800264a:	d01e      	beq.n	800268a <UART_Start_Receive_IT+0xba>
 800264c:	6883      	ldr	r3, [r0, #8]
 800264e:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002652:	d043      	beq.n	80026dc <UART_Start_Receive_IT+0x10c>
 8002654:	4b24      	ldr	r3, [pc, #144]	; (80026e8 <UART_Start_Receive_IT+0x118>)
 8002656:	6703      	str	r3, [r0, #112]	; 0x70
 8002658:	2300      	movs	r3, #0
 800265a:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 800265e:	6802      	ldr	r2, [r0, #0]
 8002660:	e852 3f00 	ldrex	r3, [r2]
 8002664:	f443 7390 	orr.w	r3, r3, #288	; 0x120
 8002668:	e842 3100 	strex	r1, r3, [r2]
 800266c:	2900      	cmp	r1, #0
 800266e:	d1f6      	bne.n	800265e <UART_Start_Receive_IT+0x8e>
 8002670:	2000      	movs	r0, #0
 8002672:	bc10      	pop	{r4}
 8002674:	4770      	bx	lr
 8002676:	6903      	ldr	r3, [r0, #16]
 8002678:	b91b      	cbnz	r3, 8002682 <UART_Start_Receive_IT+0xb2>
 800267a:	237f      	movs	r3, #127	; 0x7f
 800267c:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002680:	e7ce      	b.n	8002620 <UART_Start_Receive_IT+0x50>
 8002682:	233f      	movs	r3, #63	; 0x3f
 8002684:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002688:	e7ca      	b.n	8002620 <UART_Start_Receive_IT+0x50>
 800268a:	f8b0 3068 	ldrh.w	r3, [r0, #104]	; 0x68
 800268e:	4293      	cmp	r3, r2
 8002690:	d8dc      	bhi.n	800264c <UART_Start_Receive_IT+0x7c>
 8002692:	6883      	ldr	r3, [r0, #8]
 8002694:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002698:	d01a      	beq.n	80026d0 <UART_Start_Receive_IT+0x100>
 800269a:	4b14      	ldr	r3, [pc, #80]	; (80026ec <UART_Start_Receive_IT+0x11c>)
 800269c:	6703      	str	r3, [r0, #112]	; 0x70
 800269e:	2300      	movs	r3, #0
 80026a0:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80026a4:	6802      	ldr	r2, [r0, #0]
 80026a6:	e852 3f00 	ldrex	r3, [r2]
 80026aa:	f443 7380 	orr.w	r3, r3, #256	; 0x100
 80026ae:	e842 3100 	strex	r1, r3, [r2]
 80026b2:	2900      	cmp	r1, #0
 80026b4:	d1f6      	bne.n	80026a4 <UART_Start_Receive_IT+0xd4>
 80026b6:	6802      	ldr	r2, [r0, #0]
 80026b8:	f102 0308 	add.w	r3, r2, #8
 80026bc:	e853 3f00 	ldrex	r3, [r3]
 80026c0:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 80026c4:	3208      	adds	r2, #8
 80026c6:	e842 3100 	strex	r1, r3, [r2]
 80026ca:	2900      	cmp	r1, #0
 80026cc:	d1f3      	bne.n	80026b6 <UART_Start_Receive_IT+0xe6>
 80026ce:	e7cf      	b.n	8002670 <UART_Start_Receive_IT+0xa0>
 80026d0:	6903      	ldr	r3, [r0, #16]
 80026d2:	2b00      	cmp	r3, #0
 80026d4:	d1e1      	bne.n	800269a <UART_Start_Receive_IT+0xca>
 80026d6:	4b06      	ldr	r3, [pc, #24]	; (80026f0 <UART_Start_Receive_IT+0x120>)
 80026d8:	6703      	str	r3, [r0, #112]	; 0x70
 80026da:	e7e0      	b.n	800269e <UART_Start_Receive_IT+0xce>
 80026dc:	6903      	ldr	r3, [r0, #16]
 80026de:	2b00      	cmp	r3, #0
 80026e0:	d1b8      	bne.n	8002654 <UART_Start_Receive_IT+0x84>
 80026e2:	4b04      	ldr	r3, [pc, #16]	; (80026f4 <UART_Start_Receive_IT+0x124>)
 80026e4:	6703      	str	r3, [r0, #112]	; 0x70
 80026e6:	e7b7      	b.n	8002658 <UART_Start_Receive_IT+0x88>
 80026e8:	080019d5 	.word	0x080019d5
 80026ec:	08001b39 	.word	0x08001b39
 80026f0:	08001cd9 	.word	0x08001cd9
 80026f4:	08001a87 	.word	0x08001a87

080026f8 <HAL_UART_Receive_IT>:
 80026f8:	b538      	push	{r3, r4, r5, lr}
 80026fa:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 80026fe:	2b20      	cmp	r3, #32
 8002700:	d117      	bne.n	8002732 <HAL_UART_Receive_IT+0x3a>
 8002702:	b1c1      	cbz	r1, 8002736 <HAL_UART_Receive_IT+0x3e>
 8002704:	b1ca      	cbz	r2, 800273a <HAL_UART_Receive_IT+0x42>
 8002706:	2300      	movs	r3, #0
 8002708:	66c3      	str	r3, [r0, #108]	; 0x6c
 800270a:	6803      	ldr	r3, [r0, #0]
 800270c:	4c0c      	ldr	r4, [pc, #48]	; (8002740 <HAL_UART_Receive_IT+0x48>)
 800270e:	42a3      	cmp	r3, r4
 8002710:	d00c      	beq.n	800272c <HAL_UART_Receive_IT+0x34>
 8002712:	685b      	ldr	r3, [r3, #4]
 8002714:	f413 0f00 	tst.w	r3, #8388608	; 0x800000
 8002718:	d008      	beq.n	800272c <HAL_UART_Receive_IT+0x34>
 800271a:	6804      	ldr	r4, [r0, #0]
 800271c:	e854 3f00 	ldrex	r3, [r4]
 8002720:	f043 6380 	orr.w	r3, r3, #67108864	; 0x4000000
 8002724:	e844 3500 	strex	r5, r3, [r4]
 8002728:	2d00      	cmp	r5, #0
 800272a:	d1f6      	bne.n	800271a <HAL_UART_Receive_IT+0x22>
 800272c:	f7ff ff50 	bl	80025d0 <UART_Start_Receive_IT>
 8002730:	e000      	b.n	8002734 <HAL_UART_Receive_IT+0x3c>
 8002732:	2002      	movs	r0, #2
 8002734:	bd38      	pop	{r3, r4, r5, pc}
 8002736:	2001      	movs	r0, #1
 8002738:	e7fc      	b.n	8002734 <HAL_UART_Receive_IT+0x3c>
 800273a:	2001      	movs	r0, #1
 800273c:	e7fa      	b.n	8002734 <HAL_UART_Receive_IT+0x3c>
 800273e:	bf00      	nop
 8002740:	40008000 	.word	0x40008000

08002744 <UARTEx_SetNbDataToProcess>:
 8002744:	6e43      	ldr	r3, [r0, #100]	; 0x64
 8002746:	b92b      	cbnz	r3, 8002754 <UARTEx_SetNbDataToProcess+0x10>
 8002748:	2301      	movs	r3, #1
 800274a:	f8a0 306a 	strh.w	r3, [r0, #106]	; 0x6a
 800274e:	f8a0 3068 	strh.w	r3, [r0, #104]	; 0x68
 8002752:	4770      	bx	lr
 8002754:	b430      	push	{r4, r5}
 8002756:	6803      	ldr	r3, [r0, #0]
 8002758:	689a      	ldr	r2, [r3, #8]
 800275a:	f3c2 6242 	ubfx	r2, r2, #25, #3
 800275e:	6899      	ldr	r1, [r3, #8]
 8002760:	0f49      	lsrs	r1, r1, #29
 8002762:	4d09      	ldr	r5, [pc, #36]	; (8002788 <UARTEx_SetNbDataToProcess+0x44>)
 8002764:	5c6b      	ldrb	r3, [r5, r1]
 8002766:	00db      	lsls	r3, r3, #3
 8002768:	4c08      	ldr	r4, [pc, #32]	; (800278c <UARTEx_SetNbDataToProcess+0x48>)
 800276a:	5c61      	ldrb	r1, [r4, r1]
 800276c:	fb93 f3f1 	sdiv	r3, r3, r1
 8002770:	f8a0 306a 	strh.w	r3, [r0, #106]	; 0x6a
 8002774:	5cab      	ldrb	r3, [r5, r2]
 8002776:	00db      	lsls	r3, r3, #3
 8002778:	5ca2      	ldrb	r2, [r4, r2]
 800277a:	fb93 f3f2 	sdiv	r3, r3, r2
 800277e:	f8a0 3068 	strh.w	r3, [r0, #104]	; 0x68
 8002782:	bc30      	pop	{r4, r5}
 8002784:	4770      	bx	lr
 8002786:	bf00      	nop
 8002788:	08002bc0 	.word	0x08002bc0
 800278c:	08002bb8 	.word	0x08002bb8

08002790 <HAL_UARTEx_WakeupCallback>:
 8002790:	4770      	bx	lr

08002792 <HAL_UARTEx_RxFifoFullCallback>:
 8002792:	4770      	bx	lr

08002794 <HAL_UARTEx_TxFifoEmptyCallback>:
 8002794:	4770      	bx	lr

08002796 <HAL_UARTEx_DisableFifoMode>:
 8002796:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 800279a:	2b01      	cmp	r3, #1
 800279c:	d018      	beq.n	80027d0 <HAL_UARTEx_DisableFifoMode+0x3a>
 800279e:	2301      	movs	r3, #1
 80027a0:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80027a4:	2324      	movs	r3, #36	; 0x24
 80027a6:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80027aa:	6803      	ldr	r3, [r0, #0]
 80027ac:	681a      	ldr	r2, [r3, #0]
 80027ae:	6819      	ldr	r1, [r3, #0]
 80027b0:	f021 0101 	bic.w	r1, r1, #1
 80027b4:	6019      	str	r1, [r3, #0]
 80027b6:	f022 5200 	bic.w	r2, r2, #536870912	; 0x20000000
 80027ba:	2300      	movs	r3, #0
 80027bc:	6643      	str	r3, [r0, #100]	; 0x64
 80027be:	6801      	ldr	r1, [r0, #0]
 80027c0:	600a      	str	r2, [r1, #0]
 80027c2:	2220      	movs	r2, #32
 80027c4:	f8c0 2084 	str.w	r2, [r0, #132]	; 0x84
 80027c8:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80027cc:	4618      	mov	r0, r3
 80027ce:	4770      	bx	lr
 80027d0:	2002      	movs	r0, #2
 80027d2:	4770      	bx	lr

080027d4 <HAL_UARTEx_SetTxFifoThreshold>:
 80027d4:	b538      	push	{r3, r4, r5, lr}
 80027d6:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 80027da:	2b01      	cmp	r3, #1
 80027dc:	d01d      	beq.n	800281a <HAL_UARTEx_SetTxFifoThreshold+0x46>
 80027de:	4604      	mov	r4, r0
 80027e0:	2301      	movs	r3, #1
 80027e2:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80027e6:	2324      	movs	r3, #36	; 0x24
 80027e8:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80027ec:	6803      	ldr	r3, [r0, #0]
 80027ee:	681d      	ldr	r5, [r3, #0]
 80027f0:	681a      	ldr	r2, [r3, #0]
 80027f2:	f022 0201 	bic.w	r2, r2, #1
 80027f6:	601a      	str	r2, [r3, #0]
 80027f8:	6802      	ldr	r2, [r0, #0]
 80027fa:	6893      	ldr	r3, [r2, #8]
 80027fc:	f023 4360 	bic.w	r3, r3, #3758096384	; 0xe0000000
 8002800:	4319      	orrs	r1, r3
 8002802:	6091      	str	r1, [r2, #8]
 8002804:	f7ff ff9e 	bl	8002744 <UARTEx_SetNbDataToProcess>
 8002808:	6823      	ldr	r3, [r4, #0]
 800280a:	601d      	str	r5, [r3, #0]
 800280c:	2320      	movs	r3, #32
 800280e:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 8002812:	2000      	movs	r0, #0
 8002814:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 8002818:	bd38      	pop	{r3, r4, r5, pc}
 800281a:	2002      	movs	r0, #2
 800281c:	e7fc      	b.n	8002818 <HAL_UARTEx_SetTxFifoThreshold+0x44>

0800281e <HAL_UARTEx_SetRxFifoThreshold>:
 800281e:	b538      	push	{r3, r4, r5, lr}
 8002820:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 8002824:	2b01      	cmp	r3, #1
 8002826:	d01d      	beq.n	8002864 <HAL_UARTEx_SetRxFifoThreshold+0x46>
 8002828:	4604      	mov	r4, r0
 800282a:	2301      	movs	r3, #1
 800282c:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002830:	2324      	movs	r3, #36	; 0x24
 8002832:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8002836:	6803      	ldr	r3, [r0, #0]
 8002838:	681d      	ldr	r5, [r3, #0]
 800283a:	681a      	ldr	r2, [r3, #0]
 800283c:	f022 0201 	bic.w	r2, r2, #1
 8002840:	601a      	str	r2, [r3, #0]
 8002842:	6802      	ldr	r2, [r0, #0]
 8002844:	6893      	ldr	r3, [r2, #8]
 8002846:	f023 6360 	bic.w	r3, r3, #234881024	; 0xe000000
 800284a:	4319      	orrs	r1, r3
 800284c:	6091      	str	r1, [r2, #8]
 800284e:	f7ff ff79 	bl	8002744 <UARTEx_SetNbDataToProcess>
 8002852:	6823      	ldr	r3, [r4, #0]
 8002854:	601d      	str	r5, [r3, #0]
 8002856:	2320      	movs	r3, #32
 8002858:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 800285c:	2000      	movs	r0, #0
 800285e:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 8002862:	bd38      	pop	{r3, r4, r5, pc}
 8002864:	2002      	movs	r0, #2
 8002866:	e7fc      	b.n	8002862 <HAL_UARTEx_SetRxFifoThreshold+0x44>

08002868 <Reset_Handler>:
 8002868:	480d      	ldr	r0, [pc, #52]	; (80028a0 <LoopForever+0x2>)
 800286a:	4685      	mov	sp, r0
 800286c:	f01e ff12 	bl	8021694 <SystemInit>
 8002870:	480c      	ldr	r0, [pc, #48]	; (80028a4 <LoopForever+0x6>)
 8002872:	490d      	ldr	r1, [pc, #52]	; (80028a8 <LoopForever+0xa>)
 8002874:	4a0d      	ldr	r2, [pc, #52]	; (80028ac <LoopForever+0xe>)
 8002876:	2300      	movs	r3, #0
 8002878:	e002      	b.n	8002880 <LoopCopyDataInit>

0800287a <CopyDataInit>:
 800287a:	58d4      	ldr	r4, [r2, r3]
 800287c:	50c4      	str	r4, [r0, r3]
 800287e:	3304      	adds	r3, #4

08002880 <LoopCopyDataInit>:
 8002880:	18c4      	adds	r4, r0, r3
 8002882:	428c      	cmp	r4, r1
 8002884:	d3f9      	bcc.n	800287a <CopyDataInit>
 8002886:	4a0a      	ldr	r2, [pc, #40]	; (80028b0 <LoopForever+0x12>)
 8002888:	4c0a      	ldr	r4, [pc, #40]	; (80028b4 <LoopForever+0x16>)
 800288a:	2300      	movs	r3, #0
 800288c:	e001      	b.n	8002892 <LoopFillZerobss>

0800288e <FillZerobss>:
 800288e:	6013      	str	r3, [r2, #0]
 8002890:	3204      	adds	r2, #4

08002892 <LoopFillZerobss>:
 8002892:	42a2      	cmp	r2, r4
 8002894:	d3fb      	bcc.n	800288e <FillZerobss>
 8002896:	f7fd fc6f 	bl	8000178 <__libc_init_array>
 800289a:	f7fd fe01 	bl	80004a0 <main>

0800289e <LoopForever>:
 800289e:	e7fe      	b.n	800289e <LoopForever>
 80028a0:	2000fc00 	.word	0x2000fc00
 80028a4:	20006000 	.word	0x20006000
 80028a8:	20006068 	.word	0x20006068
 80028ac:	08005020 	.word	0x08005020
 80028b0:	20006068 	.word	0x20006068
 80028b4:	20006690 	.word	0x20006690

080028b8 <ADC_IRQHandler>:
 80028b8:	e7fe      	b.n	80028b8 <ADC_IRQHandler>
	...

080028bc <strcasecmp>:
 80028bc:	b530      	push	{r4, r5, lr}
 80028be:	4d0b      	ldr	r5, [pc, #44]	; (80028ec <strcasecmp+0x30>)
 80028c0:	4604      	mov	r4, r0
 80028c2:	f814 3b01 	ldrb.w	r3, [r4], #1
 80028c6:	5d5a      	ldrb	r2, [r3, r5]
 80028c8:	f002 0203 	and.w	r2, r2, #3
 80028cc:	2a01      	cmp	r2, #1
 80028ce:	f811 2b01 	ldrb.w	r2, [r1], #1
 80028d2:	5ca8      	ldrb	r0, [r5, r2]
 80028d4:	f000 0003 	and.w	r0, r0, #3
 80028d8:	bf08      	it	eq
 80028da:	3320      	addeq	r3, #32
 80028dc:	2801      	cmp	r0, #1
 80028de:	bf08      	it	eq
 80028e0:	3220      	addeq	r2, #32
 80028e2:	1a98      	subs	r0, r3, r2
 80028e4:	d101      	bne.n	80028ea <strcasecmp+0x2e>
 80028e6:	2a00      	cmp	r2, #0
 80028e8:	d1eb      	bne.n	80028c2 <strcasecmp+0x6>
 80028ea:	bd30      	pop	{r4, r5, pc}
 80028ec:	08002bc9 	.word	0x08002bc9

080028f0 <_init>:
 80028f0:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 80028f2:	bf00      	nop
 80028f4:	bcf8      	pop	{r3, r4, r5, r6, r7}
 80028f6:	bc08      	pop	{r3}
 80028f8:	469e      	mov	lr, r3
 80028fa:	4770      	bx	lr

080028fc <_fini>:
 80028fc:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 80028fe:	bf00      	nop
 8002900:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8002902:	bc08      	pop	{r3}
 8002904:	469e      	mov	lr, r3
 8002906:	4770      	bx	lr
