
/home/jenkins/workspace/RUI_Release/rui-v3/image/RUI_5.0.0_RAK3172-E_bl:     file format elf32-littlearm


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
 8000158:	0800286c 	.word	0x0800286c

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
 8000174:	0800286c 	.word	0x0800286c

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
 800018c:	f002 fb6e 	bl	800286c <_init>
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
 80001b0:	08002c50 	.word	0x08002c50
 80001b4:	08002c50 	.word	0x08002c50
 80001b8:	08002c50 	.word	0x08002c50
 80001bc:	08002c54 	.word	0x08002c54

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
 80001e2:	4965      	ldr	r1, [pc, #404]	; (8000378 <at_process+0x1a8>)
 80001e4:	4865      	ldr	r0, [pc, #404]	; (800037c <at_process+0x1ac>)
 80001e6:	f002 fa45 	bl	8002674 <HAL_UART_Receive_IT>
 80001ea:	2800      	cmp	r0, #0
 80001ec:	d06a      	beq.n	80002c4 <at_process+0xf4>
 80001ee:	4864      	ldr	r0, [pc, #400]	; (8000380 <at_process+0x1b0>)
 80001f0:	f000 fa28 	bl	8000644 <Serial_PutString>
 80001f4:	e066      	b.n	80002c4 <at_process+0xf4>
 80001f6:	2400      	movs	r4, #0
 80001f8:	e018      	b.n	800022c <at_process+0x5c>
 80001fa:	2501      	movs	r5, #1
 80001fc:	4b61      	ldr	r3, [pc, #388]	; (8000384 <at_process+0x1b4>)
 80001fe:	2200      	movs	r2, #0
 8000200:	701a      	strb	r2, [r3, #0]
 8000202:	4b61      	ldr	r3, [pc, #388]	; (8000388 <at_process+0x1b8>)
 8000204:	781b      	ldrb	r3, [r3, #0]
 8000206:	2b01      	cmp	r3, #1
 8000208:	d030      	beq.n	800026c <at_process+0x9c>
 800020a:	2d00      	cmp	r5, #0
 800020c:	d13a      	bne.n	8000284 <at_process+0xb4>
 800020e:	4b5d      	ldr	r3, [pc, #372]	; (8000384 <at_process+0x1b4>)
 8000210:	781b      	ldrb	r3, [r3, #0]
 8000212:	2b00      	cmp	r3, #0
 8000214:	d0f5      	beq.n	8000202 <at_process+0x32>
 8000216:	1c63      	adds	r3, r4, #1
 8000218:	b29b      	uxth	r3, r3
 800021a:	aa12      	add	r2, sp, #72	; 0x48
 800021c:	4414      	add	r4, r2
 800021e:	4a56      	ldr	r2, [pc, #344]	; (8000378 <at_process+0x1a8>)
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
 800023e:	4a53      	ldr	r2, [pc, #332]	; (800038c <at_process+0x1bc>)
 8000240:	466b      	mov	r3, sp
 8000242:	e892 0003 	ldmia.w	r2, {r0, r1}
 8000246:	e883 0003 	stmia.w	r3, {r0, r1}
 800024a:	2203      	movs	r2, #3
 800024c:	4950      	ldr	r1, [pc, #320]	; (8000390 <at_process+0x1c0>)
 800024e:	a802      	add	r0, sp, #8
 8000250:	f03a f920 	bl	803a494 <memcmp>
 8000254:	2800      	cmp	r0, #0
 8000256:	d0d0      	beq.n	80001fa <at_process+0x2a>
 8000258:	2203      	movs	r2, #3
 800025a:	494e      	ldr	r1, [pc, #312]	; (8000394 <at_process+0x1c4>)
 800025c:	a802      	add	r0, sp, #8
 800025e:	f03a f919 	bl	803a494 <memcmp>
 8000262:	b908      	cbnz	r0, 8000268 <at_process+0x98>
 8000264:	2501      	movs	r5, #1
 8000266:	e7c9      	b.n	80001fc <at_process+0x2c>
 8000268:	2400      	movs	r4, #0
 800026a:	e7c7      	b.n	80001fc <at_process+0x2c>
 800026c:	f02e fd38 	bl	802ece0 <LoRaMacProcess>
 8000270:	f01e ff92 	bl	801f198 <LmHandlerPackagesProcess>
 8000274:	4b48      	ldr	r3, [pc, #288]	; (8000398 <at_process+0x1c8>)
 8000276:	685b      	ldr	r3, [r3, #4]
 8000278:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 800027c:	d0c5      	beq.n	800020a <at_process+0x3a>
 800027e:	f001 f899 	bl	80013b4 <UplinkProcess>
 8000282:	e7c2      	b.n	800020a <at_process+0x3a>
 8000284:	3c01      	subs	r4, #1
 8000286:	ab12      	add	r3, sp, #72	; 0x48
 8000288:	441c      	add	r4, r3
 800028a:	2300      	movs	r3, #0
 800028c:	f804 3c40 	strb.w	r3, [r4, #-64]
 8000290:	4942      	ldr	r1, [pc, #264]	; (800039c <at_process+0x1cc>)
 8000292:	a802      	add	r0, sp, #8
 8000294:	f002 fad0 	bl	8002838 <strcasecmp>
 8000298:	b148      	cbz	r0, 80002ae <at_process+0xde>
 800029a:	4941      	ldr	r1, [pc, #260]	; (80003a0 <at_process+0x1d0>)
 800029c:	a802      	add	r0, sp, #8
 800029e:	f002 facb 	bl	8002838 <strcasecmp>
 80002a2:	b120      	cbz	r0, 80002ae <at_process+0xde>
 80002a4:	493f      	ldr	r1, [pc, #252]	; (80003a4 <at_process+0x1d4>)
 80002a6:	a802      	add	r0, sp, #8
 80002a8:	f002 fac6 	bl	8002838 <strcasecmp>
 80002ac:	b968      	cbnz	r0, 80002ca <at_process+0xfa>
 80002ae:	483e      	ldr	r0, [pc, #248]	; (80003a8 <at_process+0x1d8>)
 80002b0:	f000 f9c8 	bl	8000644 <Serial_PutString>
 80002b4:	483d      	ldr	r0, [pc, #244]	; (80003ac <at_process+0x1dc>)
 80002b6:	f000 f9c5 	bl	8000644 <Serial_PutString>
 80002ba:	2240      	movs	r2, #64	; 0x40
 80002bc:	2100      	movs	r1, #0
 80002be:	a802      	add	r0, sp, #8
 80002c0:	f7ff ff7e 	bl	80001c0 <memset>
 80002c4:	2500      	movs	r5, #0
 80002c6:	462c      	mov	r4, r5
 80002c8:	e7a1      	b.n	800020e <at_process+0x3e>
 80002ca:	4939      	ldr	r1, [pc, #228]	; (80003b0 <at_process+0x1e0>)
 80002cc:	a802      	add	r0, sp, #8
 80002ce:	f002 fab3 	bl	8002838 <strcasecmp>
 80002d2:	b1e8      	cbz	r0, 8000310 <at_process+0x140>
 80002d4:	4937      	ldr	r1, [pc, #220]	; (80003b4 <at_process+0x1e4>)
 80002d6:	a802      	add	r0, sp, #8
 80002d8:	f002 faae 	bl	8002838 <strcasecmp>
 80002dc:	b328      	cbz	r0, 800032a <at_process+0x15a>
 80002de:	4936      	ldr	r1, [pc, #216]	; (80003b8 <at_process+0x1e8>)
 80002e0:	a802      	add	r0, sp, #8
 80002e2:	f002 faa9 	bl	8002838 <strcasecmp>
 80002e6:	b348      	cbz	r0, 800033c <at_process+0x16c>
 80002e8:	4934      	ldr	r1, [pc, #208]	; (80003bc <at_process+0x1ec>)
 80002ea:	a802      	add	r0, sp, #8
 80002ec:	f002 faa4 	bl	8002838 <strcasecmp>
 80002f0:	2800      	cmp	r0, #0
 80002f2:	d030      	beq.n	8000356 <at_process+0x186>
 80002f4:	4932      	ldr	r1, [pc, #200]	; (80003c0 <at_process+0x1f0>)
 80002f6:	a802      	add	r0, sp, #8
 80002f8:	f002 fa9e 	bl	8002838 <strcasecmp>
 80002fc:	b378      	cbz	r0, 800035e <at_process+0x18e>
 80002fe:	4931      	ldr	r1, [pc, #196]	; (80003c4 <at_process+0x1f4>)
 8000300:	a802      	add	r0, sp, #8
 8000302:	f002 fa99 	bl	8002838 <strcasecmp>
 8000306:	2800      	cmp	r0, #0
 8000308:	d132      	bne.n	8000370 <at_process+0x1a0>
 800030a:	f01e fafd 	bl	801e908 <service_lora_fuota_join>
 800030e:	e7d4      	b.n	80002ba <at_process+0xea>
 8000310:	4b2d      	ldr	r3, [pc, #180]	; (80003c8 <at_process+0x1f8>)
 8000312:	2201      	movs	r2, #1
 8000314:	701a      	strb	r2, [r3, #0]
 8000316:	f04f 3101 	mov.w	r1, #16843009	; 0x1010101
 800031a:	482c      	ldr	r0, [pc, #176]	; (80003cc <at_process+0x1fc>)
 800031c:	f000 fa4a 	bl	80007b4 <HAL_FLASH_Program_Flag>
 8000320:	4816      	ldr	r0, [pc, #88]	; (800037c <at_process+0x1ac>)
 8000322:	f001 f8fd 	bl	8001520 <HAL_UART_AbortReceive_IT>
 8000326:	b013      	add	sp, #76	; 0x4c
 8000328:	bd30      	pop	{r4, r5, pc}
 800032a:	4829      	ldr	r0, [pc, #164]	; (80003d0 <at_process+0x200>)
 800032c:	f000 f98a 	bl	8000644 <Serial_PutString>
 8000330:	f000 fa9c 	bl	800086c <app_jump>
 8000334:	4827      	ldr	r0, [pc, #156]	; (80003d4 <at_process+0x204>)
 8000336:	f000 f985 	bl	8000644 <Serial_PutString>
 800033a:	e7be      	b.n	80002ba <at_process+0xea>
 800033c:	f3bf 8f4f 	dsb	sy
 8000340:	4925      	ldr	r1, [pc, #148]	; (80003d8 <at_process+0x208>)
 8000342:	68ca      	ldr	r2, [r1, #12]
 8000344:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000348:	4b24      	ldr	r3, [pc, #144]	; (80003dc <at_process+0x20c>)
 800034a:	4313      	orrs	r3, r2
 800034c:	60cb      	str	r3, [r1, #12]
 800034e:	f3bf 8f4f 	dsb	sy
 8000352:	bf00      	nop
 8000354:	e7fd      	b.n	8000352 <at_process+0x182>
 8000356:	4822      	ldr	r0, [pc, #136]	; (80003e0 <at_process+0x210>)
 8000358:	f000 f974 	bl	8000644 <Serial_PutString>
 800035c:	e7ad      	b.n	80002ba <at_process+0xea>
 800035e:	4821      	ldr	r0, [pc, #132]	; (80003e4 <at_process+0x214>)
 8000360:	f000 f970 	bl	8000644 <Serial_PutString>
 8000364:	f000 ffdc 	bl	8001320 <bootloader_fuota_start>
 8000368:	4b07      	ldr	r3, [pc, #28]	; (8000388 <at_process+0x1b8>)
 800036a:	2201      	movs	r2, #1
 800036c:	701a      	strb	r2, [r3, #0]
 800036e:	e7a4      	b.n	80002ba <at_process+0xea>
 8000370:	481d      	ldr	r0, [pc, #116]	; (80003e8 <at_process+0x218>)
 8000372:	f000 f967 	bl	8000644 <Serial_PutString>
 8000376:	e7a0      	b.n	80002ba <at_process+0xea>
 8000378:	20006085 	.word	0x20006085
 800037c:	200060d0 	.word	0x200060d0
 8000380:	080028a0 	.word	0x080028a0
 8000384:	20006087 	.word	0x20006087
 8000388:	20006084 	.word	0x20006084
 800038c:	08002888 	.word	0x08002888
 8000390:	08002898 	.word	0x08002898
 8000394:	0800289c 	.word	0x0800289c
 8000398:	08004000 	.word	0x08004000
 800039c:	080028bc 	.word	0x080028bc
 80003a0:	080028c8 	.word	0x080028c8
 80003a4:	080028d4 	.word	0x080028d4
 80003a8:	08005000 	.word	0x08005000
 80003ac:	08002a8c 	.word	0x08002a8c
 80003b0:	080028e4 	.word	0x080028e4
 80003b4:	080028f0 	.word	0x080028f0
 80003b8:	0800293c 	.word	0x0800293c
 80003bc:	08002948 	.word	0x08002948
 80003c0:	08002964 	.word	0x08002964
 80003c4:	08002980 	.word	0x08002980
 80003c8:	20006086 	.word	0x20006086
 80003cc:	08004004 	.word	0x08004004
 80003d0:	080028f8 	.word	0x080028f8
 80003d4:	0800290c 	.word	0x0800290c
 80003d8:	e000ed00 	.word	0xe000ed00
 80003dc:	05fa0004 	.word	0x05fa0004
 80003e0:	08002958 	.word	0x08002958
 80003e4:	08002970 	.word	0x08002970
 80003e8:	08002988 	.word	0x08002988

080003ec <IAP_Task>:
 80003ec:	b508      	push	{r3, lr}
 80003ee:	4b06      	ldr	r3, [pc, #24]	; (8000408 <IAP_Task+0x1c>)
 80003f0:	781b      	ldrb	r3, [r3, #0]
 80003f2:	b113      	cbz	r3, 80003fa <IAP_Task+0xe>
 80003f4:	2b01      	cmp	r3, #1
 80003f6:	d003      	beq.n	8000400 <IAP_Task+0x14>
 80003f8:	bd08      	pop	{r3, pc}
 80003fa:	f7ff fee9 	bl	80001d0 <at_process>
 80003fe:	e7fb      	b.n	80003f8 <IAP_Task+0xc>
 8000400:	f000 fa0a 	bl	8000818 <SerialDownload>
 8000404:	e7f8      	b.n	80003f8 <IAP_Task+0xc>
 8000406:	bf00      	nop
 8000408:	20006086 	.word	0x20006086

0800040c <SystemClock_Config>:
 800040c:	b510      	push	{r4, lr}
 800040e:	b09a      	sub	sp, #104	; 0x68
 8000410:	2248      	movs	r2, #72	; 0x48
 8000412:	2100      	movs	r1, #0
 8000414:	a808      	add	r0, sp, #32
 8000416:	f7ff fed3 	bl	80001c0 <memset>
 800041a:	2400      	movs	r4, #0
 800041c:	9402      	str	r4, [sp, #8]
 800041e:	9403      	str	r4, [sp, #12]
 8000420:	9404      	str	r4, [sp, #16]
 8000422:	9405      	str	r4, [sp, #20]
 8000424:	9406      	str	r4, [sp, #24]
 8000426:	9407      	str	r4, [sp, #28]
 8000428:	f026 ffbe 	bl	80273a8 <HAL_PWR_EnableBkUpAccess>
 800042c:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8000430:	f8d2 3090 	ldr.w	r3, [r2, #144]	; 0x90
 8000434:	f023 0318 	bic.w	r3, r3, #24
 8000438:	f8c2 3090 	str.w	r3, [r2, #144]	; 0x90
 800043c:	f502 6280 	add.w	r2, r2, #1024	; 0x400
 8000440:	6813      	ldr	r3, [r2, #0]
 8000442:	f423 63c0 	bic.w	r3, r3, #1536	; 0x600
 8000446:	f443 7300 	orr.w	r3, r3, #512	; 0x200
 800044a:	6013      	str	r3, [r2, #0]
 800044c:	6813      	ldr	r3, [r2, #0]
 800044e:	f403 63c0 	and.w	r3, r3, #1536	; 0x600
 8000452:	9301      	str	r3, [sp, #4]
 8000454:	9b01      	ldr	r3, [sp, #4]
 8000456:	232e      	movs	r3, #46	; 0x2e
 8000458:	9308      	str	r3, [sp, #32]
 800045a:	2381      	movs	r3, #129	; 0x81
 800045c:	930b      	str	r3, [sp, #44]	; 0x2c
 800045e:	2301      	movs	r3, #1
 8000460:	9310      	str	r3, [sp, #64]	; 0x40
 8000462:	f44f 7280 	mov.w	r2, #256	; 0x100
 8000466:	920c      	str	r2, [sp, #48]	; 0x30
 8000468:	9411      	str	r4, [sp, #68]	; 0x44
 800046a:	2240      	movs	r2, #64	; 0x40
 800046c:	920d      	str	r2, [sp, #52]	; 0x34
 800046e:	22b0      	movs	r2, #176	; 0xb0
 8000470:	9212      	str	r2, [sp, #72]	; 0x48
 8000472:	9413      	str	r4, [sp, #76]	; 0x4c
 8000474:	940f      	str	r4, [sp, #60]	; 0x3c
 8000476:	930e      	str	r3, [sp, #56]	; 0x38
 8000478:	a808      	add	r0, sp, #32
 800047a:	f024 fc47 	bl	8024d0c <HAL_RCC_OscConfig>
 800047e:	b970      	cbnz	r0, 800049e <SystemClock_Config+0x92>
 8000480:	234f      	movs	r3, #79	; 0x4f
 8000482:	9302      	str	r3, [sp, #8]
 8000484:	2300      	movs	r3, #0
 8000486:	9303      	str	r3, [sp, #12]
 8000488:	9304      	str	r3, [sp, #16]
 800048a:	9305      	str	r3, [sp, #20]
 800048c:	9306      	str	r3, [sp, #24]
 800048e:	9307      	str	r3, [sp, #28]
 8000490:	2102      	movs	r1, #2
 8000492:	a802      	add	r0, sp, #8
 8000494:	f024 fedc 	bl	8025250 <HAL_RCC_ClockConfig>
 8000498:	b918      	cbnz	r0, 80004a2 <SystemClock_Config+0x96>
 800049a:	b01a      	add	sp, #104	; 0x68
 800049c:	bd10      	pop	{r4, pc}
 800049e:	f020 f8a1 	bl	80205e4 <Error_Handler>
 80004a2:	f020 f89f 	bl	80205e4 <Error_Handler>
	...

080004a8 <main>:
 80004a8:	b508      	push	{r3, lr}
 80004aa:	4b23      	ldr	r3, [pc, #140]	; (8000538 <main+0x90>)
 80004ac:	685b      	ldr	r3, [r3, #4]
 80004ae:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 80004b2:	d120      	bne.n	80004f6 <main+0x4e>
 80004b4:	4b21      	ldr	r3, [pc, #132]	; (800053c <main+0x94>)
 80004b6:	f04f 6200 	mov.w	r2, #134217728	; 0x8000000
 80004ba:	609a      	str	r2, [r3, #8]
 80004bc:	4b20      	ldr	r3, [pc, #128]	; (8000540 <main+0x98>)
 80004be:	2201      	movs	r2, #1
 80004c0:	701a      	strb	r2, [r3, #0]
 80004c2:	4b20      	ldr	r3, [pc, #128]	; (8000544 <main+0x9c>)
 80004c4:	2200      	movs	r2, #0
 80004c6:	701a      	strb	r2, [r3, #0]
 80004c8:	f000 fa64 	bl	8000994 <MX_USART2_UART_Init>
 80004cc:	4b1a      	ldr	r3, [pc, #104]	; (8000538 <main+0x90>)
 80004ce:	681b      	ldr	r3, [r3, #0]
 80004d0:	f1b3 3f5a 	cmp.w	r3, #1515870810	; 0x5a5a5a5a
 80004d4:	d016      	beq.n	8000504 <main+0x5c>
 80004d6:	4b18      	ldr	r3, [pc, #96]	; (8000538 <main+0x90>)
 80004d8:	681b      	ldr	r3, [r3, #0]
 80004da:	f1b3 3f5a 	cmp.w	r3, #1515870810	; 0x5a5a5a5a
 80004de:	d122      	bne.n	8000526 <main+0x7e>
 80004e0:	4819      	ldr	r0, [pc, #100]	; (8000548 <main+0xa0>)
 80004e2:	f000 f8af 	bl	8000644 <Serial_PutString>
 80004e6:	4b14      	ldr	r3, [pc, #80]	; (8000538 <main+0x90>)
 80004e8:	685b      	ldr	r3, [r3, #4]
 80004ea:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 80004ee:	d020      	beq.n	8000532 <main+0x8a>
 80004f0:	f7ff ff7c 	bl	80003ec <IAP_Task>
 80004f4:	e7fc      	b.n	80004f0 <main+0x48>
 80004f6:	f000 fe07 	bl	8001108 <bootloader_fuota_stack_init>
 80004fa:	f024 f93b 	bl	8024774 <HAL_Init>
 80004fe:	f7ff ff85 	bl	800040c <SystemClock_Config>
 8000502:	e7e1      	b.n	80004c8 <main+0x20>
 8000504:	4b11      	ldr	r3, [pc, #68]	; (800054c <main+0xa4>)
 8000506:	681a      	ldr	r2, [r3, #0]
 8000508:	4b11      	ldr	r3, [pc, #68]	; (8000550 <main+0xa8>)
 800050a:	4013      	ands	r3, r2
 800050c:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 8000510:	d1e1      	bne.n	80004d6 <main+0x2e>
 8000512:	4b09      	ldr	r3, [pc, #36]	; (8000538 <main+0x90>)
 8000514:	685b      	ldr	r3, [r3, #4]
 8000516:	f1b3 3f01 	cmp.w	r3, #16843009	; 0x1010101
 800051a:	d0dc      	beq.n	80004d6 <main+0x2e>
 800051c:	f000 f92e 	bl	800077c <PreJump>
 8000520:	f000 f936 	bl	8000790 <JumpApp>
 8000524:	e7d7      	b.n	80004d6 <main+0x2e>
 8000526:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 800052a:	4803      	ldr	r0, [pc, #12]	; (8000538 <main+0x90>)
 800052c:	f000 f942 	bl	80007b4 <HAL_FLASH_Program_Flag>
 8000530:	e7d6      	b.n	80004e0 <main+0x38>
 8000532:	f000 fe57 	bl	80011e4 <bootloader_fuota_init>
 8000536:	e7db      	b.n	80004f0 <main+0x48>
 8000538:	08004000 	.word	0x08004000
 800053c:	e000ed00 	.word	0xe000ed00
 8000540:	20006084 	.word	0x20006084
 8000544:	20006086 	.word	0x20006086
 8000548:	0800299c 	.word	0x0800299c
 800054c:	08006000 	.word	0x08006000
 8000550:	2ffe0000 	.word	0x2ffe0000

08000554 <Str2Int>:
 8000554:	b510      	push	{r4, lr}
 8000556:	4684      	mov	ip, r0
 8000558:	7803      	ldrb	r3, [r0, #0]
 800055a:	2b30      	cmp	r3, #48	; 0x30
 800055c:	d003      	beq.n	8000566 <Str2Int+0x12>
 800055e:	2400      	movs	r4, #0
 8000560:	4620      	mov	r0, r4
 8000562:	4623      	mov	r3, r4
 8000564:	e054      	b.n	8000610 <Str2Int+0xbc>
 8000566:	7843      	ldrb	r3, [r0, #1]
 8000568:	2b78      	cmp	r3, #120	; 0x78
 800056a:	d035      	beq.n	80005d8 <Str2Int+0x84>
 800056c:	2b58      	cmp	r3, #88	; 0x58
 800056e:	d036      	beq.n	80005de <Str2Int+0x8a>
 8000570:	2400      	movs	r4, #0
 8000572:	4620      	mov	r0, r4
 8000574:	4623      	mov	r3, r4
 8000576:	e04b      	b.n	8000610 <Str2Int+0xbc>
 8000578:	0124      	lsls	r4, r4, #4
 800057a:	f1a3 0e30 	sub.w	lr, r3, #48	; 0x30
 800057e:	fa5f fe8e 	uxtb.w	lr, lr
 8000582:	f1be 0f09 	cmp.w	lr, #9
 8000586:	d821      	bhi.n	80005cc <Str2Int+0x78>
 8000588:	3b30      	subs	r3, #48	; 0x30
 800058a:	441c      	add	r4, r3
 800058c:	3001      	adds	r0, #1
 800058e:	280a      	cmp	r0, #10
 8000590:	d815      	bhi.n	80005be <Str2Int+0x6a>
 8000592:	f81c 3000 	ldrb.w	r3, [ip, r0]
 8000596:	b193      	cbz	r3, 80005be <Str2Int+0x6a>
 8000598:	f1a3 0241 	sub.w	r2, r3, #65	; 0x41
 800059c:	b2d2      	uxtb	r2, r2
 800059e:	2a05      	cmp	r2, #5
 80005a0:	d9ea      	bls.n	8000578 <Str2Int+0x24>
 80005a2:	f1a3 0e61 	sub.w	lr, r3, #97	; 0x61
 80005a6:	fa5f fe8e 	uxtb.w	lr, lr
 80005aa:	f1be 0f05 	cmp.w	lr, #5
 80005ae:	d9e3      	bls.n	8000578 <Str2Int+0x24>
 80005b0:	f1a3 0e30 	sub.w	lr, r3, #48	; 0x30
 80005b4:	fa5f fe8e 	uxtb.w	lr, lr
 80005b8:	f1be 0f09 	cmp.w	lr, #9
 80005bc:	d9dc      	bls.n	8000578 <Str2Int+0x24>
 80005be:	f81c 3000 	ldrb.w	r3, [ip, r0]
 80005c2:	2b00      	cmp	r3, #0
 80005c4:	d13b      	bne.n	800063e <Str2Int+0xea>
 80005c6:	600c      	str	r4, [r1, #0]
 80005c8:	2001      	movs	r0, #1
 80005ca:	bd10      	pop	{r4, pc}
 80005cc:	2a05      	cmp	r2, #5
 80005ce:	d801      	bhi.n	80005d4 <Str2Int+0x80>
 80005d0:	3b37      	subs	r3, #55	; 0x37
 80005d2:	e7da      	b.n	800058a <Str2Int+0x36>
 80005d4:	3b57      	subs	r3, #87	; 0x57
 80005d6:	e7d8      	b.n	800058a <Str2Int+0x36>
 80005d8:	2400      	movs	r4, #0
 80005da:	2002      	movs	r0, #2
 80005dc:	e7d7      	b.n	800058e <Str2Int+0x3a>
 80005de:	2400      	movs	r4, #0
 80005e0:	2002      	movs	r0, #2
 80005e2:	e7d4      	b.n	800058e <Str2Int+0x3a>
 80005e4:	2a6b      	cmp	r2, #107	; 0x6b
 80005e6:	d01e      	beq.n	8000626 <Str2Int+0xd2>
 80005e8:	2a4b      	cmp	r2, #75	; 0x4b
 80005ea:	d01c      	beq.n	8000626 <Str2Int+0xd2>
 80005ec:	2a6d      	cmp	r2, #109	; 0x6d
 80005ee:	d020      	beq.n	8000632 <Str2Int+0xde>
 80005f0:	2a4d      	cmp	r2, #77	; 0x4d
 80005f2:	d01e      	beq.n	8000632 <Str2Int+0xde>
 80005f4:	f1a2 0e30 	sub.w	lr, r2, #48	; 0x30
 80005f8:	fa5f fe8e 	uxtb.w	lr, lr
 80005fc:	f1be 0f09 	cmp.w	lr, #9
 8000600:	d8e3      	bhi.n	80005ca <Str2Int+0x76>
 8000602:	eb04 0484 	add.w	r4, r4, r4, lsl #2
 8000606:	eb02 0244 	add.w	r2, r2, r4, lsl #1
 800060a:	f1a2 0430 	sub.w	r4, r2, #48	; 0x30
 800060e:	3301      	adds	r3, #1
 8000610:	2b0a      	cmp	r3, #10
 8000612:	d8da      	bhi.n	80005ca <Str2Int+0x76>
 8000614:	2800      	cmp	r0, #0
 8000616:	d1d8      	bne.n	80005ca <Str2Int+0x76>
 8000618:	f81c 2003 	ldrb.w	r2, [ip, r3]
 800061c:	2a00      	cmp	r2, #0
 800061e:	d1e1      	bne.n	80005e4 <Str2Int+0x90>
 8000620:	600c      	str	r4, [r1, #0]
 8000622:	2001      	movs	r0, #1
 8000624:	e7f3      	b.n	800060e <Str2Int+0xba>
 8000626:	2b00      	cmp	r3, #0
 8000628:	d0e0      	beq.n	80005ec <Str2Int+0x98>
 800062a:	02a4      	lsls	r4, r4, #10
 800062c:	600c      	str	r4, [r1, #0]
 800062e:	2001      	movs	r0, #1
 8000630:	e7ed      	b.n	800060e <Str2Int+0xba>
 8000632:	2b00      	cmp	r3, #0
 8000634:	d0de      	beq.n	80005f4 <Str2Int+0xa0>
 8000636:	0524      	lsls	r4, r4, #20
 8000638:	600c      	str	r4, [r1, #0]
 800063a:	2001      	movs	r0, #1
 800063c:	e7e7      	b.n	800060e <Str2Int+0xba>
 800063e:	2000      	movs	r0, #0
 8000640:	e7c3      	b.n	80005ca <Str2Int+0x76>
	...

08000644 <Serial_PutString>:
 8000644:	b508      	push	{r3, lr}
 8000646:	4601      	mov	r1, r0
 8000648:	2200      	movs	r2, #0
 800064a:	e001      	b.n	8000650 <Serial_PutString+0xc>
 800064c:	3201      	adds	r2, #1
 800064e:	b292      	uxth	r2, r2
 8000650:	5c8b      	ldrb	r3, [r1, r2]
 8000652:	2b00      	cmp	r3, #0
 8000654:	d1fa      	bne.n	800064c <Serial_PutString+0x8>
 8000656:	2364      	movs	r3, #100	; 0x64
 8000658:	4801      	ldr	r0, [pc, #4]	; (8000660 <Serial_PutString+0x1c>)
 800065a:	f001 fe04 	bl	8002266 <HAL_UART_Transmit>
 800065e:	bd08      	pop	{r3, pc}
 8000660:	200060d0 	.word	0x200060d0

08000664 <Serial_PutByte>:
 8000664:	b500      	push	{lr}
 8000666:	b083      	sub	sp, #12
 8000668:	f88d 0007 	strb.w	r0, [sp, #7]
 800066c:	4b09      	ldr	r3, [pc, #36]	; (8000694 <Serial_PutByte+0x30>)
 800066e:	f8d3 3084 	ldr.w	r3, [r3, #132]	; 0x84
 8000672:	2ba0      	cmp	r3, #160	; 0xa0
 8000674:	d009      	beq.n	800068a <Serial_PutByte+0x26>
 8000676:	2364      	movs	r3, #100	; 0x64
 8000678:	2201      	movs	r2, #1
 800067a:	f10d 0107 	add.w	r1, sp, #7
 800067e:	4805      	ldr	r0, [pc, #20]	; (8000694 <Serial_PutByte+0x30>)
 8000680:	f001 fdf1 	bl	8002266 <HAL_UART_Transmit>
 8000684:	b003      	add	sp, #12
 8000686:	f85d fb04 	ldr.w	pc, [sp], #4
 800068a:	4b02      	ldr	r3, [pc, #8]	; (8000694 <Serial_PutByte+0x30>)
 800068c:	2220      	movs	r2, #32
 800068e:	f8c3 2084 	str.w	r2, [r3, #132]	; 0x84
 8000692:	e7f0      	b.n	8000676 <Serial_PutByte+0x12>
 8000694:	200060d0 	.word	0x200060d0

08000698 <Serial_Printf>:
 8000698:	b40f      	push	{r0, r1, r2, r3}
 800069a:	b500      	push	{lr}
 800069c:	f5ad 7d03 	sub.w	sp, sp, #524	; 0x20c
 80006a0:	ab84      	add	r3, sp, #528	; 0x210
 80006a2:	f853 2b04 	ldr.w	r2, [r3], #4
 80006a6:	9301      	str	r3, [sp, #4]
 80006a8:	f44f 7100 	mov.w	r1, #512	; 0x200
 80006ac:	a802      	add	r0, sp, #8
 80006ae:	f023 fd0d 	bl	80240cc <tiny_vsnprintf_like>
 80006b2:	a802      	add	r0, sp, #8
 80006b4:	f01c fca4 	bl	801d000 <strlen>
 80006b8:	2364      	movs	r3, #100	; 0x64
 80006ba:	b282      	uxth	r2, r0
 80006bc:	a902      	add	r1, sp, #8
 80006be:	4804      	ldr	r0, [pc, #16]	; (80006d0 <Serial_Printf+0x38>)
 80006c0:	f001 fdd1 	bl	8002266 <HAL_UART_Transmit>
 80006c4:	f50d 7d03 	add.w	sp, sp, #524	; 0x20c
 80006c8:	f85d eb04 	ldr.w	lr, [sp], #4
 80006cc:	b004      	add	sp, #16
 80006ce:	4770      	bx	lr
 80006d0:	200060d0 	.word	0x200060d0

080006d4 <GetPage>:
 80006d4:	f100 4078 	add.w	r0, r0, #4160749568	; 0xf8000000
 80006d8:	0ac0      	lsrs	r0, r0, #11
 80006da:	4770      	bx	lr

080006dc <FLASH_If_Erase>:
 80006dc:	b510      	push	{r4, lr}
 80006de:	b084      	sub	sp, #16
 80006e0:	4604      	mov	r4, r0
 80006e2:	2300      	movs	r3, #0
 80006e4:	9303      	str	r3, [sp, #12]
 80006e6:	f027 fa39 	bl	8027b5c <HAL_FLASH_Unlock>
 80006ea:	4b0e      	ldr	r3, [pc, #56]	; (8000724 <FLASH_If_Erase+0x48>)
 80006ec:	f44f 4200 	mov.w	r2, #32768	; 0x8000
 80006f0:	611a      	str	r2, [r3, #16]
 80006f2:	4620      	mov	r0, r4
 80006f4:	f7ff ffee 	bl	80006d4 <GetPage>
 80006f8:	f1c4 6300 	rsb	r3, r4, #134217728	; 0x8000000
 80006fc:	f503 33e8 	add.w	r3, r3, #118784	; 0x1d000
 8000700:	0adb      	lsrs	r3, r3, #11
 8000702:	2202      	movs	r2, #2
 8000704:	9200      	str	r2, [sp, #0]
 8000706:	9001      	str	r0, [sp, #4]
 8000708:	9302      	str	r3, [sp, #8]
 800070a:	a903      	add	r1, sp, #12
 800070c:	4668      	mov	r0, sp
 800070e:	f027 fc39 	bl	8027f84 <HAL_FLASHEx_Erase>
 8000712:	b928      	cbnz	r0, 8000720 <FLASH_If_Erase+0x44>
 8000714:	2400      	movs	r4, #0
 8000716:	f027 fa33 	bl	8027b80 <HAL_FLASH_Lock>
 800071a:	4620      	mov	r0, r4
 800071c:	b004      	add	sp, #16
 800071e:	bd10      	pop	{r4, pc}
 8000720:	2401      	movs	r4, #1
 8000722:	e7f8      	b.n	8000716 <FLASH_If_Erase+0x3a>
 8000724:	58004000 	.word	0x58004000

08000728 <FLASH_If_Write>:
 8000728:	b5f0      	push	{r4, r5, r6, r7, lr}
 800072a:	b083      	sub	sp, #12
 800072c:	4605      	mov	r5, r0
 800072e:	460c      	mov	r4, r1
 8000730:	4617      	mov	r7, r2
 8000732:	f027 fa13 	bl	8027b5c <HAL_FLASH_Unlock>
 8000736:	2600      	movs	r6, #0
 8000738:	e002      	b.n	8000740 <FLASH_If_Write+0x18>
 800073a:	3508      	adds	r5, #8
 800073c:	3408      	adds	r4, #8
 800073e:	3602      	adds	r6, #2
 8000740:	42be      	cmp	r6, r7
 8000742:	d215      	bcs.n	8000770 <FLASH_If_Write+0x48>
 8000744:	466b      	mov	r3, sp
 8000746:	6820      	ldr	r0, [r4, #0]
 8000748:	6861      	ldr	r1, [r4, #4]
 800074a:	c303      	stmia	r3!, {r0, r1}
 800074c:	e9dd 2300 	ldrd	r2, r3, [sp]
 8000750:	4629      	mov	r1, r5
 8000752:	2001      	movs	r0, #1
 8000754:	f027 fa80 	bl	8027c58 <HAL_FLASH_Program>
 8000758:	2800      	cmp	r0, #0
 800075a:	d1f0      	bne.n	800073e <FLASH_If_Write+0x16>
 800075c:	6828      	ldr	r0, [r5, #0]
 800075e:	686a      	ldr	r2, [r5, #4]
 8000760:	9900      	ldr	r1, [sp, #0]
 8000762:	9b01      	ldr	r3, [sp, #4]
 8000764:	429a      	cmp	r2, r3
 8000766:	bf08      	it	eq
 8000768:	4288      	cmpeq	r0, r1
 800076a:	d0e6      	beq.n	800073a <FLASH_If_Write+0x12>
 800076c:	2403      	movs	r4, #3
 800076e:	e000      	b.n	8000772 <FLASH_If_Write+0x4a>
 8000770:	2400      	movs	r4, #0
 8000772:	f027 fa05 	bl	8027b80 <HAL_FLASH_Lock>
 8000776:	4620      	mov	r0, r4
 8000778:	b003      	add	sp, #12
 800077a:	bdf0      	pop	{r4, r5, r6, r7, pc}

0800077c <PreJump>:
 800077c:	b508      	push	{r3, lr}
 800077e:	4803      	ldr	r0, [pc, #12]	; (800078c <PreJump+0x10>)
 8000780:	f000 fe8d 	bl	800149e <HAL_UART_DeInit>
 8000784:	f023 ffaa 	bl	80246dc <HAL_DeInit>
 8000788:	bd08      	pop	{r3, pc}
 800078a:	bf00      	nop
 800078c:	200060d0 	.word	0x200060d0

08000790 <JumpApp>:
 8000790:	b508      	push	{r3, lr}
 8000792:	4a05      	ldr	r2, [pc, #20]	; (80007a8 <JumpApp+0x18>)
 8000794:	6853      	ldr	r3, [r2, #4]
 8000796:	4905      	ldr	r1, [pc, #20]	; (80007ac <JumpApp+0x1c>)
 8000798:	600b      	str	r3, [r1, #0]
 800079a:	4905      	ldr	r1, [pc, #20]	; (80007b0 <JumpApp+0x20>)
 800079c:	600b      	str	r3, [r1, #0]
 800079e:	6812      	ldr	r2, [r2, #0]
 80007a0:	f382 8808 	msr	MSP, r2
 80007a4:	4798      	blx	r3
 80007a6:	bd08      	pop	{r3, pc}
 80007a8:	08006000 	.word	0x08006000
 80007ac:	20006088 	.word	0x20006088
 80007b0:	2000608c 	.word	0x2000608c

080007b4 <HAL_FLASH_Program_Flag>:
 80007b4:	b570      	push	{r4, r5, r6, lr}
 80007b6:	b088      	sub	sp, #32
 80007b8:	4604      	mov	r4, r0
 80007ba:	460d      	mov	r5, r1
 80007bc:	2300      	movs	r3, #0
 80007be:	9307      	str	r3, [sp, #28]
 80007c0:	4e13      	ldr	r6, [pc, #76]	; (8000810 <HAL_FLASH_Program_Flag+0x5c>)
 80007c2:	e9d6 2300 	ldrd	r2, r3, [r6]
 80007c6:	e9cd 2304 	strd	r2, r3, [sp, #16]
 80007ca:	f027 f9c7 	bl	8027b5c <HAL_FLASH_Unlock>
 80007ce:	4b11      	ldr	r3, [pc, #68]	; (8000814 <HAL_FLASH_Program_Flag+0x60>)
 80007d0:	f44f 4200 	mov.w	r2, #32768	; 0x8000
 80007d4:	611a      	str	r2, [r3, #16]
 80007d6:	4630      	mov	r0, r6
 80007d8:	f7ff ff7c 	bl	80006d4 <GetPage>
 80007dc:	2302      	movs	r3, #2
 80007de:	9301      	str	r3, [sp, #4]
 80007e0:	9002      	str	r0, [sp, #8]
 80007e2:	2301      	movs	r3, #1
 80007e4:	9303      	str	r3, [sp, #12]
 80007e6:	a907      	add	r1, sp, #28
 80007e8:	a801      	add	r0, sp, #4
 80007ea:	f027 fbcb 	bl	8027f84 <HAL_FLASHEx_Erase>
 80007ee:	b950      	cbnz	r0, 8000806 <HAL_FLASH_Program_Flag+0x52>
 80007f0:	42b4      	cmp	r4, r6
 80007f2:	d00a      	beq.n	800080a <HAL_FLASH_Program_Flag+0x56>
 80007f4:	9505      	str	r5, [sp, #20]
 80007f6:	e9dd 2304 	ldrd	r2, r3, [sp, #16]
 80007fa:	4905      	ldr	r1, [pc, #20]	; (8000810 <HAL_FLASH_Program_Flag+0x5c>)
 80007fc:	2001      	movs	r0, #1
 80007fe:	f027 fa2b 	bl	8027c58 <HAL_FLASH_Program>
 8000802:	f027 f9bd 	bl	8027b80 <HAL_FLASH_Lock>
 8000806:	b008      	add	sp, #32
 8000808:	bd70      	pop	{r4, r5, r6, pc}
 800080a:	9504      	str	r5, [sp, #16]
 800080c:	e7f3      	b.n	80007f6 <HAL_FLASH_Program_Flag+0x42>
 800080e:	bf00      	nop
 8000810:	08004000 	.word	0x08004000
 8000814:	58004000 	.word	0x58004000

08000818 <SerialDownload>:
 8000818:	b500      	push	{lr}
 800081a:	b083      	sub	sp, #12
 800081c:	2300      	movs	r3, #0
 800081e:	9301      	str	r3, [sp, #4]
 8000820:	a801      	add	r0, sp, #4
 8000822:	f000 fa35 	bl	8000c90 <Ymodem_Receive>
 8000826:	b110      	cbz	r0, 800082e <SerialDownload+0x16>
 8000828:	b003      	add	sp, #12
 800082a:	f85d fb04 	ldr.w	pc, [sp], #4
 800082e:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 8000832:	480a      	ldr	r0, [pc, #40]	; (800085c <SerialDownload+0x44>)
 8000834:	f7ff ffbe 	bl	80007b4 <HAL_FLASH_Program_Flag>
 8000838:	f04f 3102 	mov.w	r1, #33686018	; 0x2020202
 800083c:	4808      	ldr	r0, [pc, #32]	; (8000860 <SerialDownload+0x48>)
 800083e:	f7ff ffb9 	bl	80007b4 <HAL_FLASH_Program_Flag>
 8000842:	4b08      	ldr	r3, [pc, #32]	; (8000864 <SerialDownload+0x4c>)
 8000844:	681a      	ldr	r2, [r3, #0]
 8000846:	4b08      	ldr	r3, [pc, #32]	; (8000868 <SerialDownload+0x50>)
 8000848:	4013      	ands	r3, r2
 800084a:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 800084e:	d1eb      	bne.n	8000828 <SerialDownload+0x10>
 8000850:	f7ff ff94 	bl	800077c <PreJump>
 8000854:	f7ff ff9c 	bl	8000790 <JumpApp>
 8000858:	e7e6      	b.n	8000828 <SerialDownload+0x10>
 800085a:	bf00      	nop
 800085c:	08004000 	.word	0x08004000
 8000860:	08004004 	.word	0x08004004
 8000864:	08006000 	.word	0x08006000
 8000868:	2ffe0000 	.word	0x2ffe0000

0800086c <app_jump>:
 800086c:	b508      	push	{r3, lr}
 800086e:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 8000872:	480a      	ldr	r0, [pc, #40]	; (800089c <app_jump+0x30>)
 8000874:	f7ff ff9e 	bl	80007b4 <HAL_FLASH_Program_Flag>
 8000878:	4b09      	ldr	r3, [pc, #36]	; (80008a0 <app_jump+0x34>)
 800087a:	681a      	ldr	r2, [r3, #0]
 800087c:	4b09      	ldr	r3, [pc, #36]	; (80008a4 <app_jump+0x38>)
 800087e:	4013      	ands	r3, r2
 8000880:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 8000884:	d000      	beq.n	8000888 <app_jump+0x1c>
 8000886:	bd08      	pop	{r3, pc}
 8000888:	4b04      	ldr	r3, [pc, #16]	; (800089c <app_jump+0x30>)
 800088a:	685b      	ldr	r3, [r3, #4]
 800088c:	f1b3 3f01 	cmp.w	r3, #16843009	; 0x1010101
 8000890:	d0f9      	beq.n	8000886 <app_jump+0x1a>
 8000892:	f7ff ff73 	bl	800077c <PreJump>
 8000896:	f7ff ff7b 	bl	8000790 <JumpApp>
 800089a:	e7f4      	b.n	8000886 <app_jump+0x1a>
 800089c:	08004000 	.word	0x08004000
 80008a0:	08006000 	.word	0x08006000
 80008a4:	2ffe0000 	.word	0x2ffe0000

080008a8 <NMI_Handler>:
 80008a8:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 80008ac:	6b9a      	ldr	r2, [r3, #56]	; 0x38
 80008ae:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
 80008b2:	6399      	str	r1, [r3, #56]	; 0x38
 80008b4:	6bda      	ldr	r2, [r3, #60]	; 0x3c
 80008b6:	63d9      	str	r1, [r3, #60]	; 0x3c
 80008b8:	6b9a      	ldr	r2, [r3, #56]	; 0x38
 80008ba:	2200      	movs	r2, #0
 80008bc:	639a      	str	r2, [r3, #56]	; 0x38
 80008be:	6bd8      	ldr	r0, [r3, #60]	; 0x3c
 80008c0:	63da      	str	r2, [r3, #60]	; 0x3c
 80008c2:	6c18      	ldr	r0, [r3, #64]	; 0x40
 80008c4:	6419      	str	r1, [r3, #64]	; 0x40
 80008c6:	6c18      	ldr	r0, [r3, #64]	; 0x40
 80008c8:	641a      	str	r2, [r3, #64]	; 0x40
 80008ca:	6c58      	ldr	r0, [r3, #68]	; 0x44
 80008cc:	6459      	str	r1, [r3, #68]	; 0x44
 80008ce:	6c58      	ldr	r0, [r3, #68]	; 0x44
 80008d0:	645a      	str	r2, [r3, #68]	; 0x44
 80008d2:	6a98      	ldr	r0, [r3, #40]	; 0x28
 80008d4:	6299      	str	r1, [r3, #40]	; 0x28
 80008d6:	6a98      	ldr	r0, [r3, #40]	; 0x28
 80008d8:	629a      	str	r2, [r3, #40]	; 0x28
 80008da:	6ad8      	ldr	r0, [r3, #44]	; 0x2c
 80008dc:	62d9      	str	r1, [r3, #44]	; 0x2c
 80008de:	6ad8      	ldr	r0, [r3, #44]	; 0x2c
 80008e0:	62da      	str	r2, [r3, #44]	; 0x2c
 80008e2:	6b18      	ldr	r0, [r3, #48]	; 0x30
 80008e4:	6319      	str	r1, [r3, #48]	; 0x30
 80008e6:	6b19      	ldr	r1, [r3, #48]	; 0x30
 80008e8:	631a      	str	r2, [r3, #48]	; 0x30
 80008ea:	6c5a      	ldr	r2, [r3, #68]	; 0x44
 80008ec:	f042 0201 	orr.w	r2, r2, #1
 80008f0:	645a      	str	r2, [r3, #68]	; 0x44
 80008f2:	6c5a      	ldr	r2, [r3, #68]	; 0x44
 80008f4:	f022 0201 	bic.w	r2, r2, #1
 80008f8:	645a      	str	r2, [r3, #68]	; 0x44
 80008fa:	f8d3 2090 	ldr.w	r2, [r3, #144]	; 0x90
 80008fe:	f442 3280 	orr.w	r2, r2, #65536	; 0x10000
 8000902:	f8c3 2090 	str.w	r2, [r3, #144]	; 0x90
 8000906:	f8d3 2090 	ldr.w	r2, [r3, #144]	; 0x90
 800090a:	f422 3280 	bic.w	r2, r2, #65536	; 0x10000
 800090e:	f8c3 2090 	str.w	r2, [r3, #144]	; 0x90
 8000912:	f3bf 8f4f 	dsb	sy
 8000916:	4905      	ldr	r1, [pc, #20]	; (800092c <NMI_Handler+0x84>)
 8000918:	68ca      	ldr	r2, [r1, #12]
 800091a:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 800091e:	4b04      	ldr	r3, [pc, #16]	; (8000930 <NMI_Handler+0x88>)
 8000920:	4313      	orrs	r3, r2
 8000922:	60cb      	str	r3, [r1, #12]
 8000924:	f3bf 8f4f 	dsb	sy
 8000928:	bf00      	nop
 800092a:	e7fd      	b.n	8000928 <NMI_Handler+0x80>
 800092c:	e000ed00 	.word	0xe000ed00
 8000930:	05fa0004 	.word	0x05fa0004

08000934 <HardFault_Handler>:
 8000934:	4770      	bx	lr

08000936 <MemManage_Handler>:
 8000936:	4770      	bx	lr

08000938 <BusFault_Handler>:
 8000938:	4770      	bx	lr

0800093a <UsageFault_Handler>:
 800093a:	e7fe      	b.n	800093a <UsageFault_Handler>

0800093c <SVC_Handler>:
 800093c:	4770      	bx	lr

0800093e <DebugMon_Handler>:
 800093e:	4770      	bx	lr

08000940 <PendSV_Handler>:
 8000940:	4770      	bx	lr

08000942 <SysTick_Handler>:
 8000942:	b508      	push	{r3, lr}
 8000944:	f023 ff2c 	bl	80247a0 <HAL_IncTick>
 8000948:	f023 ff36 	bl	80247b8 <HAL_GetTick>
 800094c:	f000 fa78 	bl	8000e40 <upgrade_process_callback>
 8000950:	bd08      	pop	{r3, pc}
	...

08000954 <RTC_Alarm_IRQHandler>:
 8000954:	b508      	push	{r3, lr}
 8000956:	4802      	ldr	r0, [pc, #8]	; (8000960 <RTC_Alarm_IRQHandler+0xc>)
 8000958:	f025 fb18 	bl	8025f8c <HAL_RTC_AlarmIRQHandler>
 800095c:	bd08      	pop	{r3, pc}
 800095e:	bf00      	nop
 8000960:	200044d0 	.word	0x200044d0

08000964 <SUBGHZ_Radio_IRQHandler>:
 8000964:	b508      	push	{r3, lr}
 8000966:	4802      	ldr	r0, [pc, #8]	; (8000970 <SUBGHZ_Radio_IRQHandler+0xc>)
 8000968:	f027 fdf5 	bl	8028556 <HAL_SUBGHZ_IRQHandler>
 800096c:	bd08      	pop	{r3, pc}
 800096e:	bf00      	nop
 8000970:	200002d0 	.word	0x200002d0

08000974 <TAMP_STAMP_LSECSS_SSRU_IRQHandler>:
 8000974:	b508      	push	{r3, lr}
 8000976:	4802      	ldr	r0, [pc, #8]	; (8000980 <TAMP_STAMP_LSECSS_SSRU_IRQHandler+0xc>)
 8000978:	f026 fb42 	bl	8027000 <HAL_RTCEx_SSRUIRQHandler>
 800097c:	bd08      	pop	{r3, pc}
 800097e:	bf00      	nop
 8000980:	200044d0 	.word	0x200044d0

08000984 <USART2_IRQHandler>:
 8000984:	b508      	push	{r3, lr}
 8000986:	4802      	ldr	r0, [pc, #8]	; (8000990 <USART2_IRQHandler+0xc>)
 8000988:	f000 fe48 	bl	800161c <HAL_UART_IRQHandler>
 800098c:	bd08      	pop	{r3, pc}
 800098e:	bf00      	nop
 8000990:	200060d0 	.word	0x200060d0

08000994 <MX_USART2_UART_Init>:
 8000994:	b508      	push	{r3, lr}
 8000996:	4817      	ldr	r0, [pc, #92]	; (80009f4 <MX_USART2_UART_Init+0x60>)
 8000998:	4b17      	ldr	r3, [pc, #92]	; (80009f8 <MX_USART2_UART_Init+0x64>)
 800099a:	6003      	str	r3, [r0, #0]
 800099c:	f44f 33e1 	mov.w	r3, #115200	; 0x1c200
 80009a0:	6043      	str	r3, [r0, #4]
 80009a2:	2300      	movs	r3, #0
 80009a4:	6083      	str	r3, [r0, #8]
 80009a6:	60c3      	str	r3, [r0, #12]
 80009a8:	6103      	str	r3, [r0, #16]
 80009aa:	220c      	movs	r2, #12
 80009ac:	6142      	str	r2, [r0, #20]
 80009ae:	6183      	str	r3, [r0, #24]
 80009b0:	61c3      	str	r3, [r0, #28]
 80009b2:	6203      	str	r3, [r0, #32]
 80009b4:	6243      	str	r3, [r0, #36]	; 0x24
 80009b6:	6283      	str	r3, [r0, #40]	; 0x28
 80009b8:	f001 fd94 	bl	80024e4 <HAL_UART_Init>
 80009bc:	b970      	cbnz	r0, 80009dc <MX_USART2_UART_Init+0x48>
 80009be:	2100      	movs	r1, #0
 80009c0:	480c      	ldr	r0, [pc, #48]	; (80009f4 <MX_USART2_UART_Init+0x60>)
 80009c2:	f001 fec5 	bl	8002750 <HAL_UARTEx_SetTxFifoThreshold>
 80009c6:	b960      	cbnz	r0, 80009e2 <MX_USART2_UART_Init+0x4e>
 80009c8:	2100      	movs	r1, #0
 80009ca:	480a      	ldr	r0, [pc, #40]	; (80009f4 <MX_USART2_UART_Init+0x60>)
 80009cc:	f001 fee5 	bl	800279a <HAL_UARTEx_SetRxFifoThreshold>
 80009d0:	b950      	cbnz	r0, 80009e8 <MX_USART2_UART_Init+0x54>
 80009d2:	4808      	ldr	r0, [pc, #32]	; (80009f4 <MX_USART2_UART_Init+0x60>)
 80009d4:	f001 fe9d 	bl	8002712 <HAL_UARTEx_DisableFifoMode>
 80009d8:	b948      	cbnz	r0, 80009ee <MX_USART2_UART_Init+0x5a>
 80009da:	bd08      	pop	{r3, pc}
 80009dc:	f01f fe02 	bl	80205e4 <Error_Handler>
 80009e0:	e7ed      	b.n	80009be <MX_USART2_UART_Init+0x2a>
 80009e2:	f01f fdff 	bl	80205e4 <Error_Handler>
 80009e6:	e7ef      	b.n	80009c8 <MX_USART2_UART_Init+0x34>
 80009e8:	f01f fdfc 	bl	80205e4 <Error_Handler>
 80009ec:	e7f1      	b.n	80009d2 <MX_USART2_UART_Init+0x3e>
 80009ee:	f01f fdf9 	bl	80205e4 <Error_Handler>
 80009f2:	e7f2      	b.n	80009da <MX_USART2_UART_Init+0x46>
 80009f4:	200060d0 	.word	0x200060d0
 80009f8:	40004400 	.word	0x40004400

080009fc <HAL_UART_RxCpltCallback>:
 80009fc:	b508      	push	{r3, lr}
 80009fe:	4b07      	ldr	r3, [pc, #28]	; (8000a1c <HAL_UART_RxCpltCallback+0x20>)
 8000a00:	781b      	ldrb	r3, [r3, #0]
 8000a02:	2b01      	cmp	r3, #1
 8000a04:	d103      	bne.n	8000a0e <HAL_UART_RxCpltCallback+0x12>
 8000a06:	4b06      	ldr	r3, [pc, #24]	; (8000a20 <HAL_UART_RxCpltCallback+0x24>)
 8000a08:	2201      	movs	r2, #1
 8000a0a:	701a      	strb	r2, [r3, #0]
 8000a0c:	bd08      	pop	{r3, pc}
 8000a0e:	2201      	movs	r2, #1
 8000a10:	4904      	ldr	r1, [pc, #16]	; (8000a24 <HAL_UART_RxCpltCallback+0x28>)
 8000a12:	4805      	ldr	r0, [pc, #20]	; (8000a28 <HAL_UART_RxCpltCallback+0x2c>)
 8000a14:	f001 fe2e 	bl	8002674 <HAL_UART_Receive_IT>
 8000a18:	e7f5      	b.n	8000a06 <HAL_UART_RxCpltCallback+0xa>
 8000a1a:	bf00      	nop
 8000a1c:	20006086 	.word	0x20006086
 8000a20:	20006087 	.word	0x20006087
 8000a24:	20006085 	.word	0x20006085
 8000a28:	200060d0 	.word	0x200060d0

08000a2c <HAL_UART_MspInit>:
 8000a2c:	b510      	push	{r4, lr}
 8000a2e:	b096      	sub	sp, #88	; 0x58
 8000a30:	4604      	mov	r4, r0
 8000a32:	2100      	movs	r1, #0
 8000a34:	9111      	str	r1, [sp, #68]	; 0x44
 8000a36:	9112      	str	r1, [sp, #72]	; 0x48
 8000a38:	9113      	str	r1, [sp, #76]	; 0x4c
 8000a3a:	9114      	str	r1, [sp, #80]	; 0x50
 8000a3c:	9115      	str	r1, [sp, #84]	; 0x54
 8000a3e:	2238      	movs	r2, #56	; 0x38
 8000a40:	a803      	add	r0, sp, #12
 8000a42:	f7ff fbbd 	bl	80001c0 <memset>
 8000a46:	6822      	ldr	r2, [r4, #0]
 8000a48:	4b1e      	ldr	r3, [pc, #120]	; (8000ac4 <HAL_UART_MspInit+0x98>)
 8000a4a:	429a      	cmp	r2, r3
 8000a4c:	d001      	beq.n	8000a52 <HAL_UART_MspInit+0x26>
 8000a4e:	b016      	add	sp, #88	; 0x58
 8000a50:	bd10      	pop	{r4, pc}
 8000a52:	2302      	movs	r3, #2
 8000a54:	9303      	str	r3, [sp, #12]
 8000a56:	f44f 2340 	mov.w	r3, #786432	; 0xc0000
 8000a5a:	9305      	str	r3, [sp, #20]
 8000a5c:	a803      	add	r0, sp, #12
 8000a5e:	f024 fe3f 	bl	80256e0 <HAL_RCCEx_PeriphCLKConfig>
 8000a62:	bb58      	cbnz	r0, 8000abc <HAL_UART_MspInit+0x90>
 8000a64:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 8000a68:	6d9a      	ldr	r2, [r3, #88]	; 0x58
 8000a6a:	f442 3200 	orr.w	r2, r2, #131072	; 0x20000
 8000a6e:	659a      	str	r2, [r3, #88]	; 0x58
 8000a70:	6d9a      	ldr	r2, [r3, #88]	; 0x58
 8000a72:	f402 3200 	and.w	r2, r2, #131072	; 0x20000
 8000a76:	9202      	str	r2, [sp, #8]
 8000a78:	9a02      	ldr	r2, [sp, #8]
 8000a7a:	6cda      	ldr	r2, [r3, #76]	; 0x4c
 8000a7c:	f042 0201 	orr.w	r2, r2, #1
 8000a80:	64da      	str	r2, [r3, #76]	; 0x4c
 8000a82:	6cdb      	ldr	r3, [r3, #76]	; 0x4c
 8000a84:	f003 0301 	and.w	r3, r3, #1
 8000a88:	9301      	str	r3, [sp, #4]
 8000a8a:	9b01      	ldr	r3, [sp, #4]
 8000a8c:	230c      	movs	r3, #12
 8000a8e:	9311      	str	r3, [sp, #68]	; 0x44
 8000a90:	2302      	movs	r3, #2
 8000a92:	9312      	str	r3, [sp, #72]	; 0x48
 8000a94:	2301      	movs	r3, #1
 8000a96:	9313      	str	r3, [sp, #76]	; 0x4c
 8000a98:	2400      	movs	r4, #0
 8000a9a:	9414      	str	r4, [sp, #80]	; 0x50
 8000a9c:	2307      	movs	r3, #7
 8000a9e:	9315      	str	r3, [sp, #84]	; 0x54
 8000aa0:	a911      	add	r1, sp, #68	; 0x44
 8000aa2:	f04f 4090 	mov.w	r0, #1207959552	; 0x48000000
 8000aa6:	f027 fe09 	bl	80286bc <HAL_GPIO_Init>
 8000aaa:	4622      	mov	r2, r4
 8000aac:	4621      	mov	r1, r4
 8000aae:	2025      	movs	r0, #37	; 0x25
 8000ab0:	f021 f966 	bl	8021d80 <HAL_NVIC_SetPriority>
 8000ab4:	2025      	movs	r0, #37	; 0x25
 8000ab6:	f021 f995 	bl	8021de4 <HAL_NVIC_EnableIRQ>
 8000aba:	e7c8      	b.n	8000a4e <HAL_UART_MspInit+0x22>
 8000abc:	f01f fd92 	bl	80205e4 <Error_Handler>
 8000ac0:	e7d0      	b.n	8000a64 <HAL_UART_MspInit+0x38>
 8000ac2:	bf00      	nop
 8000ac4:	40004400 	.word	0x40004400

08000ac8 <HAL_UART_MspDeInit>:
 8000ac8:	b508      	push	{r3, lr}
 8000aca:	6802      	ldr	r2, [r0, #0]
 8000acc:	4b09      	ldr	r3, [pc, #36]	; (8000af4 <HAL_UART_MspDeInit+0x2c>)
 8000ace:	429a      	cmp	r2, r3
 8000ad0:	d000      	beq.n	8000ad4 <HAL_UART_MspDeInit+0xc>
 8000ad2:	bd08      	pop	{r3, pc}
 8000ad4:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8000ad8:	6d93      	ldr	r3, [r2, #88]	; 0x58
 8000ada:	f423 3300 	bic.w	r3, r3, #131072	; 0x20000
 8000ade:	6593      	str	r3, [r2, #88]	; 0x58
 8000ae0:	210c      	movs	r1, #12
 8000ae2:	f04f 4090 	mov.w	r0, #1207959552	; 0x48000000
 8000ae6:	f027 fe9b 	bl	8028820 <HAL_GPIO_DeInit>
 8000aea:	2025      	movs	r0, #37	; 0x25
 8000aec:	f021 f988 	bl	8021e00 <HAL_NVIC_DisableIRQ>
 8000af0:	e7ef      	b.n	8000ad2 <HAL_UART_MspDeInit+0xa>
 8000af2:	bf00      	nop
 8000af4:	40004400 	.word	0x40004400

08000af8 <__NVIC_SystemReset>:
 8000af8:	f3bf 8f4f 	dsb	sy
 8000afc:	4905      	ldr	r1, [pc, #20]	; (8000b14 <__NVIC_SystemReset+0x1c>)
 8000afe:	68ca      	ldr	r2, [r1, #12]
 8000b00:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000b04:	4b04      	ldr	r3, [pc, #16]	; (8000b18 <__NVIC_SystemReset+0x20>)
 8000b06:	4313      	orrs	r3, r2
 8000b08:	60cb      	str	r3, [r1, #12]
 8000b0a:	f3bf 8f4f 	dsb	sy
 8000b0e:	bf00      	nop
 8000b10:	e7fd      	b.n	8000b0e <__NVIC_SystemReset+0x16>
 8000b12:	bf00      	nop
 8000b14:	e000ed00 	.word	0xe000ed00
 8000b18:	05fa0004 	.word	0x05fa0004

08000b1c <UpdateCRC16>:
 8000b1c:	f441 7180 	orr.w	r1, r1, #256	; 0x100
 8000b20:	e006      	b.n	8000b30 <UpdateCRC16+0x14>
 8000b22:	f480 5081 	eor.w	r0, r0, #4128	; 0x1020
 8000b26:	f080 0001 	eor.w	r0, r0, #1
 8000b2a:	f411 3f80 	tst.w	r1, #65536	; 0x10000
 8000b2e:	d109      	bne.n	8000b44 <UpdateCRC16+0x28>
 8000b30:	0040      	lsls	r0, r0, #1
 8000b32:	0049      	lsls	r1, r1, #1
 8000b34:	f411 7f80 	tst.w	r1, #256	; 0x100
 8000b38:	d000      	beq.n	8000b3c <UpdateCRC16+0x20>
 8000b3a:	3001      	adds	r0, #1
 8000b3c:	f410 3f80 	tst.w	r0, #65536	; 0x10000
 8000b40:	d0f3      	beq.n	8000b2a <UpdateCRC16+0xe>
 8000b42:	e7ee      	b.n	8000b22 <UpdateCRC16+0x6>
 8000b44:	b280      	uxth	r0, r0
 8000b46:	4770      	bx	lr

08000b48 <Cal_CRC16>:
 8000b48:	b538      	push	{r3, r4, r5, lr}
 8000b4a:	4604      	mov	r4, r0
 8000b4c:	1845      	adds	r5, r0, r1
 8000b4e:	2000      	movs	r0, #0
 8000b50:	e004      	b.n	8000b5c <Cal_CRC16+0x14>
 8000b52:	f814 1b01 	ldrb.w	r1, [r4], #1
 8000b56:	b280      	uxth	r0, r0
 8000b58:	f7ff ffe0 	bl	8000b1c <UpdateCRC16>
 8000b5c:	42ac      	cmp	r4, r5
 8000b5e:	d3f8      	bcc.n	8000b52 <Cal_CRC16+0xa>
 8000b60:	2100      	movs	r1, #0
 8000b62:	b280      	uxth	r0, r0
 8000b64:	f7ff ffda 	bl	8000b1c <UpdateCRC16>
 8000b68:	2100      	movs	r1, #0
 8000b6a:	f7ff ffd7 	bl	8000b1c <UpdateCRC16>
 8000b6e:	bd38      	pop	{r3, r4, r5, pc}

08000b70 <ReceivePacket>:
 8000b70:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 8000b74:	b082      	sub	sp, #8
 8000b76:	4606      	mov	r6, r0
 8000b78:	460c      	mov	r4, r1
 8000b7a:	4615      	mov	r5, r2
 8000b7c:	2300      	movs	r3, #0
 8000b7e:	600b      	str	r3, [r1, #0]
 8000b80:	4613      	mov	r3, r2
 8000b82:	2201      	movs	r2, #1
 8000b84:	f10d 0107 	add.w	r1, sp, #7
 8000b88:	4840      	ldr	r0, [pc, #256]	; (8000c8c <ReceivePacket+0x11c>)
 8000b8a:	f001 fbdb 	bl	8002344 <HAL_UART_Receive>
 8000b8e:	4680      	mov	r8, r0
 8000b90:	2800      	cmp	r0, #0
 8000b92:	d172      	bne.n	8000c7a <ReceivePacket+0x10a>
 8000b94:	f89d 1007 	ldrb.w	r1, [sp, #7]
 8000b98:	2918      	cmp	r1, #24
 8000b9a:	d819      	bhi.n	8000bd0 <ReceivePacket+0x60>
 8000b9c:	b24b      	sxtb	r3, r1
 8000b9e:	2b00      	cmp	r3, #0
 8000ba0:	d048      	beq.n	8000c34 <ReceivePacket+0xc4>
 8000ba2:	3901      	subs	r1, #1
 8000ba4:	2917      	cmp	r1, #23
 8000ba6:	d80f      	bhi.n	8000bc8 <ReceivePacket+0x58>
 8000ba8:	e8df f001 	tbb	[pc, r1]
 8000bac:	0c0e3148 	.word	0x0c0e3148
 8000bb0:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bb4:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bb8:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bbc:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bc0:	340e0e0e 	.word	0x340e0e0e
 8000bc4:	2700      	movs	r7, #0
 8000bc6:	e00a      	b.n	8000bde <ReceivePacket+0x6e>
 8000bc8:	f04f 0801 	mov.w	r8, #1
 8000bcc:	2700      	movs	r7, #0
 8000bce:	e006      	b.n	8000bde <ReceivePacket+0x6e>
 8000bd0:	2941      	cmp	r1, #65	; 0x41
 8000bd2:	d035      	beq.n	8000c40 <ReceivePacket+0xd0>
 8000bd4:	2961      	cmp	r1, #97	; 0x61
 8000bd6:	d137      	bne.n	8000c48 <ReceivePacket+0xd8>
 8000bd8:	f04f 0802 	mov.w	r8, #2
 8000bdc:	2700      	movs	r7, #0
 8000bde:	f89d 3007 	ldrb.w	r3, [sp, #7]
 8000be2:	7033      	strb	r3, [r6, #0]
 8000be4:	2f7f      	cmp	r7, #127	; 0x7f
 8000be6:	d949      	bls.n	8000c7c <ReceivePacket+0x10c>
 8000be8:	462b      	mov	r3, r5
 8000bea:	1d3a      	adds	r2, r7, #4
 8000bec:	1cb1      	adds	r1, r6, #2
 8000bee:	4827      	ldr	r0, [pc, #156]	; (8000c8c <ReceivePacket+0x11c>)
 8000bf0:	f001 fba8 	bl	8002344 <HAL_UART_Receive>
 8000bf4:	4680      	mov	r8, r0
 8000bf6:	2800      	cmp	r0, #0
 8000bf8:	d145      	bne.n	8000c86 <ReceivePacket+0x116>
 8000bfa:	78b2      	ldrb	r2, [r6, #2]
 8000bfc:	78f3      	ldrb	r3, [r6, #3]
 8000bfe:	43db      	mvns	r3, r3
 8000c00:	b2db      	uxtb	r3, r3
 8000c02:	429a      	cmp	r2, r3
 8000c04:	d02a      	beq.n	8000c5c <ReceivePacket+0xec>
 8000c06:	f04f 0801 	mov.w	r8, #1
 8000c0a:	2700      	movs	r7, #0
 8000c0c:	e036      	b.n	8000c7c <ReceivePacket+0x10c>
 8000c0e:	f44f 6780 	mov.w	r7, #1024	; 0x400
 8000c12:	e7e4      	b.n	8000bde <ReceivePacket+0x6e>
 8000c14:	462b      	mov	r3, r5
 8000c16:	2201      	movs	r2, #1
 8000c18:	f10d 0107 	add.w	r1, sp, #7
 8000c1c:	481b      	ldr	r0, [pc, #108]	; (8000c8c <ReceivePacket+0x11c>)
 8000c1e:	f001 fb91 	bl	8002344 <HAL_UART_Receive>
 8000c22:	b9a8      	cbnz	r0, 8000c50 <ReceivePacket+0xe0>
 8000c24:	f89d 3007 	ldrb.w	r3, [sp, #7]
 8000c28:	2b18      	cmp	r3, #24
 8000c2a:	d015      	beq.n	8000c58 <ReceivePacket+0xe8>
 8000c2c:	f04f 0801 	mov.w	r8, #1
 8000c30:	2700      	movs	r7, #0
 8000c32:	e7d4      	b.n	8000bde <ReceivePacket+0x6e>
 8000c34:	f04f 0801 	mov.w	r8, #1
 8000c38:	2700      	movs	r7, #0
 8000c3a:	e7d0      	b.n	8000bde <ReceivePacket+0x6e>
 8000c3c:	2780      	movs	r7, #128	; 0x80
 8000c3e:	e7ce      	b.n	8000bde <ReceivePacket+0x6e>
 8000c40:	f04f 0802 	mov.w	r8, #2
 8000c44:	2700      	movs	r7, #0
 8000c46:	e7ca      	b.n	8000bde <ReceivePacket+0x6e>
 8000c48:	f04f 0801 	mov.w	r8, #1
 8000c4c:	2700      	movs	r7, #0
 8000c4e:	e7c6      	b.n	8000bde <ReceivePacket+0x6e>
 8000c50:	f04f 0801 	mov.w	r8, #1
 8000c54:	2700      	movs	r7, #0
 8000c56:	e7c2      	b.n	8000bde <ReceivePacket+0x6e>
 8000c58:	2702      	movs	r7, #2
 8000c5a:	e7c0      	b.n	8000bde <ReceivePacket+0x6e>
 8000c5c:	19f3      	adds	r3, r6, r7
 8000c5e:	791a      	ldrb	r2, [r3, #4]
 8000c60:	795d      	ldrb	r5, [r3, #5]
 8000c62:	eb05 2502 	add.w	r5, r5, r2, lsl #8
 8000c66:	4639      	mov	r1, r7
 8000c68:	1d30      	adds	r0, r6, #4
 8000c6a:	f7ff ff6d 	bl	8000b48 <Cal_CRC16>
 8000c6e:	42a8      	cmp	r0, r5
 8000c70:	d004      	beq.n	8000c7c <ReceivePacket+0x10c>
 8000c72:	f04f 0801 	mov.w	r8, #1
 8000c76:	2700      	movs	r7, #0
 8000c78:	e000      	b.n	8000c7c <ReceivePacket+0x10c>
 8000c7a:	2700      	movs	r7, #0
 8000c7c:	6027      	str	r7, [r4, #0]
 8000c7e:	4640      	mov	r0, r8
 8000c80:	b002      	add	sp, #8
 8000c82:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 8000c86:	2700      	movs	r7, #0
 8000c88:	e7f8      	b.n	8000c7c <ReceivePacket+0x10c>
 8000c8a:	bf00      	nop
 8000c8c:	200060d0 	.word	0x200060d0

08000c90 <Ymodem_Receive>:
 8000c90:	e92d 4ff0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
 8000c94:	b089      	sub	sp, #36	; 0x24
 8000c96:	9001      	str	r0, [sp, #4]
 8000c98:	f04f 0800 	mov.w	r8, #0
 8000c9c:	4646      	mov	r6, r8
 8000c9e:	f8df b188 	ldr.w	fp, [pc, #392]	; 8000e28 <Ymodem_Receive+0x198>
 8000ca2:	46c1      	mov	r9, r8
 8000ca4:	4645      	mov	r5, r8
 8000ca6:	46c2      	mov	sl, r8
 8000ca8:	f1ba 0f00 	cmp.w	sl, #0
 8000cac:	f040 80b8 	bne.w	8000e20 <Ymodem_Receive+0x190>
 8000cb0:	2e00      	cmp	r6, #0
 8000cb2:	f040 80b5 	bne.w	8000e20 <Ymodem_Receive+0x190>
 8000cb6:	4b5d      	ldr	r3, [pc, #372]	; (8000e2c <Ymodem_Receive+0x19c>)
 8000cb8:	2200      	movs	r2, #0
 8000cba:	701a      	strb	r2, [r3, #0]
 8000cbc:	4657      	mov	r7, sl
 8000cbe:	e085      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000cc0:	9d07      	ldr	r5, [sp, #28]
 8000cc2:	b13d      	cbz	r5, 8000cd4 <Ymodem_Receive+0x44>
 8000cc4:	2d02      	cmp	r5, #2
 8000cc6:	d10a      	bne.n	8000cde <Ymodem_Receive+0x4e>
 8000cc8:	2006      	movs	r0, #6
 8000cca:	f7ff fccb 	bl	8000664 <Serial_PutByte>
 8000cce:	463d      	mov	r5, r7
 8000cd0:	2602      	movs	r6, #2
 8000cd2:	e07b      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000cd4:	2006      	movs	r0, #6
 8000cd6:	f7ff fcc5 	bl	8000664 <Serial_PutByte>
 8000cda:	2701      	movs	r7, #1
 8000cdc:	e076      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000cde:	4b54      	ldr	r3, [pc, #336]	; (8000e30 <Ymodem_Receive+0x1a0>)
 8000ce0:	789a      	ldrb	r2, [r3, #2]
 8000ce2:	4b52      	ldr	r3, [pc, #328]	; (8000e2c <Ymodem_Receive+0x19c>)
 8000ce4:	781b      	ldrb	r3, [r3, #0]
 8000ce6:	429a      	cmp	r2, r3
 8000ce8:	d10b      	bne.n	8000d02 <Ymodem_Receive+0x72>
 8000cea:	2b00      	cmp	r3, #0
 8000cec:	d153      	bne.n	8000d96 <Ymodem_Receive+0x106>
 8000cee:	4b50      	ldr	r3, [pc, #320]	; (8000e30 <Ymodem_Receive+0x1a0>)
 8000cf0:	791b      	ldrb	r3, [r3, #4]
 8000cf2:	b9cb      	cbnz	r3, 8000d28 <Ymodem_Receive+0x98>
 8000cf4:	2006      	movs	r0, #6
 8000cf6:	f7ff fcb5 	bl	8000664 <Serial_PutByte>
 8000cfa:	463d      	mov	r5, r7
 8000cfc:	2701      	movs	r7, #1
 8000cfe:	46ba      	mov	sl, r7
 8000d00:	e064      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000d02:	2015      	movs	r0, #21
 8000d04:	f7ff fcae 	bl	8000664 <Serial_PutByte>
 8000d08:	463d      	mov	r5, r7
 8000d0a:	e05f      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000d0c:	3301      	adds	r3, #1
 8000d0e:	4849      	ldr	r0, [pc, #292]	; (8000e34 <Ymodem_Receive+0x1a4>)
 8000d10:	5481      	strb	r1, [r0, r2]
 8000d12:	3201      	adds	r2, #1
 8000d14:	7819      	ldrb	r1, [r3, #0]
 8000d16:	b109      	cbz	r1, 8000d1c <Ymodem_Receive+0x8c>
 8000d18:	2a3f      	cmp	r2, #63	; 0x3f
 8000d1a:	d9f7      	bls.n	8000d0c <Ymodem_Receive+0x7c>
 8000d1c:	4945      	ldr	r1, [pc, #276]	; (8000e34 <Ymodem_Receive+0x1a4>)
 8000d1e:	2000      	movs	r0, #0
 8000d20:	5488      	strb	r0, [r1, r2]
 8000d22:	3301      	adds	r3, #1
 8000d24:	463a      	mov	r2, r7
 8000d26:	e008      	b.n	8000d3a <Ymodem_Receive+0xaa>
 8000d28:	463a      	mov	r2, r7
 8000d2a:	4b43      	ldr	r3, [pc, #268]	; (8000e38 <Ymodem_Receive+0x1a8>)
 8000d2c:	e7f2      	b.n	8000d14 <Ymodem_Receive+0x84>
 8000d2e:	3301      	adds	r3, #1
 8000d30:	a808      	add	r0, sp, #32
 8000d32:	4410      	add	r0, r2
 8000d34:	f800 1c18 	strb.w	r1, [r0, #-24]
 8000d38:	3201      	adds	r2, #1
 8000d3a:	7819      	ldrb	r1, [r3, #0]
 8000d3c:	2920      	cmp	r1, #32
 8000d3e:	d001      	beq.n	8000d44 <Ymodem_Receive+0xb4>
 8000d40:	2a0f      	cmp	r2, #15
 8000d42:	d9f4      	bls.n	8000d2e <Ymodem_Receive+0x9e>
 8000d44:	ab08      	add	r3, sp, #32
 8000d46:	441a      	add	r2, r3
 8000d48:	2300      	movs	r3, #0
 8000d4a:	f802 3c18 	strb.w	r3, [r2, #-24]
 8000d4e:	a906      	add	r1, sp, #24
 8000d50:	a802      	add	r0, sp, #8
 8000d52:	f7ff fbff 	bl	8000554 <Str2Int>
 8000d56:	9a06      	ldr	r2, [sp, #24]
 8000d58:	4b38      	ldr	r3, [pc, #224]	; (8000e3c <Ymodem_Receive+0x1ac>)
 8000d5a:	429a      	cmp	r2, r3
 8000d5c:	d813      	bhi.n	8000d86 <Ymodem_Receive+0xf6>
 8000d5e:	4832      	ldr	r0, [pc, #200]	; (8000e28 <Ymodem_Receive+0x198>)
 8000d60:	f7ff fcbc 	bl	80006dc <FLASH_If_Erase>
 8000d64:	9b06      	ldr	r3, [sp, #24]
 8000d66:	9a01      	ldr	r2, [sp, #4]
 8000d68:	6013      	str	r3, [r2, #0]
 8000d6a:	2006      	movs	r0, #6
 8000d6c:	f7ff fc7a 	bl	8000664 <Serial_PutByte>
 8000d70:	2043      	movs	r0, #67	; 0x43
 8000d72:	f7ff fc77 	bl	8000664 <Serial_PutByte>
 8000d76:	4a2d      	ldr	r2, [pc, #180]	; (8000e2c <Ymodem_Receive+0x19c>)
 8000d78:	7813      	ldrb	r3, [r2, #0]
 8000d7a:	3301      	adds	r3, #1
 8000d7c:	7013      	strb	r3, [r2, #0]
 8000d7e:	463d      	mov	r5, r7
 8000d80:	f04f 0901 	mov.w	r9, #1
 8000d84:	e022      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000d86:	2018      	movs	r0, #24
 8000d88:	f7ff fc6c 	bl	8000664 <Serial_PutByte>
 8000d8c:	2018      	movs	r0, #24
 8000d8e:	f7ff fc69 	bl	8000664 <Serial_PutByte>
 8000d92:	2605      	movs	r6, #5
 8000d94:	e7e3      	b.n	8000d5e <Ymodem_Receive+0xce>
 8000d96:	08aa      	lsrs	r2, r5, #2
 8000d98:	4927      	ldr	r1, [pc, #156]	; (8000e38 <Ymodem_Receive+0x1a8>)
 8000d9a:	4658      	mov	r0, fp
 8000d9c:	f7ff fcc4 	bl	8000728 <FLASH_If_Write>
 8000da0:	b928      	cbnz	r0, 8000dae <Ymodem_Receive+0x11e>
 8000da2:	9b07      	ldr	r3, [sp, #28]
 8000da4:	449b      	add	fp, r3
 8000da6:	2006      	movs	r0, #6
 8000da8:	f7ff fc5c 	bl	8000664 <Serial_PutByte>
 8000dac:	e7e3      	b.n	8000d76 <Ymodem_Receive+0xe6>
 8000dae:	2018      	movs	r0, #24
 8000db0:	f7ff fc58 	bl	8000664 <Serial_PutByte>
 8000db4:	2018      	movs	r0, #24
 8000db6:	f7ff fc55 	bl	8000664 <Serial_PutByte>
 8000dba:	2604      	movs	r6, #4
 8000dbc:	e7db      	b.n	8000d76 <Ymodem_Receive+0xe6>
 8000dbe:	2018      	movs	r0, #24
 8000dc0:	f7ff fc50 	bl	8000664 <Serial_PutByte>
 8000dc4:	2018      	movs	r0, #24
 8000dc6:	f7ff fc4d 	bl	8000664 <Serial_PutByte>
 8000dca:	4626      	mov	r6, r4
 8000dcc:	2f00      	cmp	r7, #0
 8000dce:	f47f af6b 	bne.w	8000ca8 <Ymodem_Receive+0x18>
 8000dd2:	2e00      	cmp	r6, #0
 8000dd4:	f47f af68 	bne.w	8000ca8 <Ymodem_Receive+0x18>
 8000dd8:	f44f 72fa 	mov.w	r2, #500	; 0x1f4
 8000ddc:	a907      	add	r1, sp, #28
 8000dde:	4814      	ldr	r0, [pc, #80]	; (8000e30 <Ymodem_Receive+0x1a0>)
 8000de0:	f7ff fec6 	bl	8000b70 <ReceivePacket>
 8000de4:	4604      	mov	r4, r0
 8000de6:	2800      	cmp	r0, #0
 8000de8:	f43f af6a 	beq.w	8000cc0 <Ymodem_Receive+0x30>
 8000dec:	2802      	cmp	r0, #2
 8000dee:	d0e6      	beq.n	8000dbe <Ymodem_Receive+0x12e>
 8000df0:	f1b9 0f00 	cmp.w	r9, #0
 8000df4:	d000      	beq.n	8000df8 <Ymodem_Receive+0x168>
 8000df6:	3501      	adds	r5, #1
 8000df8:	2d05      	cmp	r5, #5
 8000dfa:	d907      	bls.n	8000e0c <Ymodem_Receive+0x17c>
 8000dfc:	2018      	movs	r0, #24
 8000dfe:	f7ff fc31 	bl	8000664 <Serial_PutByte>
 8000e02:	2018      	movs	r0, #24
 8000e04:	f7ff fc2e 	bl	8000664 <Serial_PutByte>
 8000e08:	2602      	movs	r6, #2
 8000e0a:	e7df      	b.n	8000dcc <Ymodem_Receive+0x13c>
 8000e0c:	2043      	movs	r0, #67	; 0x43
 8000e0e:	f7ff fc29 	bl	8000664 <Serial_PutByte>
 8000e12:	f108 0801 	add.w	r8, r8, #1
 8000e16:	f1b8 0f3b 	cmp.w	r8, #59	; 0x3b
 8000e1a:	d9d7      	bls.n	8000dcc <Ymodem_Receive+0x13c>
 8000e1c:	f7ff fe6c 	bl	8000af8 <__NVIC_SystemReset>
 8000e20:	4630      	mov	r0, r6
 8000e22:	b009      	add	sp, #36	; 0x24
 8000e24:	e8bd 8ff0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, pc}
 8000e28:	08006000 	.word	0x08006000
 8000e2c:	20006566 	.word	0x20006566
 8000e30:	20006160 	.word	0x20006160
 8000e34:	20006090 	.word	0x20006090
 8000e38:	20006164 	.word	0x20006164
 8000e3c:	00031001 	.word	0x00031001

08000e40 <upgrade_process_callback>:
 8000e40:	b508      	push	{r3, lr}
 8000e42:	4b0a      	ldr	r3, [pc, #40]	; (8000e6c <upgrade_process_callback+0x2c>)
 8000e44:	fba3 2300 	umull	r2, r3, r3, r0
 8000e48:	0b1b      	lsrs	r3, r3, #12
 8000e4a:	f643 2298 	movw	r2, #15000	; 0x3a98
 8000e4e:	fb02 0313 	mls	r3, r2, r3, r0
 8000e52:	b943      	cbnz	r3, 8000e66 <upgrade_process_callback+0x26>
 8000e54:	4b06      	ldr	r3, [pc, #24]	; (8000e70 <upgrade_process_callback+0x30>)
 8000e56:	781b      	ldrb	r3, [r3, #0]
 8000e58:	b12b      	cbz	r3, 8000e66 <upgrade_process_callback+0x26>
 8000e5a:	4a06      	ldr	r2, [pc, #24]	; (8000e74 <upgrade_process_callback+0x34>)
 8000e5c:	7812      	ldrb	r2, [r2, #0]
 8000e5e:	4293      	cmp	r3, r2
 8000e60:	d002      	beq.n	8000e68 <upgrade_process_callback+0x28>
 8000e62:	4a04      	ldr	r2, [pc, #16]	; (8000e74 <upgrade_process_callback+0x34>)
 8000e64:	7013      	strb	r3, [r2, #0]
 8000e66:	bd08      	pop	{r3, pc}
 8000e68:	f7ff fe46 	bl	8000af8 <__NVIC_SystemReset>
 8000e6c:	45e7b273 	.word	0x45e7b273
 8000e70:	20006566 	.word	0x20006566
 8000e74:	20006567 	.word	0x20006567

08000e78 <__NVIC_SystemReset>:
 8000e78:	f3bf 8f4f 	dsb	sy
 8000e7c:	4905      	ldr	r1, [pc, #20]	; (8000e94 <__NVIC_SystemReset+0x1c>)
 8000e7e:	68ca      	ldr	r2, [r1, #12]
 8000e80:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000e84:	4b04      	ldr	r3, [pc, #16]	; (8000e98 <__NVIC_SystemReset+0x20>)
 8000e86:	4313      	orrs	r3, r2
 8000e88:	60cb      	str	r3, [r1, #12]
 8000e8a:	f3bf 8f4f 	dsb	sy
 8000e8e:	bf00      	nop
 8000e90:	e7fd      	b.n	8000e8e <__NVIC_SystemReset+0x16>
 8000e92:	bf00      	nop
 8000e94:	e000ed00 	.word	0xe000ed00
 8000e98:	05fa0004 	.word	0x05fa0004

08000e9c <OnNvmDataChange_fuota>:
 8000e9c:	4770      	bx	lr

08000e9e <OnMacProcessNotify_fuota>:
 8000e9e:	4770      	bx	lr

08000ea0 <fuota_OnMacMcpsRequest>:
 8000ea0:	4770      	bx	lr

08000ea2 <fuota_OnMacMlmeRequest>:
 8000ea2:	4770      	bx	lr

08000ea4 <fuota_LmHandlerJoinRequest>:
 8000ea4:	4770      	bx	lr

08000ea6 <OnNetworkParametersChange>:
 8000ea6:	4770      	bx	lr

08000ea8 <OnMacMcpsRequest>:
 8000ea8:	4770      	bx	lr

08000eaa <OnMacMlmeRequest>:
 8000eaa:	4770      	bx	lr

08000eac <OnJoinRequest>:
 8000eac:	4770      	bx	lr

08000eae <OnTxData>:
 8000eae:	4770      	bx	lr

08000eb0 <OnRxData>:
 8000eb0:	4770      	bx	lr

08000eb2 <OnBeaconStatusChange>:
 8000eb2:	4770      	bx	lr

08000eb4 <OnSysTimeUpdate>:
 8000eb4:	4b01      	ldr	r3, [pc, #4]	; (8000ebc <OnSysTimeUpdate+0x8>)
 8000eb6:	2201      	movs	r2, #1
 8000eb8:	701a      	strb	r2, [r3, #0]
 8000eba:	4770      	bx	lr
 8000ebc:	200002e4 	.word	0x200002e4

08000ec0 <LmHandlerPackagesNotify>:
 8000ec0:	b570      	push	{r4, r5, r6, lr}
 8000ec2:	4605      	mov	r5, r0
 8000ec4:	460e      	mov	r6, r1
 8000ec6:	2400      	movs	r4, #0
 8000ec8:	e005      	b.n	8000ed6 <LmHandlerPackagesNotify+0x16>
 8000eca:	695b      	ldr	r3, [r3, #20]
 8000ecc:	b10b      	cbz	r3, 8000ed2 <LmHandlerPackagesNotify+0x12>
 8000ece:	4630      	mov	r0, r6
 8000ed0:	4798      	blx	r3
 8000ed2:	3401      	adds	r4, #1
 8000ed4:	b264      	sxtb	r4, r4
 8000ed6:	2c04      	cmp	r4, #4
 8000ed8:	dc24      	bgt.n	8000f24 <LmHandlerPackagesNotify+0x64>
 8000eda:	4b13      	ldr	r3, [pc, #76]	; (8000f28 <LmHandlerPackagesNotify+0x68>)
 8000edc:	f853 3024 	ldr.w	r3, [r3, r4, lsl #2]
 8000ee0:	2b00      	cmp	r3, #0
 8000ee2:	d0f6      	beq.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000ee4:	2d03      	cmp	r5, #3
 8000ee6:	d8f4      	bhi.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000ee8:	a201      	add	r2, pc, #4	; (adr r2, 8000ef0 <LmHandlerPackagesNotify+0x30>)
 8000eea:	f852 f025 	ldr.w	pc, [r2, r5, lsl #2]
 8000eee:	bf00      	nop
 8000ef0:	08000ecb 	.word	0x08000ecb
 8000ef4:	08000f01 	.word	0x08000f01
 8000ef8:	08000f0d 	.word	0x08000f0d
 8000efc:	08000f19 	.word	0x08000f19
 8000f00:	699b      	ldr	r3, [r3, #24]
 8000f02:	2b00      	cmp	r3, #0
 8000f04:	d0e5      	beq.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000f06:	4630      	mov	r0, r6
 8000f08:	4798      	blx	r3
 8000f0a:	e7e2      	b.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000f0c:	69db      	ldr	r3, [r3, #28]
 8000f0e:	2b00      	cmp	r3, #0
 8000f10:	d0df      	beq.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000f12:	4630      	mov	r0, r6
 8000f14:	4798      	blx	r3
 8000f16:	e7dc      	b.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000f18:	6a1b      	ldr	r3, [r3, #32]
 8000f1a:	2b00      	cmp	r3, #0
 8000f1c:	d0d9      	beq.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000f1e:	4630      	mov	r0, r6
 8000f20:	4798      	blx	r3
 8000f22:	e7d6      	b.n	8000ed2 <LmHandlerPackagesNotify+0x12>
 8000f24:	bd70      	pop	{r4, r5, r6, pc}
 8000f26:	bf00      	nop
 8000f28:	200003d0 	.word	0x200003d0

08000f2c <MlmeIndication_fuota>:
 8000f2c:	b508      	push	{r3, lr}
 8000f2e:	4601      	mov	r1, r0
 8000f30:	2003      	movs	r0, #3
 8000f32:	f7ff ffc5 	bl	8000ec0 <LmHandlerPackagesNotify>
 8000f36:	bd08      	pop	{r3, pc}

08000f38 <McpsConfirm_fuota>:
 8000f38:	b508      	push	{r3, lr}
 8000f3a:	4601      	mov	r1, r0
 8000f3c:	2000      	movs	r0, #0
 8000f3e:	f7ff ffbf 	bl	8000ec0 <LmHandlerPackagesNotify>
 8000f42:	bd08      	pop	{r3, pc}

08000f44 <fuota_OnFragProgress>:
 8000f44:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000f46:	4604      	mov	r4, r0
 8000f48:	460e      	mov	r6, r1
 8000f4a:	4615      	mov	r5, r2
 8000f4c:	461f      	mov	r7, r3
 8000f4e:	460a      	mov	r2, r1
 8000f50:	4601      	mov	r1, r0
 8000f52:	4807      	ldr	r0, [pc, #28]	; (8000f70 <fuota_OnFragProgress+0x2c>)
 8000f54:	f7ff fba0 	bl	8000698 <Serial_Printf>
 8000f58:	fb05 f206 	mul.w	r2, r5, r6
 8000f5c:	fb05 f104 	mul.w	r1, r5, r4
 8000f60:	4804      	ldr	r0, [pc, #16]	; (8000f74 <fuota_OnFragProgress+0x30>)
 8000f62:	f7ff fb99 	bl	8000698 <Serial_Printf>
 8000f66:	4639      	mov	r1, r7
 8000f68:	4803      	ldr	r0, [pc, #12]	; (8000f78 <fuota_OnFragProgress+0x34>)
 8000f6a:	f7ff fb95 	bl	8000698 <Serial_Printf>
 8000f6e:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}
 8000f70:	080029ac 	.word	0x080029ac
 8000f74:	080029d0 	.word	0x080029d0
 8000f78:	080029f0 	.word	0x080029f0

08000f7c <fuota_OnFragDone>:
 8000f7c:	b508      	push	{r3, lr}
 8000f7e:	4806      	ldr	r0, [pc, #24]	; (8000f98 <fuota_OnFragDone+0x1c>)
 8000f80:	f7ff fb8a 	bl	8000698 <Serial_Printf>
 8000f84:	4b05      	ldr	r3, [pc, #20]	; (8000f9c <fuota_OnFragDone+0x20>)
 8000f86:	2201      	movs	r2, #1
 8000f88:	701a      	strb	r2, [r3, #0]
 8000f8a:	f04f 3102 	mov.w	r1, #33686018	; 0x2020202
 8000f8e:	4804      	ldr	r0, [pc, #16]	; (8000fa0 <fuota_OnFragDone+0x24>)
 8000f90:	f7ff fc10 	bl	80007b4 <HAL_FLASH_Program_Flag>
 8000f94:	bd08      	pop	{r3, pc}
 8000f96:	bf00      	nop
 8000f98:	08002a14 	.word	0x08002a14
 8000f9c:	2000665a 	.word	0x2000665a
 8000fa0:	08004004 	.word	0x08004004

08000fa4 <fuota_FragDecoderRead>:
 8000fa4:	b508      	push	{r3, lr}
 8000fa6:	4613      	mov	r3, r2
 8000fa8:	460a      	mov	r2, r1
 8000faa:	4619      	mov	r1, r3
 8000fac:	f100 6000 	add.w	r0, r0, #134217728	; 0x8000000
 8000fb0:	f500 40c0 	add.w	r0, r0, #24576	; 0x6000
 8000fb4:	f01f f9cc 	bl	8020350 <udrv_flash_read>
 8000fb8:	2000      	movs	r0, #0
 8000fba:	bd08      	pop	{r3, pc}

08000fbc <fuota_FragDecoderWrite>:
 8000fbc:	b508      	push	{r3, lr}
 8000fbe:	4613      	mov	r3, r2
 8000fc0:	460a      	mov	r2, r1
 8000fc2:	4619      	mov	r1, r3
 8000fc4:	f100 6000 	add.w	r0, r0, #134217728	; 0x8000000
 8000fc8:	f500 40c0 	add.w	r0, r0, #24576	; 0x6000
 8000fcc:	f01f fa6a 	bl	80204a4 <udrv_flash_write>
 8000fd0:	2000      	movs	r0, #0
 8000fd2:	bd08      	pop	{r3, pc}

08000fd4 <OnClassChange>:
 8000fd4:	b500      	push	{lr}
 8000fd6:	b083      	sub	sp, #12
 8000fd8:	2801      	cmp	r0, #1
 8000fda:	d010      	beq.n	8000ffe <OnClassChange+0x2a>
 8000fdc:	2802      	cmp	r0, #2
 8000fde:	d106      	bne.n	8000fee <OnClassChange+0x1a>
 8000fe0:	4b10      	ldr	r3, [pc, #64]	; (8001024 <OnClassChange+0x50>)
 8000fe2:	2201      	movs	r2, #1
 8000fe4:	701a      	strb	r2, [r3, #0]
 8000fe6:	4810      	ldr	r0, [pc, #64]	; (8001028 <OnClassChange+0x54>)
 8000fe8:	f7ff fb56 	bl	8000698 <Serial_Printf>
 8000fec:	e016      	b.n	800101c <OnClassChange+0x48>
 8000fee:	4b0d      	ldr	r3, [pc, #52]	; (8001024 <OnClassChange+0x50>)
 8000ff0:	2200      	movs	r2, #0
 8000ff2:	701a      	strb	r2, [r3, #0]
 8000ff4:	480d      	ldr	r0, [pc, #52]	; (800102c <OnClassChange+0x58>)
 8000ff6:	f7ff fb4f 	bl	8000698 <Serial_Printf>
 8000ffa:	f7ff ff3d 	bl	8000e78 <__NVIC_SystemReset>
 8000ffe:	2100      	movs	r1, #0
 8001000:	f88d 1000 	strb.w	r1, [sp]
 8001004:	f88d 1001 	strb.w	r1, [sp, #1]
 8001008:	9101      	str	r1, [sp, #4]
 800100a:	4668      	mov	r0, sp
 800100c:	f01d fda6 	bl	801eb5c <LmHandlerSend>
 8001010:	4b04      	ldr	r3, [pc, #16]	; (8001024 <OnClassChange+0x50>)
 8001012:	2201      	movs	r2, #1
 8001014:	701a      	strb	r2, [r3, #0]
 8001016:	4806      	ldr	r0, [pc, #24]	; (8001030 <OnClassChange+0x5c>)
 8001018:	f7ff fb3e 	bl	8000698 <Serial_Printf>
 800101c:	b003      	add	sp, #12
 800101e:	f85d fb04 	ldr.w	pc, [sp], #4
 8001022:	bf00      	nop
 8001024:	2000665b 	.word	0x2000665b
 8001028:	08002a4c 	.word	0x08002a4c
 800102c:	08002a24 	.word	0x08002a24
 8001030:	08002a38 	.word	0x08002a38

08001034 <MlmeConfirm_fuota>:
 8001034:	b538      	push	{r3, r4, r5, lr}
 8001036:	4604      	mov	r4, r0
 8001038:	4811      	ldr	r0, [pc, #68]	; (8001080 <MlmeConfirm_fuota+0x4c>)
 800103a:	f022 fed9 	bl	8023df0 <UTIL_TIMER_IsRunning>
 800103e:	b938      	cbnz	r0, 8001050 <MlmeConfirm_fuota+0x1c>
 8001040:	7823      	ldrb	r3, [r4, #0]
 8001042:	2b01      	cmp	r3, #1
 8001044:	d011      	beq.n	800106a <MlmeConfirm_fuota+0x36>
 8001046:	4621      	mov	r1, r4
 8001048:	2002      	movs	r0, #2
 800104a:	f7ff ff39 	bl	8000ec0 <LmHandlerPackagesNotify>
 800104e:	bd38      	pop	{r3, r4, r5, pc}
 8001050:	4d0b      	ldr	r5, [pc, #44]	; (8001080 <MlmeConfirm_fuota+0x4c>)
 8001052:	4628      	mov	r0, r5
 8001054:	f022 ff3c 	bl	8023ed0 <UTIL_TIMER_Stop>
 8001058:	f644 6120 	movw	r1, #20000	; 0x4e20
 800105c:	4628      	mov	r0, r5
 800105e:	f022 ffd9 	bl	8024014 <UTIL_TIMER_SetPeriod>
 8001062:	4628      	mov	r0, r5
 8001064:	f022 ff84 	bl	8023f70 <UTIL_TIMER_Start>
 8001068:	e7ea      	b.n	8001040 <MlmeConfirm_fuota+0xc>
 800106a:	7863      	ldrb	r3, [r4, #1]
 800106c:	2b00      	cmp	r3, #0
 800106e:	d1ea      	bne.n	8001046 <MlmeConfirm_fuota+0x12>
 8001070:	4b04      	ldr	r3, [pc, #16]	; (8001084 <MlmeConfirm_fuota+0x50>)
 8001072:	2201      	movs	r2, #1
 8001074:	701a      	strb	r2, [r3, #0]
 8001076:	4804      	ldr	r0, [pc, #16]	; (8001088 <MlmeConfirm_fuota+0x54>)
 8001078:	f7ff fb0e 	bl	8000698 <Serial_Printf>
 800107c:	e7e3      	b.n	8001046 <MlmeConfirm_fuota+0x12>
 800107e:	bf00      	nop
 8001080:	20006674 	.word	0x20006674
 8001084:	20006670 	.word	0x20006670
 8001088:	08002a60 	.word	0x08002a60

0800108c <McpsIndication_fuota>:
 800108c:	b538      	push	{r3, r4, r5, lr}
 800108e:	4604      	mov	r4, r0
 8001090:	480d      	ldr	r0, [pc, #52]	; (80010c8 <McpsIndication_fuota+0x3c>)
 8001092:	f022 fead 	bl	8023df0 <UTIL_TIMER_IsRunning>
 8001096:	b950      	cbnz	r0, 80010ae <McpsIndication_fuota+0x22>
 8001098:	7f23      	ldrb	r3, [r4, #28]
 800109a:	b11b      	cbz	r3, 80010a4 <McpsIndication_fuota+0x18>
 800109c:	4b0b      	ldr	r3, [pc, #44]	; (80010cc <McpsIndication_fuota+0x40>)
 800109e:	6b5b      	ldr	r3, [r3, #52]	; 0x34
 80010a0:	b103      	cbz	r3, 80010a4 <McpsIndication_fuota+0x18>
 80010a2:	4798      	blx	r3
 80010a4:	4621      	mov	r1, r4
 80010a6:	2001      	movs	r0, #1
 80010a8:	f7ff ff0a 	bl	8000ec0 <LmHandlerPackagesNotify>
 80010ac:	bd38      	pop	{r3, r4, r5, pc}
 80010ae:	4d06      	ldr	r5, [pc, #24]	; (80010c8 <McpsIndication_fuota+0x3c>)
 80010b0:	4628      	mov	r0, r5
 80010b2:	f022 ff0d 	bl	8023ed0 <UTIL_TIMER_Stop>
 80010b6:	f644 6120 	movw	r1, #20000	; 0x4e20
 80010ba:	4628      	mov	r0, r5
 80010bc:	f022 ffaa 	bl	8024014 <UTIL_TIMER_SetPeriod>
 80010c0:	4628      	mov	r0, r5
 80010c2:	f022 ff55 	bl	8023f70 <UTIL_TIMER_Start>
 80010c6:	e7e7      	b.n	8001098 <McpsIndication_fuota+0xc>
 80010c8:	20006674 	.word	0x20006674
 80010cc:	20006000 	.word	0x20006000

080010d0 <timer_callback>:
 80010d0:	b508      	push	{r3, lr}
 80010d2:	f02c f85d 	bl	802d190 <LoRaMacIsBusy>
 80010d6:	b938      	cbnz	r0, 80010e8 <timer_callback+0x18>
 80010d8:	4b07      	ldr	r3, [pc, #28]	; (80010f8 <timer_callback+0x28>)
 80010da:	781b      	ldrb	r3, [r3, #0]
 80010dc:	b92b      	cbnz	r3, 80010ea <timer_callback+0x1a>
 80010de:	4807      	ldr	r0, [pc, #28]	; (80010fc <timer_callback+0x2c>)
 80010e0:	f7ff fab0 	bl	8000644 <Serial_PutString>
 80010e4:	f01d fc10 	bl	801e908 <service_lora_fuota_join>
 80010e8:	bd08      	pop	{r3, pc}
 80010ea:	4805      	ldr	r0, [pc, #20]	; (8001100 <timer_callback+0x30>)
 80010ec:	f7ff faaa 	bl	8000644 <Serial_PutString>
 80010f0:	4b04      	ldr	r3, [pc, #16]	; (8001104 <timer_callback+0x34>)
 80010f2:	2201      	movs	r2, #1
 80010f4:	701a      	strb	r2, [r3, #0]
 80010f6:	e7f7      	b.n	80010e8 <timer_callback+0x18>
 80010f8:	20006670 	.word	0x20006670
 80010fc:	08002a70 	.word	0x08002a70
 8001100:	08002a78 	.word	0x08002a78
 8001104:	2000665c 	.word	0x2000665c

08001108 <bootloader_fuota_stack_init>:
 8001108:	b508      	push	{r3, lr}
 800110a:	4806      	ldr	r0, [pc, #24]	; (8001124 <bootloader_fuota_stack_init+0x1c>)
 800110c:	4a06      	ldr	r2, [pc, #24]	; (8001128 <bootloader_fuota_stack_init+0x20>)
 800110e:	1a12      	subs	r2, r2, r0
 8001110:	4906      	ldr	r1, [pc, #24]	; (800112c <bootloader_fuota_stack_init+0x24>)
 8001112:	f039 f9cf 	bl	803a4b4 <memcpy>
 8001116:	4806      	ldr	r0, [pc, #24]	; (8001130 <bootloader_fuota_stack_init+0x28>)
 8001118:	4a06      	ldr	r2, [pc, #24]	; (8001134 <bootloader_fuota_stack_init+0x2c>)
 800111a:	1a12      	subs	r2, r2, r0
 800111c:	2100      	movs	r1, #0
 800111e:	f7ff f84f 	bl	80001c0 <memset>
 8001122:	bd08      	pop	{r3, pc}
 8001124:	20000000 	.word	0x20000000
 8001128:	200002d0 	.word	0x200002d0
 800112c:	0803afb8 	.word	0x0803afb8
 8001130:	200002d0 	.word	0x200002d0
 8001134:	20005e90 	.word	0x20005e90

08001138 <fuota_LmHandlerPackageRegister>:
 8001138:	b508      	push	{r3, lr}
 800113a:	4b12      	ldr	r3, [pc, #72]	; (8001184 <fuota_LmHandlerPackageRegister+0x4c>)
 800113c:	f843 1020 	str.w	r1, [r3, r0, lsl #2]
 8001140:	4a11      	ldr	r2, [pc, #68]	; (8001188 <fuota_LmHandlerPackageRegister+0x50>)
 8001142:	624a      	str	r2, [r1, #36]	; 0x24
 8001144:	f853 2020 	ldr.w	r2, [r3, r0, lsl #2]
 8001148:	4910      	ldr	r1, [pc, #64]	; (800118c <fuota_LmHandlerPackageRegister+0x54>)
 800114a:	6291      	str	r1, [r2, #40]	; 0x28
 800114c:	f853 2020 	ldr.w	r2, [r3, r0, lsl #2]
 8001150:	490f      	ldr	r1, [pc, #60]	; (8001190 <fuota_LmHandlerPackageRegister+0x58>)
 8001152:	62d1      	str	r1, [r2, #44]	; 0x2c
 8001154:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 8001158:	4a0e      	ldr	r2, [pc, #56]	; (8001194 <fuota_LmHandlerPackageRegister+0x5c>)
 800115a:	635a      	str	r2, [r3, #52]	; 0x34
 800115c:	2803      	cmp	r0, #3
 800115e:	d008      	beq.n	8001172 <fuota_LmHandlerPackageRegister+0x3a>
 8001160:	4b08      	ldr	r3, [pc, #32]	; (8001184 <fuota_LmHandlerPackageRegister+0x4c>)
 8001162:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 8001166:	685b      	ldr	r3, [r3, #4]
 8001168:	22f2      	movs	r2, #242	; 0xf2
 800116a:	490b      	ldr	r1, [pc, #44]	; (8001198 <fuota_LmHandlerPackageRegister+0x60>)
 800116c:	2000      	movs	r0, #0
 800116e:	4798      	blx	r3
 8001170:	bd08      	pop	{r3, pc}
 8001172:	4b04      	ldr	r3, [pc, #16]	; (8001184 <fuota_LmHandlerPackageRegister+0x4c>)
 8001174:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 8001178:	685b      	ldr	r3, [r3, #4]
 800117a:	22f2      	movs	r2, #242	; 0xf2
 800117c:	4906      	ldr	r1, [pc, #24]	; (8001198 <fuota_LmHandlerPackageRegister+0x60>)
 800117e:	4807      	ldr	r0, [pc, #28]	; (800119c <fuota_LmHandlerPackageRegister+0x64>)
 8001180:	4798      	blx	r3
 8001182:	e7f5      	b.n	8001170 <fuota_LmHandlerPackageRegister+0x38>
 8001184:	200003d0 	.word	0x200003d0
 8001188:	08000ea1 	.word	0x08000ea1
 800118c:	08000ea3 	.word	0x08000ea3
 8001190:	08000ea5 	.word	0x08000ea5
 8001194:	0801effd 	.word	0x0801effd
 8001198:	20006568 	.word	0x20006568
 800119c:	20006038 	.word	0x20006038

080011a0 <fuota_LmHandlerRegister>:
 80011a0:	b510      	push	{r4, lr}
 80011a2:	f01e f945 	bl	801f430 <LmphClockSyncPackageFactory>
 80011a6:	4604      	mov	r4, r0
 80011a8:	2001      	movs	r0, #1
 80011aa:	f01e f83b 	bl	801f224 <LmHandlerFuotaStackPackageRegister>
 80011ae:	4621      	mov	r1, r4
 80011b0:	2001      	movs	r0, #1
 80011b2:	f7ff ffc1 	bl	8001138 <fuota_LmHandlerPackageRegister>
 80011b6:	f01e fbd7 	bl	801f968 <LmhpRemoteMcastSetupPackageFactory>
 80011ba:	4604      	mov	r4, r0
 80011bc:	2002      	movs	r0, #2
 80011be:	f01e f831 	bl	801f224 <LmHandlerFuotaStackPackageRegister>
 80011c2:	4621      	mov	r1, r4
 80011c4:	2002      	movs	r0, #2
 80011c6:	f7ff ffb7 	bl	8001138 <fuota_LmHandlerPackageRegister>
 80011ca:	f01e fdd1 	bl	801fd70 <LmhpFragmentationPackageFactory>
 80011ce:	4604      	mov	r4, r0
 80011d0:	2003      	movs	r0, #3
 80011d2:	f01e f827 	bl	801f224 <LmHandlerFuotaStackPackageRegister>
 80011d6:	4621      	mov	r1, r4
 80011d8:	2003      	movs	r0, #3
 80011da:	f7ff ffad 	bl	8001138 <fuota_LmHandlerPackageRegister>
 80011de:	2000      	movs	r0, #0
 80011e0:	bd10      	pop	{r4, pc}
	...

080011e4 <bootloader_fuota_init>:
 80011e4:	b538      	push	{r3, r4, r5, lr}
 80011e6:	4916      	ldr	r1, [pc, #88]	; (8001240 <bootloader_fuota_init+0x5c>)
 80011e8:	4816      	ldr	r0, [pc, #88]	; (8001244 <bootloader_fuota_init+0x60>)
 80011ea:	f02e fc7d 	bl	802fae8 <LoRaMacUpdateCallbacks>
 80011ee:	f01d fbaa 	bl	801e946 <service_lora_fuota_get_band>
 80011f2:	4c15      	ldr	r4, [pc, #84]	; (8001248 <bootloader_fuota_init+0x64>)
 80011f4:	7020      	strb	r0, [r4, #0]
 80011f6:	f01f fee5 	bl	8020fc4 <service_nvm_get_adr_from_nvm>
 80011fa:	3800      	subs	r0, #0
 80011fc:	bf18      	it	ne
 80011fe:	2001      	movne	r0, #1
 8001200:	7060      	strb	r0, [r4, #1]
 8001202:	f01f fea9 	bl	8020f58 <service_nvm_get_cfm_from_nvm>
 8001206:	70a0      	strb	r0, [r4, #2]
 8001208:	f01f ff00 	bl	802100c <service_nvm_get_dr_from_nvm>
 800120c:	70e0      	strb	r0, [r4, #3]
 800120e:	2501      	movs	r5, #1
 8001210:	7125      	strb	r5, [r4, #4]
 8001212:	f020 fa2f 	bl	8021674 <service_nvm_get_dcs_from_nvm>
 8001216:	3800      	subs	r0, #0
 8001218:	bf18      	it	ne
 800121a:	2001      	movne	r0, #1
 800121c:	7160      	strb	r0, [r4, #5]
 800121e:	23f2      	movs	r3, #242	; 0xf2
 8001220:	71a3      	strb	r3, [r4, #6]
 8001222:	4b0a      	ldr	r3, [pc, #40]	; (800124c <bootloader_fuota_init+0x68>)
 8001224:	60a3      	str	r3, [r4, #8]
 8001226:	4621      	mov	r1, r4
 8001228:	4809      	ldr	r0, [pc, #36]	; (8001250 <bootloader_fuota_init+0x6c>)
 800122a:	f01d fe97 	bl	801ef5c <LmHandlerInit>
 800122e:	f7ff ffb7 	bl	80011a0 <fuota_LmHandlerRegister>
 8001232:	4808      	ldr	r0, [pc, #32]	; (8001254 <bootloader_fuota_init+0x70>)
 8001234:	f01e fe8e 	bl	801ff54 <FragDecoderUpdateCallback>
 8001238:	4b07      	ldr	r3, [pc, #28]	; (8001258 <bootloader_fuota_init+0x74>)
 800123a:	701d      	strb	r5, [r3, #0]
 800123c:	bd38      	pop	{r3, r4, r5, pc}
 800123e:	bf00      	nop
 8001240:	20006048 	.word	0x20006048
 8001244:	20006058 	.word	0x20006058
 8001248:	20006660 	.word	0x20006660
 800124c:	20006568 	.word	0x20006568
 8001250:	20006000 	.word	0x20006000
 8001254:	20006038 	.word	0x20006038
 8001258:	2000665b 	.word	0x2000665b

0800125c <fuota_init>:
 800125c:	b510      	push	{r4, lr}
 800125e:	f01c fe5c 	bl	801df1a <BoardInitMcu>
 8001262:	f01d fb47 	bl	801e8f4 <service_fuota_nvm_init>
 8001266:	f01f fd1d 	bl	8020ca4 <service_nvm_get_band_from_nvm>
 800126a:	f010 04ff 	ands.w	r4, r0, #255	; 0xff
 800126e:	d035      	beq.n	80012dc <fuota_init+0x80>
 8001270:	2c14      	cmp	r4, #20
 8001272:	d037      	beq.n	80012e4 <fuota_init+0x88>
 8001274:	2c15      	cmp	r4, #21
 8001276:	d039      	beq.n	80012ec <fuota_init+0x90>
 8001278:	2c16      	cmp	r4, #22
 800127a:	d03b      	beq.n	80012f4 <fuota_init+0x98>
 800127c:	f01d fb63 	bl	801e946 <service_lora_fuota_get_band>
 8001280:	b2c2      	uxtb	r2, r0
 8001282:	4921      	ldr	r1, [pc, #132]	; (8001308 <fuota_init+0xac>)
 8001284:	4821      	ldr	r0, [pc, #132]	; (800130c <fuota_init+0xb0>)
 8001286:	f02c fb6b 	bl	802d960 <LoRaMacInitialization>
 800128a:	bbb8      	cbnz	r0, 80012fc <fuota_init+0xa0>
 800128c:	f01d fb5b 	bl	801e946 <service_lora_fuota_get_band>
 8001290:	4c1f      	ldr	r4, [pc, #124]	; (8001310 <fuota_init+0xb4>)
 8001292:	7020      	strb	r0, [r4, #0]
 8001294:	f01f fe96 	bl	8020fc4 <service_nvm_get_adr_from_nvm>
 8001298:	3800      	subs	r0, #0
 800129a:	bf18      	it	ne
 800129c:	2001      	movne	r0, #1
 800129e:	7060      	strb	r0, [r4, #1]
 80012a0:	f01f fe5a 	bl	8020f58 <service_nvm_get_cfm_from_nvm>
 80012a4:	70a0      	strb	r0, [r4, #2]
 80012a6:	f01f feb1 	bl	802100c <service_nvm_get_dr_from_nvm>
 80012aa:	70e0      	strb	r0, [r4, #3]
 80012ac:	2301      	movs	r3, #1
 80012ae:	7123      	strb	r3, [r4, #4]
 80012b0:	f020 f9e0 	bl	8021674 <service_nvm_get_dcs_from_nvm>
 80012b4:	3800      	subs	r0, #0
 80012b6:	bf18      	it	ne
 80012b8:	2001      	movne	r0, #1
 80012ba:	7160      	strb	r0, [r4, #5]
 80012bc:	23f2      	movs	r3, #242	; 0xf2
 80012be:	71a3      	strb	r3, [r4, #6]
 80012c0:	4b14      	ldr	r3, [pc, #80]	; (8001314 <fuota_init+0xb8>)
 80012c2:	60a3      	str	r3, [r4, #8]
 80012c4:	4621      	mov	r1, r4
 80012c6:	4814      	ldr	r0, [pc, #80]	; (8001318 <fuota_init+0xbc>)
 80012c8:	f01d fe48 	bl	801ef5c <LmHandlerInit>
 80012cc:	f7ff ff68 	bl	80011a0 <fuota_LmHandlerRegister>
 80012d0:	f01d fb44 	bl	801e95c <service_fuota_lora_config>
 80012d4:	f02c fd20 	bl	802dd18 <LoRaMacStart>
 80012d8:	2000      	movs	r0, #0
 80012da:	bd10      	pop	{r4, pc}
 80012dc:	2001      	movs	r0, #1
 80012de:	f030 ff11 	bl	8032104 <RegionAS923SubBandSet>
 80012e2:	e7c5      	b.n	8001270 <fuota_init+0x14>
 80012e4:	2002      	movs	r0, #2
 80012e6:	f030 ff0d 	bl	8032104 <RegionAS923SubBandSet>
 80012ea:	e7c3      	b.n	8001274 <fuota_init+0x18>
 80012ec:	2003      	movs	r0, #3
 80012ee:	f030 ff09 	bl	8032104 <RegionAS923SubBandSet>
 80012f2:	e7c1      	b.n	8001278 <fuota_init+0x1c>
 80012f4:	2004      	movs	r0, #4
 80012f6:	f030 ff05 	bl	8032104 <RegionAS923SubBandSet>
 80012fa:	e7bf      	b.n	800127c <fuota_init+0x20>
 80012fc:	4807      	ldr	r0, [pc, #28]	; (800131c <fuota_init+0xc0>)
 80012fe:	f7ff f9a1 	bl	8000644 <Serial_PutString>
 8001302:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
 8001306:	e7e8      	b.n	80012da <fuota_init+0x7e>
 8001308:	20006048 	.word	0x20006048
 800130c:	20006058 	.word	0x20006058
 8001310:	20006660 	.word	0x20006660
 8001314:	20006568 	.word	0x20006568
 8001318:	20006000 	.word	0x20006000
 800131c:	08002a90 	.word	0x08002a90

08001320 <bootloader_fuota_start>:
 8001320:	b510      	push	{r4, lr}
 8001322:	b084      	sub	sp, #16
 8001324:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 8001328:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 800132a:	f042 0204 	orr.w	r2, r2, #4
 800132e:	649a      	str	r2, [r3, #72]	; 0x48
 8001330:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 8001332:	f002 0204 	and.w	r2, r2, #4
 8001336:	9203      	str	r2, [sp, #12]
 8001338:	9a03      	ldr	r2, [sp, #12]
 800133a:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 800133c:	f042 0201 	orr.w	r2, r2, #1
 8001340:	649a      	str	r2, [r3, #72]	; 0x48
 8001342:	6c9b      	ldr	r3, [r3, #72]	; 0x48
 8001344:	f003 0301 	and.w	r3, r3, #1
 8001348:	9302      	str	r3, [sp, #8]
 800134a:	9b02      	ldr	r3, [sp, #8]
 800134c:	2200      	movs	r2, #0
 800134e:	4611      	mov	r1, r2
 8001350:	200b      	movs	r0, #11
 8001352:	f020 fd15 	bl	8021d80 <HAL_NVIC_SetPriority>
 8001356:	200b      	movs	r0, #11
 8001358:	f020 fd44 	bl	8021de4 <HAL_NVIC_EnableIRQ>
 800135c:	f022 fd18 	bl	8023d90 <UTIL_TIMER_Init>
 8001360:	f7ff ff7c 	bl	800125c <fuota_init>
 8001364:	f01d fad0 	bl	801e908 <service_lora_fuota_join>
 8001368:	2801      	cmp	r0, #1
 800136a:	d016      	beq.n	800139a <bootloader_fuota_start+0x7a>
 800136c:	480d      	ldr	r0, [pc, #52]	; (80013a4 <bootloader_fuota_start+0x84>)
 800136e:	f7ff f969 	bl	8000644 <Serial_PutString>
 8001372:	4c0d      	ldr	r4, [pc, #52]	; (80013a8 <bootloader_fuota_start+0x88>)
 8001374:	2300      	movs	r3, #0
 8001376:	9300      	str	r3, [sp, #0]
 8001378:	4b0c      	ldr	r3, [pc, #48]	; (80013ac <bootloader_fuota_start+0x8c>)
 800137a:	2201      	movs	r2, #1
 800137c:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
 8001380:	4620      	mov	r0, r4
 8001382:	f022 fd15 	bl	8023db0 <UTIL_TIMER_Create>
 8001386:	f644 6120 	movw	r1, #20000	; 0x4e20
 800138a:	4620      	mov	r0, r4
 800138c:	f022 fe42 	bl	8024014 <UTIL_TIMER_SetPeriod>
 8001390:	4620      	mov	r0, r4
 8001392:	f022 fded 	bl	8023f70 <UTIL_TIMER_Start>
 8001396:	b004      	add	sp, #16
 8001398:	bd10      	pop	{r4, pc}
 800139a:	4805      	ldr	r0, [pc, #20]	; (80013b0 <bootloader_fuota_start+0x90>)
 800139c:	f7ff f952 	bl	8000644 <Serial_PutString>
 80013a0:	e7e7      	b.n	8001372 <bootloader_fuota_start+0x52>
 80013a2:	bf00      	nop
 80013a4:	08002ac0 	.word	0x08002ac0
 80013a8:	20006674 	.word	0x20006674
 80013ac:	080010d1 	.word	0x080010d1
 80013b0:	08002ab0 	.word	0x08002ab0

080013b4 <UplinkProcess>:
 80013b4:	b500      	push	{lr}
 80013b6:	b083      	sub	sp, #12
 80013b8:	f01d fdda 	bl	801ef70 <LmHandlerIsBusy>
 80013bc:	b930      	cbnz	r0, 80013cc <UplinkProcess+0x18>
 80013be:	4a19      	ldr	r2, [pc, #100]	; (8001424 <UplinkProcess+0x70>)
 80013c0:	7813      	ldrb	r3, [r2, #0]
 80013c2:	b2db      	uxtb	r3, r3
 80013c4:	2100      	movs	r1, #0
 80013c6:	7011      	strb	r1, [r2, #0]
 80013c8:	2b01      	cmp	r3, #1
 80013ca:	d002      	beq.n	80013d2 <UplinkProcess+0x1e>
 80013cc:	b003      	add	sp, #12
 80013ce:	f85d fb04 	ldr.w	pc, [sp], #4
 80013d2:	4b15      	ldr	r3, [pc, #84]	; (8001428 <UplinkProcess+0x74>)
 80013d4:	781b      	ldrb	r3, [r3, #0]
 80013d6:	2b00      	cmp	r3, #0
 80013d8:	d1f8      	bne.n	80013cc <UplinkProcess+0x18>
 80013da:	4814      	ldr	r0, [pc, #80]	; (800142c <UplinkProcess+0x78>)
 80013dc:	f7ff f932 	bl	8000644 <Serial_PutString>
 80013e0:	4b13      	ldr	r3, [pc, #76]	; (8001430 <UplinkProcess+0x7c>)
 80013e2:	781b      	ldrb	r3, [r3, #0]
 80013e4:	b9cb      	cbnz	r3, 800141a <UplinkProcess+0x66>
 80013e6:	4b13      	ldr	r3, [pc, #76]	; (8001434 <UplinkProcess+0x80>)
 80013e8:	781b      	ldrb	r3, [r3, #0]
 80013ea:	b913      	cbnz	r3, 80013f2 <UplinkProcess+0x3e>
 80013ec:	f01e f824 	bl	801f438 <LmhpClockSyncAppTimeReq>
 80013f0:	e7ec      	b.n	80013cc <UplinkProcess+0x18>
 80013f2:	4811      	ldr	r0, [pc, #68]	; (8001438 <UplinkProcess+0x84>)
 80013f4:	f7ff f926 	bl	8000644 <Serial_PutString>
 80013f8:	21ff      	movs	r1, #255	; 0xff
 80013fa:	2000      	movs	r0, #0
 80013fc:	f02a fab2 	bl	802b964 <randr>
 8001400:	4b0e      	ldr	r3, [pc, #56]	; (800143c <UplinkProcess+0x88>)
 8001402:	7018      	strb	r0, [r3, #0]
 8001404:	4a0e      	ldr	r2, [pc, #56]	; (8001440 <UplinkProcess+0x8c>)
 8001406:	466b      	mov	r3, sp
 8001408:	e892 0003 	ldmia.w	r2, {r0, r1}
 800140c:	e883 0003 	stmia.w	r3, {r0, r1}
 8001410:	2100      	movs	r1, #0
 8001412:	4618      	mov	r0, r3
 8001414:	f01d fba2 	bl	801eb5c <LmHandlerSend>
 8001418:	e7d8      	b.n	80013cc <UplinkProcess+0x18>
 800141a:	480a      	ldr	r0, [pc, #40]	; (8001444 <UplinkProcess+0x90>)
 800141c:	f7ff f912 	bl	8000644 <Serial_PutString>
 8001420:	f7ff fd2a 	bl	8000e78 <__NVIC_SystemReset>
 8001424:	2000665c 	.word	0x2000665c
 8001428:	2000665b 	.word	0x2000665b
 800142c:	08002acc 	.word	0x08002acc
 8001430:	2000665a 	.word	0x2000665a
 8001434:	200002e4 	.word	0x200002e4
 8001438:	08002aec 	.word	0x08002aec
 800143c:	20006568 	.word	0x20006568
 8001440:	08002890 	.word	0x08002890
 8001444:	08002b04 	.word	0x08002b04

08001448 <UART_EndRxTransfer>:
 8001448:	6802      	ldr	r2, [r0, #0]
 800144a:	e852 3f00 	ldrex	r3, [r2]
 800144e:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001452:	e842 3100 	strex	r1, r3, [r2]
 8001456:	2900      	cmp	r1, #0
 8001458:	d1f6      	bne.n	8001448 <UART_EndRxTransfer>
 800145a:	6802      	ldr	r2, [r0, #0]
 800145c:	f102 0308 	add.w	r3, r2, #8
 8001460:	e853 3f00 	ldrex	r3, [r3]
 8001464:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001468:	f023 0301 	bic.w	r3, r3, #1
 800146c:	3208      	adds	r2, #8
 800146e:	e842 3100 	strex	r1, r3, [r2]
 8001472:	2900      	cmp	r1, #0
 8001474:	d1f1      	bne.n	800145a <UART_EndRxTransfer+0x12>
 8001476:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 8001478:	2b01      	cmp	r3, #1
 800147a:	d006      	beq.n	800148a <UART_EndRxTransfer+0x42>
 800147c:	2320      	movs	r3, #32
 800147e:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001482:	2300      	movs	r3, #0
 8001484:	66c3      	str	r3, [r0, #108]	; 0x6c
 8001486:	6703      	str	r3, [r0, #112]	; 0x70
 8001488:	4770      	bx	lr
 800148a:	6802      	ldr	r2, [r0, #0]
 800148c:	e852 3f00 	ldrex	r3, [r2]
 8001490:	f023 0310 	bic.w	r3, r3, #16
 8001494:	e842 3100 	strex	r1, r3, [r2]
 8001498:	2900      	cmp	r1, #0
 800149a:	d1f6      	bne.n	800148a <UART_EndRxTransfer+0x42>
 800149c:	e7ee      	b.n	800147c <UART_EndRxTransfer+0x34>

0800149e <HAL_UART_DeInit>:
 800149e:	b1e8      	cbz	r0, 80014dc <HAL_UART_DeInit+0x3e>
 80014a0:	b538      	push	{r3, r4, r5, lr}
 80014a2:	4605      	mov	r5, r0
 80014a4:	2324      	movs	r3, #36	; 0x24
 80014a6:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80014aa:	6802      	ldr	r2, [r0, #0]
 80014ac:	6813      	ldr	r3, [r2, #0]
 80014ae:	f023 0301 	bic.w	r3, r3, #1
 80014b2:	6013      	str	r3, [r2, #0]
 80014b4:	6803      	ldr	r3, [r0, #0]
 80014b6:	2400      	movs	r4, #0
 80014b8:	601c      	str	r4, [r3, #0]
 80014ba:	6803      	ldr	r3, [r0, #0]
 80014bc:	605c      	str	r4, [r3, #4]
 80014be:	6803      	ldr	r3, [r0, #0]
 80014c0:	609c      	str	r4, [r3, #8]
 80014c2:	f7ff fb01 	bl	8000ac8 <HAL_UART_MspDeInit>
 80014c6:	f8c5 408c 	str.w	r4, [r5, #140]	; 0x8c
 80014ca:	f8c5 4084 	str.w	r4, [r5, #132]	; 0x84
 80014ce:	f8c5 4088 	str.w	r4, [r5, #136]	; 0x88
 80014d2:	66ec      	str	r4, [r5, #108]	; 0x6c
 80014d4:	f885 4080 	strb.w	r4, [r5, #128]	; 0x80
 80014d8:	4620      	mov	r0, r4
 80014da:	bd38      	pop	{r3, r4, r5, pc}
 80014dc:	2001      	movs	r0, #1
 80014de:	4770      	bx	lr

080014e0 <HAL_UART_TxCpltCallback>:
 80014e0:	4770      	bx	lr

080014e2 <UART_EndTransmit_IT>:
 80014e2:	b508      	push	{r3, lr}
 80014e4:	6802      	ldr	r2, [r0, #0]
 80014e6:	e852 3f00 	ldrex	r3, [r2]
 80014ea:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 80014ee:	e842 3100 	strex	r1, r3, [r2]
 80014f2:	2900      	cmp	r1, #0
 80014f4:	d1f6      	bne.n	80014e4 <UART_EndTransmit_IT+0x2>
 80014f6:	2320      	movs	r3, #32
 80014f8:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80014fc:	2300      	movs	r3, #0
 80014fe:	6743      	str	r3, [r0, #116]	; 0x74
 8001500:	f7ff ffee 	bl	80014e0 <HAL_UART_TxCpltCallback>
 8001504:	bd08      	pop	{r3, pc}

08001506 <HAL_UART_ErrorCallback>:
 8001506:	4770      	bx	lr

08001508 <UART_DMAAbortOnError>:
 8001508:	b508      	push	{r3, lr}
 800150a:	6a80      	ldr	r0, [r0, #40]	; 0x28
 800150c:	2300      	movs	r3, #0
 800150e:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 8001512:	f8a0 3056 	strh.w	r3, [r0, #86]	; 0x56
 8001516:	f7ff fff6 	bl	8001506 <HAL_UART_ErrorCallback>
 800151a:	bd08      	pop	{r3, pc}

0800151c <HAL_UART_AbortReceiveCpltCallback>:
 800151c:	4770      	bx	lr
	...

08001520 <HAL_UART_AbortReceive_IT>:
 8001520:	b510      	push	{r4, lr}
 8001522:	4604      	mov	r4, r0
 8001524:	6822      	ldr	r2, [r4, #0]
 8001526:	e852 3f00 	ldrex	r3, [r2]
 800152a:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 800152e:	e842 3100 	strex	r1, r3, [r2]
 8001532:	2900      	cmp	r1, #0
 8001534:	d1f6      	bne.n	8001524 <HAL_UART_AbortReceive_IT+0x4>
 8001536:	6822      	ldr	r2, [r4, #0]
 8001538:	f102 0308 	add.w	r3, r2, #8
 800153c:	e853 3f00 	ldrex	r3, [r3]
 8001540:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001544:	f023 0301 	bic.w	r3, r3, #1
 8001548:	3208      	adds	r2, #8
 800154a:	e842 3100 	strex	r1, r3, [r2]
 800154e:	2900      	cmp	r1, #0
 8001550:	d1f1      	bne.n	8001536 <HAL_UART_AbortReceive_IT+0x16>
 8001552:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001554:	2b01      	cmp	r3, #1
 8001556:	d01c      	beq.n	8001592 <HAL_UART_AbortReceive_IT+0x72>
 8001558:	6823      	ldr	r3, [r4, #0]
 800155a:	689a      	ldr	r2, [r3, #8]
 800155c:	f012 0f40 	tst.w	r2, #64	; 0x40
 8001560:	d035      	beq.n	80015ce <HAL_UART_AbortReceive_IT+0xae>
 8001562:	6822      	ldr	r2, [r4, #0]
 8001564:	f102 0308 	add.w	r3, r2, #8
 8001568:	e853 3f00 	ldrex	r3, [r3]
 800156c:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 8001570:	3208      	adds	r2, #8
 8001572:	e842 3100 	strex	r1, r3, [r2]
 8001576:	2900      	cmp	r1, #0
 8001578:	d1f3      	bne.n	8001562 <HAL_UART_AbortReceive_IT+0x42>
 800157a:	6fe3      	ldr	r3, [r4, #124]	; 0x7c
 800157c:	b19b      	cbz	r3, 80015a6 <HAL_UART_AbortReceive_IT+0x86>
 800157e:	4a1b      	ldr	r2, [pc, #108]	; (80015ec <HAL_UART_AbortReceive_IT+0xcc>)
 8001580:	639a      	str	r2, [r3, #56]	; 0x38
 8001582:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 8001584:	f02a f85e 	bl	802b644 <HAL_DMA_Abort_IT>
 8001588:	b370      	cbz	r0, 80015e8 <HAL_UART_AbortReceive_IT+0xc8>
 800158a:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 800158c:	6b83      	ldr	r3, [r0, #56]	; 0x38
 800158e:	4798      	blx	r3
 8001590:	e02a      	b.n	80015e8 <HAL_UART_AbortReceive_IT+0xc8>
 8001592:	6822      	ldr	r2, [r4, #0]
 8001594:	e852 3f00 	ldrex	r3, [r2]
 8001598:	f023 0310 	bic.w	r3, r3, #16
 800159c:	e842 3100 	strex	r1, r3, [r2]
 80015a0:	2900      	cmp	r1, #0
 80015a2:	d1f6      	bne.n	8001592 <HAL_UART_AbortReceive_IT+0x72>
 80015a4:	e7d8      	b.n	8001558 <HAL_UART_AbortReceive_IT+0x38>
 80015a6:	2300      	movs	r3, #0
 80015a8:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 80015ac:	65a3      	str	r3, [r4, #88]	; 0x58
 80015ae:	6822      	ldr	r2, [r4, #0]
 80015b0:	210f      	movs	r1, #15
 80015b2:	6211      	str	r1, [r2, #32]
 80015b4:	6821      	ldr	r1, [r4, #0]
 80015b6:	698a      	ldr	r2, [r1, #24]
 80015b8:	f042 0208 	orr.w	r2, r2, #8
 80015bc:	618a      	str	r2, [r1, #24]
 80015be:	2220      	movs	r2, #32
 80015c0:	f8c4 2088 	str.w	r2, [r4, #136]	; 0x88
 80015c4:	66e3      	str	r3, [r4, #108]	; 0x6c
 80015c6:	4620      	mov	r0, r4
 80015c8:	f7ff ffa8 	bl	800151c <HAL_UART_AbortReceiveCpltCallback>
 80015cc:	e00c      	b.n	80015e8 <HAL_UART_AbortReceive_IT+0xc8>
 80015ce:	2200      	movs	r2, #0
 80015d0:	f8a4 205e 	strh.w	r2, [r4, #94]	; 0x5e
 80015d4:	65a2      	str	r2, [r4, #88]	; 0x58
 80015d6:	210f      	movs	r1, #15
 80015d8:	6219      	str	r1, [r3, #32]
 80015da:	2320      	movs	r3, #32
 80015dc:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80015e0:	66e2      	str	r2, [r4, #108]	; 0x6c
 80015e2:	4620      	mov	r0, r4
 80015e4:	f7ff ff9a 	bl	800151c <HAL_UART_AbortReceiveCpltCallback>
 80015e8:	2000      	movs	r0, #0
 80015ea:	bd10      	pop	{r4, pc}
 80015ec:	080015f1 	.word	0x080015f1

080015f0 <UART_DMARxOnlyAbortCallback>:
 80015f0:	b508      	push	{r3, lr}
 80015f2:	6a80      	ldr	r0, [r0, #40]	; 0x28
 80015f4:	2200      	movs	r2, #0
 80015f6:	f8a0 205e 	strh.w	r2, [r0, #94]	; 0x5e
 80015fa:	6803      	ldr	r3, [r0, #0]
 80015fc:	210f      	movs	r1, #15
 80015fe:	6219      	str	r1, [r3, #32]
 8001600:	6801      	ldr	r1, [r0, #0]
 8001602:	698b      	ldr	r3, [r1, #24]
 8001604:	f043 0308 	orr.w	r3, r3, #8
 8001608:	618b      	str	r3, [r1, #24]
 800160a:	2320      	movs	r3, #32
 800160c:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001610:	66c2      	str	r2, [r0, #108]	; 0x6c
 8001612:	f7ff ff83 	bl	800151c <HAL_UART_AbortReceiveCpltCallback>
 8001616:	bd08      	pop	{r3, pc}

08001618 <HAL_UARTEx_RxEventCallback>:
 8001618:	4770      	bx	lr
	...

0800161c <HAL_UART_IRQHandler>:
 800161c:	b570      	push	{r4, r5, r6, lr}
 800161e:	4604      	mov	r4, r0
 8001620:	6801      	ldr	r1, [r0, #0]
 8001622:	69cb      	ldr	r3, [r1, #28]
 8001624:	6808      	ldr	r0, [r1, #0]
 8001626:	688d      	ldr	r5, [r1, #8]
 8001628:	f640 020f 	movw	r2, #2063	; 0x80f
 800162c:	401a      	ands	r2, r3
 800162e:	d108      	bne.n	8001642 <HAL_UART_IRQHandler+0x26>
 8001630:	f013 0f20 	tst.w	r3, #32
 8001634:	d005      	beq.n	8001642 <HAL_UART_IRQHandler+0x26>
 8001636:	f010 0f20 	tst.w	r0, #32
 800163a:	d134      	bne.n	80016a6 <HAL_UART_IRQHandler+0x8a>
 800163c:	f015 5f80 	tst.w	r5, #268435456	; 0x10000000
 8001640:	d131      	bne.n	80016a6 <HAL_UART_IRQHandler+0x8a>
 8001642:	b12a      	cbz	r2, 8001650 <HAL_UART_IRQHandler+0x34>
 8001644:	4a95      	ldr	r2, [pc, #596]	; (800189c <HAL_UART_IRQHandler+0x280>)
 8001646:	402a      	ands	r2, r5
 8001648:	d133      	bne.n	80016b2 <HAL_UART_IRQHandler+0x96>
 800164a:	4e95      	ldr	r6, [pc, #596]	; (80018a0 <HAL_UART_IRQHandler+0x284>)
 800164c:	4230      	tst	r0, r6
 800164e:	d130      	bne.n	80016b2 <HAL_UART_IRQHandler+0x96>
 8001650:	6ee2      	ldr	r2, [r4, #108]	; 0x6c
 8001652:	2a01      	cmp	r2, #1
 8001654:	f000 80c3 	beq.w	80017de <HAL_UART_IRQHandler+0x1c2>
 8001658:	f413 1f80 	tst.w	r3, #1048576	; 0x100000
 800165c:	d003      	beq.n	8001666 <HAL_UART_IRQHandler+0x4a>
 800165e:	f415 0f80 	tst.w	r5, #4194304	; 0x400000
 8001662:	f040 815b 	bne.w	800191c <HAL_UART_IRQHandler+0x300>
 8001666:	f013 0f80 	tst.w	r3, #128	; 0x80
 800166a:	d007      	beq.n	800167c <HAL_UART_IRQHandler+0x60>
 800166c:	f010 0f80 	tst.w	r0, #128	; 0x80
 8001670:	f040 815b 	bne.w	800192a <HAL_UART_IRQHandler+0x30e>
 8001674:	f415 0f00 	tst.w	r5, #8388608	; 0x800000
 8001678:	f040 8157 	bne.w	800192a <HAL_UART_IRQHandler+0x30e>
 800167c:	f013 0f40 	tst.w	r3, #64	; 0x40
 8001680:	d003      	beq.n	800168a <HAL_UART_IRQHandler+0x6e>
 8001682:	f010 0f40 	tst.w	r0, #64	; 0x40
 8001686:	f040 8157 	bne.w	8001938 <HAL_UART_IRQHandler+0x31c>
 800168a:	f413 0f00 	tst.w	r3, #8388608	; 0x800000
 800168e:	d003      	beq.n	8001698 <HAL_UART_IRQHandler+0x7c>
 8001690:	f010 4f80 	tst.w	r0, #1073741824	; 0x40000000
 8001694:	f040 8154 	bne.w	8001940 <HAL_UART_IRQHandler+0x324>
 8001698:	f013 7f80 	tst.w	r3, #16777216	; 0x1000000
 800169c:	d002      	beq.n	80016a4 <HAL_UART_IRQHandler+0x88>
 800169e:	2800      	cmp	r0, #0
 80016a0:	f2c0 8152 	blt.w	8001948 <HAL_UART_IRQHandler+0x32c>
 80016a4:	bd70      	pop	{r4, r5, r6, pc}
 80016a6:	6f23      	ldr	r3, [r4, #112]	; 0x70
 80016a8:	2b00      	cmp	r3, #0
 80016aa:	d0fb      	beq.n	80016a4 <HAL_UART_IRQHandler+0x88>
 80016ac:	4620      	mov	r0, r4
 80016ae:	4798      	blx	r3
 80016b0:	e7f8      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 80016b2:	f013 0f01 	tst.w	r3, #1
 80016b6:	d009      	beq.n	80016cc <HAL_UART_IRQHandler+0xb0>
 80016b8:	f410 7f80 	tst.w	r0, #256	; 0x100
 80016bc:	d006      	beq.n	80016cc <HAL_UART_IRQHandler+0xb0>
 80016be:	2601      	movs	r6, #1
 80016c0:	620e      	str	r6, [r1, #32]
 80016c2:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 80016c6:	4331      	orrs	r1, r6
 80016c8:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 80016cc:	f013 0f02 	tst.w	r3, #2
 80016d0:	d00b      	beq.n	80016ea <HAL_UART_IRQHandler+0xce>
 80016d2:	f015 0f01 	tst.w	r5, #1
 80016d6:	d008      	beq.n	80016ea <HAL_UART_IRQHandler+0xce>
 80016d8:	6821      	ldr	r1, [r4, #0]
 80016da:	2602      	movs	r6, #2
 80016dc:	620e      	str	r6, [r1, #32]
 80016de:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 80016e2:	f041 0104 	orr.w	r1, r1, #4
 80016e6:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 80016ea:	f013 0f04 	tst.w	r3, #4
 80016ee:	d00b      	beq.n	8001708 <HAL_UART_IRQHandler+0xec>
 80016f0:	f015 0f01 	tst.w	r5, #1
 80016f4:	d008      	beq.n	8001708 <HAL_UART_IRQHandler+0xec>
 80016f6:	6821      	ldr	r1, [r4, #0]
 80016f8:	2604      	movs	r6, #4
 80016fa:	620e      	str	r6, [r1, #32]
 80016fc:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 8001700:	f041 0102 	orr.w	r1, r1, #2
 8001704:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 8001708:	f013 0f08 	tst.w	r3, #8
 800170c:	d00b      	beq.n	8001726 <HAL_UART_IRQHandler+0x10a>
 800170e:	f010 0f20 	tst.w	r0, #32
 8001712:	d100      	bne.n	8001716 <HAL_UART_IRQHandler+0xfa>
 8001714:	b13a      	cbz	r2, 8001726 <HAL_UART_IRQHandler+0x10a>
 8001716:	6822      	ldr	r2, [r4, #0]
 8001718:	2108      	movs	r1, #8
 800171a:	6211      	str	r1, [r2, #32]
 800171c:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 8001720:	430a      	orrs	r2, r1
 8001722:	f8c4 208c 	str.w	r2, [r4, #140]	; 0x8c
 8001726:	f413 6f00 	tst.w	r3, #2048	; 0x800
 800172a:	d00c      	beq.n	8001746 <HAL_UART_IRQHandler+0x12a>
 800172c:	f010 6f80 	tst.w	r0, #67108864	; 0x4000000
 8001730:	d009      	beq.n	8001746 <HAL_UART_IRQHandler+0x12a>
 8001732:	6822      	ldr	r2, [r4, #0]
 8001734:	f44f 6100 	mov.w	r1, #2048	; 0x800
 8001738:	6211      	str	r1, [r2, #32]
 800173a:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 800173e:	f042 0220 	orr.w	r2, r2, #32
 8001742:	f8c4 208c 	str.w	r2, [r4, #140]	; 0x8c
 8001746:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 800174a:	2a00      	cmp	r2, #0
 800174c:	d0aa      	beq.n	80016a4 <HAL_UART_IRQHandler+0x88>
 800174e:	f013 0f20 	tst.w	r3, #32
 8001752:	d009      	beq.n	8001768 <HAL_UART_IRQHandler+0x14c>
 8001754:	f010 0f20 	tst.w	r0, #32
 8001758:	d102      	bne.n	8001760 <HAL_UART_IRQHandler+0x144>
 800175a:	f015 5f80 	tst.w	r5, #268435456	; 0x10000000
 800175e:	d003      	beq.n	8001768 <HAL_UART_IRQHandler+0x14c>
 8001760:	6f23      	ldr	r3, [r4, #112]	; 0x70
 8001762:	b10b      	cbz	r3, 8001768 <HAL_UART_IRQHandler+0x14c>
 8001764:	4620      	mov	r0, r4
 8001766:	4798      	blx	r3
 8001768:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 800176c:	6823      	ldr	r3, [r4, #0]
 800176e:	689b      	ldr	r3, [r3, #8]
 8001770:	f013 0f40 	tst.w	r3, #64	; 0x40
 8001774:	d102      	bne.n	800177c <HAL_UART_IRQHandler+0x160>
 8001776:	f012 0f28 	tst.w	r2, #40	; 0x28
 800177a:	d029      	beq.n	80017d0 <HAL_UART_IRQHandler+0x1b4>
 800177c:	4620      	mov	r0, r4
 800177e:	f7ff fe63 	bl	8001448 <UART_EndRxTransfer>
 8001782:	6823      	ldr	r3, [r4, #0]
 8001784:	689b      	ldr	r3, [r3, #8]
 8001786:	f013 0f40 	tst.w	r3, #64	; 0x40
 800178a:	d01d      	beq.n	80017c8 <HAL_UART_IRQHandler+0x1ac>
 800178c:	6822      	ldr	r2, [r4, #0]
 800178e:	f102 0308 	add.w	r3, r2, #8
 8001792:	e853 3f00 	ldrex	r3, [r3]
 8001796:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 800179a:	3208      	adds	r2, #8
 800179c:	e842 3100 	strex	r1, r3, [r2]
 80017a0:	2900      	cmp	r1, #0
 80017a2:	d1f3      	bne.n	800178c <HAL_UART_IRQHandler+0x170>
 80017a4:	6fe3      	ldr	r3, [r4, #124]	; 0x7c
 80017a6:	b15b      	cbz	r3, 80017c0 <HAL_UART_IRQHandler+0x1a4>
 80017a8:	4a3e      	ldr	r2, [pc, #248]	; (80018a4 <HAL_UART_IRQHandler+0x288>)
 80017aa:	639a      	str	r2, [r3, #56]	; 0x38
 80017ac:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 80017ae:	f029 ff49 	bl	802b644 <HAL_DMA_Abort_IT>
 80017b2:	2800      	cmp	r0, #0
 80017b4:	f43f af76 	beq.w	80016a4 <HAL_UART_IRQHandler+0x88>
 80017b8:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 80017ba:	6b83      	ldr	r3, [r0, #56]	; 0x38
 80017bc:	4798      	blx	r3
 80017be:	e771      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 80017c0:	4620      	mov	r0, r4
 80017c2:	f7ff fea0 	bl	8001506 <HAL_UART_ErrorCallback>
 80017c6:	e76d      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 80017c8:	4620      	mov	r0, r4
 80017ca:	f7ff fe9c 	bl	8001506 <HAL_UART_ErrorCallback>
 80017ce:	e769      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 80017d0:	4620      	mov	r0, r4
 80017d2:	f7ff fe98 	bl	8001506 <HAL_UART_ErrorCallback>
 80017d6:	2300      	movs	r3, #0
 80017d8:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 80017dc:	e762      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 80017de:	f013 0f10 	tst.w	r3, #16
 80017e2:	f43f af39 	beq.w	8001658 <HAL_UART_IRQHandler+0x3c>
 80017e6:	f010 0f10 	tst.w	r0, #16
 80017ea:	f43f af35 	beq.w	8001658 <HAL_UART_IRQHandler+0x3c>
 80017ee:	2310      	movs	r3, #16
 80017f0:	620b      	str	r3, [r1, #32]
 80017f2:	6823      	ldr	r3, [r4, #0]
 80017f4:	689b      	ldr	r3, [r3, #8]
 80017f6:	f013 0f40 	tst.w	r3, #64	; 0x40
 80017fa:	d055      	beq.n	80018a8 <HAL_UART_IRQHandler+0x28c>
 80017fc:	6fe2      	ldr	r2, [r4, #124]	; 0x7c
 80017fe:	6813      	ldr	r3, [r2, #0]
 8001800:	685b      	ldr	r3, [r3, #4]
 8001802:	b29b      	uxth	r3, r3
 8001804:	2b00      	cmp	r3, #0
 8001806:	f43f af4d 	beq.w	80016a4 <HAL_UART_IRQHandler+0x88>
 800180a:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 800180e:	4299      	cmp	r1, r3
 8001810:	f67f af48 	bls.w	80016a4 <HAL_UART_IRQHandler+0x88>
 8001814:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001818:	6813      	ldr	r3, [r2, #0]
 800181a:	681b      	ldr	r3, [r3, #0]
 800181c:	f013 0f20 	tst.w	r3, #32
 8001820:	d131      	bne.n	8001886 <HAL_UART_IRQHandler+0x26a>
 8001822:	6822      	ldr	r2, [r4, #0]
 8001824:	e852 3f00 	ldrex	r3, [r2]
 8001828:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 800182c:	e842 3100 	strex	r1, r3, [r2]
 8001830:	2900      	cmp	r1, #0
 8001832:	d1f6      	bne.n	8001822 <HAL_UART_IRQHandler+0x206>
 8001834:	6822      	ldr	r2, [r4, #0]
 8001836:	f102 0308 	add.w	r3, r2, #8
 800183a:	e853 3f00 	ldrex	r3, [r3]
 800183e:	f023 0301 	bic.w	r3, r3, #1
 8001842:	3208      	adds	r2, #8
 8001844:	e842 3100 	strex	r1, r3, [r2]
 8001848:	2900      	cmp	r1, #0
 800184a:	d1f3      	bne.n	8001834 <HAL_UART_IRQHandler+0x218>
 800184c:	6822      	ldr	r2, [r4, #0]
 800184e:	f102 0308 	add.w	r3, r2, #8
 8001852:	e853 3f00 	ldrex	r3, [r3]
 8001856:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 800185a:	3208      	adds	r2, #8
 800185c:	e842 3100 	strex	r1, r3, [r2]
 8001860:	2900      	cmp	r1, #0
 8001862:	d1f3      	bne.n	800184c <HAL_UART_IRQHandler+0x230>
 8001864:	2320      	movs	r3, #32
 8001866:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 800186a:	2300      	movs	r3, #0
 800186c:	66e3      	str	r3, [r4, #108]	; 0x6c
 800186e:	6822      	ldr	r2, [r4, #0]
 8001870:	e852 3f00 	ldrex	r3, [r2]
 8001874:	f023 0310 	bic.w	r3, r3, #16
 8001878:	e842 3100 	strex	r1, r3, [r2]
 800187c:	2900      	cmp	r1, #0
 800187e:	d1f6      	bne.n	800186e <HAL_UART_IRQHandler+0x252>
 8001880:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 8001882:	f029 fea9 	bl	802b5d8 <HAL_DMA_Abort>
 8001886:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 800188a:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 800188e:	b29b      	uxth	r3, r3
 8001890:	1ac9      	subs	r1, r1, r3
 8001892:	b289      	uxth	r1, r1
 8001894:	4620      	mov	r0, r4
 8001896:	f7ff febf 	bl	8001618 <HAL_UARTEx_RxEventCallback>
 800189a:	e703      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 800189c:	10000001 	.word	0x10000001
 80018a0:	04000120 	.word	0x04000120
 80018a4:	08001509 	.word	0x08001509
 80018a8:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 80018ac:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 80018b0:	b29b      	uxth	r3, r3
 80018b2:	1ac9      	subs	r1, r1, r3
 80018b4:	b289      	uxth	r1, r1
 80018b6:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 80018ba:	b29b      	uxth	r3, r3
 80018bc:	2b00      	cmp	r3, #0
 80018be:	f43f aef1 	beq.w	80016a4 <HAL_UART_IRQHandler+0x88>
 80018c2:	2900      	cmp	r1, #0
 80018c4:	f43f aeee 	beq.w	80016a4 <HAL_UART_IRQHandler+0x88>
 80018c8:	6822      	ldr	r2, [r4, #0]
 80018ca:	e852 3f00 	ldrex	r3, [r2]
 80018ce:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 80018d2:	e842 3000 	strex	r0, r3, [r2]
 80018d6:	2800      	cmp	r0, #0
 80018d8:	d1f6      	bne.n	80018c8 <HAL_UART_IRQHandler+0x2ac>
 80018da:	6822      	ldr	r2, [r4, #0]
 80018dc:	f102 0308 	add.w	r3, r2, #8
 80018e0:	e853 3f00 	ldrex	r3, [r3]
 80018e4:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 80018e8:	f023 0301 	bic.w	r3, r3, #1
 80018ec:	3208      	adds	r2, #8
 80018ee:	e842 3000 	strex	r0, r3, [r2]
 80018f2:	2800      	cmp	r0, #0
 80018f4:	d1f1      	bne.n	80018da <HAL_UART_IRQHandler+0x2be>
 80018f6:	2320      	movs	r3, #32
 80018f8:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80018fc:	2300      	movs	r3, #0
 80018fe:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001900:	6723      	str	r3, [r4, #112]	; 0x70
 8001902:	6822      	ldr	r2, [r4, #0]
 8001904:	e852 3f00 	ldrex	r3, [r2]
 8001908:	f023 0310 	bic.w	r3, r3, #16
 800190c:	e842 3000 	strex	r0, r3, [r2]
 8001910:	2800      	cmp	r0, #0
 8001912:	d1f6      	bne.n	8001902 <HAL_UART_IRQHandler+0x2e6>
 8001914:	4620      	mov	r0, r4
 8001916:	f7ff fe7f 	bl	8001618 <HAL_UARTEx_RxEventCallback>
 800191a:	e6c3      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 800191c:	f44f 1380 	mov.w	r3, #1048576	; 0x100000
 8001920:	620b      	str	r3, [r1, #32]
 8001922:	4620      	mov	r0, r4
 8001924:	f000 fef2 	bl	800270c <HAL_UARTEx_WakeupCallback>
 8001928:	e6bc      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 800192a:	6f63      	ldr	r3, [r4, #116]	; 0x74
 800192c:	2b00      	cmp	r3, #0
 800192e:	f43f aeb9 	beq.w	80016a4 <HAL_UART_IRQHandler+0x88>
 8001932:	4620      	mov	r0, r4
 8001934:	4798      	blx	r3
 8001936:	e6b5      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 8001938:	4620      	mov	r0, r4
 800193a:	f7ff fdd2 	bl	80014e2 <UART_EndTransmit_IT>
 800193e:	e6b1      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 8001940:	4620      	mov	r0, r4
 8001942:	f000 fee5 	bl	8002710 <HAL_UARTEx_TxFifoEmptyCallback>
 8001946:	e6ad      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>
 8001948:	4620      	mov	r0, r4
 800194a:	f000 fee0 	bl	800270e <HAL_UARTEx_RxFifoFullCallback>
 800194e:	e6a9      	b.n	80016a4 <HAL_UART_IRQHandler+0x88>

08001950 <UART_RxISR_8BIT>:
 8001950:	b508      	push	{r3, lr}
 8001952:	f8b0 3060 	ldrh.w	r3, [r0, #96]	; 0x60
 8001956:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 800195a:	2a22      	cmp	r2, #34	; 0x22
 800195c:	d005      	beq.n	800196a <UART_RxISR_8BIT+0x1a>
 800195e:	6802      	ldr	r2, [r0, #0]
 8001960:	6993      	ldr	r3, [r2, #24]
 8001962:	f043 0308 	orr.w	r3, r3, #8
 8001966:	6193      	str	r3, [r2, #24]
 8001968:	bd08      	pop	{r3, pc}
 800196a:	6802      	ldr	r2, [r0, #0]
 800196c:	6a51      	ldr	r1, [r2, #36]	; 0x24
 800196e:	b2db      	uxtb	r3, r3
 8001970:	6d82      	ldr	r2, [r0, #88]	; 0x58
 8001972:	400b      	ands	r3, r1
 8001974:	7013      	strb	r3, [r2, #0]
 8001976:	6d83      	ldr	r3, [r0, #88]	; 0x58
 8001978:	3301      	adds	r3, #1
 800197a:	6583      	str	r3, [r0, #88]	; 0x58
 800197c:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001980:	b29b      	uxth	r3, r3
 8001982:	3b01      	subs	r3, #1
 8001984:	b29b      	uxth	r3, r3
 8001986:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 800198a:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 800198e:	b29b      	uxth	r3, r3
 8001990:	2b00      	cmp	r3, #0
 8001992:	d1e9      	bne.n	8001968 <UART_RxISR_8BIT+0x18>
 8001994:	6802      	ldr	r2, [r0, #0]
 8001996:	e852 3f00 	ldrex	r3, [r2]
 800199a:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 800199e:	e842 3100 	strex	r1, r3, [r2]
 80019a2:	2900      	cmp	r1, #0
 80019a4:	d1f6      	bne.n	8001994 <UART_RxISR_8BIT+0x44>
 80019a6:	6802      	ldr	r2, [r0, #0]
 80019a8:	f102 0308 	add.w	r3, r2, #8
 80019ac:	e853 3f00 	ldrex	r3, [r3]
 80019b0:	f023 0301 	bic.w	r3, r3, #1
 80019b4:	3208      	adds	r2, #8
 80019b6:	e842 3100 	strex	r1, r3, [r2]
 80019ba:	2900      	cmp	r1, #0
 80019bc:	d1f3      	bne.n	80019a6 <UART_RxISR_8BIT+0x56>
 80019be:	2320      	movs	r3, #32
 80019c0:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 80019c4:	2300      	movs	r3, #0
 80019c6:	6703      	str	r3, [r0, #112]	; 0x70
 80019c8:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 80019ca:	2b01      	cmp	r3, #1
 80019cc:	d116      	bne.n	80019fc <UART_RxISR_8BIT+0xac>
 80019ce:	2300      	movs	r3, #0
 80019d0:	66c3      	str	r3, [r0, #108]	; 0x6c
 80019d2:	6802      	ldr	r2, [r0, #0]
 80019d4:	e852 3f00 	ldrex	r3, [r2]
 80019d8:	f023 0310 	bic.w	r3, r3, #16
 80019dc:	e842 3100 	strex	r1, r3, [r2]
 80019e0:	2900      	cmp	r1, #0
 80019e2:	d1f6      	bne.n	80019d2 <UART_RxISR_8BIT+0x82>
 80019e4:	6803      	ldr	r3, [r0, #0]
 80019e6:	69da      	ldr	r2, [r3, #28]
 80019e8:	f012 0f10 	tst.w	r2, #16
 80019ec:	d001      	beq.n	80019f2 <UART_RxISR_8BIT+0xa2>
 80019ee:	2210      	movs	r2, #16
 80019f0:	621a      	str	r2, [r3, #32]
 80019f2:	f8b0 105c 	ldrh.w	r1, [r0, #92]	; 0x5c
 80019f6:	f7ff fe0f 	bl	8001618 <HAL_UARTEx_RxEventCallback>
 80019fa:	e7b5      	b.n	8001968 <UART_RxISR_8BIT+0x18>
 80019fc:	f7fe fffe 	bl	80009fc <HAL_UART_RxCpltCallback>
 8001a00:	e7b2      	b.n	8001968 <UART_RxISR_8BIT+0x18>

08001a02 <UART_RxISR_16BIT>:
 8001a02:	b508      	push	{r3, lr}
 8001a04:	f8b0 2060 	ldrh.w	r2, [r0, #96]	; 0x60
 8001a08:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 8001a0c:	2b22      	cmp	r3, #34	; 0x22
 8001a0e:	d005      	beq.n	8001a1c <UART_RxISR_16BIT+0x1a>
 8001a10:	6802      	ldr	r2, [r0, #0]
 8001a12:	6993      	ldr	r3, [r2, #24]
 8001a14:	f043 0308 	orr.w	r3, r3, #8
 8001a18:	6193      	str	r3, [r2, #24]
 8001a1a:	bd08      	pop	{r3, pc}
 8001a1c:	6803      	ldr	r3, [r0, #0]
 8001a1e:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8001a20:	6d81      	ldr	r1, [r0, #88]	; 0x58
 8001a22:	4013      	ands	r3, r2
 8001a24:	800b      	strh	r3, [r1, #0]
 8001a26:	6d83      	ldr	r3, [r0, #88]	; 0x58
 8001a28:	3302      	adds	r3, #2
 8001a2a:	6583      	str	r3, [r0, #88]	; 0x58
 8001a2c:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001a30:	b29b      	uxth	r3, r3
 8001a32:	3b01      	subs	r3, #1
 8001a34:	b29b      	uxth	r3, r3
 8001a36:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 8001a3a:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001a3e:	b29b      	uxth	r3, r3
 8001a40:	2b00      	cmp	r3, #0
 8001a42:	d1ea      	bne.n	8001a1a <UART_RxISR_16BIT+0x18>
 8001a44:	6802      	ldr	r2, [r0, #0]
 8001a46:	e852 3f00 	ldrex	r3, [r2]
 8001a4a:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001a4e:	e842 3100 	strex	r1, r3, [r2]
 8001a52:	2900      	cmp	r1, #0
 8001a54:	d1f6      	bne.n	8001a44 <UART_RxISR_16BIT+0x42>
 8001a56:	6802      	ldr	r2, [r0, #0]
 8001a58:	f102 0308 	add.w	r3, r2, #8
 8001a5c:	e853 3f00 	ldrex	r3, [r3]
 8001a60:	f023 0301 	bic.w	r3, r3, #1
 8001a64:	3208      	adds	r2, #8
 8001a66:	e842 3100 	strex	r1, r3, [r2]
 8001a6a:	2900      	cmp	r1, #0
 8001a6c:	d1f3      	bne.n	8001a56 <UART_RxISR_16BIT+0x54>
 8001a6e:	2320      	movs	r3, #32
 8001a70:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001a74:	2300      	movs	r3, #0
 8001a76:	6703      	str	r3, [r0, #112]	; 0x70
 8001a78:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 8001a7a:	2b01      	cmp	r3, #1
 8001a7c:	d116      	bne.n	8001aac <UART_RxISR_16BIT+0xaa>
 8001a7e:	2300      	movs	r3, #0
 8001a80:	66c3      	str	r3, [r0, #108]	; 0x6c
 8001a82:	6802      	ldr	r2, [r0, #0]
 8001a84:	e852 3f00 	ldrex	r3, [r2]
 8001a88:	f023 0310 	bic.w	r3, r3, #16
 8001a8c:	e842 3100 	strex	r1, r3, [r2]
 8001a90:	2900      	cmp	r1, #0
 8001a92:	d1f6      	bne.n	8001a82 <UART_RxISR_16BIT+0x80>
 8001a94:	6803      	ldr	r3, [r0, #0]
 8001a96:	69da      	ldr	r2, [r3, #28]
 8001a98:	f012 0f10 	tst.w	r2, #16
 8001a9c:	d001      	beq.n	8001aa2 <UART_RxISR_16BIT+0xa0>
 8001a9e:	2210      	movs	r2, #16
 8001aa0:	621a      	str	r2, [r3, #32]
 8001aa2:	f8b0 105c 	ldrh.w	r1, [r0, #92]	; 0x5c
 8001aa6:	f7ff fdb7 	bl	8001618 <HAL_UARTEx_RxEventCallback>
 8001aaa:	e7b6      	b.n	8001a1a <UART_RxISR_16BIT+0x18>
 8001aac:	f7fe ffa6 	bl	80009fc <HAL_UART_RxCpltCallback>
 8001ab0:	e7b3      	b.n	8001a1a <UART_RxISR_16BIT+0x18>
	...

08001ab4 <UART_RxISR_8BIT_FIFOEN>:
 8001ab4:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001ab8:	f8b0 6060 	ldrh.w	r6, [r0, #96]	; 0x60
 8001abc:	6803      	ldr	r3, [r0, #0]
 8001abe:	69dd      	ldr	r5, [r3, #28]
 8001ac0:	f8d3 9000 	ldr.w	r9, [r3]
 8001ac4:	f8d3 8008 	ldr.w	r8, [r3, #8]
 8001ac8:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001acc:	2a22      	cmp	r2, #34	; 0x22
 8001ace:	d005      	beq.n	8001adc <UART_RxISR_8BIT_FIFOEN+0x28>
 8001ad0:	699a      	ldr	r2, [r3, #24]
 8001ad2:	f042 0208 	orr.w	r2, r2, #8
 8001ad6:	619a      	str	r2, [r3, #24]
 8001ad8:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001adc:	4604      	mov	r4, r0
 8001ade:	f8b0 7068 	ldrh.w	r7, [r0, #104]	; 0x68
 8001ae2:	e008      	b.n	8001af6 <UART_RxISR_8BIT_FIFOEN+0x42>
 8001ae4:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001ae8:	2b00      	cmp	r3, #0
 8001aea:	d14c      	bne.n	8001b86 <UART_RxISR_8BIT_FIFOEN+0xd2>
 8001aec:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001af0:	b29b      	uxth	r3, r3
 8001af2:	2b00      	cmp	r3, #0
 8001af4:	d04e      	beq.n	8001b94 <UART_RxISR_8BIT_FIFOEN+0xe0>
 8001af6:	2f00      	cmp	r7, #0
 8001af8:	f000 8087 	beq.w	8001c0a <UART_RxISR_8BIT_FIFOEN+0x156>
 8001afc:	f015 0f20 	tst.w	r5, #32
 8001b00:	f000 8083 	beq.w	8001c0a <UART_RxISR_8BIT_FIFOEN+0x156>
 8001b04:	6823      	ldr	r3, [r4, #0]
 8001b06:	6a59      	ldr	r1, [r3, #36]	; 0x24
 8001b08:	b2f3      	uxtb	r3, r6
 8001b0a:	6da2      	ldr	r2, [r4, #88]	; 0x58
 8001b0c:	400b      	ands	r3, r1
 8001b0e:	7013      	strb	r3, [r2, #0]
 8001b10:	6da3      	ldr	r3, [r4, #88]	; 0x58
 8001b12:	3301      	adds	r3, #1
 8001b14:	65a3      	str	r3, [r4, #88]	; 0x58
 8001b16:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001b1a:	b29b      	uxth	r3, r3
 8001b1c:	3b01      	subs	r3, #1
 8001b1e:	b29b      	uxth	r3, r3
 8001b20:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001b24:	6823      	ldr	r3, [r4, #0]
 8001b26:	69dd      	ldr	r5, [r3, #28]
 8001b28:	f015 0f07 	tst.w	r5, #7
 8001b2c:	d0de      	beq.n	8001aec <UART_RxISR_8BIT_FIFOEN+0x38>
 8001b2e:	f015 0f01 	tst.w	r5, #1
 8001b32:	d009      	beq.n	8001b48 <UART_RxISR_8BIT_FIFOEN+0x94>
 8001b34:	f419 7f80 	tst.w	r9, #256	; 0x100
 8001b38:	d006      	beq.n	8001b48 <UART_RxISR_8BIT_FIFOEN+0x94>
 8001b3a:	2201      	movs	r2, #1
 8001b3c:	621a      	str	r2, [r3, #32]
 8001b3e:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b42:	4313      	orrs	r3, r2
 8001b44:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b48:	f015 0f02 	tst.w	r5, #2
 8001b4c:	d00b      	beq.n	8001b66 <UART_RxISR_8BIT_FIFOEN+0xb2>
 8001b4e:	f018 0f01 	tst.w	r8, #1
 8001b52:	d008      	beq.n	8001b66 <UART_RxISR_8BIT_FIFOEN+0xb2>
 8001b54:	6823      	ldr	r3, [r4, #0]
 8001b56:	2202      	movs	r2, #2
 8001b58:	621a      	str	r2, [r3, #32]
 8001b5a:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b5e:	f043 0304 	orr.w	r3, r3, #4
 8001b62:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b66:	f015 0f04 	tst.w	r5, #4
 8001b6a:	d0bb      	beq.n	8001ae4 <UART_RxISR_8BIT_FIFOEN+0x30>
 8001b6c:	f018 0f01 	tst.w	r8, #1
 8001b70:	d0b8      	beq.n	8001ae4 <UART_RxISR_8BIT_FIFOEN+0x30>
 8001b72:	6823      	ldr	r3, [r4, #0]
 8001b74:	2204      	movs	r2, #4
 8001b76:	621a      	str	r2, [r3, #32]
 8001b78:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b7c:	f043 0302 	orr.w	r3, r3, #2
 8001b80:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b84:	e7ae      	b.n	8001ae4 <UART_RxISR_8BIT_FIFOEN+0x30>
 8001b86:	4620      	mov	r0, r4
 8001b88:	f7ff fcbd 	bl	8001506 <HAL_UART_ErrorCallback>
 8001b8c:	2300      	movs	r3, #0
 8001b8e:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b92:	e7ab      	b.n	8001aec <UART_RxISR_8BIT_FIFOEN+0x38>
 8001b94:	6822      	ldr	r2, [r4, #0]
 8001b96:	e852 3f00 	ldrex	r3, [r2]
 8001b9a:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001b9e:	e842 3100 	strex	r1, r3, [r2]
 8001ba2:	2900      	cmp	r1, #0
 8001ba4:	d1f6      	bne.n	8001b94 <UART_RxISR_8BIT_FIFOEN+0xe0>
 8001ba6:	6822      	ldr	r2, [r4, #0]
 8001ba8:	f102 0308 	add.w	r3, r2, #8
 8001bac:	e853 3f00 	ldrex	r3, [r3]
 8001bb0:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001bb4:	f023 0301 	bic.w	r3, r3, #1
 8001bb8:	3208      	adds	r2, #8
 8001bba:	e842 3100 	strex	r1, r3, [r2]
 8001bbe:	2900      	cmp	r1, #0
 8001bc0:	d1f1      	bne.n	8001ba6 <UART_RxISR_8BIT_FIFOEN+0xf2>
 8001bc2:	2320      	movs	r3, #32
 8001bc4:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001bc8:	2300      	movs	r3, #0
 8001bca:	6723      	str	r3, [r4, #112]	; 0x70
 8001bcc:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001bce:	2b01      	cmp	r3, #1
 8001bd0:	d003      	beq.n	8001bda <UART_RxISR_8BIT_FIFOEN+0x126>
 8001bd2:	4620      	mov	r0, r4
 8001bd4:	f7fe ff12 	bl	80009fc <HAL_UART_RxCpltCallback>
 8001bd8:	e78d      	b.n	8001af6 <UART_RxISR_8BIT_FIFOEN+0x42>
 8001bda:	2300      	movs	r3, #0
 8001bdc:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001bde:	6822      	ldr	r2, [r4, #0]
 8001be0:	e852 3f00 	ldrex	r3, [r2]
 8001be4:	f023 0310 	bic.w	r3, r3, #16
 8001be8:	e842 3100 	strex	r1, r3, [r2]
 8001bec:	2900      	cmp	r1, #0
 8001bee:	d1f6      	bne.n	8001bde <UART_RxISR_8BIT_FIFOEN+0x12a>
 8001bf0:	6823      	ldr	r3, [r4, #0]
 8001bf2:	69da      	ldr	r2, [r3, #28]
 8001bf4:	f012 0f10 	tst.w	r2, #16
 8001bf8:	d001      	beq.n	8001bfe <UART_RxISR_8BIT_FIFOEN+0x14a>
 8001bfa:	2210      	movs	r2, #16
 8001bfc:	621a      	str	r2, [r3, #32]
 8001bfe:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001c02:	4620      	mov	r0, r4
 8001c04:	f7ff fd08 	bl	8001618 <HAL_UARTEx_RxEventCallback>
 8001c08:	e775      	b.n	8001af6 <UART_RxISR_8BIT_FIFOEN+0x42>
 8001c0a:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001c0e:	b29b      	uxth	r3, r3
 8001c10:	2b00      	cmp	r3, #0
 8001c12:	f43f af61 	beq.w	8001ad8 <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c16:	f8b4 2068 	ldrh.w	r2, [r4, #104]	; 0x68
 8001c1a:	429a      	cmp	r2, r3
 8001c1c:	f67f af5c 	bls.w	8001ad8 <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c20:	6822      	ldr	r2, [r4, #0]
 8001c22:	f102 0308 	add.w	r3, r2, #8
 8001c26:	e853 3f00 	ldrex	r3, [r3]
 8001c2a:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001c2e:	3208      	adds	r2, #8
 8001c30:	e842 3100 	strex	r1, r3, [r2]
 8001c34:	2900      	cmp	r1, #0
 8001c36:	d1f3      	bne.n	8001c20 <UART_RxISR_8BIT_FIFOEN+0x16c>
 8001c38:	4b05      	ldr	r3, [pc, #20]	; (8001c50 <UART_RxISR_8BIT_FIFOEN+0x19c>)
 8001c3a:	6723      	str	r3, [r4, #112]	; 0x70
 8001c3c:	6822      	ldr	r2, [r4, #0]
 8001c3e:	e852 3f00 	ldrex	r3, [r2]
 8001c42:	f043 0320 	orr.w	r3, r3, #32
 8001c46:	e842 3100 	strex	r1, r3, [r2]
 8001c4a:	2900      	cmp	r1, #0
 8001c4c:	d1f6      	bne.n	8001c3c <UART_RxISR_8BIT_FIFOEN+0x188>
 8001c4e:	e743      	b.n	8001ad8 <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c50:	08001951 	.word	0x08001951

08001c54 <UART_RxISR_16BIT_FIFOEN>:
 8001c54:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001c58:	f8b0 6060 	ldrh.w	r6, [r0, #96]	; 0x60
 8001c5c:	6803      	ldr	r3, [r0, #0]
 8001c5e:	69dd      	ldr	r5, [r3, #28]
 8001c60:	f8d3 9000 	ldr.w	r9, [r3]
 8001c64:	f8d3 8008 	ldr.w	r8, [r3, #8]
 8001c68:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001c6c:	2a22      	cmp	r2, #34	; 0x22
 8001c6e:	d005      	beq.n	8001c7c <UART_RxISR_16BIT_FIFOEN+0x28>
 8001c70:	699a      	ldr	r2, [r3, #24]
 8001c72:	f042 0208 	orr.w	r2, r2, #8
 8001c76:	619a      	str	r2, [r3, #24]
 8001c78:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001c7c:	4604      	mov	r4, r0
 8001c7e:	f8b0 7068 	ldrh.w	r7, [r0, #104]	; 0x68
 8001c82:	e008      	b.n	8001c96 <UART_RxISR_16BIT_FIFOEN+0x42>
 8001c84:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001c88:	2b00      	cmp	r3, #0
 8001c8a:	d14b      	bne.n	8001d24 <UART_RxISR_16BIT_FIFOEN+0xd0>
 8001c8c:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001c90:	b29b      	uxth	r3, r3
 8001c92:	2b00      	cmp	r3, #0
 8001c94:	d04d      	beq.n	8001d32 <UART_RxISR_16BIT_FIFOEN+0xde>
 8001c96:	2f00      	cmp	r7, #0
 8001c98:	f000 8086 	beq.w	8001da8 <UART_RxISR_16BIT_FIFOEN+0x154>
 8001c9c:	f015 0f20 	tst.w	r5, #32
 8001ca0:	f000 8082 	beq.w	8001da8 <UART_RxISR_16BIT_FIFOEN+0x154>
 8001ca4:	6823      	ldr	r3, [r4, #0]
 8001ca6:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8001ca8:	6da2      	ldr	r2, [r4, #88]	; 0x58
 8001caa:	4033      	ands	r3, r6
 8001cac:	8013      	strh	r3, [r2, #0]
 8001cae:	6da3      	ldr	r3, [r4, #88]	; 0x58
 8001cb0:	3302      	adds	r3, #2
 8001cb2:	65a3      	str	r3, [r4, #88]	; 0x58
 8001cb4:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001cb8:	b29b      	uxth	r3, r3
 8001cba:	3b01      	subs	r3, #1
 8001cbc:	b29b      	uxth	r3, r3
 8001cbe:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001cc2:	6823      	ldr	r3, [r4, #0]
 8001cc4:	69dd      	ldr	r5, [r3, #28]
 8001cc6:	f015 0f07 	tst.w	r5, #7
 8001cca:	d0df      	beq.n	8001c8c <UART_RxISR_16BIT_FIFOEN+0x38>
 8001ccc:	f015 0f01 	tst.w	r5, #1
 8001cd0:	d009      	beq.n	8001ce6 <UART_RxISR_16BIT_FIFOEN+0x92>
 8001cd2:	f419 7f80 	tst.w	r9, #256	; 0x100
 8001cd6:	d006      	beq.n	8001ce6 <UART_RxISR_16BIT_FIFOEN+0x92>
 8001cd8:	2201      	movs	r2, #1
 8001cda:	621a      	str	r2, [r3, #32]
 8001cdc:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001ce0:	4313      	orrs	r3, r2
 8001ce2:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001ce6:	f015 0f02 	tst.w	r5, #2
 8001cea:	d00b      	beq.n	8001d04 <UART_RxISR_16BIT_FIFOEN+0xb0>
 8001cec:	f018 0f01 	tst.w	r8, #1
 8001cf0:	d008      	beq.n	8001d04 <UART_RxISR_16BIT_FIFOEN+0xb0>
 8001cf2:	6823      	ldr	r3, [r4, #0]
 8001cf4:	2202      	movs	r2, #2
 8001cf6:	621a      	str	r2, [r3, #32]
 8001cf8:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001cfc:	f043 0304 	orr.w	r3, r3, #4
 8001d00:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d04:	f015 0f04 	tst.w	r5, #4
 8001d08:	d0bc      	beq.n	8001c84 <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d0a:	f018 0f01 	tst.w	r8, #1
 8001d0e:	d0b9      	beq.n	8001c84 <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d10:	6823      	ldr	r3, [r4, #0]
 8001d12:	2204      	movs	r2, #4
 8001d14:	621a      	str	r2, [r3, #32]
 8001d16:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d1a:	f043 0302 	orr.w	r3, r3, #2
 8001d1e:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d22:	e7af      	b.n	8001c84 <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d24:	4620      	mov	r0, r4
 8001d26:	f7ff fbee 	bl	8001506 <HAL_UART_ErrorCallback>
 8001d2a:	2300      	movs	r3, #0
 8001d2c:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d30:	e7ac      	b.n	8001c8c <UART_RxISR_16BIT_FIFOEN+0x38>
 8001d32:	6822      	ldr	r2, [r4, #0]
 8001d34:	e852 3f00 	ldrex	r3, [r2]
 8001d38:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001d3c:	e842 3100 	strex	r1, r3, [r2]
 8001d40:	2900      	cmp	r1, #0
 8001d42:	d1f6      	bne.n	8001d32 <UART_RxISR_16BIT_FIFOEN+0xde>
 8001d44:	6822      	ldr	r2, [r4, #0]
 8001d46:	f102 0308 	add.w	r3, r2, #8
 8001d4a:	e853 3f00 	ldrex	r3, [r3]
 8001d4e:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001d52:	f023 0301 	bic.w	r3, r3, #1
 8001d56:	3208      	adds	r2, #8
 8001d58:	e842 3100 	strex	r1, r3, [r2]
 8001d5c:	2900      	cmp	r1, #0
 8001d5e:	d1f1      	bne.n	8001d44 <UART_RxISR_16BIT_FIFOEN+0xf0>
 8001d60:	2320      	movs	r3, #32
 8001d62:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001d66:	2300      	movs	r3, #0
 8001d68:	6723      	str	r3, [r4, #112]	; 0x70
 8001d6a:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001d6c:	2b01      	cmp	r3, #1
 8001d6e:	d003      	beq.n	8001d78 <UART_RxISR_16BIT_FIFOEN+0x124>
 8001d70:	4620      	mov	r0, r4
 8001d72:	f7fe fe43 	bl	80009fc <HAL_UART_RxCpltCallback>
 8001d76:	e78e      	b.n	8001c96 <UART_RxISR_16BIT_FIFOEN+0x42>
 8001d78:	2300      	movs	r3, #0
 8001d7a:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001d7c:	6822      	ldr	r2, [r4, #0]
 8001d7e:	e852 3f00 	ldrex	r3, [r2]
 8001d82:	f023 0310 	bic.w	r3, r3, #16
 8001d86:	e842 3100 	strex	r1, r3, [r2]
 8001d8a:	2900      	cmp	r1, #0
 8001d8c:	d1f6      	bne.n	8001d7c <UART_RxISR_16BIT_FIFOEN+0x128>
 8001d8e:	6823      	ldr	r3, [r4, #0]
 8001d90:	69da      	ldr	r2, [r3, #28]
 8001d92:	f012 0f10 	tst.w	r2, #16
 8001d96:	d001      	beq.n	8001d9c <UART_RxISR_16BIT_FIFOEN+0x148>
 8001d98:	2210      	movs	r2, #16
 8001d9a:	621a      	str	r2, [r3, #32]
 8001d9c:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001da0:	4620      	mov	r0, r4
 8001da2:	f7ff fc39 	bl	8001618 <HAL_UARTEx_RxEventCallback>
 8001da6:	e776      	b.n	8001c96 <UART_RxISR_16BIT_FIFOEN+0x42>
 8001da8:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001dac:	b29b      	uxth	r3, r3
 8001dae:	2b00      	cmp	r3, #0
 8001db0:	f43f af62 	beq.w	8001c78 <UART_RxISR_16BIT_FIFOEN+0x24>
 8001db4:	f8b4 2068 	ldrh.w	r2, [r4, #104]	; 0x68
 8001db8:	429a      	cmp	r2, r3
 8001dba:	f67f af5d 	bls.w	8001c78 <UART_RxISR_16BIT_FIFOEN+0x24>
 8001dbe:	6822      	ldr	r2, [r4, #0]
 8001dc0:	f102 0308 	add.w	r3, r2, #8
 8001dc4:	e853 3f00 	ldrex	r3, [r3]
 8001dc8:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001dcc:	3208      	adds	r2, #8
 8001dce:	e842 3100 	strex	r1, r3, [r2]
 8001dd2:	2900      	cmp	r1, #0
 8001dd4:	d1f3      	bne.n	8001dbe <UART_RxISR_16BIT_FIFOEN+0x16a>
 8001dd6:	4b06      	ldr	r3, [pc, #24]	; (8001df0 <UART_RxISR_16BIT_FIFOEN+0x19c>)
 8001dd8:	6723      	str	r3, [r4, #112]	; 0x70
 8001dda:	6822      	ldr	r2, [r4, #0]
 8001ddc:	e852 3f00 	ldrex	r3, [r2]
 8001de0:	f043 0320 	orr.w	r3, r3, #32
 8001de4:	e842 3100 	strex	r1, r3, [r2]
 8001de8:	2900      	cmp	r1, #0
 8001dea:	d1f6      	bne.n	8001dda <UART_RxISR_16BIT_FIFOEN+0x186>
 8001dec:	e744      	b.n	8001c78 <UART_RxISR_16BIT_FIFOEN+0x24>
 8001dee:	bf00      	nop
 8001df0:	08001a03 	.word	0x08001a03

08001df4 <UART_SetConfig>:
 8001df4:	b570      	push	{r4, r5, r6, lr}
 8001df6:	4604      	mov	r4, r0
 8001df8:	6801      	ldr	r1, [r0, #0]
 8001dfa:	6883      	ldr	r3, [r0, #8]
 8001dfc:	6902      	ldr	r2, [r0, #16]
 8001dfe:	4313      	orrs	r3, r2
 8001e00:	6942      	ldr	r2, [r0, #20]
 8001e02:	4313      	orrs	r3, r2
 8001e04:	69c2      	ldr	r2, [r0, #28]
 8001e06:	4313      	orrs	r3, r2
 8001e08:	6808      	ldr	r0, [r1, #0]
 8001e0a:	4a9d      	ldr	r2, [pc, #628]	; (8002080 <UART_SetConfig+0x28c>)
 8001e0c:	4002      	ands	r2, r0
 8001e0e:	4313      	orrs	r3, r2
 8001e10:	600b      	str	r3, [r1, #0]
 8001e12:	6822      	ldr	r2, [r4, #0]
 8001e14:	6853      	ldr	r3, [r2, #4]
 8001e16:	f423 5340 	bic.w	r3, r3, #12288	; 0x3000
 8001e1a:	68e1      	ldr	r1, [r4, #12]
 8001e1c:	430b      	orrs	r3, r1
 8001e1e:	6053      	str	r3, [r2, #4]
 8001e20:	69a1      	ldr	r1, [r4, #24]
 8001e22:	6822      	ldr	r2, [r4, #0]
 8001e24:	4b97      	ldr	r3, [pc, #604]	; (8002084 <UART_SetConfig+0x290>)
 8001e26:	429a      	cmp	r2, r3
 8001e28:	d001      	beq.n	8001e2e <UART_SetConfig+0x3a>
 8001e2a:	6a23      	ldr	r3, [r4, #32]
 8001e2c:	4319      	orrs	r1, r3
 8001e2e:	6893      	ldr	r3, [r2, #8]
 8001e30:	f023 436e 	bic.w	r3, r3, #3992977408	; 0xee000000
 8001e34:	f423 6330 	bic.w	r3, r3, #2816	; 0xb00
 8001e38:	430b      	orrs	r3, r1
 8001e3a:	6093      	str	r3, [r2, #8]
 8001e3c:	6822      	ldr	r2, [r4, #0]
 8001e3e:	6ad3      	ldr	r3, [r2, #44]	; 0x2c
 8001e40:	f023 030f 	bic.w	r3, r3, #15
 8001e44:	6a61      	ldr	r1, [r4, #36]	; 0x24
 8001e46:	430b      	orrs	r3, r1
 8001e48:	62d3      	str	r3, [r2, #44]	; 0x2c
 8001e4a:	6823      	ldr	r3, [r4, #0]
 8001e4c:	4a8e      	ldr	r2, [pc, #568]	; (8002088 <UART_SetConfig+0x294>)
 8001e4e:	4293      	cmp	r3, r2
 8001e50:	d01c      	beq.n	8001e8c <UART_SetConfig+0x98>
 8001e52:	4a8e      	ldr	r2, [pc, #568]	; (800208c <UART_SetConfig+0x298>)
 8001e54:	4293      	cmp	r3, r2
 8001e56:	d031      	beq.n	8001ebc <UART_SetConfig+0xc8>
 8001e58:	4a8a      	ldr	r2, [pc, #552]	; (8002084 <UART_SetConfig+0x290>)
 8001e5a:	4293      	cmp	r3, r2
 8001e5c:	d04b      	beq.n	8001ef6 <UART_SetConfig+0x102>
 8001e5e:	2210      	movs	r2, #16
 8001e60:	4988      	ldr	r1, [pc, #544]	; (8002084 <UART_SetConfig+0x290>)
 8001e62:	428b      	cmp	r3, r1
 8001e64:	d068      	beq.n	8001f38 <UART_SetConfig+0x144>
 8001e66:	69e0      	ldr	r0, [r4, #28]
 8001e68:	f5b0 4f00 	cmp.w	r0, #32768	; 0x8000
 8001e6c:	f000 80a5 	beq.w	8001fba <UART_SetConfig+0x1c6>
 8001e70:	2a08      	cmp	r2, #8
 8001e72:	f200 811f 	bhi.w	80020b4 <UART_SetConfig+0x2c0>
 8001e76:	e8df f012 	tbh	[pc, r2, lsl #1]
 8001e7a:	00d3      	.short	0x00d3
 8001e7c:	00d100f5 	.word	0x00d100f5
 8001e80:	00f8011d 	.word	0x00f8011d
 8001e84:	011d011d 	.word	0x011d011d
 8001e88:	00fb011d 	.word	0x00fb011d
 8001e8c:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001e90:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001e94:	f002 0203 	and.w	r2, r2, #3
 8001e98:	f442 3240 	orr.w	r2, r2, #196608	; 0x30000
 8001e9c:	f5a2 3240 	sub.w	r2, r2, #196608	; 0x30000
 8001ea0:	2a03      	cmp	r2, #3
 8001ea2:	d809      	bhi.n	8001eb8 <UART_SetConfig+0xc4>
 8001ea4:	e8df f002 	tbb	[pc, r2]
 8001ea8:	063c0402 	.word	0x063c0402
 8001eac:	2201      	movs	r2, #1
 8001eae:	e7d7      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001eb0:	2204      	movs	r2, #4
 8001eb2:	e7d5      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001eb4:	2208      	movs	r2, #8
 8001eb6:	e7d3      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001eb8:	2210      	movs	r2, #16
 8001eba:	e7d1      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001ebc:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001ec0:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001ec4:	f002 020c 	and.w	r2, r2, #12
 8001ec8:	f442 2240 	orr.w	r2, r2, #786432	; 0xc0000
 8001ecc:	f5a2 2240 	sub.w	r2, r2, #786432	; 0xc0000
 8001ed0:	2a0c      	cmp	r2, #12
 8001ed2:	d80e      	bhi.n	8001ef2 <UART_SetConfig+0xfe>
 8001ed4:	e8df f002 	tbb	[pc, r2]
 8001ed8:	0d0d0d07 	.word	0x0d0d0d07
 8001edc:	0d0d0d09 	.word	0x0d0d0d09
 8001ee0:	0d0d0d26 	.word	0x0d0d0d26
 8001ee4:	0b          	.byte	0x0b
 8001ee5:	00          	.byte	0x00
 8001ee6:	2200      	movs	r2, #0
 8001ee8:	e7ba      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001eea:	2204      	movs	r2, #4
 8001eec:	e7b8      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001eee:	2208      	movs	r2, #8
 8001ef0:	e7b6      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001ef2:	2210      	movs	r2, #16
 8001ef4:	e7b4      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001ef6:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001efa:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001efe:	f402 6240 	and.w	r2, r2, #3072	; 0xc00
 8001f02:	f5b2 6f00 	cmp.w	r2, #2048	; 0x800
 8001f06:	d00f      	beq.n	8001f28 <UART_SetConfig+0x134>
 8001f08:	d805      	bhi.n	8001f16 <UART_SetConfig+0x122>
 8001f0a:	b17a      	cbz	r2, 8001f2c <UART_SetConfig+0x138>
 8001f0c:	f5b2 6f80 	cmp.w	r2, #1024	; 0x400
 8001f10:	d10e      	bne.n	8001f30 <UART_SetConfig+0x13c>
 8001f12:	2204      	movs	r2, #4
 8001f14:	e7a4      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f16:	f5b2 6f40 	cmp.w	r2, #3072	; 0xc00
 8001f1a:	d10b      	bne.n	8001f34 <UART_SetConfig+0x140>
 8001f1c:	2208      	movs	r2, #8
 8001f1e:	e79f      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f20:	2202      	movs	r2, #2
 8001f22:	e79d      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f24:	2202      	movs	r2, #2
 8001f26:	e79b      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f28:	2202      	movs	r2, #2
 8001f2a:	e799      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f2c:	2200      	movs	r2, #0
 8001f2e:	e797      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f30:	2210      	movs	r2, #16
 8001f32:	e795      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f34:	2210      	movs	r2, #16
 8001f36:	e793      	b.n	8001e60 <UART_SetConfig+0x6c>
 8001f38:	2a08      	cmp	r2, #8
 8001f3a:	f200 809c 	bhi.w	8002076 <UART_SetConfig+0x282>
 8001f3e:	e8df f002 	tbb	[pc, r2]
 8001f42:	9a08      	.short	0x9a08
 8001f44:	9a379a3a 	.word	0x9a379a3a
 8001f48:	9a9a      	.short	0x9a9a
 8001f4a:	05          	.byte	0x05
 8001f4b:	00          	.byte	0x00
 8001f4c:	f44f 4000 	mov.w	r0, #32768	; 0x8000
 8001f50:	e004      	b.n	8001f5c <UART_SetConfig+0x168>
 8001f52:	f023 fa6d 	bl	8025430 <HAL_RCC_GetPCLK1Freq>
 8001f56:	2800      	cmp	r0, #0
 8001f58:	f000 808f 	beq.w	800207a <UART_SetConfig+0x286>
 8001f5c:	6a62      	ldr	r2, [r4, #36]	; 0x24
 8001f5e:	4b4c      	ldr	r3, [pc, #304]	; (8002090 <UART_SetConfig+0x29c>)
 8001f60:	f833 2012 	ldrh.w	r2, [r3, r2, lsl #1]
 8001f64:	fbb0 f3f2 	udiv	r3, r0, r2
 8001f68:	6865      	ldr	r5, [r4, #4]
 8001f6a:	eb05 0145 	add.w	r1, r5, r5, lsl #1
 8001f6e:	4299      	cmp	r1, r3
 8001f70:	f200 8094 	bhi.w	800209c <UART_SetConfig+0x2a8>
 8001f74:	ebb3 3f05 	cmp.w	r3, r5, lsl #12
 8001f78:	f200 8092 	bhi.w	80020a0 <UART_SetConfig+0x2ac>
 8001f7c:	2600      	movs	r6, #0
 8001f7e:	4633      	mov	r3, r6
 8001f80:	4631      	mov	r1, r6
 8001f82:	f01b fc85 	bl	801d890 <__aeabi_uldivmod>
 8001f86:	0209      	lsls	r1, r1, #8
 8001f88:	ea41 6110 	orr.w	r1, r1, r0, lsr #24
 8001f8c:	0200      	lsls	r0, r0, #8
 8001f8e:	086b      	lsrs	r3, r5, #1
 8001f90:	18c0      	adds	r0, r0, r3
 8001f92:	462a      	mov	r2, r5
 8001f94:	4633      	mov	r3, r6
 8001f96:	f141 0100 	adc.w	r1, r1, #0
 8001f9a:	f01b fc79 	bl	801d890 <__aeabi_uldivmod>
 8001f9e:	f5a0 7240 	sub.w	r2, r0, #768	; 0x300
 8001fa2:	4b3c      	ldr	r3, [pc, #240]	; (8002094 <UART_SetConfig+0x2a0>)
 8001fa4:	429a      	cmp	r2, r3
 8001fa6:	d87d      	bhi.n	80020a4 <UART_SetConfig+0x2b0>
 8001fa8:	6823      	ldr	r3, [r4, #0]
 8001faa:	60d8      	str	r0, [r3, #12]
 8001fac:	4630      	mov	r0, r6
 8001fae:	e050      	b.n	8002052 <UART_SetConfig+0x25e>
 8001fb0:	f022 fe2e 	bl	8024c10 <HAL_RCC_GetSysClockFreq>
 8001fb4:	e7cf      	b.n	8001f56 <UART_SetConfig+0x162>
 8001fb6:	4838      	ldr	r0, [pc, #224]	; (8002098 <UART_SetConfig+0x2a4>)
 8001fb8:	e7d0      	b.n	8001f5c <UART_SetConfig+0x168>
 8001fba:	2a08      	cmp	r2, #8
 8001fbc:	d874      	bhi.n	80020a8 <UART_SetConfig+0x2b4>
 8001fbe:	e8df f002 	tbb	[pc, r2]
 8001fc2:	2707      	.short	0x2707
 8001fc4:	732a7305 	.word	0x732a7305
 8001fc8:	7373      	.short	0x7373
 8001fca:	0b          	.byte	0x0b
 8001fcb:	00          	.byte	0x00
 8001fcc:	4832      	ldr	r0, [pc, #200]	; (8002098 <UART_SetConfig+0x2a4>)
 8001fce:	e003      	b.n	8001fd8 <UART_SetConfig+0x1e4>
 8001fd0:	f023 fa2e 	bl	8025430 <HAL_RCC_GetPCLK1Freq>
 8001fd4:	2800      	cmp	r0, #0
 8001fd6:	d069      	beq.n	80020ac <UART_SetConfig+0x2b8>
 8001fd8:	6a62      	ldr	r2, [r4, #36]	; 0x24
 8001fda:	4b2d      	ldr	r3, [pc, #180]	; (8002090 <UART_SetConfig+0x29c>)
 8001fdc:	f833 3012 	ldrh.w	r3, [r3, r2, lsl #1]
 8001fe0:	fbb0 f0f3 	udiv	r0, r0, r3
 8001fe4:	6862      	ldr	r2, [r4, #4]
 8001fe6:	0853      	lsrs	r3, r2, #1
 8001fe8:	eb03 0040 	add.w	r0, r3, r0, lsl #1
 8001fec:	fbb0 f0f2 	udiv	r0, r0, r2
 8001ff0:	b280      	uxth	r0, r0
 8001ff2:	f1a0 0210 	sub.w	r2, r0, #16
 8001ff6:	f64f 73ef 	movw	r3, #65519	; 0xffef
 8001ffa:	429a      	cmp	r2, r3
 8001ffc:	d858      	bhi.n	80020b0 <UART_SetConfig+0x2bc>
 8001ffe:	f020 030f 	bic.w	r3, r0, #15
 8002002:	f3c0 0042 	ubfx	r0, r0, #1, #3
 8002006:	4318      	orrs	r0, r3
 8002008:	6823      	ldr	r3, [r4, #0]
 800200a:	60d8      	str	r0, [r3, #12]
 800200c:	2000      	movs	r0, #0
 800200e:	e020      	b.n	8002052 <UART_SetConfig+0x25e>
 8002010:	f023 fa1e 	bl	8025450 <HAL_RCC_GetPCLK2Freq>
 8002014:	e7de      	b.n	8001fd4 <UART_SetConfig+0x1e0>
 8002016:	f022 fdfb 	bl	8024c10 <HAL_RCC_GetSysClockFreq>
 800201a:	e7db      	b.n	8001fd4 <UART_SetConfig+0x1e0>
 800201c:	481e      	ldr	r0, [pc, #120]	; (8002098 <UART_SetConfig+0x2a4>)
 800201e:	e003      	b.n	8002028 <UART_SetConfig+0x234>
 8002020:	f023 fa06 	bl	8025430 <HAL_RCC_GetPCLK1Freq>
 8002024:	2800      	cmp	r0, #0
 8002026:	d047      	beq.n	80020b8 <UART_SetConfig+0x2c4>
 8002028:	6a62      	ldr	r2, [r4, #36]	; 0x24
 800202a:	4b19      	ldr	r3, [pc, #100]	; (8002090 <UART_SetConfig+0x29c>)
 800202c:	f833 3012 	ldrh.w	r3, [r3, r2, lsl #1]
 8002030:	fbb0 f0f3 	udiv	r0, r0, r3
 8002034:	6863      	ldr	r3, [r4, #4]
 8002036:	eb00 0053 	add.w	r0, r0, r3, lsr #1
 800203a:	fbb0 f0f3 	udiv	r0, r0, r3
 800203e:	b280      	uxth	r0, r0
 8002040:	f1a0 0210 	sub.w	r2, r0, #16
 8002044:	f64f 73ef 	movw	r3, #65519	; 0xffef
 8002048:	429a      	cmp	r2, r3
 800204a:	d837      	bhi.n	80020bc <UART_SetConfig+0x2c8>
 800204c:	6823      	ldr	r3, [r4, #0]
 800204e:	60d8      	str	r0, [r3, #12]
 8002050:	2000      	movs	r0, #0
 8002052:	2301      	movs	r3, #1
 8002054:	f8a4 306a 	strh.w	r3, [r4, #106]	; 0x6a
 8002058:	f8a4 3068 	strh.w	r3, [r4, #104]	; 0x68
 800205c:	2300      	movs	r3, #0
 800205e:	6723      	str	r3, [r4, #112]	; 0x70
 8002060:	6763      	str	r3, [r4, #116]	; 0x74
 8002062:	bd70      	pop	{r4, r5, r6, pc}
 8002064:	f023 f9f4 	bl	8025450 <HAL_RCC_GetPCLK2Freq>
 8002068:	e7dc      	b.n	8002024 <UART_SetConfig+0x230>
 800206a:	f022 fdd1 	bl	8024c10 <HAL_RCC_GetSysClockFreq>
 800206e:	e7d9      	b.n	8002024 <UART_SetConfig+0x230>
 8002070:	f44f 4000 	mov.w	r0, #32768	; 0x8000
 8002074:	e7d8      	b.n	8002028 <UART_SetConfig+0x234>
 8002076:	2001      	movs	r0, #1
 8002078:	e7eb      	b.n	8002052 <UART_SetConfig+0x25e>
 800207a:	2000      	movs	r0, #0
 800207c:	e7e9      	b.n	8002052 <UART_SetConfig+0x25e>
 800207e:	bf00      	nop
 8002080:	cfff69f3 	.word	0xcfff69f3
 8002084:	40008000 	.word	0x40008000
 8002088:	40013800 	.word	0x40013800
 800208c:	40004400 	.word	0x40004400
 8002090:	08002b24 	.word	0x08002b24
 8002094:	000ffcff 	.word	0x000ffcff
 8002098:	00f42400 	.word	0x00f42400
 800209c:	2001      	movs	r0, #1
 800209e:	e7d8      	b.n	8002052 <UART_SetConfig+0x25e>
 80020a0:	2001      	movs	r0, #1
 80020a2:	e7d6      	b.n	8002052 <UART_SetConfig+0x25e>
 80020a4:	2001      	movs	r0, #1
 80020a6:	e7d4      	b.n	8002052 <UART_SetConfig+0x25e>
 80020a8:	2001      	movs	r0, #1
 80020aa:	e7d2      	b.n	8002052 <UART_SetConfig+0x25e>
 80020ac:	2000      	movs	r0, #0
 80020ae:	e7d0      	b.n	8002052 <UART_SetConfig+0x25e>
 80020b0:	2001      	movs	r0, #1
 80020b2:	e7ce      	b.n	8002052 <UART_SetConfig+0x25e>
 80020b4:	2001      	movs	r0, #1
 80020b6:	e7cc      	b.n	8002052 <UART_SetConfig+0x25e>
 80020b8:	2000      	movs	r0, #0
 80020ba:	e7ca      	b.n	8002052 <UART_SetConfig+0x25e>
 80020bc:	2001      	movs	r0, #1
 80020be:	e7c8      	b.n	8002052 <UART_SetConfig+0x25e>

080020c0 <UART_AdvFeatureConfig>:
 80020c0:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80020c2:	f013 0f01 	tst.w	r3, #1
 80020c6:	d006      	beq.n	80020d6 <UART_AdvFeatureConfig+0x16>
 80020c8:	6802      	ldr	r2, [r0, #0]
 80020ca:	6853      	ldr	r3, [r2, #4]
 80020cc:	f423 3300 	bic.w	r3, r3, #131072	; 0x20000
 80020d0:	6ac1      	ldr	r1, [r0, #44]	; 0x2c
 80020d2:	430b      	orrs	r3, r1
 80020d4:	6053      	str	r3, [r2, #4]
 80020d6:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80020d8:	f013 0f02 	tst.w	r3, #2
 80020dc:	d006      	beq.n	80020ec <UART_AdvFeatureConfig+0x2c>
 80020de:	6802      	ldr	r2, [r0, #0]
 80020e0:	6853      	ldr	r3, [r2, #4]
 80020e2:	f423 3380 	bic.w	r3, r3, #65536	; 0x10000
 80020e6:	6b01      	ldr	r1, [r0, #48]	; 0x30
 80020e8:	430b      	orrs	r3, r1
 80020ea:	6053      	str	r3, [r2, #4]
 80020ec:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80020ee:	f013 0f04 	tst.w	r3, #4
 80020f2:	d006      	beq.n	8002102 <UART_AdvFeatureConfig+0x42>
 80020f4:	6802      	ldr	r2, [r0, #0]
 80020f6:	6853      	ldr	r3, [r2, #4]
 80020f8:	f423 2380 	bic.w	r3, r3, #262144	; 0x40000
 80020fc:	6b41      	ldr	r1, [r0, #52]	; 0x34
 80020fe:	430b      	orrs	r3, r1
 8002100:	6053      	str	r3, [r2, #4]
 8002102:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002104:	f013 0f08 	tst.w	r3, #8
 8002108:	d006      	beq.n	8002118 <UART_AdvFeatureConfig+0x58>
 800210a:	6802      	ldr	r2, [r0, #0]
 800210c:	6853      	ldr	r3, [r2, #4]
 800210e:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 8002112:	6b81      	ldr	r1, [r0, #56]	; 0x38
 8002114:	430b      	orrs	r3, r1
 8002116:	6053      	str	r3, [r2, #4]
 8002118:	6a83      	ldr	r3, [r0, #40]	; 0x28
 800211a:	f013 0f10 	tst.w	r3, #16
 800211e:	d006      	beq.n	800212e <UART_AdvFeatureConfig+0x6e>
 8002120:	6802      	ldr	r2, [r0, #0]
 8002122:	6893      	ldr	r3, [r2, #8]
 8002124:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
 8002128:	6bc1      	ldr	r1, [r0, #60]	; 0x3c
 800212a:	430b      	orrs	r3, r1
 800212c:	6093      	str	r3, [r2, #8]
 800212e:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002130:	f013 0f20 	tst.w	r3, #32
 8002134:	d006      	beq.n	8002144 <UART_AdvFeatureConfig+0x84>
 8002136:	6802      	ldr	r2, [r0, #0]
 8002138:	6893      	ldr	r3, [r2, #8]
 800213a:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 800213e:	6c01      	ldr	r1, [r0, #64]	; 0x40
 8002140:	430b      	orrs	r3, r1
 8002142:	6093      	str	r3, [r2, #8]
 8002144:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002146:	f013 0f40 	tst.w	r3, #64	; 0x40
 800214a:	d00a      	beq.n	8002162 <UART_AdvFeatureConfig+0xa2>
 800214c:	6802      	ldr	r2, [r0, #0]
 800214e:	6853      	ldr	r3, [r2, #4]
 8002150:	f423 1380 	bic.w	r3, r3, #1048576	; 0x100000
 8002154:	6c41      	ldr	r1, [r0, #68]	; 0x44
 8002156:	430b      	orrs	r3, r1
 8002158:	6053      	str	r3, [r2, #4]
 800215a:	6c43      	ldr	r3, [r0, #68]	; 0x44
 800215c:	f5b3 1f80 	cmp.w	r3, #1048576	; 0x100000
 8002160:	d00b      	beq.n	800217a <UART_AdvFeatureConfig+0xba>
 8002162:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002164:	f013 0f80 	tst.w	r3, #128	; 0x80
 8002168:	d006      	beq.n	8002178 <UART_AdvFeatureConfig+0xb8>
 800216a:	6802      	ldr	r2, [r0, #0]
 800216c:	6853      	ldr	r3, [r2, #4]
 800216e:	f423 2300 	bic.w	r3, r3, #524288	; 0x80000
 8002172:	6cc1      	ldr	r1, [r0, #76]	; 0x4c
 8002174:	430b      	orrs	r3, r1
 8002176:	6053      	str	r3, [r2, #4]
 8002178:	4770      	bx	lr
 800217a:	6802      	ldr	r2, [r0, #0]
 800217c:	6853      	ldr	r3, [r2, #4]
 800217e:	f423 03c0 	bic.w	r3, r3, #6291456	; 0x600000
 8002182:	6c81      	ldr	r1, [r0, #72]	; 0x48
 8002184:	430b      	orrs	r3, r1
 8002186:	6053      	str	r3, [r2, #4]
 8002188:	e7eb      	b.n	8002162 <UART_AdvFeatureConfig+0xa2>

0800218a <UART_WaitOnFlagUntilTimeout>:
 800218a:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 800218e:	4605      	mov	r5, r0
 8002190:	460f      	mov	r7, r1
 8002192:	4616      	mov	r6, r2
 8002194:	4699      	mov	r9, r3
 8002196:	f8dd 8020 	ldr.w	r8, [sp, #32]
 800219a:	682c      	ldr	r4, [r5, #0]
 800219c:	69e4      	ldr	r4, [r4, #28]
 800219e:	ea37 0304 	bics.w	r3, r7, r4
 80021a2:	bf0c      	ite	eq
 80021a4:	f04f 0c01 	moveq.w	ip, #1
 80021a8:	f04f 0c00 	movne.w	ip, #0
 80021ac:	45b4      	cmp	ip, r6
 80021ae:	d157      	bne.n	8002260 <UART_WaitOnFlagUntilTimeout+0xd6>
 80021b0:	f1b8 3fff 	cmp.w	r8, #4294967295	; 0xffffffff
 80021b4:	d0f1      	beq.n	800219a <UART_WaitOnFlagUntilTimeout+0x10>
 80021b6:	f022 faff 	bl	80247b8 <HAL_GetTick>
 80021ba:	eba0 0009 	sub.w	r0, r0, r9
 80021be:	4540      	cmp	r0, r8
 80021c0:	d82f      	bhi.n	8002222 <UART_WaitOnFlagUntilTimeout+0x98>
 80021c2:	f1b8 0f00 	cmp.w	r8, #0
 80021c6:	d02c      	beq.n	8002222 <UART_WaitOnFlagUntilTimeout+0x98>
 80021c8:	682b      	ldr	r3, [r5, #0]
 80021ca:	681a      	ldr	r2, [r3, #0]
 80021cc:	f012 0f04 	tst.w	r2, #4
 80021d0:	d0e3      	beq.n	800219a <UART_WaitOnFlagUntilTimeout+0x10>
 80021d2:	69da      	ldr	r2, [r3, #28]
 80021d4:	f412 6f00 	tst.w	r2, #2048	; 0x800
 80021d8:	d0df      	beq.n	800219a <UART_WaitOnFlagUntilTimeout+0x10>
 80021da:	f44f 6200 	mov.w	r2, #2048	; 0x800
 80021de:	621a      	str	r2, [r3, #32]
 80021e0:	682a      	ldr	r2, [r5, #0]
 80021e2:	e852 3f00 	ldrex	r3, [r2]
 80021e6:	f423 73d0 	bic.w	r3, r3, #416	; 0x1a0
 80021ea:	e842 3100 	strex	r1, r3, [r2]
 80021ee:	2900      	cmp	r1, #0
 80021f0:	d1f6      	bne.n	80021e0 <UART_WaitOnFlagUntilTimeout+0x56>
 80021f2:	682a      	ldr	r2, [r5, #0]
 80021f4:	f102 0308 	add.w	r3, r2, #8
 80021f8:	e853 3f00 	ldrex	r3, [r3]
 80021fc:	f023 0301 	bic.w	r3, r3, #1
 8002200:	3208      	adds	r2, #8
 8002202:	e842 3100 	strex	r1, r3, [r2]
 8002206:	2900      	cmp	r1, #0
 8002208:	d1f3      	bne.n	80021f2 <UART_WaitOnFlagUntilTimeout+0x68>
 800220a:	2320      	movs	r3, #32
 800220c:	f8c5 3084 	str.w	r3, [r5, #132]	; 0x84
 8002210:	f8c5 3088 	str.w	r3, [r5, #136]	; 0x88
 8002214:	f8c5 308c 	str.w	r3, [r5, #140]	; 0x8c
 8002218:	2300      	movs	r3, #0
 800221a:	f885 3080 	strb.w	r3, [r5, #128]	; 0x80
 800221e:	2003      	movs	r0, #3
 8002220:	e01f      	b.n	8002262 <UART_WaitOnFlagUntilTimeout+0xd8>
 8002222:	682a      	ldr	r2, [r5, #0]
 8002224:	e852 3f00 	ldrex	r3, [r2]
 8002228:	f423 73d0 	bic.w	r3, r3, #416	; 0x1a0
 800222c:	e842 3100 	strex	r1, r3, [r2]
 8002230:	2900      	cmp	r1, #0
 8002232:	d1f6      	bne.n	8002222 <UART_WaitOnFlagUntilTimeout+0x98>
 8002234:	682a      	ldr	r2, [r5, #0]
 8002236:	f102 0308 	add.w	r3, r2, #8
 800223a:	e853 3f00 	ldrex	r3, [r3]
 800223e:	f023 0301 	bic.w	r3, r3, #1
 8002242:	3208      	adds	r2, #8
 8002244:	e842 3100 	strex	r1, r3, [r2]
 8002248:	2900      	cmp	r1, #0
 800224a:	d1f3      	bne.n	8002234 <UART_WaitOnFlagUntilTimeout+0xaa>
 800224c:	2320      	movs	r3, #32
 800224e:	f8c5 3084 	str.w	r3, [r5, #132]	; 0x84
 8002252:	f8c5 3088 	str.w	r3, [r5, #136]	; 0x88
 8002256:	2300      	movs	r3, #0
 8002258:	f885 3080 	strb.w	r3, [r5, #128]	; 0x80
 800225c:	2003      	movs	r0, #3
 800225e:	e000      	b.n	8002262 <UART_WaitOnFlagUntilTimeout+0xd8>
 8002260:	2000      	movs	r0, #0
 8002262:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}

08002266 <HAL_UART_Transmit>:
 8002266:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 800226a:	b082      	sub	sp, #8
 800226c:	461e      	mov	r6, r3
 800226e:	f8d0 3084 	ldr.w	r3, [r0, #132]	; 0x84
 8002272:	2b20      	cmp	r3, #32
 8002274:	d158      	bne.n	8002328 <HAL_UART_Transmit+0xc2>
 8002276:	4604      	mov	r4, r0
 8002278:	460d      	mov	r5, r1
 800227a:	4690      	mov	r8, r2
 800227c:	2900      	cmp	r1, #0
 800227e:	d057      	beq.n	8002330 <HAL_UART_Transmit+0xca>
 8002280:	2a00      	cmp	r2, #0
 8002282:	d057      	beq.n	8002334 <HAL_UART_Transmit+0xce>
 8002284:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 8002288:	2b01      	cmp	r3, #1
 800228a:	d055      	beq.n	8002338 <HAL_UART_Transmit+0xd2>
 800228c:	2301      	movs	r3, #1
 800228e:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002292:	2300      	movs	r3, #0
 8002294:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 8002298:	2321      	movs	r3, #33	; 0x21
 800229a:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 800229e:	f022 fa8b 	bl	80247b8 <HAL_GetTick>
 80022a2:	4607      	mov	r7, r0
 80022a4:	f8a4 8054 	strh.w	r8, [r4, #84]	; 0x54
 80022a8:	f8a4 8056 	strh.w	r8, [r4, #86]	; 0x56
 80022ac:	68a3      	ldr	r3, [r4, #8]
 80022ae:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80022b2:	d005      	beq.n	80022c0 <HAL_UART_Transmit+0x5a>
 80022b4:	f04f 0800 	mov.w	r8, #0
 80022b8:	2300      	movs	r3, #0
 80022ba:	f884 3080 	strb.w	r3, [r4, #128]	; 0x80
 80022be:	e014      	b.n	80022ea <HAL_UART_Transmit+0x84>
 80022c0:	6923      	ldr	r3, [r4, #16]
 80022c2:	b113      	cbz	r3, 80022ca <HAL_UART_Transmit+0x64>
 80022c4:	f04f 0800 	mov.w	r8, #0
 80022c8:	e7f6      	b.n	80022b8 <HAL_UART_Transmit+0x52>
 80022ca:	46a8      	mov	r8, r5
 80022cc:	2500      	movs	r5, #0
 80022ce:	e7f3      	b.n	80022b8 <HAL_UART_Transmit+0x52>
 80022d0:	f838 3b02 	ldrh.w	r3, [r8], #2
 80022d4:	6822      	ldr	r2, [r4, #0]
 80022d6:	f3c3 0308 	ubfx	r3, r3, #0, #9
 80022da:	6293      	str	r3, [r2, #40]	; 0x28
 80022dc:	f8b4 2056 	ldrh.w	r2, [r4, #86]	; 0x56
 80022e0:	b292      	uxth	r2, r2
 80022e2:	3a01      	subs	r2, #1
 80022e4:	b292      	uxth	r2, r2
 80022e6:	f8a4 2056 	strh.w	r2, [r4, #86]	; 0x56
 80022ea:	f8b4 3056 	ldrh.w	r3, [r4, #86]	; 0x56
 80022ee:	b29b      	uxth	r3, r3
 80022f0:	b173      	cbz	r3, 8002310 <HAL_UART_Transmit+0xaa>
 80022f2:	9600      	str	r6, [sp, #0]
 80022f4:	463b      	mov	r3, r7
 80022f6:	2200      	movs	r2, #0
 80022f8:	2180      	movs	r1, #128	; 0x80
 80022fa:	4620      	mov	r0, r4
 80022fc:	f7ff ff45 	bl	800218a <UART_WaitOnFlagUntilTimeout>
 8002300:	b9e0      	cbnz	r0, 800233c <HAL_UART_Transmit+0xd6>
 8002302:	2d00      	cmp	r5, #0
 8002304:	d0e4      	beq.n	80022d0 <HAL_UART_Transmit+0x6a>
 8002306:	f815 2b01 	ldrb.w	r2, [r5], #1
 800230a:	6823      	ldr	r3, [r4, #0]
 800230c:	629a      	str	r2, [r3, #40]	; 0x28
 800230e:	e7e5      	b.n	80022dc <HAL_UART_Transmit+0x76>
 8002310:	9600      	str	r6, [sp, #0]
 8002312:	463b      	mov	r3, r7
 8002314:	2200      	movs	r2, #0
 8002316:	2140      	movs	r1, #64	; 0x40
 8002318:	4620      	mov	r0, r4
 800231a:	f7ff ff36 	bl	800218a <UART_WaitOnFlagUntilTimeout>
 800231e:	b978      	cbnz	r0, 8002340 <HAL_UART_Transmit+0xda>
 8002320:	2320      	movs	r3, #32
 8002322:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 8002326:	e000      	b.n	800232a <HAL_UART_Transmit+0xc4>
 8002328:	2002      	movs	r0, #2
 800232a:	b002      	add	sp, #8
 800232c:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 8002330:	2001      	movs	r0, #1
 8002332:	e7fa      	b.n	800232a <HAL_UART_Transmit+0xc4>
 8002334:	2001      	movs	r0, #1
 8002336:	e7f8      	b.n	800232a <HAL_UART_Transmit+0xc4>
 8002338:	2002      	movs	r0, #2
 800233a:	e7f6      	b.n	800232a <HAL_UART_Transmit+0xc4>
 800233c:	2003      	movs	r0, #3
 800233e:	e7f4      	b.n	800232a <HAL_UART_Transmit+0xc4>
 8002340:	2003      	movs	r0, #3
 8002342:	e7f2      	b.n	800232a <HAL_UART_Transmit+0xc4>

08002344 <HAL_UART_Receive>:
 8002344:	e92d 43f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, lr}
 8002348:	b083      	sub	sp, #12
 800234a:	461e      	mov	r6, r3
 800234c:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 8002350:	2b20      	cmp	r3, #32
 8002352:	f040 8081 	bne.w	8002458 <HAL_UART_Receive+0x114>
 8002356:	4604      	mov	r4, r0
 8002358:	460d      	mov	r5, r1
 800235a:	4690      	mov	r8, r2
 800235c:	2900      	cmp	r1, #0
 800235e:	d07f      	beq.n	8002460 <HAL_UART_Receive+0x11c>
 8002360:	2a00      	cmp	r2, #0
 8002362:	d07f      	beq.n	8002464 <HAL_UART_Receive+0x120>
 8002364:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 8002368:	2b01      	cmp	r3, #1
 800236a:	d07d      	beq.n	8002468 <HAL_UART_Receive+0x124>
 800236c:	2301      	movs	r3, #1
 800236e:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002372:	2300      	movs	r3, #0
 8002374:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 8002378:	2222      	movs	r2, #34	; 0x22
 800237a:	f8c0 2088 	str.w	r2, [r0, #136]	; 0x88
 800237e:	66c3      	str	r3, [r0, #108]	; 0x6c
 8002380:	f022 fa1a 	bl	80247b8 <HAL_GetTick>
 8002384:	4607      	mov	r7, r0
 8002386:	f8a4 805c 	strh.w	r8, [r4, #92]	; 0x5c
 800238a:	f8a4 805e 	strh.w	r8, [r4, #94]	; 0x5e
 800238e:	68a3      	ldr	r3, [r4, #8]
 8002390:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002394:	d006      	beq.n	80023a4 <HAL_UART_Receive+0x60>
 8002396:	b9a3      	cbnz	r3, 80023c2 <HAL_UART_Receive+0x7e>
 8002398:	6922      	ldr	r2, [r4, #16]
 800239a:	b972      	cbnz	r2, 80023ba <HAL_UART_Receive+0x76>
 800239c:	22ff      	movs	r2, #255	; 0xff
 800239e:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023a2:	e014      	b.n	80023ce <HAL_UART_Receive+0x8a>
 80023a4:	6922      	ldr	r2, [r4, #16]
 80023a6:	b922      	cbnz	r2, 80023b2 <HAL_UART_Receive+0x6e>
 80023a8:	f240 12ff 	movw	r2, #511	; 0x1ff
 80023ac:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023b0:	e00d      	b.n	80023ce <HAL_UART_Receive+0x8a>
 80023b2:	22ff      	movs	r2, #255	; 0xff
 80023b4:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023b8:	e009      	b.n	80023ce <HAL_UART_Receive+0x8a>
 80023ba:	227f      	movs	r2, #127	; 0x7f
 80023bc:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023c0:	e005      	b.n	80023ce <HAL_UART_Receive+0x8a>
 80023c2:	f1b3 5f80 	cmp.w	r3, #268435456	; 0x10000000
 80023c6:	d00d      	beq.n	80023e4 <HAL_UART_Receive+0xa0>
 80023c8:	2200      	movs	r2, #0
 80023ca:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023ce:	f8b4 8060 	ldrh.w	r8, [r4, #96]	; 0x60
 80023d2:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80023d6:	d00f      	beq.n	80023f8 <HAL_UART_Receive+0xb4>
 80023d8:	f04f 0900 	mov.w	r9, #0
 80023dc:	2300      	movs	r3, #0
 80023de:	f884 3080 	strb.w	r3, [r4, #128]	; 0x80
 80023e2:	e01e      	b.n	8002422 <HAL_UART_Receive+0xde>
 80023e4:	6922      	ldr	r2, [r4, #16]
 80023e6:	b91a      	cbnz	r2, 80023f0 <HAL_UART_Receive+0xac>
 80023e8:	227f      	movs	r2, #127	; 0x7f
 80023ea:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023ee:	e7ee      	b.n	80023ce <HAL_UART_Receive+0x8a>
 80023f0:	223f      	movs	r2, #63	; 0x3f
 80023f2:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023f6:	e7ea      	b.n	80023ce <HAL_UART_Receive+0x8a>
 80023f8:	6923      	ldr	r3, [r4, #16]
 80023fa:	b113      	cbz	r3, 8002402 <HAL_UART_Receive+0xbe>
 80023fc:	f04f 0900 	mov.w	r9, #0
 8002400:	e7ec      	b.n	80023dc <HAL_UART_Receive+0x98>
 8002402:	46a9      	mov	r9, r5
 8002404:	2500      	movs	r5, #0
 8002406:	e7e9      	b.n	80023dc <HAL_UART_Receive+0x98>
 8002408:	6823      	ldr	r3, [r4, #0]
 800240a:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 800240c:	ea08 0303 	and.w	r3, r8, r3
 8002410:	f829 3b02 	strh.w	r3, [r9], #2
 8002414:	f8b4 205e 	ldrh.w	r2, [r4, #94]	; 0x5e
 8002418:	b292      	uxth	r2, r2
 800241a:	3a01      	subs	r2, #1
 800241c:	b292      	uxth	r2, r2
 800241e:	f8a4 205e 	strh.w	r2, [r4, #94]	; 0x5e
 8002422:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8002426:	b29b      	uxth	r3, r3
 8002428:	b18b      	cbz	r3, 800244e <HAL_UART_Receive+0x10a>
 800242a:	9600      	str	r6, [sp, #0]
 800242c:	463b      	mov	r3, r7
 800242e:	2200      	movs	r2, #0
 8002430:	2120      	movs	r1, #32
 8002432:	4620      	mov	r0, r4
 8002434:	f7ff fea9 	bl	800218a <UART_WaitOnFlagUntilTimeout>
 8002438:	b9c0      	cbnz	r0, 800246c <HAL_UART_Receive+0x128>
 800243a:	2d00      	cmp	r5, #0
 800243c:	d0e4      	beq.n	8002408 <HAL_UART_Receive+0xc4>
 800243e:	6823      	ldr	r3, [r4, #0]
 8002440:	6a5a      	ldr	r2, [r3, #36]	; 0x24
 8002442:	fa5f f388 	uxtb.w	r3, r8
 8002446:	4013      	ands	r3, r2
 8002448:	f805 3b01 	strb.w	r3, [r5], #1
 800244c:	e7e2      	b.n	8002414 <HAL_UART_Receive+0xd0>
 800244e:	2320      	movs	r3, #32
 8002450:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8002454:	2000      	movs	r0, #0
 8002456:	e000      	b.n	800245a <HAL_UART_Receive+0x116>
 8002458:	2002      	movs	r0, #2
 800245a:	b003      	add	sp, #12
 800245c:	e8bd 83f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, pc}
 8002460:	2001      	movs	r0, #1
 8002462:	e7fa      	b.n	800245a <HAL_UART_Receive+0x116>
 8002464:	2001      	movs	r0, #1
 8002466:	e7f8      	b.n	800245a <HAL_UART_Receive+0x116>
 8002468:	2002      	movs	r0, #2
 800246a:	e7f6      	b.n	800245a <HAL_UART_Receive+0x116>
 800246c:	2003      	movs	r0, #3
 800246e:	e7f4      	b.n	800245a <HAL_UART_Receive+0x116>

08002470 <UART_CheckIdleState>:
 8002470:	b530      	push	{r4, r5, lr}
 8002472:	b083      	sub	sp, #12
 8002474:	4604      	mov	r4, r0
 8002476:	2300      	movs	r3, #0
 8002478:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 800247c:	f022 f99c 	bl	80247b8 <HAL_GetTick>
 8002480:	4605      	mov	r5, r0
 8002482:	6822      	ldr	r2, [r4, #0]
 8002484:	6812      	ldr	r2, [r2, #0]
 8002486:	f012 0f08 	tst.w	r2, #8
 800248a:	d10f      	bne.n	80024ac <UART_CheckIdleState+0x3c>
 800248c:	6823      	ldr	r3, [r4, #0]
 800248e:	681b      	ldr	r3, [r3, #0]
 8002490:	f013 0f04 	tst.w	r3, #4
 8002494:	d118      	bne.n	80024c8 <UART_CheckIdleState+0x58>
 8002496:	2320      	movs	r3, #32
 8002498:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 800249c:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80024a0:	2000      	movs	r0, #0
 80024a2:	66e0      	str	r0, [r4, #108]	; 0x6c
 80024a4:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 80024a8:	b003      	add	sp, #12
 80024aa:	bd30      	pop	{r4, r5, pc}
 80024ac:	f06f 437e 	mvn.w	r3, #4261412864	; 0xfe000000
 80024b0:	9300      	str	r3, [sp, #0]
 80024b2:	4603      	mov	r3, r0
 80024b4:	2200      	movs	r2, #0
 80024b6:	f44f 1100 	mov.w	r1, #2097152	; 0x200000
 80024ba:	4620      	mov	r0, r4
 80024bc:	f7ff fe65 	bl	800218a <UART_WaitOnFlagUntilTimeout>
 80024c0:	2800      	cmp	r0, #0
 80024c2:	d0e3      	beq.n	800248c <UART_CheckIdleState+0x1c>
 80024c4:	2003      	movs	r0, #3
 80024c6:	e7ef      	b.n	80024a8 <UART_CheckIdleState+0x38>
 80024c8:	f06f 437e 	mvn.w	r3, #4261412864	; 0xfe000000
 80024cc:	9300      	str	r3, [sp, #0]
 80024ce:	462b      	mov	r3, r5
 80024d0:	2200      	movs	r2, #0
 80024d2:	f44f 0180 	mov.w	r1, #4194304	; 0x400000
 80024d6:	4620      	mov	r0, r4
 80024d8:	f7ff fe57 	bl	800218a <UART_WaitOnFlagUntilTimeout>
 80024dc:	2800      	cmp	r0, #0
 80024de:	d0da      	beq.n	8002496 <UART_CheckIdleState+0x26>
 80024e0:	2003      	movs	r0, #3
 80024e2:	e7e1      	b.n	80024a8 <UART_CheckIdleState+0x38>

080024e4 <HAL_UART_Init>:
 80024e4:	b378      	cbz	r0, 8002546 <HAL_UART_Init+0x62>
 80024e6:	b510      	push	{r4, lr}
 80024e8:	4604      	mov	r4, r0
 80024ea:	f8d0 3084 	ldr.w	r3, [r0, #132]	; 0x84
 80024ee:	b30b      	cbz	r3, 8002534 <HAL_UART_Init+0x50>
 80024f0:	2324      	movs	r3, #36	; 0x24
 80024f2:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 80024f6:	6822      	ldr	r2, [r4, #0]
 80024f8:	6813      	ldr	r3, [r2, #0]
 80024fa:	f023 0301 	bic.w	r3, r3, #1
 80024fe:	6013      	str	r3, [r2, #0]
 8002500:	4620      	mov	r0, r4
 8002502:	f7ff fc77 	bl	8001df4 <UART_SetConfig>
 8002506:	2801      	cmp	r0, #1
 8002508:	d013      	beq.n	8002532 <HAL_UART_Init+0x4e>
 800250a:	6aa3      	ldr	r3, [r4, #40]	; 0x28
 800250c:	b9bb      	cbnz	r3, 800253e <HAL_UART_Init+0x5a>
 800250e:	6822      	ldr	r2, [r4, #0]
 8002510:	6853      	ldr	r3, [r2, #4]
 8002512:	f423 4390 	bic.w	r3, r3, #18432	; 0x4800
 8002516:	6053      	str	r3, [r2, #4]
 8002518:	6822      	ldr	r2, [r4, #0]
 800251a:	6893      	ldr	r3, [r2, #8]
 800251c:	f023 032a 	bic.w	r3, r3, #42	; 0x2a
 8002520:	6093      	str	r3, [r2, #8]
 8002522:	6822      	ldr	r2, [r4, #0]
 8002524:	6813      	ldr	r3, [r2, #0]
 8002526:	f043 0301 	orr.w	r3, r3, #1
 800252a:	6013      	str	r3, [r2, #0]
 800252c:	4620      	mov	r0, r4
 800252e:	f7ff ff9f 	bl	8002470 <UART_CheckIdleState>
 8002532:	bd10      	pop	{r4, pc}
 8002534:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002538:	f7fe fa78 	bl	8000a2c <HAL_UART_MspInit>
 800253c:	e7d8      	b.n	80024f0 <HAL_UART_Init+0xc>
 800253e:	4620      	mov	r0, r4
 8002540:	f7ff fdbe 	bl	80020c0 <UART_AdvFeatureConfig>
 8002544:	e7e3      	b.n	800250e <HAL_UART_Init+0x2a>
 8002546:	2001      	movs	r0, #1
 8002548:	4770      	bx	lr
	...

0800254c <UART_Start_Receive_IT>:
 800254c:	b410      	push	{r4}
 800254e:	6581      	str	r1, [r0, #88]	; 0x58
 8002550:	f8a0 205c 	strh.w	r2, [r0, #92]	; 0x5c
 8002554:	f8a0 205e 	strh.w	r2, [r0, #94]	; 0x5e
 8002558:	2300      	movs	r3, #0
 800255a:	6703      	str	r3, [r0, #112]	; 0x70
 800255c:	6883      	ldr	r3, [r0, #8]
 800255e:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002562:	d006      	beq.n	8002572 <UART_Start_Receive_IT+0x26>
 8002564:	b9a3      	cbnz	r3, 8002590 <UART_Start_Receive_IT+0x44>
 8002566:	6903      	ldr	r3, [r0, #16]
 8002568:	b973      	cbnz	r3, 8002588 <UART_Start_Receive_IT+0x3c>
 800256a:	23ff      	movs	r3, #255	; 0xff
 800256c:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002570:	e014      	b.n	800259c <UART_Start_Receive_IT+0x50>
 8002572:	6903      	ldr	r3, [r0, #16]
 8002574:	b923      	cbnz	r3, 8002580 <UART_Start_Receive_IT+0x34>
 8002576:	f240 13ff 	movw	r3, #511	; 0x1ff
 800257a:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 800257e:	e00d      	b.n	800259c <UART_Start_Receive_IT+0x50>
 8002580:	23ff      	movs	r3, #255	; 0xff
 8002582:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002586:	e009      	b.n	800259c <UART_Start_Receive_IT+0x50>
 8002588:	237f      	movs	r3, #127	; 0x7f
 800258a:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 800258e:	e005      	b.n	800259c <UART_Start_Receive_IT+0x50>
 8002590:	f1b3 5f80 	cmp.w	r3, #268435456	; 0x10000000
 8002594:	d02d      	beq.n	80025f2 <UART_Start_Receive_IT+0xa6>
 8002596:	2300      	movs	r3, #0
 8002598:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 800259c:	2300      	movs	r3, #0
 800259e:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 80025a2:	2322      	movs	r3, #34	; 0x22
 80025a4:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 80025a8:	6801      	ldr	r1, [r0, #0]
 80025aa:	f101 0308 	add.w	r3, r1, #8
 80025ae:	e853 3f00 	ldrex	r3, [r3]
 80025b2:	f043 0301 	orr.w	r3, r3, #1
 80025b6:	3108      	adds	r1, #8
 80025b8:	e841 3400 	strex	r4, r3, [r1]
 80025bc:	2c00      	cmp	r4, #0
 80025be:	d1f3      	bne.n	80025a8 <UART_Start_Receive_IT+0x5c>
 80025c0:	6e43      	ldr	r3, [r0, #100]	; 0x64
 80025c2:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 80025c6:	d01e      	beq.n	8002606 <UART_Start_Receive_IT+0xba>
 80025c8:	6883      	ldr	r3, [r0, #8]
 80025ca:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80025ce:	d043      	beq.n	8002658 <UART_Start_Receive_IT+0x10c>
 80025d0:	4b24      	ldr	r3, [pc, #144]	; (8002664 <UART_Start_Receive_IT+0x118>)
 80025d2:	6703      	str	r3, [r0, #112]	; 0x70
 80025d4:	2300      	movs	r3, #0
 80025d6:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80025da:	6802      	ldr	r2, [r0, #0]
 80025dc:	e852 3f00 	ldrex	r3, [r2]
 80025e0:	f443 7390 	orr.w	r3, r3, #288	; 0x120
 80025e4:	e842 3100 	strex	r1, r3, [r2]
 80025e8:	2900      	cmp	r1, #0
 80025ea:	d1f6      	bne.n	80025da <UART_Start_Receive_IT+0x8e>
 80025ec:	2000      	movs	r0, #0
 80025ee:	bc10      	pop	{r4}
 80025f0:	4770      	bx	lr
 80025f2:	6903      	ldr	r3, [r0, #16]
 80025f4:	b91b      	cbnz	r3, 80025fe <UART_Start_Receive_IT+0xb2>
 80025f6:	237f      	movs	r3, #127	; 0x7f
 80025f8:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 80025fc:	e7ce      	b.n	800259c <UART_Start_Receive_IT+0x50>
 80025fe:	233f      	movs	r3, #63	; 0x3f
 8002600:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002604:	e7ca      	b.n	800259c <UART_Start_Receive_IT+0x50>
 8002606:	f8b0 3068 	ldrh.w	r3, [r0, #104]	; 0x68
 800260a:	4293      	cmp	r3, r2
 800260c:	d8dc      	bhi.n	80025c8 <UART_Start_Receive_IT+0x7c>
 800260e:	6883      	ldr	r3, [r0, #8]
 8002610:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 8002614:	d01a      	beq.n	800264c <UART_Start_Receive_IT+0x100>
 8002616:	4b14      	ldr	r3, [pc, #80]	; (8002668 <UART_Start_Receive_IT+0x11c>)
 8002618:	6703      	str	r3, [r0, #112]	; 0x70
 800261a:	2300      	movs	r3, #0
 800261c:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002620:	6802      	ldr	r2, [r0, #0]
 8002622:	e852 3f00 	ldrex	r3, [r2]
 8002626:	f443 7380 	orr.w	r3, r3, #256	; 0x100
 800262a:	e842 3100 	strex	r1, r3, [r2]
 800262e:	2900      	cmp	r1, #0
 8002630:	d1f6      	bne.n	8002620 <UART_Start_Receive_IT+0xd4>
 8002632:	6802      	ldr	r2, [r0, #0]
 8002634:	f102 0308 	add.w	r3, r2, #8
 8002638:	e853 3f00 	ldrex	r3, [r3]
 800263c:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 8002640:	3208      	adds	r2, #8
 8002642:	e842 3100 	strex	r1, r3, [r2]
 8002646:	2900      	cmp	r1, #0
 8002648:	d1f3      	bne.n	8002632 <UART_Start_Receive_IT+0xe6>
 800264a:	e7cf      	b.n	80025ec <UART_Start_Receive_IT+0xa0>
 800264c:	6903      	ldr	r3, [r0, #16]
 800264e:	2b00      	cmp	r3, #0
 8002650:	d1e1      	bne.n	8002616 <UART_Start_Receive_IT+0xca>
 8002652:	4b06      	ldr	r3, [pc, #24]	; (800266c <UART_Start_Receive_IT+0x120>)
 8002654:	6703      	str	r3, [r0, #112]	; 0x70
 8002656:	e7e0      	b.n	800261a <UART_Start_Receive_IT+0xce>
 8002658:	6903      	ldr	r3, [r0, #16]
 800265a:	2b00      	cmp	r3, #0
 800265c:	d1b8      	bne.n	80025d0 <UART_Start_Receive_IT+0x84>
 800265e:	4b04      	ldr	r3, [pc, #16]	; (8002670 <UART_Start_Receive_IT+0x124>)
 8002660:	6703      	str	r3, [r0, #112]	; 0x70
 8002662:	e7b7      	b.n	80025d4 <UART_Start_Receive_IT+0x88>
 8002664:	08001951 	.word	0x08001951
 8002668:	08001ab5 	.word	0x08001ab5
 800266c:	08001c55 	.word	0x08001c55
 8002670:	08001a03 	.word	0x08001a03

08002674 <HAL_UART_Receive_IT>:
 8002674:	b538      	push	{r3, r4, r5, lr}
 8002676:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 800267a:	2b20      	cmp	r3, #32
 800267c:	d117      	bne.n	80026ae <HAL_UART_Receive_IT+0x3a>
 800267e:	b1c1      	cbz	r1, 80026b2 <HAL_UART_Receive_IT+0x3e>
 8002680:	b1ca      	cbz	r2, 80026b6 <HAL_UART_Receive_IT+0x42>
 8002682:	2300      	movs	r3, #0
 8002684:	66c3      	str	r3, [r0, #108]	; 0x6c
 8002686:	6803      	ldr	r3, [r0, #0]
 8002688:	4c0c      	ldr	r4, [pc, #48]	; (80026bc <HAL_UART_Receive_IT+0x48>)
 800268a:	42a3      	cmp	r3, r4
 800268c:	d00c      	beq.n	80026a8 <HAL_UART_Receive_IT+0x34>
 800268e:	685b      	ldr	r3, [r3, #4]
 8002690:	f413 0f00 	tst.w	r3, #8388608	; 0x800000
 8002694:	d008      	beq.n	80026a8 <HAL_UART_Receive_IT+0x34>
 8002696:	6804      	ldr	r4, [r0, #0]
 8002698:	e854 3f00 	ldrex	r3, [r4]
 800269c:	f043 6380 	orr.w	r3, r3, #67108864	; 0x4000000
 80026a0:	e844 3500 	strex	r5, r3, [r4]
 80026a4:	2d00      	cmp	r5, #0
 80026a6:	d1f6      	bne.n	8002696 <HAL_UART_Receive_IT+0x22>
 80026a8:	f7ff ff50 	bl	800254c <UART_Start_Receive_IT>
 80026ac:	e000      	b.n	80026b0 <HAL_UART_Receive_IT+0x3c>
 80026ae:	2002      	movs	r0, #2
 80026b0:	bd38      	pop	{r3, r4, r5, pc}
 80026b2:	2001      	movs	r0, #1
 80026b4:	e7fc      	b.n	80026b0 <HAL_UART_Receive_IT+0x3c>
 80026b6:	2001      	movs	r0, #1
 80026b8:	e7fa      	b.n	80026b0 <HAL_UART_Receive_IT+0x3c>
 80026ba:	bf00      	nop
 80026bc:	40008000 	.word	0x40008000

080026c0 <UARTEx_SetNbDataToProcess>:
 80026c0:	6e43      	ldr	r3, [r0, #100]	; 0x64
 80026c2:	b92b      	cbnz	r3, 80026d0 <UARTEx_SetNbDataToProcess+0x10>
 80026c4:	2301      	movs	r3, #1
 80026c6:	f8a0 306a 	strh.w	r3, [r0, #106]	; 0x6a
 80026ca:	f8a0 3068 	strh.w	r3, [r0, #104]	; 0x68
 80026ce:	4770      	bx	lr
 80026d0:	b430      	push	{r4, r5}
 80026d2:	6803      	ldr	r3, [r0, #0]
 80026d4:	689a      	ldr	r2, [r3, #8]
 80026d6:	f3c2 6242 	ubfx	r2, r2, #25, #3
 80026da:	6899      	ldr	r1, [r3, #8]
 80026dc:	0f49      	lsrs	r1, r1, #29
 80026de:	4d09      	ldr	r5, [pc, #36]	; (8002704 <UARTEx_SetNbDataToProcess+0x44>)
 80026e0:	5c6b      	ldrb	r3, [r5, r1]
 80026e2:	00db      	lsls	r3, r3, #3
 80026e4:	4c08      	ldr	r4, [pc, #32]	; (8002708 <UARTEx_SetNbDataToProcess+0x48>)
 80026e6:	5c61      	ldrb	r1, [r4, r1]
 80026e8:	fb93 f3f1 	sdiv	r3, r3, r1
 80026ec:	f8a0 306a 	strh.w	r3, [r0, #106]	; 0x6a
 80026f0:	5cab      	ldrb	r3, [r5, r2]
 80026f2:	00db      	lsls	r3, r3, #3
 80026f4:	5ca2      	ldrb	r2, [r4, r2]
 80026f6:	fb93 f3f2 	sdiv	r3, r3, r2
 80026fa:	f8a0 3068 	strh.w	r3, [r0, #104]	; 0x68
 80026fe:	bc30      	pop	{r4, r5}
 8002700:	4770      	bx	lr
 8002702:	bf00      	nop
 8002704:	08002b44 	.word	0x08002b44
 8002708:	08002b3c 	.word	0x08002b3c

0800270c <HAL_UARTEx_WakeupCallback>:
 800270c:	4770      	bx	lr

0800270e <HAL_UARTEx_RxFifoFullCallback>:
 800270e:	4770      	bx	lr

08002710 <HAL_UARTEx_TxFifoEmptyCallback>:
 8002710:	4770      	bx	lr

08002712 <HAL_UARTEx_DisableFifoMode>:
 8002712:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 8002716:	2b01      	cmp	r3, #1
 8002718:	d018      	beq.n	800274c <HAL_UARTEx_DisableFifoMode+0x3a>
 800271a:	2301      	movs	r3, #1
 800271c:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002720:	2324      	movs	r3, #36	; 0x24
 8002722:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8002726:	6803      	ldr	r3, [r0, #0]
 8002728:	681a      	ldr	r2, [r3, #0]
 800272a:	6819      	ldr	r1, [r3, #0]
 800272c:	f021 0101 	bic.w	r1, r1, #1
 8002730:	6019      	str	r1, [r3, #0]
 8002732:	f022 5200 	bic.w	r2, r2, #536870912	; 0x20000000
 8002736:	2300      	movs	r3, #0
 8002738:	6643      	str	r3, [r0, #100]	; 0x64
 800273a:	6801      	ldr	r1, [r0, #0]
 800273c:	600a      	str	r2, [r1, #0]
 800273e:	2220      	movs	r2, #32
 8002740:	f8c0 2084 	str.w	r2, [r0, #132]	; 0x84
 8002744:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002748:	4618      	mov	r0, r3
 800274a:	4770      	bx	lr
 800274c:	2002      	movs	r0, #2
 800274e:	4770      	bx	lr

08002750 <HAL_UARTEx_SetTxFifoThreshold>:
 8002750:	b538      	push	{r3, r4, r5, lr}
 8002752:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 8002756:	2b01      	cmp	r3, #1
 8002758:	d01d      	beq.n	8002796 <HAL_UARTEx_SetTxFifoThreshold+0x46>
 800275a:	4604      	mov	r4, r0
 800275c:	2301      	movs	r3, #1
 800275e:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002762:	2324      	movs	r3, #36	; 0x24
 8002764:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8002768:	6803      	ldr	r3, [r0, #0]
 800276a:	681d      	ldr	r5, [r3, #0]
 800276c:	681a      	ldr	r2, [r3, #0]
 800276e:	f022 0201 	bic.w	r2, r2, #1
 8002772:	601a      	str	r2, [r3, #0]
 8002774:	6802      	ldr	r2, [r0, #0]
 8002776:	6893      	ldr	r3, [r2, #8]
 8002778:	f023 4360 	bic.w	r3, r3, #3758096384	; 0xe0000000
 800277c:	4319      	orrs	r1, r3
 800277e:	6091      	str	r1, [r2, #8]
 8002780:	f7ff ff9e 	bl	80026c0 <UARTEx_SetNbDataToProcess>
 8002784:	6823      	ldr	r3, [r4, #0]
 8002786:	601d      	str	r5, [r3, #0]
 8002788:	2320      	movs	r3, #32
 800278a:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 800278e:	2000      	movs	r0, #0
 8002790:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 8002794:	bd38      	pop	{r3, r4, r5, pc}
 8002796:	2002      	movs	r0, #2
 8002798:	e7fc      	b.n	8002794 <HAL_UARTEx_SetTxFifoThreshold+0x44>

0800279a <HAL_UARTEx_SetRxFifoThreshold>:
 800279a:	b538      	push	{r3, r4, r5, lr}
 800279c:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 80027a0:	2b01      	cmp	r3, #1
 80027a2:	d01d      	beq.n	80027e0 <HAL_UARTEx_SetRxFifoThreshold+0x46>
 80027a4:	4604      	mov	r4, r0
 80027a6:	2301      	movs	r3, #1
 80027a8:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80027ac:	2324      	movs	r3, #36	; 0x24
 80027ae:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80027b2:	6803      	ldr	r3, [r0, #0]
 80027b4:	681d      	ldr	r5, [r3, #0]
 80027b6:	681a      	ldr	r2, [r3, #0]
 80027b8:	f022 0201 	bic.w	r2, r2, #1
 80027bc:	601a      	str	r2, [r3, #0]
 80027be:	6802      	ldr	r2, [r0, #0]
 80027c0:	6893      	ldr	r3, [r2, #8]
 80027c2:	f023 6360 	bic.w	r3, r3, #234881024	; 0xe000000
 80027c6:	4319      	orrs	r1, r3
 80027c8:	6091      	str	r1, [r2, #8]
 80027ca:	f7ff ff79 	bl	80026c0 <UARTEx_SetNbDataToProcess>
 80027ce:	6823      	ldr	r3, [r4, #0]
 80027d0:	601d      	str	r5, [r3, #0]
 80027d2:	2320      	movs	r3, #32
 80027d4:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 80027d8:	2000      	movs	r0, #0
 80027da:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 80027de:	bd38      	pop	{r3, r4, r5, pc}
 80027e0:	2002      	movs	r0, #2
 80027e2:	e7fc      	b.n	80027de <HAL_UARTEx_SetRxFifoThreshold+0x44>

080027e4 <Reset_Handler>:
 80027e4:	480d      	ldr	r0, [pc, #52]	; (800281c <LoopForever+0x2>)
 80027e6:	4685      	mov	sp, r0
 80027e8:	f01d ff0e 	bl	8020608 <SystemInit>
 80027ec:	480c      	ldr	r0, [pc, #48]	; (8002820 <LoopForever+0x6>)
 80027ee:	490d      	ldr	r1, [pc, #52]	; (8002824 <LoopForever+0xa>)
 80027f0:	4a0d      	ldr	r2, [pc, #52]	; (8002828 <LoopForever+0xe>)
 80027f2:	2300      	movs	r3, #0
 80027f4:	e002      	b.n	80027fc <LoopCopyDataInit>

080027f6 <CopyDataInit>:
 80027f6:	58d4      	ldr	r4, [r2, r3]
 80027f8:	50c4      	str	r4, [r0, r3]
 80027fa:	3304      	adds	r3, #4

080027fc <LoopCopyDataInit>:
 80027fc:	18c4      	adds	r4, r0, r3
 80027fe:	428c      	cmp	r4, r1
 8002800:	d3f9      	bcc.n	80027f6 <CopyDataInit>
 8002802:	4a0a      	ldr	r2, [pc, #40]	; (800282c <LoopForever+0x12>)
 8002804:	4c0a      	ldr	r4, [pc, #40]	; (8002830 <LoopForever+0x16>)
 8002806:	2300      	movs	r3, #0
 8002808:	e001      	b.n	800280e <LoopFillZerobss>

0800280a <FillZerobss>:
 800280a:	6013      	str	r3, [r2, #0]
 800280c:	3204      	adds	r2, #4

0800280e <LoopFillZerobss>:
 800280e:	42a2      	cmp	r2, r4
 8002810:	d3fb      	bcc.n	800280a <FillZerobss>
 8002812:	f7fd fcb1 	bl	8000178 <__libc_init_array>
 8002816:	f7fd fe47 	bl	80004a8 <main>

0800281a <LoopForever>:
 800281a:	e7fe      	b.n	800281a <LoopForever>
 800281c:	2000fc00 	.word	0x2000fc00
 8002820:	20006000 	.word	0x20006000
 8002824:	20006068 	.word	0x20006068
 8002828:	08005020 	.word	0x08005020
 800282c:	20006068 	.word	0x20006068
 8002830:	20006690 	.word	0x20006690

08002834 <ADC_IRQHandler>:
 8002834:	e7fe      	b.n	8002834 <ADC_IRQHandler>
	...

08002838 <strcasecmp>:
 8002838:	b530      	push	{r4, r5, lr}
 800283a:	4d0b      	ldr	r5, [pc, #44]	; (8002868 <strcasecmp+0x30>)
 800283c:	4604      	mov	r4, r0
 800283e:	f814 3b01 	ldrb.w	r3, [r4], #1
 8002842:	5d5a      	ldrb	r2, [r3, r5]
 8002844:	f002 0203 	and.w	r2, r2, #3
 8002848:	2a01      	cmp	r2, #1
 800284a:	f811 2b01 	ldrb.w	r2, [r1], #1
 800284e:	5ca8      	ldrb	r0, [r5, r2]
 8002850:	f000 0003 	and.w	r0, r0, #3
 8002854:	bf08      	it	eq
 8002856:	3320      	addeq	r3, #32
 8002858:	2801      	cmp	r0, #1
 800285a:	bf08      	it	eq
 800285c:	3220      	addeq	r2, #32
 800285e:	1a98      	subs	r0, r3, r2
 8002860:	d101      	bne.n	8002866 <strcasecmp+0x2e>
 8002862:	2a00      	cmp	r2, #0
 8002864:	d1eb      	bne.n	800283e <strcasecmp+0x6>
 8002866:	bd30      	pop	{r4, r5, pc}
 8002868:	08002b4d 	.word	0x08002b4d

0800286c <_init>:
 800286c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800286e:	bf00      	nop
 8002870:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8002872:	bc08      	pop	{r3}
 8002874:	469e      	mov	lr, r3
 8002876:	4770      	bx	lr

08002878 <_fini>:
 8002878:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 800287a:	bf00      	nop
 800287c:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800287e:	bc08      	pop	{r3}
 8002880:	469e      	mov	lr, r3
 8002882:	4770      	bx	lr
 8002884:	0000      	movs	r0, r0
	...
