
/home/jenkins/workspace/RUI_Release/rui-v3/image/RUI_5.0.1_RAK3172-E_bl:     file format elf32-littlearm


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
 8000158:	08002884 	.word	0x08002884

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
 8000174:	08002884 	.word	0x08002884

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
 800018c:	f002 fb7a 	bl	8002884 <_init>
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
 80001b0:	08002c48 	.word	0x08002c48
 80001b4:	08002c48 	.word	0x08002c48
 80001b8:	08002c48 	.word	0x08002c48
 80001bc:	08002c4c 	.word	0x08002c4c

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
 80001e6:	f002 fa51 	bl	800268c <HAL_UART_Receive_IT>
 80001ea:	2800      	cmp	r0, #0
 80001ec:	d063      	beq.n	80002b6 <at_process+0xe6>
 80001ee:	4862      	ldr	r0, [pc, #392]	; (8000378 <at_process+0x1a8>)
 80001f0:	f000 fa24 	bl	800063c <Serial_PutString>
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
 8000250:	f03b f942 	bl	803b4d8 <memcmp>
 8000254:	2800      	cmp	r0, #0
 8000256:	d0d0      	beq.n	80001fa <at_process+0x2a>
 8000258:	2203      	movs	r2, #3
 800025a:	494c      	ldr	r1, [pc, #304]	; (800038c <at_process+0x1bc>)
 800025c:	a802      	add	r0, sp, #8
 800025e:	f03b f93b 	bl	803b4d8 <memcmp>
 8000262:	b908      	cbnz	r0, 8000268 <at_process+0x98>
 8000264:	2501      	movs	r5, #1
 8000266:	e7c9      	b.n	80001fc <at_process+0x2c>
 8000268:	2400      	movs	r4, #0
 800026a:	e7c7      	b.n	80001fc <at_process+0x2c>
 800026c:	f02f fd7e 	bl	802fd6c <LoRaMacProcess>
 8000270:	f01f ffa4 	bl	80201bc <LmHandlerPackagesProcess>
 8000274:	e7c9      	b.n	800020a <at_process+0x3a>
 8000276:	3c01      	subs	r4, #1
 8000278:	ab12      	add	r3, sp, #72	; 0x48
 800027a:	441c      	add	r4, r3
 800027c:	2300      	movs	r3, #0
 800027e:	f804 3c40 	strb.w	r3, [r4, #-64]
 8000282:	4943      	ldr	r1, [pc, #268]	; (8000390 <at_process+0x1c0>)
 8000284:	a802      	add	r0, sp, #8
 8000286:	f002 fae3 	bl	8002850 <strcasecmp>
 800028a:	b148      	cbz	r0, 80002a0 <at_process+0xd0>
 800028c:	4941      	ldr	r1, [pc, #260]	; (8000394 <at_process+0x1c4>)
 800028e:	a802      	add	r0, sp, #8
 8000290:	f002 fade 	bl	8002850 <strcasecmp>
 8000294:	b120      	cbz	r0, 80002a0 <at_process+0xd0>
 8000296:	4940      	ldr	r1, [pc, #256]	; (8000398 <at_process+0x1c8>)
 8000298:	a802      	add	r0, sp, #8
 800029a:	f002 fad9 	bl	8002850 <strcasecmp>
 800029e:	b968      	cbnz	r0, 80002bc <at_process+0xec>
 80002a0:	483e      	ldr	r0, [pc, #248]	; (800039c <at_process+0x1cc>)
 80002a2:	f000 f9cb 	bl	800063c <Serial_PutString>
 80002a6:	483e      	ldr	r0, [pc, #248]	; (80003a0 <at_process+0x1d0>)
 80002a8:	f000 f9c8 	bl	800063c <Serial_PutString>
 80002ac:	2240      	movs	r2, #64	; 0x40
 80002ae:	2100      	movs	r1, #0
 80002b0:	a802      	add	r0, sp, #8
 80002b2:	f7ff ff85 	bl	80001c0 <memset>
 80002b6:	2500      	movs	r5, #0
 80002b8:	462c      	mov	r4, r5
 80002ba:	e7a8      	b.n	800020e <at_process+0x3e>
 80002bc:	4939      	ldr	r1, [pc, #228]	; (80003a4 <at_process+0x1d4>)
 80002be:	a802      	add	r0, sp, #8
 80002c0:	f002 fac6 	bl	8002850 <strcasecmp>
 80002c4:	b1e8      	cbz	r0, 8000302 <at_process+0x132>
 80002c6:	4938      	ldr	r1, [pc, #224]	; (80003a8 <at_process+0x1d8>)
 80002c8:	a802      	add	r0, sp, #8
 80002ca:	f002 fac1 	bl	8002850 <strcasecmp>
 80002ce:	b328      	cbz	r0, 800031c <at_process+0x14c>
 80002d0:	4936      	ldr	r1, [pc, #216]	; (80003ac <at_process+0x1dc>)
 80002d2:	a802      	add	r0, sp, #8
 80002d4:	f002 fabc 	bl	8002850 <strcasecmp>
 80002d8:	b348      	cbz	r0, 800032e <at_process+0x15e>
 80002da:	4935      	ldr	r1, [pc, #212]	; (80003b0 <at_process+0x1e0>)
 80002dc:	a802      	add	r0, sp, #8
 80002de:	f002 fab7 	bl	8002850 <strcasecmp>
 80002e2:	2800      	cmp	r0, #0
 80002e4:	d030      	beq.n	8000348 <at_process+0x178>
 80002e6:	4933      	ldr	r1, [pc, #204]	; (80003b4 <at_process+0x1e4>)
 80002e8:	a802      	add	r0, sp, #8
 80002ea:	f002 fab1 	bl	8002850 <strcasecmp>
 80002ee:	b378      	cbz	r0, 8000350 <at_process+0x180>
 80002f0:	4931      	ldr	r1, [pc, #196]	; (80003b8 <at_process+0x1e8>)
 80002f2:	a802      	add	r0, sp, #8
 80002f4:	f002 faac 	bl	8002850 <strcasecmp>
 80002f8:	2800      	cmp	r0, #0
 80002fa:	d134      	bne.n	8000366 <at_process+0x196>
 80002fc:	f01f fb16 	bl	801f92c <service_lora_fuota_join>
 8000300:	e7d4      	b.n	80002ac <at_process+0xdc>
 8000302:	4b2e      	ldr	r3, [pc, #184]	; (80003bc <at_process+0x1ec>)
 8000304:	2201      	movs	r2, #1
 8000306:	701a      	strb	r2, [r3, #0]
 8000308:	f04f 3101 	mov.w	r1, #16843009	; 0x1010101
 800030c:	482c      	ldr	r0, [pc, #176]	; (80003c0 <at_process+0x1f0>)
 800030e:	f000 fa4d 	bl	80007ac <HAL_FLASH_Program_Flag>
 8000312:	4818      	ldr	r0, [pc, #96]	; (8000374 <at_process+0x1a4>)
 8000314:	f001 f910 	bl	8001538 <HAL_UART_AbortReceive_IT>
 8000318:	b013      	add	sp, #76	; 0x4c
 800031a:	bd30      	pop	{r4, r5, pc}
 800031c:	4829      	ldr	r0, [pc, #164]	; (80003c4 <at_process+0x1f4>)
 800031e:	f000 f98d 	bl	800063c <Serial_PutString>
 8000322:	f000 fa9f 	bl	8000864 <app_jump>
 8000326:	4828      	ldr	r0, [pc, #160]	; (80003c8 <at_process+0x1f8>)
 8000328:	f000 f988 	bl	800063c <Serial_PutString>
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
 800034a:	f000 f977 	bl	800063c <Serial_PutString>
 800034e:	e7ad      	b.n	80002ac <at_process+0xdc>
 8000350:	4821      	ldr	r0, [pc, #132]	; (80003d8 <at_process+0x208>)
 8000352:	f000 f973 	bl	800063c <Serial_PutString>
 8000356:	f000 ffa1 	bl	800129c <bootloader_fuota_start>
 800035a:	2301      	movs	r3, #1
 800035c:	4a08      	ldr	r2, [pc, #32]	; (8000380 <at_process+0x1b0>)
 800035e:	7013      	strb	r3, [r2, #0]
 8000360:	4a1e      	ldr	r2, [pc, #120]	; (80003dc <at_process+0x20c>)
 8000362:	7013      	strb	r3, [r2, #0]
 8000364:	e7a2      	b.n	80002ac <at_process+0xdc>
 8000366:	481e      	ldr	r0, [pc, #120]	; (80003e0 <at_process+0x210>)
 8000368:	f000 f968 	bl	800063c <Serial_PutString>
 800036c:	e79e      	b.n	80002ac <at_process+0xdc>
 800036e:	bf00      	nop
 8000370:	20006086 	.word	0x20006086
 8000374:	200060d4 	.word	0x200060d4
 8000378:	080028b8 	.word	0x080028b8
 800037c:	20006088 	.word	0x20006088
 8000380:	20006084 	.word	0x20006084
 8000384:	080028a0 	.word	0x080028a0
 8000388:	080028b0 	.word	0x080028b0
 800038c:	080028b4 	.word	0x080028b4
 8000390:	080028d4 	.word	0x080028d4
 8000394:	080028e0 	.word	0x080028e0
 8000398:	080028ec 	.word	0x080028ec
 800039c:	08005000 	.word	0x08005000
 80003a0:	08002a88 	.word	0x08002a88
 80003a4:	080028fc 	.word	0x080028fc
 80003a8:	08002908 	.word	0x08002908
 80003ac:	08002954 	.word	0x08002954
 80003b0:	08002960 	.word	0x08002960
 80003b4:	0800297c 	.word	0x0800297c
 80003b8:	08002998 	.word	0x08002998
 80003bc:	20006087 	.word	0x20006087
 80003c0:	08004004 	.word	0x08004004
 80003c4:	08002910 	.word	0x08002910
 80003c8:	08002924 	.word	0x08002924
 80003cc:	e000ed00 	.word	0xe000ed00
 80003d0:	05fa0004 	.word	0x05fa0004
 80003d4:	08002970 	.word	0x08002970
 80003d8:	08002988 	.word	0x08002988
 80003dc:	20006085 	.word	0x20006085
 80003e0:	080029a0 	.word	0x080029a0

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
 80003f8:	f000 fa0a 	bl	8000810 <SerialDownload>
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
 8000420:	f028 f808 	bl	8028434 <HAL_PWR_EnableBkUpAccess>
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
 8000472:	f025 fc91 	bl	8025d98 <HAL_RCC_OscConfig>
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
 800048c:	f025 ff26 	bl	80262dc <HAL_RCC_ClockConfig>
 8000490:	b918      	cbnz	r0, 800049a <SystemClock_Config+0x96>
 8000492:	b01a      	add	sp, #104	; 0x68
 8000494:	bd10      	pop	{r4, pc}
 8000496:	f021 f8e3 	bl	8021660 <Error_Handler>
 800049a:	f021 f8e1 	bl	8021660 <Error_Handler>
	...

080004a0 <main>:
 80004a0:	b508      	push	{r3, lr}
 80004a2:	4b23      	ldr	r3, [pc, #140]	; (8000530 <main+0x90>)
 80004a4:	685b      	ldr	r3, [r3, #4]
 80004a6:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 80004aa:	d120      	bne.n	80004ee <main+0x4e>
 80004ac:	4b21      	ldr	r3, [pc, #132]	; (8000534 <main+0x94>)
 80004ae:	f04f 6200 	mov.w	r2, #134217728	; 0x8000000
 80004b2:	609a      	str	r2, [r3, #8]
 80004b4:	4b20      	ldr	r3, [pc, #128]	; (8000538 <main+0x98>)
 80004b6:	2201      	movs	r2, #1
 80004b8:	701a      	strb	r2, [r3, #0]
 80004ba:	4b20      	ldr	r3, [pc, #128]	; (800053c <main+0x9c>)
 80004bc:	2200      	movs	r2, #0
 80004be:	701a      	strb	r2, [r3, #0]
 80004c0:	f000 fa64 	bl	800098c <MX_USART2_UART_Init>
 80004c4:	4b1a      	ldr	r3, [pc, #104]	; (8000530 <main+0x90>)
 80004c6:	681b      	ldr	r3, [r3, #0]
 80004c8:	f1b3 3f5a 	cmp.w	r3, #1515870810	; 0x5a5a5a5a
 80004cc:	d016      	beq.n	80004fc <main+0x5c>
 80004ce:	4b18      	ldr	r3, [pc, #96]	; (8000530 <main+0x90>)
 80004d0:	681b      	ldr	r3, [r3, #0]
 80004d2:	f1b3 3f5a 	cmp.w	r3, #1515870810	; 0x5a5a5a5a
 80004d6:	d122      	bne.n	800051e <main+0x7e>
 80004d8:	4819      	ldr	r0, [pc, #100]	; (8000540 <main+0xa0>)
 80004da:	f000 f8af 	bl	800063c <Serial_PutString>
 80004de:	4b14      	ldr	r3, [pc, #80]	; (8000530 <main+0x90>)
 80004e0:	685b      	ldr	r3, [r3, #4]
 80004e2:	f1b3 3f04 	cmp.w	r3, #67372036	; 0x4040404
 80004e6:	d020      	beq.n	800052a <main+0x8a>
 80004e8:	f7ff ff7c 	bl	80003e4 <IAP_Task>
 80004ec:	e7fc      	b.n	80004e8 <main+0x48>
 80004ee:	f000 fdc9 	bl	8001084 <bootloader_fuota_stack_init>
 80004f2:	f025 f985 	bl	8025800 <HAL_Init>
 80004f6:	f7ff ff85 	bl	8000404 <SystemClock_Config>
 80004fa:	e7e1      	b.n	80004c0 <main+0x20>
 80004fc:	4b11      	ldr	r3, [pc, #68]	; (8000544 <main+0xa4>)
 80004fe:	681a      	ldr	r2, [r3, #0]
 8000500:	4b11      	ldr	r3, [pc, #68]	; (8000548 <main+0xa8>)
 8000502:	4013      	ands	r3, r2
 8000504:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 8000508:	d1e1      	bne.n	80004ce <main+0x2e>
 800050a:	4b09      	ldr	r3, [pc, #36]	; (8000530 <main+0x90>)
 800050c:	685b      	ldr	r3, [r3, #4]
 800050e:	f1b3 3f01 	cmp.w	r3, #16843009	; 0x1010101
 8000512:	d0dc      	beq.n	80004ce <main+0x2e>
 8000514:	f000 f92e 	bl	8000774 <PreJump>
 8000518:	f000 f936 	bl	8000788 <JumpApp>
 800051c:	e7d7      	b.n	80004ce <main+0x2e>
 800051e:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 8000522:	4803      	ldr	r0, [pc, #12]	; (8000530 <main+0x90>)
 8000524:	f000 f942 	bl	80007ac <HAL_FLASH_Program_Flag>
 8000528:	e7d6      	b.n	80004d8 <main+0x38>
 800052a:	f000 fe19 	bl	8001160 <bootloader_fuota_init>
 800052e:	e7db      	b.n	80004e8 <main+0x48>
 8000530:	08004000 	.word	0x08004000
 8000534:	e000ed00 	.word	0xe000ed00
 8000538:	20006084 	.word	0x20006084
 800053c:	20006087 	.word	0x20006087
 8000540:	080029b4 	.word	0x080029b4
 8000544:	08006000 	.word	0x08006000
 8000548:	2ffe0000 	.word	0x2ffe0000

0800054c <Str2Int>:
 800054c:	b510      	push	{r4, lr}
 800054e:	4684      	mov	ip, r0
 8000550:	7803      	ldrb	r3, [r0, #0]
 8000552:	2b30      	cmp	r3, #48	; 0x30
 8000554:	d003      	beq.n	800055e <Str2Int+0x12>
 8000556:	2400      	movs	r4, #0
 8000558:	4620      	mov	r0, r4
 800055a:	4623      	mov	r3, r4
 800055c:	e054      	b.n	8000608 <Str2Int+0xbc>
 800055e:	7843      	ldrb	r3, [r0, #1]
 8000560:	2b78      	cmp	r3, #120	; 0x78
 8000562:	d035      	beq.n	80005d0 <Str2Int+0x84>
 8000564:	2b58      	cmp	r3, #88	; 0x58
 8000566:	d036      	beq.n	80005d6 <Str2Int+0x8a>
 8000568:	2400      	movs	r4, #0
 800056a:	4620      	mov	r0, r4
 800056c:	4623      	mov	r3, r4
 800056e:	e04b      	b.n	8000608 <Str2Int+0xbc>
 8000570:	0124      	lsls	r4, r4, #4
 8000572:	f1a3 0e30 	sub.w	lr, r3, #48	; 0x30
 8000576:	fa5f fe8e 	uxtb.w	lr, lr
 800057a:	f1be 0f09 	cmp.w	lr, #9
 800057e:	d821      	bhi.n	80005c4 <Str2Int+0x78>
 8000580:	3b30      	subs	r3, #48	; 0x30
 8000582:	441c      	add	r4, r3
 8000584:	3001      	adds	r0, #1
 8000586:	280a      	cmp	r0, #10
 8000588:	d815      	bhi.n	80005b6 <Str2Int+0x6a>
 800058a:	f81c 3000 	ldrb.w	r3, [ip, r0]
 800058e:	b193      	cbz	r3, 80005b6 <Str2Int+0x6a>
 8000590:	f1a3 0241 	sub.w	r2, r3, #65	; 0x41
 8000594:	b2d2      	uxtb	r2, r2
 8000596:	2a05      	cmp	r2, #5
 8000598:	d9ea      	bls.n	8000570 <Str2Int+0x24>
 800059a:	f1a3 0e61 	sub.w	lr, r3, #97	; 0x61
 800059e:	fa5f fe8e 	uxtb.w	lr, lr
 80005a2:	f1be 0f05 	cmp.w	lr, #5
 80005a6:	d9e3      	bls.n	8000570 <Str2Int+0x24>
 80005a8:	f1a3 0e30 	sub.w	lr, r3, #48	; 0x30
 80005ac:	fa5f fe8e 	uxtb.w	lr, lr
 80005b0:	f1be 0f09 	cmp.w	lr, #9
 80005b4:	d9dc      	bls.n	8000570 <Str2Int+0x24>
 80005b6:	f81c 3000 	ldrb.w	r3, [ip, r0]
 80005ba:	2b00      	cmp	r3, #0
 80005bc:	d13b      	bne.n	8000636 <Str2Int+0xea>
 80005be:	600c      	str	r4, [r1, #0]
 80005c0:	2001      	movs	r0, #1
 80005c2:	bd10      	pop	{r4, pc}
 80005c4:	2a05      	cmp	r2, #5
 80005c6:	d801      	bhi.n	80005cc <Str2Int+0x80>
 80005c8:	3b37      	subs	r3, #55	; 0x37
 80005ca:	e7da      	b.n	8000582 <Str2Int+0x36>
 80005cc:	3b57      	subs	r3, #87	; 0x57
 80005ce:	e7d8      	b.n	8000582 <Str2Int+0x36>
 80005d0:	2400      	movs	r4, #0
 80005d2:	2002      	movs	r0, #2
 80005d4:	e7d7      	b.n	8000586 <Str2Int+0x3a>
 80005d6:	2400      	movs	r4, #0
 80005d8:	2002      	movs	r0, #2
 80005da:	e7d4      	b.n	8000586 <Str2Int+0x3a>
 80005dc:	2a6b      	cmp	r2, #107	; 0x6b
 80005de:	d01e      	beq.n	800061e <Str2Int+0xd2>
 80005e0:	2a4b      	cmp	r2, #75	; 0x4b
 80005e2:	d01c      	beq.n	800061e <Str2Int+0xd2>
 80005e4:	2a6d      	cmp	r2, #109	; 0x6d
 80005e6:	d020      	beq.n	800062a <Str2Int+0xde>
 80005e8:	2a4d      	cmp	r2, #77	; 0x4d
 80005ea:	d01e      	beq.n	800062a <Str2Int+0xde>
 80005ec:	f1a2 0e30 	sub.w	lr, r2, #48	; 0x30
 80005f0:	fa5f fe8e 	uxtb.w	lr, lr
 80005f4:	f1be 0f09 	cmp.w	lr, #9
 80005f8:	d8e3      	bhi.n	80005c2 <Str2Int+0x76>
 80005fa:	eb04 0484 	add.w	r4, r4, r4, lsl #2
 80005fe:	eb02 0244 	add.w	r2, r2, r4, lsl #1
 8000602:	f1a2 0430 	sub.w	r4, r2, #48	; 0x30
 8000606:	3301      	adds	r3, #1
 8000608:	2b0a      	cmp	r3, #10
 800060a:	d8da      	bhi.n	80005c2 <Str2Int+0x76>
 800060c:	2800      	cmp	r0, #0
 800060e:	d1d8      	bne.n	80005c2 <Str2Int+0x76>
 8000610:	f81c 2003 	ldrb.w	r2, [ip, r3]
 8000614:	2a00      	cmp	r2, #0
 8000616:	d1e1      	bne.n	80005dc <Str2Int+0x90>
 8000618:	600c      	str	r4, [r1, #0]
 800061a:	2001      	movs	r0, #1
 800061c:	e7f3      	b.n	8000606 <Str2Int+0xba>
 800061e:	2b00      	cmp	r3, #0
 8000620:	d0e0      	beq.n	80005e4 <Str2Int+0x98>
 8000622:	02a4      	lsls	r4, r4, #10
 8000624:	600c      	str	r4, [r1, #0]
 8000626:	2001      	movs	r0, #1
 8000628:	e7ed      	b.n	8000606 <Str2Int+0xba>
 800062a:	2b00      	cmp	r3, #0
 800062c:	d0de      	beq.n	80005ec <Str2Int+0xa0>
 800062e:	0524      	lsls	r4, r4, #20
 8000630:	600c      	str	r4, [r1, #0]
 8000632:	2001      	movs	r0, #1
 8000634:	e7e7      	b.n	8000606 <Str2Int+0xba>
 8000636:	2000      	movs	r0, #0
 8000638:	e7c3      	b.n	80005c2 <Str2Int+0x76>
	...

0800063c <Serial_PutString>:
 800063c:	b508      	push	{r3, lr}
 800063e:	4601      	mov	r1, r0
 8000640:	2200      	movs	r2, #0
 8000642:	e001      	b.n	8000648 <Serial_PutString+0xc>
 8000644:	3201      	adds	r2, #1
 8000646:	b292      	uxth	r2, r2
 8000648:	5c8b      	ldrb	r3, [r1, r2]
 800064a:	2b00      	cmp	r3, #0
 800064c:	d1fa      	bne.n	8000644 <Serial_PutString+0x8>
 800064e:	2364      	movs	r3, #100	; 0x64
 8000650:	4801      	ldr	r0, [pc, #4]	; (8000658 <Serial_PutString+0x1c>)
 8000652:	f001 fe14 	bl	800227e <HAL_UART_Transmit>
 8000656:	bd08      	pop	{r3, pc}
 8000658:	200060d4 	.word	0x200060d4

0800065c <Serial_PutByte>:
 800065c:	b500      	push	{lr}
 800065e:	b083      	sub	sp, #12
 8000660:	f88d 0007 	strb.w	r0, [sp, #7]
 8000664:	4b09      	ldr	r3, [pc, #36]	; (800068c <Serial_PutByte+0x30>)
 8000666:	f8d3 3084 	ldr.w	r3, [r3, #132]	; 0x84
 800066a:	2ba0      	cmp	r3, #160	; 0xa0
 800066c:	d009      	beq.n	8000682 <Serial_PutByte+0x26>
 800066e:	2364      	movs	r3, #100	; 0x64
 8000670:	2201      	movs	r2, #1
 8000672:	f10d 0107 	add.w	r1, sp, #7
 8000676:	4805      	ldr	r0, [pc, #20]	; (800068c <Serial_PutByte+0x30>)
 8000678:	f001 fe01 	bl	800227e <HAL_UART_Transmit>
 800067c:	b003      	add	sp, #12
 800067e:	f85d fb04 	ldr.w	pc, [sp], #4
 8000682:	4b02      	ldr	r3, [pc, #8]	; (800068c <Serial_PutByte+0x30>)
 8000684:	2220      	movs	r2, #32
 8000686:	f8c3 2084 	str.w	r2, [r3, #132]	; 0x84
 800068a:	e7f0      	b.n	800066e <Serial_PutByte+0x12>
 800068c:	200060d4 	.word	0x200060d4

08000690 <Serial_Printf>:
 8000690:	b40f      	push	{r0, r1, r2, r3}
 8000692:	b500      	push	{lr}
 8000694:	f5ad 7d03 	sub.w	sp, sp, #524	; 0x20c
 8000698:	ab84      	add	r3, sp, #528	; 0x210
 800069a:	f853 2b04 	ldr.w	r2, [r3], #4
 800069e:	9301      	str	r3, [sp, #4]
 80006a0:	f44f 7100 	mov.w	r1, #512	; 0x200
 80006a4:	a802      	add	r0, sp, #8
 80006a6:	f024 fd57 	bl	8025158 <tiny_vsnprintf_like>
 80006aa:	a802      	add	r0, sp, #8
 80006ac:	f01d fca8 	bl	801e000 <strlen>
 80006b0:	2364      	movs	r3, #100	; 0x64
 80006b2:	b282      	uxth	r2, r0
 80006b4:	a902      	add	r1, sp, #8
 80006b6:	4804      	ldr	r0, [pc, #16]	; (80006c8 <Serial_Printf+0x38>)
 80006b8:	f001 fde1 	bl	800227e <HAL_UART_Transmit>
 80006bc:	f50d 7d03 	add.w	sp, sp, #524	; 0x20c
 80006c0:	f85d eb04 	ldr.w	lr, [sp], #4
 80006c4:	b004      	add	sp, #16
 80006c6:	4770      	bx	lr
 80006c8:	200060d4 	.word	0x200060d4

080006cc <GetPage>:
 80006cc:	f100 4078 	add.w	r0, r0, #4160749568	; 0xf8000000
 80006d0:	0ac0      	lsrs	r0, r0, #11
 80006d2:	4770      	bx	lr

080006d4 <FLASH_If_Erase>:
 80006d4:	b510      	push	{r4, lr}
 80006d6:	b084      	sub	sp, #16
 80006d8:	4604      	mov	r4, r0
 80006da:	2300      	movs	r3, #0
 80006dc:	9303      	str	r3, [sp, #12]
 80006de:	f028 fa83 	bl	8028be8 <HAL_FLASH_Unlock>
 80006e2:	4b0e      	ldr	r3, [pc, #56]	; (800071c <FLASH_If_Erase+0x48>)
 80006e4:	f44f 4200 	mov.w	r2, #32768	; 0x8000
 80006e8:	611a      	str	r2, [r3, #16]
 80006ea:	4620      	mov	r0, r4
 80006ec:	f7ff ffee 	bl	80006cc <GetPage>
 80006f0:	f1c4 6300 	rsb	r3, r4, #134217728	; 0x8000000
 80006f4:	f503 33e8 	add.w	r3, r3, #118784	; 0x1d000
 80006f8:	0adb      	lsrs	r3, r3, #11
 80006fa:	2202      	movs	r2, #2
 80006fc:	9200      	str	r2, [sp, #0]
 80006fe:	9001      	str	r0, [sp, #4]
 8000700:	9302      	str	r3, [sp, #8]
 8000702:	a903      	add	r1, sp, #12
 8000704:	4668      	mov	r0, sp
 8000706:	f028 fc83 	bl	8029010 <HAL_FLASHEx_Erase>
 800070a:	b928      	cbnz	r0, 8000718 <FLASH_If_Erase+0x44>
 800070c:	2400      	movs	r4, #0
 800070e:	f028 fa7d 	bl	8028c0c <HAL_FLASH_Lock>
 8000712:	4620      	mov	r0, r4
 8000714:	b004      	add	sp, #16
 8000716:	bd10      	pop	{r4, pc}
 8000718:	2401      	movs	r4, #1
 800071a:	e7f8      	b.n	800070e <FLASH_If_Erase+0x3a>
 800071c:	58004000 	.word	0x58004000

08000720 <FLASH_If_Write>:
 8000720:	b5f0      	push	{r4, r5, r6, r7, lr}
 8000722:	b083      	sub	sp, #12
 8000724:	4605      	mov	r5, r0
 8000726:	460c      	mov	r4, r1
 8000728:	4617      	mov	r7, r2
 800072a:	f028 fa5d 	bl	8028be8 <HAL_FLASH_Unlock>
 800072e:	2600      	movs	r6, #0
 8000730:	e002      	b.n	8000738 <FLASH_If_Write+0x18>
 8000732:	3508      	adds	r5, #8
 8000734:	3408      	adds	r4, #8
 8000736:	3602      	adds	r6, #2
 8000738:	42be      	cmp	r6, r7
 800073a:	d215      	bcs.n	8000768 <FLASH_If_Write+0x48>
 800073c:	466b      	mov	r3, sp
 800073e:	6820      	ldr	r0, [r4, #0]
 8000740:	6861      	ldr	r1, [r4, #4]
 8000742:	c303      	stmia	r3!, {r0, r1}
 8000744:	e9dd 2300 	ldrd	r2, r3, [sp]
 8000748:	4629      	mov	r1, r5
 800074a:	2001      	movs	r0, #1
 800074c:	f028 faca 	bl	8028ce4 <HAL_FLASH_Program>
 8000750:	2800      	cmp	r0, #0
 8000752:	d1f0      	bne.n	8000736 <FLASH_If_Write+0x16>
 8000754:	6828      	ldr	r0, [r5, #0]
 8000756:	686a      	ldr	r2, [r5, #4]
 8000758:	9900      	ldr	r1, [sp, #0]
 800075a:	9b01      	ldr	r3, [sp, #4]
 800075c:	429a      	cmp	r2, r3
 800075e:	bf08      	it	eq
 8000760:	4288      	cmpeq	r0, r1
 8000762:	d0e6      	beq.n	8000732 <FLASH_If_Write+0x12>
 8000764:	2403      	movs	r4, #3
 8000766:	e000      	b.n	800076a <FLASH_If_Write+0x4a>
 8000768:	2400      	movs	r4, #0
 800076a:	f028 fa4f 	bl	8028c0c <HAL_FLASH_Lock>
 800076e:	4620      	mov	r0, r4
 8000770:	b003      	add	sp, #12
 8000772:	bdf0      	pop	{r4, r5, r6, r7, pc}

08000774 <PreJump>:
 8000774:	b508      	push	{r3, lr}
 8000776:	4803      	ldr	r0, [pc, #12]	; (8000784 <PreJump+0x10>)
 8000778:	f000 fe9d 	bl	80014b6 <HAL_UART_DeInit>
 800077c:	f024 fff4 	bl	8025768 <HAL_DeInit>
 8000780:	bd08      	pop	{r3, pc}
 8000782:	bf00      	nop
 8000784:	200060d4 	.word	0x200060d4

08000788 <JumpApp>:
 8000788:	b508      	push	{r3, lr}
 800078a:	4a05      	ldr	r2, [pc, #20]	; (80007a0 <JumpApp+0x18>)
 800078c:	6853      	ldr	r3, [r2, #4]
 800078e:	4905      	ldr	r1, [pc, #20]	; (80007a4 <JumpApp+0x1c>)
 8000790:	600b      	str	r3, [r1, #0]
 8000792:	4905      	ldr	r1, [pc, #20]	; (80007a8 <JumpApp+0x20>)
 8000794:	600b      	str	r3, [r1, #0]
 8000796:	6812      	ldr	r2, [r2, #0]
 8000798:	f382 8808 	msr	MSP, r2
 800079c:	4798      	blx	r3
 800079e:	bd08      	pop	{r3, pc}
 80007a0:	08006000 	.word	0x08006000
 80007a4:	2000608c 	.word	0x2000608c
 80007a8:	20006090 	.word	0x20006090

080007ac <HAL_FLASH_Program_Flag>:
 80007ac:	b570      	push	{r4, r5, r6, lr}
 80007ae:	b088      	sub	sp, #32
 80007b0:	4604      	mov	r4, r0
 80007b2:	460d      	mov	r5, r1
 80007b4:	2300      	movs	r3, #0
 80007b6:	9307      	str	r3, [sp, #28]
 80007b8:	4e13      	ldr	r6, [pc, #76]	; (8000808 <HAL_FLASH_Program_Flag+0x5c>)
 80007ba:	e9d6 2300 	ldrd	r2, r3, [r6]
 80007be:	e9cd 2304 	strd	r2, r3, [sp, #16]
 80007c2:	f028 fa11 	bl	8028be8 <HAL_FLASH_Unlock>
 80007c6:	4b11      	ldr	r3, [pc, #68]	; (800080c <HAL_FLASH_Program_Flag+0x60>)
 80007c8:	f44f 4200 	mov.w	r2, #32768	; 0x8000
 80007cc:	611a      	str	r2, [r3, #16]
 80007ce:	4630      	mov	r0, r6
 80007d0:	f7ff ff7c 	bl	80006cc <GetPage>
 80007d4:	2302      	movs	r3, #2
 80007d6:	9301      	str	r3, [sp, #4]
 80007d8:	9002      	str	r0, [sp, #8]
 80007da:	2301      	movs	r3, #1
 80007dc:	9303      	str	r3, [sp, #12]
 80007de:	a907      	add	r1, sp, #28
 80007e0:	a801      	add	r0, sp, #4
 80007e2:	f028 fc15 	bl	8029010 <HAL_FLASHEx_Erase>
 80007e6:	b950      	cbnz	r0, 80007fe <HAL_FLASH_Program_Flag+0x52>
 80007e8:	42b4      	cmp	r4, r6
 80007ea:	d00a      	beq.n	8000802 <HAL_FLASH_Program_Flag+0x56>
 80007ec:	9505      	str	r5, [sp, #20]
 80007ee:	e9dd 2304 	ldrd	r2, r3, [sp, #16]
 80007f2:	4905      	ldr	r1, [pc, #20]	; (8000808 <HAL_FLASH_Program_Flag+0x5c>)
 80007f4:	2001      	movs	r0, #1
 80007f6:	f028 fa75 	bl	8028ce4 <HAL_FLASH_Program>
 80007fa:	f028 fa07 	bl	8028c0c <HAL_FLASH_Lock>
 80007fe:	b008      	add	sp, #32
 8000800:	bd70      	pop	{r4, r5, r6, pc}
 8000802:	9504      	str	r5, [sp, #16]
 8000804:	e7f3      	b.n	80007ee <HAL_FLASH_Program_Flag+0x42>
 8000806:	bf00      	nop
 8000808:	08004000 	.word	0x08004000
 800080c:	58004000 	.word	0x58004000

08000810 <SerialDownload>:
 8000810:	b500      	push	{lr}
 8000812:	b083      	sub	sp, #12
 8000814:	2300      	movs	r3, #0
 8000816:	9301      	str	r3, [sp, #4]
 8000818:	a801      	add	r0, sp, #4
 800081a:	f000 fa35 	bl	8000c88 <Ymodem_Receive>
 800081e:	b110      	cbz	r0, 8000826 <SerialDownload+0x16>
 8000820:	b003      	add	sp, #12
 8000822:	f85d fb04 	ldr.w	pc, [sp], #4
 8000826:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 800082a:	480a      	ldr	r0, [pc, #40]	; (8000854 <SerialDownload+0x44>)
 800082c:	f7ff ffbe 	bl	80007ac <HAL_FLASH_Program_Flag>
 8000830:	f04f 3102 	mov.w	r1, #33686018	; 0x2020202
 8000834:	4808      	ldr	r0, [pc, #32]	; (8000858 <SerialDownload+0x48>)
 8000836:	f7ff ffb9 	bl	80007ac <HAL_FLASH_Program_Flag>
 800083a:	4b08      	ldr	r3, [pc, #32]	; (800085c <SerialDownload+0x4c>)
 800083c:	681a      	ldr	r2, [r3, #0]
 800083e:	4b08      	ldr	r3, [pc, #32]	; (8000860 <SerialDownload+0x50>)
 8000840:	4013      	ands	r3, r2
 8000842:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 8000846:	d1eb      	bne.n	8000820 <SerialDownload+0x10>
 8000848:	f7ff ff94 	bl	8000774 <PreJump>
 800084c:	f7ff ff9c 	bl	8000788 <JumpApp>
 8000850:	e7e6      	b.n	8000820 <SerialDownload+0x10>
 8000852:	bf00      	nop
 8000854:	08004000 	.word	0x08004000
 8000858:	08004004 	.word	0x08004004
 800085c:	08006000 	.word	0x08006000
 8000860:	2ffe0000 	.word	0x2ffe0000

08000864 <app_jump>:
 8000864:	b508      	push	{r3, lr}
 8000866:	f04f 315a 	mov.w	r1, #1515870810	; 0x5a5a5a5a
 800086a:	480a      	ldr	r0, [pc, #40]	; (8000894 <app_jump+0x30>)
 800086c:	f7ff ff9e 	bl	80007ac <HAL_FLASH_Program_Flag>
 8000870:	4b09      	ldr	r3, [pc, #36]	; (8000898 <app_jump+0x34>)
 8000872:	681a      	ldr	r2, [r3, #0]
 8000874:	4b09      	ldr	r3, [pc, #36]	; (800089c <app_jump+0x38>)
 8000876:	4013      	ands	r3, r2
 8000878:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 800087c:	d000      	beq.n	8000880 <app_jump+0x1c>
 800087e:	bd08      	pop	{r3, pc}
 8000880:	4b04      	ldr	r3, [pc, #16]	; (8000894 <app_jump+0x30>)
 8000882:	685b      	ldr	r3, [r3, #4]
 8000884:	f1b3 3f01 	cmp.w	r3, #16843009	; 0x1010101
 8000888:	d0f9      	beq.n	800087e <app_jump+0x1a>
 800088a:	f7ff ff73 	bl	8000774 <PreJump>
 800088e:	f7ff ff7b 	bl	8000788 <JumpApp>
 8000892:	e7f4      	b.n	800087e <app_jump+0x1a>
 8000894:	08004000 	.word	0x08004000
 8000898:	08006000 	.word	0x08006000
 800089c:	2ffe0000 	.word	0x2ffe0000

080008a0 <NMI_Handler>:
 80008a0:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 80008a4:	6b9a      	ldr	r2, [r3, #56]	; 0x38
 80008a6:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
 80008aa:	6399      	str	r1, [r3, #56]	; 0x38
 80008ac:	6bda      	ldr	r2, [r3, #60]	; 0x3c
 80008ae:	63d9      	str	r1, [r3, #60]	; 0x3c
 80008b0:	6b9a      	ldr	r2, [r3, #56]	; 0x38
 80008b2:	2200      	movs	r2, #0
 80008b4:	639a      	str	r2, [r3, #56]	; 0x38
 80008b6:	6bd8      	ldr	r0, [r3, #60]	; 0x3c
 80008b8:	63da      	str	r2, [r3, #60]	; 0x3c
 80008ba:	6c18      	ldr	r0, [r3, #64]	; 0x40
 80008bc:	6419      	str	r1, [r3, #64]	; 0x40
 80008be:	6c18      	ldr	r0, [r3, #64]	; 0x40
 80008c0:	641a      	str	r2, [r3, #64]	; 0x40
 80008c2:	6c58      	ldr	r0, [r3, #68]	; 0x44
 80008c4:	6459      	str	r1, [r3, #68]	; 0x44
 80008c6:	6c58      	ldr	r0, [r3, #68]	; 0x44
 80008c8:	645a      	str	r2, [r3, #68]	; 0x44
 80008ca:	6a98      	ldr	r0, [r3, #40]	; 0x28
 80008cc:	6299      	str	r1, [r3, #40]	; 0x28
 80008ce:	6a98      	ldr	r0, [r3, #40]	; 0x28
 80008d0:	629a      	str	r2, [r3, #40]	; 0x28
 80008d2:	6ad8      	ldr	r0, [r3, #44]	; 0x2c
 80008d4:	62d9      	str	r1, [r3, #44]	; 0x2c
 80008d6:	6ad8      	ldr	r0, [r3, #44]	; 0x2c
 80008d8:	62da      	str	r2, [r3, #44]	; 0x2c
 80008da:	6b18      	ldr	r0, [r3, #48]	; 0x30
 80008dc:	6319      	str	r1, [r3, #48]	; 0x30
 80008de:	6b19      	ldr	r1, [r3, #48]	; 0x30
 80008e0:	631a      	str	r2, [r3, #48]	; 0x30
 80008e2:	6c5a      	ldr	r2, [r3, #68]	; 0x44
 80008e4:	f042 0201 	orr.w	r2, r2, #1
 80008e8:	645a      	str	r2, [r3, #68]	; 0x44
 80008ea:	6c5a      	ldr	r2, [r3, #68]	; 0x44
 80008ec:	f022 0201 	bic.w	r2, r2, #1
 80008f0:	645a      	str	r2, [r3, #68]	; 0x44
 80008f2:	f8d3 2090 	ldr.w	r2, [r3, #144]	; 0x90
 80008f6:	f442 3280 	orr.w	r2, r2, #65536	; 0x10000
 80008fa:	f8c3 2090 	str.w	r2, [r3, #144]	; 0x90
 80008fe:	f8d3 2090 	ldr.w	r2, [r3, #144]	; 0x90
 8000902:	f422 3280 	bic.w	r2, r2, #65536	; 0x10000
 8000906:	f8c3 2090 	str.w	r2, [r3, #144]	; 0x90
 800090a:	f3bf 8f4f 	dsb	sy
 800090e:	4905      	ldr	r1, [pc, #20]	; (8000924 <NMI_Handler+0x84>)
 8000910:	68ca      	ldr	r2, [r1, #12]
 8000912:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000916:	4b04      	ldr	r3, [pc, #16]	; (8000928 <NMI_Handler+0x88>)
 8000918:	4313      	orrs	r3, r2
 800091a:	60cb      	str	r3, [r1, #12]
 800091c:	f3bf 8f4f 	dsb	sy
 8000920:	bf00      	nop
 8000922:	e7fd      	b.n	8000920 <NMI_Handler+0x80>
 8000924:	e000ed00 	.word	0xe000ed00
 8000928:	05fa0004 	.word	0x05fa0004

0800092c <HardFault_Handler>:
 800092c:	4770      	bx	lr

0800092e <MemManage_Handler>:
 800092e:	4770      	bx	lr

08000930 <BusFault_Handler>:
 8000930:	4770      	bx	lr

08000932 <UsageFault_Handler>:
 8000932:	e7fe      	b.n	8000932 <UsageFault_Handler>

08000934 <SVC_Handler>:
 8000934:	4770      	bx	lr

08000936 <DebugMon_Handler>:
 8000936:	4770      	bx	lr

08000938 <PendSV_Handler>:
 8000938:	4770      	bx	lr

0800093a <SysTick_Handler>:
 800093a:	b508      	push	{r3, lr}
 800093c:	f024 ff76 	bl	802582c <HAL_IncTick>
 8000940:	f024 ff80 	bl	8025844 <HAL_GetTick>
 8000944:	f000 fa78 	bl	8000e38 <upgrade_process_callback>
 8000948:	bd08      	pop	{r3, pc}
	...

0800094c <RTC_Alarm_IRQHandler>:
 800094c:	b508      	push	{r3, lr}
 800094e:	4802      	ldr	r0, [pc, #8]	; (8000958 <RTC_Alarm_IRQHandler+0xc>)
 8000950:	f026 fb62 	bl	8027018 <HAL_RTC_AlarmIRQHandler>
 8000954:	bd08      	pop	{r3, pc}
 8000956:	bf00      	nop
 8000958:	200044d8 	.word	0x200044d8

0800095c <SUBGHZ_Radio_IRQHandler>:
 800095c:	b508      	push	{r3, lr}
 800095e:	4802      	ldr	r0, [pc, #8]	; (8000968 <SUBGHZ_Radio_IRQHandler+0xc>)
 8000960:	f028 fe3f 	bl	80295e2 <HAL_SUBGHZ_IRQHandler>
 8000964:	bd08      	pop	{r3, pc}
 8000966:	bf00      	nop
 8000968:	200002d0 	.word	0x200002d0

0800096c <TAMP_STAMP_LSECSS_SSRU_IRQHandler>:
 800096c:	b508      	push	{r3, lr}
 800096e:	4802      	ldr	r0, [pc, #8]	; (8000978 <TAMP_STAMP_LSECSS_SSRU_IRQHandler+0xc>)
 8000970:	f027 fb8c 	bl	802808c <HAL_RTCEx_SSRUIRQHandler>
 8000974:	bd08      	pop	{r3, pc}
 8000976:	bf00      	nop
 8000978:	200044d8 	.word	0x200044d8

0800097c <USART2_IRQHandler>:
 800097c:	b508      	push	{r3, lr}
 800097e:	4802      	ldr	r0, [pc, #8]	; (8000988 <USART2_IRQHandler+0xc>)
 8000980:	f000 fe58 	bl	8001634 <HAL_UART_IRQHandler>
 8000984:	bd08      	pop	{r3, pc}
 8000986:	bf00      	nop
 8000988:	200060d4 	.word	0x200060d4

0800098c <MX_USART2_UART_Init>:
 800098c:	b508      	push	{r3, lr}
 800098e:	4817      	ldr	r0, [pc, #92]	; (80009ec <MX_USART2_UART_Init+0x60>)
 8000990:	4b17      	ldr	r3, [pc, #92]	; (80009f0 <MX_USART2_UART_Init+0x64>)
 8000992:	6003      	str	r3, [r0, #0]
 8000994:	f44f 33e1 	mov.w	r3, #115200	; 0x1c200
 8000998:	6043      	str	r3, [r0, #4]
 800099a:	2300      	movs	r3, #0
 800099c:	6083      	str	r3, [r0, #8]
 800099e:	60c3      	str	r3, [r0, #12]
 80009a0:	6103      	str	r3, [r0, #16]
 80009a2:	220c      	movs	r2, #12
 80009a4:	6142      	str	r2, [r0, #20]
 80009a6:	6183      	str	r3, [r0, #24]
 80009a8:	61c3      	str	r3, [r0, #28]
 80009aa:	6203      	str	r3, [r0, #32]
 80009ac:	6243      	str	r3, [r0, #36]	; 0x24
 80009ae:	6283      	str	r3, [r0, #40]	; 0x28
 80009b0:	f001 fda4 	bl	80024fc <HAL_UART_Init>
 80009b4:	b970      	cbnz	r0, 80009d4 <MX_USART2_UART_Init+0x48>
 80009b6:	2100      	movs	r1, #0
 80009b8:	480c      	ldr	r0, [pc, #48]	; (80009ec <MX_USART2_UART_Init+0x60>)
 80009ba:	f001 fed5 	bl	8002768 <HAL_UARTEx_SetTxFifoThreshold>
 80009be:	b960      	cbnz	r0, 80009da <MX_USART2_UART_Init+0x4e>
 80009c0:	2100      	movs	r1, #0
 80009c2:	480a      	ldr	r0, [pc, #40]	; (80009ec <MX_USART2_UART_Init+0x60>)
 80009c4:	f001 fef5 	bl	80027b2 <HAL_UARTEx_SetRxFifoThreshold>
 80009c8:	b950      	cbnz	r0, 80009e0 <MX_USART2_UART_Init+0x54>
 80009ca:	4808      	ldr	r0, [pc, #32]	; (80009ec <MX_USART2_UART_Init+0x60>)
 80009cc:	f001 fead 	bl	800272a <HAL_UARTEx_DisableFifoMode>
 80009d0:	b948      	cbnz	r0, 80009e6 <MX_USART2_UART_Init+0x5a>
 80009d2:	bd08      	pop	{r3, pc}
 80009d4:	f020 fe44 	bl	8021660 <Error_Handler>
 80009d8:	e7ed      	b.n	80009b6 <MX_USART2_UART_Init+0x2a>
 80009da:	f020 fe41 	bl	8021660 <Error_Handler>
 80009de:	e7ef      	b.n	80009c0 <MX_USART2_UART_Init+0x34>
 80009e0:	f020 fe3e 	bl	8021660 <Error_Handler>
 80009e4:	e7f1      	b.n	80009ca <MX_USART2_UART_Init+0x3e>
 80009e6:	f020 fe3b 	bl	8021660 <Error_Handler>
 80009ea:	e7f2      	b.n	80009d2 <MX_USART2_UART_Init+0x46>
 80009ec:	200060d4 	.word	0x200060d4
 80009f0:	40004400 	.word	0x40004400

080009f4 <HAL_UART_RxCpltCallback>:
 80009f4:	b508      	push	{r3, lr}
 80009f6:	4b07      	ldr	r3, [pc, #28]	; (8000a14 <HAL_UART_RxCpltCallback+0x20>)
 80009f8:	781b      	ldrb	r3, [r3, #0]
 80009fa:	2b01      	cmp	r3, #1
 80009fc:	d103      	bne.n	8000a06 <HAL_UART_RxCpltCallback+0x12>
 80009fe:	4b06      	ldr	r3, [pc, #24]	; (8000a18 <HAL_UART_RxCpltCallback+0x24>)
 8000a00:	2201      	movs	r2, #1
 8000a02:	701a      	strb	r2, [r3, #0]
 8000a04:	bd08      	pop	{r3, pc}
 8000a06:	2201      	movs	r2, #1
 8000a08:	4904      	ldr	r1, [pc, #16]	; (8000a1c <HAL_UART_RxCpltCallback+0x28>)
 8000a0a:	4805      	ldr	r0, [pc, #20]	; (8000a20 <HAL_UART_RxCpltCallback+0x2c>)
 8000a0c:	f001 fe3e 	bl	800268c <HAL_UART_Receive_IT>
 8000a10:	e7f5      	b.n	80009fe <HAL_UART_RxCpltCallback+0xa>
 8000a12:	bf00      	nop
 8000a14:	20006087 	.word	0x20006087
 8000a18:	20006088 	.word	0x20006088
 8000a1c:	20006086 	.word	0x20006086
 8000a20:	200060d4 	.word	0x200060d4

08000a24 <HAL_UART_MspInit>:
 8000a24:	b510      	push	{r4, lr}
 8000a26:	b096      	sub	sp, #88	; 0x58
 8000a28:	4604      	mov	r4, r0
 8000a2a:	2100      	movs	r1, #0
 8000a2c:	9111      	str	r1, [sp, #68]	; 0x44
 8000a2e:	9112      	str	r1, [sp, #72]	; 0x48
 8000a30:	9113      	str	r1, [sp, #76]	; 0x4c
 8000a32:	9114      	str	r1, [sp, #80]	; 0x50
 8000a34:	9115      	str	r1, [sp, #84]	; 0x54
 8000a36:	2238      	movs	r2, #56	; 0x38
 8000a38:	a803      	add	r0, sp, #12
 8000a3a:	f7ff fbc1 	bl	80001c0 <memset>
 8000a3e:	6822      	ldr	r2, [r4, #0]
 8000a40:	4b1e      	ldr	r3, [pc, #120]	; (8000abc <HAL_UART_MspInit+0x98>)
 8000a42:	429a      	cmp	r2, r3
 8000a44:	d001      	beq.n	8000a4a <HAL_UART_MspInit+0x26>
 8000a46:	b016      	add	sp, #88	; 0x58
 8000a48:	bd10      	pop	{r4, pc}
 8000a4a:	2302      	movs	r3, #2
 8000a4c:	9303      	str	r3, [sp, #12]
 8000a4e:	f44f 2340 	mov.w	r3, #786432	; 0xc0000
 8000a52:	9305      	str	r3, [sp, #20]
 8000a54:	a803      	add	r0, sp, #12
 8000a56:	f025 fe89 	bl	802676c <HAL_RCCEx_PeriphCLKConfig>
 8000a5a:	bb58      	cbnz	r0, 8000ab4 <HAL_UART_MspInit+0x90>
 8000a5c:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 8000a60:	6d9a      	ldr	r2, [r3, #88]	; 0x58
 8000a62:	f442 3200 	orr.w	r2, r2, #131072	; 0x20000
 8000a66:	659a      	str	r2, [r3, #88]	; 0x58
 8000a68:	6d9a      	ldr	r2, [r3, #88]	; 0x58
 8000a6a:	f402 3200 	and.w	r2, r2, #131072	; 0x20000
 8000a6e:	9202      	str	r2, [sp, #8]
 8000a70:	9a02      	ldr	r2, [sp, #8]
 8000a72:	6cda      	ldr	r2, [r3, #76]	; 0x4c
 8000a74:	f042 0201 	orr.w	r2, r2, #1
 8000a78:	64da      	str	r2, [r3, #76]	; 0x4c
 8000a7a:	6cdb      	ldr	r3, [r3, #76]	; 0x4c
 8000a7c:	f003 0301 	and.w	r3, r3, #1
 8000a80:	9301      	str	r3, [sp, #4]
 8000a82:	9b01      	ldr	r3, [sp, #4]
 8000a84:	230c      	movs	r3, #12
 8000a86:	9311      	str	r3, [sp, #68]	; 0x44
 8000a88:	2302      	movs	r3, #2
 8000a8a:	9312      	str	r3, [sp, #72]	; 0x48
 8000a8c:	2301      	movs	r3, #1
 8000a8e:	9313      	str	r3, [sp, #76]	; 0x4c
 8000a90:	2400      	movs	r4, #0
 8000a92:	9414      	str	r4, [sp, #80]	; 0x50
 8000a94:	2307      	movs	r3, #7
 8000a96:	9315      	str	r3, [sp, #84]	; 0x54
 8000a98:	a911      	add	r1, sp, #68	; 0x44
 8000a9a:	f04f 4090 	mov.w	r0, #1207959552	; 0x48000000
 8000a9e:	f028 fe53 	bl	8029748 <HAL_GPIO_Init>
 8000aa2:	4622      	mov	r2, r4
 8000aa4:	4621      	mov	r1, r4
 8000aa6:	2025      	movs	r0, #37	; 0x25
 8000aa8:	f022 f9b0 	bl	8022e0c <HAL_NVIC_SetPriority>
 8000aac:	2025      	movs	r0, #37	; 0x25
 8000aae:	f022 f9df 	bl	8022e70 <HAL_NVIC_EnableIRQ>
 8000ab2:	e7c8      	b.n	8000a46 <HAL_UART_MspInit+0x22>
 8000ab4:	f020 fdd4 	bl	8021660 <Error_Handler>
 8000ab8:	e7d0      	b.n	8000a5c <HAL_UART_MspInit+0x38>
 8000aba:	bf00      	nop
 8000abc:	40004400 	.word	0x40004400

08000ac0 <HAL_UART_MspDeInit>:
 8000ac0:	b508      	push	{r3, lr}
 8000ac2:	6802      	ldr	r2, [r0, #0]
 8000ac4:	4b09      	ldr	r3, [pc, #36]	; (8000aec <HAL_UART_MspDeInit+0x2c>)
 8000ac6:	429a      	cmp	r2, r3
 8000ac8:	d000      	beq.n	8000acc <HAL_UART_MspDeInit+0xc>
 8000aca:	bd08      	pop	{r3, pc}
 8000acc:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8000ad0:	6d93      	ldr	r3, [r2, #88]	; 0x58
 8000ad2:	f423 3300 	bic.w	r3, r3, #131072	; 0x20000
 8000ad6:	6593      	str	r3, [r2, #88]	; 0x58
 8000ad8:	210c      	movs	r1, #12
 8000ada:	f04f 4090 	mov.w	r0, #1207959552	; 0x48000000
 8000ade:	f028 fee5 	bl	80298ac <HAL_GPIO_DeInit>
 8000ae2:	2025      	movs	r0, #37	; 0x25
 8000ae4:	f022 f9d2 	bl	8022e8c <HAL_NVIC_DisableIRQ>
 8000ae8:	e7ef      	b.n	8000aca <HAL_UART_MspDeInit+0xa>
 8000aea:	bf00      	nop
 8000aec:	40004400 	.word	0x40004400

08000af0 <__NVIC_SystemReset>:
 8000af0:	f3bf 8f4f 	dsb	sy
 8000af4:	4905      	ldr	r1, [pc, #20]	; (8000b0c <__NVIC_SystemReset+0x1c>)
 8000af6:	68ca      	ldr	r2, [r1, #12]
 8000af8:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000afc:	4b04      	ldr	r3, [pc, #16]	; (8000b10 <__NVIC_SystemReset+0x20>)
 8000afe:	4313      	orrs	r3, r2
 8000b00:	60cb      	str	r3, [r1, #12]
 8000b02:	f3bf 8f4f 	dsb	sy
 8000b06:	bf00      	nop
 8000b08:	e7fd      	b.n	8000b06 <__NVIC_SystemReset+0x16>
 8000b0a:	bf00      	nop
 8000b0c:	e000ed00 	.word	0xe000ed00
 8000b10:	05fa0004 	.word	0x05fa0004

08000b14 <UpdateCRC16>:
 8000b14:	f441 7180 	orr.w	r1, r1, #256	; 0x100
 8000b18:	e006      	b.n	8000b28 <UpdateCRC16+0x14>
 8000b1a:	f480 5081 	eor.w	r0, r0, #4128	; 0x1020
 8000b1e:	f080 0001 	eor.w	r0, r0, #1
 8000b22:	f411 3f80 	tst.w	r1, #65536	; 0x10000
 8000b26:	d109      	bne.n	8000b3c <UpdateCRC16+0x28>
 8000b28:	0040      	lsls	r0, r0, #1
 8000b2a:	0049      	lsls	r1, r1, #1
 8000b2c:	f411 7f80 	tst.w	r1, #256	; 0x100
 8000b30:	d000      	beq.n	8000b34 <UpdateCRC16+0x20>
 8000b32:	3001      	adds	r0, #1
 8000b34:	f410 3f80 	tst.w	r0, #65536	; 0x10000
 8000b38:	d0f3      	beq.n	8000b22 <UpdateCRC16+0xe>
 8000b3a:	e7ee      	b.n	8000b1a <UpdateCRC16+0x6>
 8000b3c:	b280      	uxth	r0, r0
 8000b3e:	4770      	bx	lr

08000b40 <Cal_CRC16>:
 8000b40:	b538      	push	{r3, r4, r5, lr}
 8000b42:	4604      	mov	r4, r0
 8000b44:	1845      	adds	r5, r0, r1
 8000b46:	2000      	movs	r0, #0
 8000b48:	e004      	b.n	8000b54 <Cal_CRC16+0x14>
 8000b4a:	f814 1b01 	ldrb.w	r1, [r4], #1
 8000b4e:	b280      	uxth	r0, r0
 8000b50:	f7ff ffe0 	bl	8000b14 <UpdateCRC16>
 8000b54:	42ac      	cmp	r4, r5
 8000b56:	d3f8      	bcc.n	8000b4a <Cal_CRC16+0xa>
 8000b58:	2100      	movs	r1, #0
 8000b5a:	b280      	uxth	r0, r0
 8000b5c:	f7ff ffda 	bl	8000b14 <UpdateCRC16>
 8000b60:	2100      	movs	r1, #0
 8000b62:	f7ff ffd7 	bl	8000b14 <UpdateCRC16>
 8000b66:	bd38      	pop	{r3, r4, r5, pc}

08000b68 <ReceivePacket>:
 8000b68:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 8000b6c:	b082      	sub	sp, #8
 8000b6e:	4606      	mov	r6, r0
 8000b70:	460c      	mov	r4, r1
 8000b72:	4615      	mov	r5, r2
 8000b74:	2300      	movs	r3, #0
 8000b76:	600b      	str	r3, [r1, #0]
 8000b78:	4613      	mov	r3, r2
 8000b7a:	2201      	movs	r2, #1
 8000b7c:	f10d 0107 	add.w	r1, sp, #7
 8000b80:	4840      	ldr	r0, [pc, #256]	; (8000c84 <ReceivePacket+0x11c>)
 8000b82:	f001 fbeb 	bl	800235c <HAL_UART_Receive>
 8000b86:	4680      	mov	r8, r0
 8000b88:	2800      	cmp	r0, #0
 8000b8a:	d172      	bne.n	8000c72 <ReceivePacket+0x10a>
 8000b8c:	f89d 1007 	ldrb.w	r1, [sp, #7]
 8000b90:	2918      	cmp	r1, #24
 8000b92:	d819      	bhi.n	8000bc8 <ReceivePacket+0x60>
 8000b94:	b24b      	sxtb	r3, r1
 8000b96:	2b00      	cmp	r3, #0
 8000b98:	d048      	beq.n	8000c2c <ReceivePacket+0xc4>
 8000b9a:	3901      	subs	r1, #1
 8000b9c:	2917      	cmp	r1, #23
 8000b9e:	d80f      	bhi.n	8000bc0 <ReceivePacket+0x58>
 8000ba0:	e8df f001 	tbb	[pc, r1]
 8000ba4:	0c0e3148 	.word	0x0c0e3148
 8000ba8:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bac:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bb0:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bb4:	0e0e0e0e 	.word	0x0e0e0e0e
 8000bb8:	340e0e0e 	.word	0x340e0e0e
 8000bbc:	2700      	movs	r7, #0
 8000bbe:	e00a      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000bc0:	f04f 0801 	mov.w	r8, #1
 8000bc4:	2700      	movs	r7, #0
 8000bc6:	e006      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000bc8:	2941      	cmp	r1, #65	; 0x41
 8000bca:	d035      	beq.n	8000c38 <ReceivePacket+0xd0>
 8000bcc:	2961      	cmp	r1, #97	; 0x61
 8000bce:	d137      	bne.n	8000c40 <ReceivePacket+0xd8>
 8000bd0:	f04f 0802 	mov.w	r8, #2
 8000bd4:	2700      	movs	r7, #0
 8000bd6:	f89d 3007 	ldrb.w	r3, [sp, #7]
 8000bda:	7033      	strb	r3, [r6, #0]
 8000bdc:	2f7f      	cmp	r7, #127	; 0x7f
 8000bde:	d949      	bls.n	8000c74 <ReceivePacket+0x10c>
 8000be0:	462b      	mov	r3, r5
 8000be2:	1d3a      	adds	r2, r7, #4
 8000be4:	1cb1      	adds	r1, r6, #2
 8000be6:	4827      	ldr	r0, [pc, #156]	; (8000c84 <ReceivePacket+0x11c>)
 8000be8:	f001 fbb8 	bl	800235c <HAL_UART_Receive>
 8000bec:	4680      	mov	r8, r0
 8000bee:	2800      	cmp	r0, #0
 8000bf0:	d145      	bne.n	8000c7e <ReceivePacket+0x116>
 8000bf2:	78b2      	ldrb	r2, [r6, #2]
 8000bf4:	78f3      	ldrb	r3, [r6, #3]
 8000bf6:	43db      	mvns	r3, r3
 8000bf8:	b2db      	uxtb	r3, r3
 8000bfa:	429a      	cmp	r2, r3
 8000bfc:	d02a      	beq.n	8000c54 <ReceivePacket+0xec>
 8000bfe:	f04f 0801 	mov.w	r8, #1
 8000c02:	2700      	movs	r7, #0
 8000c04:	e036      	b.n	8000c74 <ReceivePacket+0x10c>
 8000c06:	f44f 6780 	mov.w	r7, #1024	; 0x400
 8000c0a:	e7e4      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c0c:	462b      	mov	r3, r5
 8000c0e:	2201      	movs	r2, #1
 8000c10:	f10d 0107 	add.w	r1, sp, #7
 8000c14:	481b      	ldr	r0, [pc, #108]	; (8000c84 <ReceivePacket+0x11c>)
 8000c16:	f001 fba1 	bl	800235c <HAL_UART_Receive>
 8000c1a:	b9a8      	cbnz	r0, 8000c48 <ReceivePacket+0xe0>
 8000c1c:	f89d 3007 	ldrb.w	r3, [sp, #7]
 8000c20:	2b18      	cmp	r3, #24
 8000c22:	d015      	beq.n	8000c50 <ReceivePacket+0xe8>
 8000c24:	f04f 0801 	mov.w	r8, #1
 8000c28:	2700      	movs	r7, #0
 8000c2a:	e7d4      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c2c:	f04f 0801 	mov.w	r8, #1
 8000c30:	2700      	movs	r7, #0
 8000c32:	e7d0      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c34:	2780      	movs	r7, #128	; 0x80
 8000c36:	e7ce      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c38:	f04f 0802 	mov.w	r8, #2
 8000c3c:	2700      	movs	r7, #0
 8000c3e:	e7ca      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c40:	f04f 0801 	mov.w	r8, #1
 8000c44:	2700      	movs	r7, #0
 8000c46:	e7c6      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c48:	f04f 0801 	mov.w	r8, #1
 8000c4c:	2700      	movs	r7, #0
 8000c4e:	e7c2      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c50:	2702      	movs	r7, #2
 8000c52:	e7c0      	b.n	8000bd6 <ReceivePacket+0x6e>
 8000c54:	19f3      	adds	r3, r6, r7
 8000c56:	791a      	ldrb	r2, [r3, #4]
 8000c58:	795d      	ldrb	r5, [r3, #5]
 8000c5a:	eb05 2502 	add.w	r5, r5, r2, lsl #8
 8000c5e:	4639      	mov	r1, r7
 8000c60:	1d30      	adds	r0, r6, #4
 8000c62:	f7ff ff6d 	bl	8000b40 <Cal_CRC16>
 8000c66:	42a8      	cmp	r0, r5
 8000c68:	d004      	beq.n	8000c74 <ReceivePacket+0x10c>
 8000c6a:	f04f 0801 	mov.w	r8, #1
 8000c6e:	2700      	movs	r7, #0
 8000c70:	e000      	b.n	8000c74 <ReceivePacket+0x10c>
 8000c72:	2700      	movs	r7, #0
 8000c74:	6027      	str	r7, [r4, #0]
 8000c76:	4640      	mov	r0, r8
 8000c78:	b002      	add	sp, #8
 8000c7a:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 8000c7e:	2700      	movs	r7, #0
 8000c80:	e7f8      	b.n	8000c74 <ReceivePacket+0x10c>
 8000c82:	bf00      	nop
 8000c84:	200060d4 	.word	0x200060d4

08000c88 <Ymodem_Receive>:
 8000c88:	e92d 4ff0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, lr}
 8000c8c:	b089      	sub	sp, #36	; 0x24
 8000c8e:	9001      	str	r0, [sp, #4]
 8000c90:	f04f 0800 	mov.w	r8, #0
 8000c94:	4646      	mov	r6, r8
 8000c96:	f8df b188 	ldr.w	fp, [pc, #392]	; 8000e20 <Ymodem_Receive+0x198>
 8000c9a:	46c1      	mov	r9, r8
 8000c9c:	4645      	mov	r5, r8
 8000c9e:	46c2      	mov	sl, r8
 8000ca0:	f1ba 0f00 	cmp.w	sl, #0
 8000ca4:	f040 80b8 	bne.w	8000e18 <Ymodem_Receive+0x190>
 8000ca8:	2e00      	cmp	r6, #0
 8000caa:	f040 80b5 	bne.w	8000e18 <Ymodem_Receive+0x190>
 8000cae:	4b5d      	ldr	r3, [pc, #372]	; (8000e24 <Ymodem_Receive+0x19c>)
 8000cb0:	2200      	movs	r2, #0
 8000cb2:	701a      	strb	r2, [r3, #0]
 8000cb4:	4657      	mov	r7, sl
 8000cb6:	e085      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000cb8:	9d07      	ldr	r5, [sp, #28]
 8000cba:	b13d      	cbz	r5, 8000ccc <Ymodem_Receive+0x44>
 8000cbc:	2d02      	cmp	r5, #2
 8000cbe:	d10a      	bne.n	8000cd6 <Ymodem_Receive+0x4e>
 8000cc0:	2006      	movs	r0, #6
 8000cc2:	f7ff fccb 	bl	800065c <Serial_PutByte>
 8000cc6:	463d      	mov	r5, r7
 8000cc8:	2602      	movs	r6, #2
 8000cca:	e07b      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000ccc:	2006      	movs	r0, #6
 8000cce:	f7ff fcc5 	bl	800065c <Serial_PutByte>
 8000cd2:	2701      	movs	r7, #1
 8000cd4:	e076      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000cd6:	4b54      	ldr	r3, [pc, #336]	; (8000e28 <Ymodem_Receive+0x1a0>)
 8000cd8:	789a      	ldrb	r2, [r3, #2]
 8000cda:	4b52      	ldr	r3, [pc, #328]	; (8000e24 <Ymodem_Receive+0x19c>)
 8000cdc:	781b      	ldrb	r3, [r3, #0]
 8000cde:	429a      	cmp	r2, r3
 8000ce0:	d10b      	bne.n	8000cfa <Ymodem_Receive+0x72>
 8000ce2:	2b00      	cmp	r3, #0
 8000ce4:	d153      	bne.n	8000d8e <Ymodem_Receive+0x106>
 8000ce6:	4b50      	ldr	r3, [pc, #320]	; (8000e28 <Ymodem_Receive+0x1a0>)
 8000ce8:	791b      	ldrb	r3, [r3, #4]
 8000cea:	b9cb      	cbnz	r3, 8000d20 <Ymodem_Receive+0x98>
 8000cec:	2006      	movs	r0, #6
 8000cee:	f7ff fcb5 	bl	800065c <Serial_PutByte>
 8000cf2:	463d      	mov	r5, r7
 8000cf4:	2701      	movs	r7, #1
 8000cf6:	46ba      	mov	sl, r7
 8000cf8:	e064      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000cfa:	2015      	movs	r0, #21
 8000cfc:	f7ff fcae 	bl	800065c <Serial_PutByte>
 8000d00:	463d      	mov	r5, r7
 8000d02:	e05f      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000d04:	3301      	adds	r3, #1
 8000d06:	4849      	ldr	r0, [pc, #292]	; (8000e2c <Ymodem_Receive+0x1a4>)
 8000d08:	5481      	strb	r1, [r0, r2]
 8000d0a:	3201      	adds	r2, #1
 8000d0c:	7819      	ldrb	r1, [r3, #0]
 8000d0e:	b109      	cbz	r1, 8000d14 <Ymodem_Receive+0x8c>
 8000d10:	2a3f      	cmp	r2, #63	; 0x3f
 8000d12:	d9f7      	bls.n	8000d04 <Ymodem_Receive+0x7c>
 8000d14:	4945      	ldr	r1, [pc, #276]	; (8000e2c <Ymodem_Receive+0x1a4>)
 8000d16:	2000      	movs	r0, #0
 8000d18:	5488      	strb	r0, [r1, r2]
 8000d1a:	3301      	adds	r3, #1
 8000d1c:	463a      	mov	r2, r7
 8000d1e:	e008      	b.n	8000d32 <Ymodem_Receive+0xaa>
 8000d20:	463a      	mov	r2, r7
 8000d22:	4b43      	ldr	r3, [pc, #268]	; (8000e30 <Ymodem_Receive+0x1a8>)
 8000d24:	e7f2      	b.n	8000d0c <Ymodem_Receive+0x84>
 8000d26:	3301      	adds	r3, #1
 8000d28:	a808      	add	r0, sp, #32
 8000d2a:	4410      	add	r0, r2
 8000d2c:	f800 1c18 	strb.w	r1, [r0, #-24]
 8000d30:	3201      	adds	r2, #1
 8000d32:	7819      	ldrb	r1, [r3, #0]
 8000d34:	2920      	cmp	r1, #32
 8000d36:	d001      	beq.n	8000d3c <Ymodem_Receive+0xb4>
 8000d38:	2a0f      	cmp	r2, #15
 8000d3a:	d9f4      	bls.n	8000d26 <Ymodem_Receive+0x9e>
 8000d3c:	ab08      	add	r3, sp, #32
 8000d3e:	441a      	add	r2, r3
 8000d40:	2300      	movs	r3, #0
 8000d42:	f802 3c18 	strb.w	r3, [r2, #-24]
 8000d46:	a906      	add	r1, sp, #24
 8000d48:	a802      	add	r0, sp, #8
 8000d4a:	f7ff fbff 	bl	800054c <Str2Int>
 8000d4e:	9a06      	ldr	r2, [sp, #24]
 8000d50:	4b38      	ldr	r3, [pc, #224]	; (8000e34 <Ymodem_Receive+0x1ac>)
 8000d52:	429a      	cmp	r2, r3
 8000d54:	d813      	bhi.n	8000d7e <Ymodem_Receive+0xf6>
 8000d56:	4832      	ldr	r0, [pc, #200]	; (8000e20 <Ymodem_Receive+0x198>)
 8000d58:	f7ff fcbc 	bl	80006d4 <FLASH_If_Erase>
 8000d5c:	9b06      	ldr	r3, [sp, #24]
 8000d5e:	9a01      	ldr	r2, [sp, #4]
 8000d60:	6013      	str	r3, [r2, #0]
 8000d62:	2006      	movs	r0, #6
 8000d64:	f7ff fc7a 	bl	800065c <Serial_PutByte>
 8000d68:	2043      	movs	r0, #67	; 0x43
 8000d6a:	f7ff fc77 	bl	800065c <Serial_PutByte>
 8000d6e:	4a2d      	ldr	r2, [pc, #180]	; (8000e24 <Ymodem_Receive+0x19c>)
 8000d70:	7813      	ldrb	r3, [r2, #0]
 8000d72:	3301      	adds	r3, #1
 8000d74:	7013      	strb	r3, [r2, #0]
 8000d76:	463d      	mov	r5, r7
 8000d78:	f04f 0901 	mov.w	r9, #1
 8000d7c:	e022      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000d7e:	2018      	movs	r0, #24
 8000d80:	f7ff fc6c 	bl	800065c <Serial_PutByte>
 8000d84:	2018      	movs	r0, #24
 8000d86:	f7ff fc69 	bl	800065c <Serial_PutByte>
 8000d8a:	2605      	movs	r6, #5
 8000d8c:	e7e3      	b.n	8000d56 <Ymodem_Receive+0xce>
 8000d8e:	08aa      	lsrs	r2, r5, #2
 8000d90:	4927      	ldr	r1, [pc, #156]	; (8000e30 <Ymodem_Receive+0x1a8>)
 8000d92:	4658      	mov	r0, fp
 8000d94:	f7ff fcc4 	bl	8000720 <FLASH_If_Write>
 8000d98:	b928      	cbnz	r0, 8000da6 <Ymodem_Receive+0x11e>
 8000d9a:	9b07      	ldr	r3, [sp, #28]
 8000d9c:	449b      	add	fp, r3
 8000d9e:	2006      	movs	r0, #6
 8000da0:	f7ff fc5c 	bl	800065c <Serial_PutByte>
 8000da4:	e7e3      	b.n	8000d6e <Ymodem_Receive+0xe6>
 8000da6:	2018      	movs	r0, #24
 8000da8:	f7ff fc58 	bl	800065c <Serial_PutByte>
 8000dac:	2018      	movs	r0, #24
 8000dae:	f7ff fc55 	bl	800065c <Serial_PutByte>
 8000db2:	2604      	movs	r6, #4
 8000db4:	e7db      	b.n	8000d6e <Ymodem_Receive+0xe6>
 8000db6:	2018      	movs	r0, #24
 8000db8:	f7ff fc50 	bl	800065c <Serial_PutByte>
 8000dbc:	2018      	movs	r0, #24
 8000dbe:	f7ff fc4d 	bl	800065c <Serial_PutByte>
 8000dc2:	4626      	mov	r6, r4
 8000dc4:	2f00      	cmp	r7, #0
 8000dc6:	f47f af6b 	bne.w	8000ca0 <Ymodem_Receive+0x18>
 8000dca:	2e00      	cmp	r6, #0
 8000dcc:	f47f af68 	bne.w	8000ca0 <Ymodem_Receive+0x18>
 8000dd0:	f44f 72fa 	mov.w	r2, #500	; 0x1f4
 8000dd4:	a907      	add	r1, sp, #28
 8000dd6:	4814      	ldr	r0, [pc, #80]	; (8000e28 <Ymodem_Receive+0x1a0>)
 8000dd8:	f7ff fec6 	bl	8000b68 <ReceivePacket>
 8000ddc:	4604      	mov	r4, r0
 8000dde:	2800      	cmp	r0, #0
 8000de0:	f43f af6a 	beq.w	8000cb8 <Ymodem_Receive+0x30>
 8000de4:	2802      	cmp	r0, #2
 8000de6:	d0e6      	beq.n	8000db6 <Ymodem_Receive+0x12e>
 8000de8:	f1b9 0f00 	cmp.w	r9, #0
 8000dec:	d000      	beq.n	8000df0 <Ymodem_Receive+0x168>
 8000dee:	3501      	adds	r5, #1
 8000df0:	2d05      	cmp	r5, #5
 8000df2:	d907      	bls.n	8000e04 <Ymodem_Receive+0x17c>
 8000df4:	2018      	movs	r0, #24
 8000df6:	f7ff fc31 	bl	800065c <Serial_PutByte>
 8000dfa:	2018      	movs	r0, #24
 8000dfc:	f7ff fc2e 	bl	800065c <Serial_PutByte>
 8000e00:	2602      	movs	r6, #2
 8000e02:	e7df      	b.n	8000dc4 <Ymodem_Receive+0x13c>
 8000e04:	2043      	movs	r0, #67	; 0x43
 8000e06:	f7ff fc29 	bl	800065c <Serial_PutByte>
 8000e0a:	f108 0801 	add.w	r8, r8, #1
 8000e0e:	f1b8 0f3b 	cmp.w	r8, #59	; 0x3b
 8000e12:	d9d7      	bls.n	8000dc4 <Ymodem_Receive+0x13c>
 8000e14:	f7ff fe6c 	bl	8000af0 <__NVIC_SystemReset>
 8000e18:	4630      	mov	r0, r6
 8000e1a:	b009      	add	sp, #36	; 0x24
 8000e1c:	e8bd 8ff0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, pc}
 8000e20:	08006000 	.word	0x08006000
 8000e24:	2000656a 	.word	0x2000656a
 8000e28:	20006164 	.word	0x20006164
 8000e2c:	20006094 	.word	0x20006094
 8000e30:	20006168 	.word	0x20006168
 8000e34:	00031001 	.word	0x00031001

08000e38 <upgrade_process_callback>:
 8000e38:	b508      	push	{r3, lr}
 8000e3a:	4b0a      	ldr	r3, [pc, #40]	; (8000e64 <upgrade_process_callback+0x2c>)
 8000e3c:	fba3 2300 	umull	r2, r3, r3, r0
 8000e40:	0b1b      	lsrs	r3, r3, #12
 8000e42:	f643 2298 	movw	r2, #15000	; 0x3a98
 8000e46:	fb02 0313 	mls	r3, r2, r3, r0
 8000e4a:	b943      	cbnz	r3, 8000e5e <upgrade_process_callback+0x26>
 8000e4c:	4b06      	ldr	r3, [pc, #24]	; (8000e68 <upgrade_process_callback+0x30>)
 8000e4e:	781b      	ldrb	r3, [r3, #0]
 8000e50:	b12b      	cbz	r3, 8000e5e <upgrade_process_callback+0x26>
 8000e52:	4a06      	ldr	r2, [pc, #24]	; (8000e6c <upgrade_process_callback+0x34>)
 8000e54:	7812      	ldrb	r2, [r2, #0]
 8000e56:	4293      	cmp	r3, r2
 8000e58:	d002      	beq.n	8000e60 <upgrade_process_callback+0x28>
 8000e5a:	4a04      	ldr	r2, [pc, #16]	; (8000e6c <upgrade_process_callback+0x34>)
 8000e5c:	7013      	strb	r3, [r2, #0]
 8000e5e:	bd08      	pop	{r3, pc}
 8000e60:	f7ff fe46 	bl	8000af0 <__NVIC_SystemReset>
 8000e64:	45e7b273 	.word	0x45e7b273
 8000e68:	2000656a 	.word	0x2000656a
 8000e6c:	2000656b 	.word	0x2000656b

08000e70 <__NVIC_SystemReset>:
 8000e70:	f3bf 8f4f 	dsb	sy
 8000e74:	4905      	ldr	r1, [pc, #20]	; (8000e8c <__NVIC_SystemReset+0x1c>)
 8000e76:	68ca      	ldr	r2, [r1, #12]
 8000e78:	f402 62e0 	and.w	r2, r2, #1792	; 0x700
 8000e7c:	4b04      	ldr	r3, [pc, #16]	; (8000e90 <__NVIC_SystemReset+0x20>)
 8000e7e:	4313      	orrs	r3, r2
 8000e80:	60cb      	str	r3, [r1, #12]
 8000e82:	f3bf 8f4f 	dsb	sy
 8000e86:	bf00      	nop
 8000e88:	e7fd      	b.n	8000e86 <__NVIC_SystemReset+0x16>
 8000e8a:	bf00      	nop
 8000e8c:	e000ed00 	.word	0xe000ed00
 8000e90:	05fa0004 	.word	0x05fa0004

08000e94 <OnNvmDataChange_fuota>:
 8000e94:	4770      	bx	lr

08000e96 <OnMacProcessNotify_fuota>:
 8000e96:	4770      	bx	lr

08000e98 <fuota_OnMacMcpsRequest>:
 8000e98:	4770      	bx	lr

08000e9a <fuota_OnMacMlmeRequest>:
 8000e9a:	4770      	bx	lr

08000e9c <fuota_LmHandlerJoinRequest>:
 8000e9c:	4770      	bx	lr

08000e9e <OnNetworkParametersChange>:
 8000e9e:	4770      	bx	lr

08000ea0 <OnMacMcpsRequest>:
 8000ea0:	4770      	bx	lr

08000ea2 <OnMacMlmeRequest>:
 8000ea2:	4770      	bx	lr

08000ea4 <OnJoinRequest>:
 8000ea4:	4770      	bx	lr

08000ea6 <OnTxData>:
 8000ea6:	4770      	bx	lr

08000ea8 <OnRxData>:
 8000ea8:	4770      	bx	lr

08000eaa <OnBeaconStatusChange>:
 8000eaa:	4770      	bx	lr

08000eac <OnSysTimeUpdate>:
 8000eac:	4b01      	ldr	r3, [pc, #4]	; (8000eb4 <OnSysTimeUpdate+0x8>)
 8000eae:	2201      	movs	r2, #1
 8000eb0:	701a      	strb	r2, [r3, #0]
 8000eb2:	4770      	bx	lr
 8000eb4:	200002e4 	.word	0x200002e4

08000eb8 <LmHandlerPackagesNotify>:
 8000eb8:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000eba:	4605      	mov	r5, r0
 8000ebc:	460f      	mov	r7, r1
 8000ebe:	2400      	movs	r4, #0
 8000ec0:	e016      	b.n	8000ef0 <LmHandlerPackagesNotify+0x38>
 8000ec2:	695b      	ldr	r3, [r3, #20]
 8000ec4:	b193      	cbz	r3, 8000eec <LmHandlerPackagesNotify+0x34>
 8000ec6:	4638      	mov	r0, r7
 8000ec8:	4798      	blx	r3
 8000eca:	e00f      	b.n	8000eec <LmHandlerPackagesNotify+0x34>
 8000ecc:	699b      	ldr	r3, [r3, #24]
 8000ece:	b16b      	cbz	r3, 8000eec <LmHandlerPackagesNotify+0x34>
 8000ed0:	4638      	mov	r0, r7
 8000ed2:	4798      	blx	r3
 8000ed4:	e00a      	b.n	8000eec <LmHandlerPackagesNotify+0x34>
 8000ed6:	69db      	ldr	r3, [r3, #28]
 8000ed8:	b10b      	cbz	r3, 8000ede <LmHandlerPackagesNotify+0x26>
 8000eda:	4638      	mov	r0, r7
 8000edc:	4798      	blx	r3
 8000ede:	4b10      	ldr	r3, [pc, #64]	; (8000f20 <LmHandlerPackagesNotify+0x68>)
 8000ee0:	f853 3026 	ldr.w	r3, [r3, r6, lsl #2]
 8000ee4:	6a1b      	ldr	r3, [r3, #32]
 8000ee6:	b10b      	cbz	r3, 8000eec <LmHandlerPackagesNotify+0x34>
 8000ee8:	4638      	mov	r0, r7
 8000eea:	4798      	blx	r3
 8000eec:	3401      	adds	r4, #1
 8000eee:	b264      	sxtb	r4, r4
 8000ef0:	2c03      	cmp	r4, #3
 8000ef2:	dc13      	bgt.n	8000f1c <LmHandlerPackagesNotify+0x64>
 8000ef4:	4626      	mov	r6, r4
 8000ef6:	4b0a      	ldr	r3, [pc, #40]	; (8000f20 <LmHandlerPackagesNotify+0x68>)
 8000ef8:	f853 3024 	ldr.w	r3, [r3, r4, lsl #2]
 8000efc:	2b00      	cmp	r3, #0
 8000efe:	d0f5      	beq.n	8000eec <LmHandlerPackagesNotify+0x34>
 8000f00:	2d03      	cmp	r5, #3
 8000f02:	d8f3      	bhi.n	8000eec <LmHandlerPackagesNotify+0x34>
 8000f04:	a201      	add	r2, pc, #4	; (adr r2, 8000f0c <LmHandlerPackagesNotify+0x54>)
 8000f06:	f852 f025 	ldr.w	pc, [r2, r5, lsl #2]
 8000f0a:	bf00      	nop
 8000f0c:	08000ec3 	.word	0x08000ec3
 8000f10:	08000ecd 	.word	0x08000ecd
 8000f14:	08000ed7 	.word	0x08000ed7
 8000f18:	08000edf 	.word	0x08000edf
 8000f1c:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}
 8000f1e:	bf00      	nop
 8000f20:	200003d0 	.word	0x200003d0

08000f24 <MlmeIndication_fuota>:
 8000f24:	b508      	push	{r3, lr}
 8000f26:	4601      	mov	r1, r0
 8000f28:	2003      	movs	r0, #3
 8000f2a:	f7ff ffc5 	bl	8000eb8 <LmHandlerPackagesNotify>
 8000f2e:	bd08      	pop	{r3, pc}

08000f30 <McpsConfirm_fuota>:
 8000f30:	b508      	push	{r3, lr}
 8000f32:	4601      	mov	r1, r0
 8000f34:	2000      	movs	r0, #0
 8000f36:	f7ff ffbf 	bl	8000eb8 <LmHandlerPackagesNotify>
 8000f3a:	bd08      	pop	{r3, pc}

08000f3c <fuota_OnFragProgress>:
 8000f3c:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8000f3e:	4604      	mov	r4, r0
 8000f40:	460e      	mov	r6, r1
 8000f42:	4615      	mov	r5, r2
 8000f44:	461f      	mov	r7, r3
 8000f46:	460a      	mov	r2, r1
 8000f48:	4601      	mov	r1, r0
 8000f4a:	4807      	ldr	r0, [pc, #28]	; (8000f68 <fuota_OnFragProgress+0x2c>)
 8000f4c:	f7ff fba0 	bl	8000690 <Serial_Printf>
 8000f50:	fb05 f206 	mul.w	r2, r5, r6
 8000f54:	fb05 f104 	mul.w	r1, r5, r4
 8000f58:	4804      	ldr	r0, [pc, #16]	; (8000f6c <fuota_OnFragProgress+0x30>)
 8000f5a:	f7ff fb99 	bl	8000690 <Serial_Printf>
 8000f5e:	4639      	mov	r1, r7
 8000f60:	4803      	ldr	r0, [pc, #12]	; (8000f70 <fuota_OnFragProgress+0x34>)
 8000f62:	f7ff fb95 	bl	8000690 <Serial_Printf>
 8000f66:	bdf8      	pop	{r3, r4, r5, r6, r7, pc}
 8000f68:	080029c4 	.word	0x080029c4
 8000f6c:	080029e8 	.word	0x080029e8
 8000f70:	08002a08 	.word	0x08002a08

08000f74 <fuota_OnFragDone>:
 8000f74:	b508      	push	{r3, lr}
 8000f76:	4808      	ldr	r0, [pc, #32]	; (8000f98 <fuota_OnFragDone+0x24>)
 8000f78:	f7ff fb8a 	bl	8000690 <Serial_Printf>
 8000f7c:	4b07      	ldr	r3, [pc, #28]	; (8000f9c <fuota_OnFragDone+0x28>)
 8000f7e:	2201      	movs	r2, #1
 8000f80:	701a      	strb	r2, [r3, #0]
 8000f82:	f04f 3102 	mov.w	r1, #33686018	; 0x2020202
 8000f86:	4806      	ldr	r0, [pc, #24]	; (8000fa0 <fuota_OnFragDone+0x2c>)
 8000f88:	f7ff fc10 	bl	80007ac <HAL_FLASH_Program_Flag>
 8000f8c:	4805      	ldr	r0, [pc, #20]	; (8000fa4 <fuota_OnFragDone+0x30>)
 8000f8e:	f7ff fb7f 	bl	8000690 <Serial_Printf>
 8000f92:	f7ff ff6d 	bl	8000e70 <__NVIC_SystemReset>
 8000f96:	bf00      	nop
 8000f98:	08002a2c 	.word	0x08002a2c
 8000f9c:	2000665e 	.word	0x2000665e
 8000fa0:	08004004 	.word	0x08004004
 8000fa4:	08002a3c 	.word	0x08002a3c

08000fa8 <fuota_FragDecoderRead>:
 8000fa8:	b508      	push	{r3, lr}
 8000faa:	4613      	mov	r3, r2
 8000fac:	460a      	mov	r2, r1
 8000fae:	4619      	mov	r1, r3
 8000fb0:	f100 6000 	add.w	r0, r0, #134217728	; 0x8000000
 8000fb4:	f500 40c0 	add.w	r0, r0, #24576	; 0x6000
 8000fb8:	f020 fa08 	bl	80213cc <udrv_flash_read>
 8000fbc:	2000      	movs	r0, #0
 8000fbe:	bd08      	pop	{r3, pc}

08000fc0 <fuota_FragDecoderWrite>:
 8000fc0:	b508      	push	{r3, lr}
 8000fc2:	4613      	mov	r3, r2
 8000fc4:	460a      	mov	r2, r1
 8000fc6:	4619      	mov	r1, r3
 8000fc8:	f100 6000 	add.w	r0, r0, #134217728	; 0x8000000
 8000fcc:	f500 40c0 	add.w	r0, r0, #24576	; 0x6000
 8000fd0:	f020 faa6 	bl	8021520 <udrv_flash_write>
 8000fd4:	2000      	movs	r0, #0
 8000fd6:	bd08      	pop	{r3, pc}

08000fd8 <MlmeConfirm_fuota>:
 8000fd8:	b538      	push	{r3, r4, r5, lr}
 8000fda:	4604      	mov	r4, r0
 8000fdc:	4814      	ldr	r0, [pc, #80]	; (8001030 <MlmeConfirm_fuota+0x58>)
 8000fde:	f023 ff4d 	bl	8024e7c <UTIL_TIMER_IsRunning>
 8000fe2:	b938      	cbnz	r0, 8000ff4 <MlmeConfirm_fuota+0x1c>
 8000fe4:	7823      	ldrb	r3, [r4, #0]
 8000fe6:	2b01      	cmp	r3, #1
 8000fe8:	d011      	beq.n	800100e <MlmeConfirm_fuota+0x36>
 8000fea:	4621      	mov	r1, r4
 8000fec:	2002      	movs	r0, #2
 8000fee:	f7ff ff63 	bl	8000eb8 <LmHandlerPackagesNotify>
 8000ff2:	bd38      	pop	{r3, r4, r5, pc}
 8000ff4:	4d0e      	ldr	r5, [pc, #56]	; (8001030 <MlmeConfirm_fuota+0x58>)
 8000ff6:	4628      	mov	r0, r5
 8000ff8:	f023 ffb0 	bl	8024f5c <UTIL_TIMER_Stop>
 8000ffc:	f644 6120 	movw	r1, #20000	; 0x4e20
 8001000:	4628      	mov	r0, r5
 8001002:	f024 f84d 	bl	80250a0 <UTIL_TIMER_SetPeriod>
 8001006:	4628      	mov	r0, r5
 8001008:	f023 fff8 	bl	8024ffc <UTIL_TIMER_Start>
 800100c:	e7ea      	b.n	8000fe4 <MlmeConfirm_fuota+0xc>
 800100e:	7863      	ldrb	r3, [r4, #1]
 8001010:	b933      	cbnz	r3, 8001020 <MlmeConfirm_fuota+0x48>
 8001012:	4b08      	ldr	r3, [pc, #32]	; (8001034 <MlmeConfirm_fuota+0x5c>)
 8001014:	2201      	movs	r2, #1
 8001016:	701a      	strb	r2, [r3, #0]
 8001018:	4807      	ldr	r0, [pc, #28]	; (8001038 <MlmeConfirm_fuota+0x60>)
 800101a:	f7ff fb39 	bl	8000690 <Serial_Printf>
 800101e:	e7e4      	b.n	8000fea <MlmeConfirm_fuota+0x12>
 8001020:	4b04      	ldr	r3, [pc, #16]	; (8001034 <MlmeConfirm_fuota+0x5c>)
 8001022:	2200      	movs	r2, #0
 8001024:	701a      	strb	r2, [r3, #0]
 8001026:	4805      	ldr	r0, [pc, #20]	; (800103c <MlmeConfirm_fuota+0x64>)
 8001028:	f7ff fb32 	bl	8000690 <Serial_Printf>
 800102c:	e7dd      	b.n	8000fea <MlmeConfirm_fuota+0x12>
 800102e:	bf00      	nop
 8001030:	20006678 	.word	0x20006678
 8001034:	20006674 	.word	0x20006674
 8001038:	08002a48 	.word	0x08002a48
 800103c:	08002a58 	.word	0x08002a58

08001040 <McpsIndication_fuota>:
 8001040:	b538      	push	{r3, r4, r5, lr}
 8001042:	4604      	mov	r4, r0
 8001044:	480d      	ldr	r0, [pc, #52]	; (800107c <McpsIndication_fuota+0x3c>)
 8001046:	f023 ff19 	bl	8024e7c <UTIL_TIMER_IsRunning>
 800104a:	b950      	cbnz	r0, 8001062 <McpsIndication_fuota+0x22>
 800104c:	7f23      	ldrb	r3, [r4, #28]
 800104e:	b11b      	cbz	r3, 8001058 <McpsIndication_fuota+0x18>
 8001050:	4b0b      	ldr	r3, [pc, #44]	; (8001080 <McpsIndication_fuota+0x40>)
 8001052:	6b5b      	ldr	r3, [r3, #52]	; 0x34
 8001054:	b103      	cbz	r3, 8001058 <McpsIndication_fuota+0x18>
 8001056:	4798      	blx	r3
 8001058:	4621      	mov	r1, r4
 800105a:	2001      	movs	r0, #1
 800105c:	f7ff ff2c 	bl	8000eb8 <LmHandlerPackagesNotify>
 8001060:	bd38      	pop	{r3, r4, r5, pc}
 8001062:	4d06      	ldr	r5, [pc, #24]	; (800107c <McpsIndication_fuota+0x3c>)
 8001064:	4628      	mov	r0, r5
 8001066:	f023 ff79 	bl	8024f5c <UTIL_TIMER_Stop>
 800106a:	f644 6120 	movw	r1, #20000	; 0x4e20
 800106e:	4628      	mov	r0, r5
 8001070:	f024 f816 	bl	80250a0 <UTIL_TIMER_SetPeriod>
 8001074:	4628      	mov	r0, r5
 8001076:	f023 ffc1 	bl	8024ffc <UTIL_TIMER_Start>
 800107a:	e7e7      	b.n	800104c <McpsIndication_fuota+0xc>
 800107c:	20006678 	.word	0x20006678
 8001080:	20006000 	.word	0x20006000

08001084 <bootloader_fuota_stack_init>:
 8001084:	b508      	push	{r3, lr}
 8001086:	4806      	ldr	r0, [pc, #24]	; (80010a0 <bootloader_fuota_stack_init+0x1c>)
 8001088:	4a06      	ldr	r2, [pc, #24]	; (80010a4 <bootloader_fuota_stack_init+0x20>)
 800108a:	1a12      	subs	r2, r2, r0
 800108c:	4906      	ldr	r1, [pc, #24]	; (80010a8 <bootloader_fuota_stack_init+0x24>)
 800108e:	f03a fa33 	bl	803b4f8 <memcpy>
 8001092:	4806      	ldr	r0, [pc, #24]	; (80010ac <bootloader_fuota_stack_init+0x28>)
 8001094:	4a06      	ldr	r2, [pc, #24]	; (80010b0 <bootloader_fuota_stack_init+0x2c>)
 8001096:	1a12      	subs	r2, r2, r0
 8001098:	2100      	movs	r1, #0
 800109a:	f7ff f891 	bl	80001c0 <memset>
 800109e:	bd08      	pop	{r3, pc}
 80010a0:	20000000 	.word	0x20000000
 80010a4:	200002d0 	.word	0x200002d0
 80010a8:	0803c000 	.word	0x0803c000
 80010ac:	200002d0 	.word	0x200002d0
 80010b0:	20005e98 	.word	0x20005e98

080010b4 <fuota_LmHandlerPackageRegister>:
 80010b4:	b508      	push	{r3, lr}
 80010b6:	4b12      	ldr	r3, [pc, #72]	; (8001100 <fuota_LmHandlerPackageRegister+0x4c>)
 80010b8:	f843 1020 	str.w	r1, [r3, r0, lsl #2]
 80010bc:	4a11      	ldr	r2, [pc, #68]	; (8001104 <fuota_LmHandlerPackageRegister+0x50>)
 80010be:	624a      	str	r2, [r1, #36]	; 0x24
 80010c0:	f853 2020 	ldr.w	r2, [r3, r0, lsl #2]
 80010c4:	4910      	ldr	r1, [pc, #64]	; (8001108 <fuota_LmHandlerPackageRegister+0x54>)
 80010c6:	6291      	str	r1, [r2, #40]	; 0x28
 80010c8:	f853 2020 	ldr.w	r2, [r3, r0, lsl #2]
 80010cc:	490f      	ldr	r1, [pc, #60]	; (800110c <fuota_LmHandlerPackageRegister+0x58>)
 80010ce:	62d1      	str	r1, [r2, #44]	; 0x2c
 80010d0:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 80010d4:	4a0e      	ldr	r2, [pc, #56]	; (8001110 <fuota_LmHandlerPackageRegister+0x5c>)
 80010d6:	631a      	str	r2, [r3, #48]	; 0x30
 80010d8:	2803      	cmp	r0, #3
 80010da:	d008      	beq.n	80010ee <fuota_LmHandlerPackageRegister+0x3a>
 80010dc:	4b08      	ldr	r3, [pc, #32]	; (8001100 <fuota_LmHandlerPackageRegister+0x4c>)
 80010de:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 80010e2:	685b      	ldr	r3, [r3, #4]
 80010e4:	22f2      	movs	r2, #242	; 0xf2
 80010e6:	490b      	ldr	r1, [pc, #44]	; (8001114 <fuota_LmHandlerPackageRegister+0x60>)
 80010e8:	2000      	movs	r0, #0
 80010ea:	4798      	blx	r3
 80010ec:	bd08      	pop	{r3, pc}
 80010ee:	4b04      	ldr	r3, [pc, #16]	; (8001100 <fuota_LmHandlerPackageRegister+0x4c>)
 80010f0:	f853 3020 	ldr.w	r3, [r3, r0, lsl #2]
 80010f4:	685b      	ldr	r3, [r3, #4]
 80010f6:	22f2      	movs	r2, #242	; 0xf2
 80010f8:	4906      	ldr	r1, [pc, #24]	; (8001114 <fuota_LmHandlerPackageRegister+0x60>)
 80010fa:	4807      	ldr	r0, [pc, #28]	; (8001118 <fuota_LmHandlerPackageRegister+0x64>)
 80010fc:	4798      	blx	r3
 80010fe:	e7f5      	b.n	80010ec <fuota_LmHandlerPackageRegister+0x38>
 8001100:	200003d0 	.word	0x200003d0
 8001104:	08000e99 	.word	0x08000e99
 8001108:	08000e9b 	.word	0x08000e9b
 800110c:	08000e9d 	.word	0x08000e9d
 8001110:	08020021 	.word	0x08020021
 8001114:	2000656c 	.word	0x2000656c
 8001118:	20006038 	.word	0x20006038

0800111c <fuota_LmHandlerRegister>:
 800111c:	b510      	push	{r4, lr}
 800111e:	f01f f999 	bl	8020454 <LmphClockSyncPackageFactory>
 8001122:	4604      	mov	r4, r0
 8001124:	2001      	movs	r0, #1
 8001126:	f01f f88f 	bl	8020248 <LmHandlerFuotaStackPackageRegister>
 800112a:	4621      	mov	r1, r4
 800112c:	2001      	movs	r0, #1
 800112e:	f7ff ffc1 	bl	80010b4 <fuota_LmHandlerPackageRegister>
 8001132:	f01f fc37 	bl	80209a4 <LmhpRemoteMcastSetupPackageFactory>
 8001136:	4604      	mov	r4, r0
 8001138:	2002      	movs	r0, #2
 800113a:	f01f f885 	bl	8020248 <LmHandlerFuotaStackPackageRegister>
 800113e:	4621      	mov	r1, r4
 8001140:	2002      	movs	r0, #2
 8001142:	f7ff ffb7 	bl	80010b4 <fuota_LmHandlerPackageRegister>
 8001146:	f01f fe51 	bl	8020dec <LmhpFragmentationPackageFactory>
 800114a:	4604      	mov	r4, r0
 800114c:	2003      	movs	r0, #3
 800114e:	f01f f87b 	bl	8020248 <LmHandlerFuotaStackPackageRegister>
 8001152:	4621      	mov	r1, r4
 8001154:	2003      	movs	r0, #3
 8001156:	f7ff ffad 	bl	80010b4 <fuota_LmHandlerPackageRegister>
 800115a:	2000      	movs	r0, #0
 800115c:	bd10      	pop	{r4, pc}
	...

08001160 <bootloader_fuota_init>:
 8001160:	b538      	push	{r3, r4, r5, lr}
 8001162:	4916      	ldr	r1, [pc, #88]	; (80011bc <bootloader_fuota_init+0x5c>)
 8001164:	4816      	ldr	r0, [pc, #88]	; (80011c0 <bootloader_fuota_init+0x60>)
 8001166:	f02f fd05 	bl	8030b74 <LoRaMacUpdateCallbacks>
 800116a:	f01e fbfe 	bl	801f96a <service_lora_fuota_get_band>
 800116e:	4c15      	ldr	r4, [pc, #84]	; (80011c4 <bootloader_fuota_init+0x64>)
 8001170:	7020      	strb	r0, [r4, #0]
 8001172:	f020 ff6d 	bl	8022050 <service_nvm_get_adr_from_nvm>
 8001176:	3800      	subs	r0, #0
 8001178:	bf18      	it	ne
 800117a:	2001      	movne	r0, #1
 800117c:	7060      	strb	r0, [r4, #1]
 800117e:	f020 ff31 	bl	8021fe4 <service_nvm_get_cfm_from_nvm>
 8001182:	70a0      	strb	r0, [r4, #2]
 8001184:	f020 ff88 	bl	8022098 <service_nvm_get_dr_from_nvm>
 8001188:	70e0      	strb	r0, [r4, #3]
 800118a:	2501      	movs	r5, #1
 800118c:	7125      	strb	r5, [r4, #4]
 800118e:	f021 fab7 	bl	8022700 <service_nvm_get_dcs_from_nvm>
 8001192:	3800      	subs	r0, #0
 8001194:	bf18      	it	ne
 8001196:	2001      	movne	r0, #1
 8001198:	7160      	strb	r0, [r4, #5]
 800119a:	23f2      	movs	r3, #242	; 0xf2
 800119c:	71a3      	strb	r3, [r4, #6]
 800119e:	4b0a      	ldr	r3, [pc, #40]	; (80011c8 <bootloader_fuota_init+0x68>)
 80011a0:	60a3      	str	r3, [r4, #8]
 80011a2:	4621      	mov	r1, r4
 80011a4:	4809      	ldr	r0, [pc, #36]	; (80011cc <bootloader_fuota_init+0x6c>)
 80011a6:	f01e feeb 	bl	801ff80 <LmHandlerInit>
 80011aa:	f7ff ffb7 	bl	800111c <fuota_LmHandlerRegister>
 80011ae:	4808      	ldr	r0, [pc, #32]	; (80011d0 <bootloader_fuota_init+0x70>)
 80011b0:	f01f ff0e 	bl	8020fd0 <FragDecoderUpdateCallback>
 80011b4:	4b07      	ldr	r3, [pc, #28]	; (80011d4 <bootloader_fuota_init+0x74>)
 80011b6:	701d      	strb	r5, [r3, #0]
 80011b8:	bd38      	pop	{r3, r4, r5, pc}
 80011ba:	bf00      	nop
 80011bc:	20006048 	.word	0x20006048
 80011c0:	20006058 	.word	0x20006058
 80011c4:	20006664 	.word	0x20006664
 80011c8:	2000656c 	.word	0x2000656c
 80011cc:	20006000 	.word	0x20006000
 80011d0:	20006038 	.word	0x20006038
 80011d4:	2000665f 	.word	0x2000665f

080011d8 <fuota_init>:
 80011d8:	b510      	push	{r4, lr}
 80011da:	f01d fe9e 	bl	801ef1a <BoardInitMcu>
 80011de:	f01e fb9b 	bl	801f918 <service_fuota_nvm_init>
 80011e2:	f020 fda5 	bl	8021d30 <service_nvm_get_band_from_nvm>
 80011e6:	f010 04ff 	ands.w	r4, r0, #255	; 0xff
 80011ea:	d035      	beq.n	8001258 <fuota_init+0x80>
 80011ec:	2c14      	cmp	r4, #20
 80011ee:	d037      	beq.n	8001260 <fuota_init+0x88>
 80011f0:	2c15      	cmp	r4, #21
 80011f2:	d039      	beq.n	8001268 <fuota_init+0x90>
 80011f4:	2c16      	cmp	r4, #22
 80011f6:	d03b      	beq.n	8001270 <fuota_init+0x98>
 80011f8:	f01e fbb7 	bl	801f96a <service_lora_fuota_get_band>
 80011fc:	b2c2      	uxtb	r2, r0
 80011fe:	4921      	ldr	r1, [pc, #132]	; (8001284 <fuota_init+0xac>)
 8001200:	4821      	ldr	r0, [pc, #132]	; (8001288 <fuota_init+0xb0>)
 8001202:	f02d fbf3 	bl	802e9ec <LoRaMacInitialization>
 8001206:	bbb8      	cbnz	r0, 8001278 <fuota_init+0xa0>
 8001208:	f01e fbaf 	bl	801f96a <service_lora_fuota_get_band>
 800120c:	4c1f      	ldr	r4, [pc, #124]	; (800128c <fuota_init+0xb4>)
 800120e:	7020      	strb	r0, [r4, #0]
 8001210:	f020 ff1e 	bl	8022050 <service_nvm_get_adr_from_nvm>
 8001214:	3800      	subs	r0, #0
 8001216:	bf18      	it	ne
 8001218:	2001      	movne	r0, #1
 800121a:	7060      	strb	r0, [r4, #1]
 800121c:	f020 fee2 	bl	8021fe4 <service_nvm_get_cfm_from_nvm>
 8001220:	70a0      	strb	r0, [r4, #2]
 8001222:	f020 ff39 	bl	8022098 <service_nvm_get_dr_from_nvm>
 8001226:	70e0      	strb	r0, [r4, #3]
 8001228:	2301      	movs	r3, #1
 800122a:	7123      	strb	r3, [r4, #4]
 800122c:	f021 fa68 	bl	8022700 <service_nvm_get_dcs_from_nvm>
 8001230:	3800      	subs	r0, #0
 8001232:	bf18      	it	ne
 8001234:	2001      	movne	r0, #1
 8001236:	7160      	strb	r0, [r4, #5]
 8001238:	23f2      	movs	r3, #242	; 0xf2
 800123a:	71a3      	strb	r3, [r4, #6]
 800123c:	4b14      	ldr	r3, [pc, #80]	; (8001290 <fuota_init+0xb8>)
 800123e:	60a3      	str	r3, [r4, #8]
 8001240:	4621      	mov	r1, r4
 8001242:	4814      	ldr	r0, [pc, #80]	; (8001294 <fuota_init+0xbc>)
 8001244:	f01e fe9c 	bl	801ff80 <LmHandlerInit>
 8001248:	f7ff ff68 	bl	800111c <fuota_LmHandlerRegister>
 800124c:	f01e fb98 	bl	801f980 <service_fuota_lora_config>
 8001250:	f02d fda8 	bl	802eda4 <LoRaMacStart>
 8001254:	2000      	movs	r0, #0
 8001256:	bd10      	pop	{r4, pc}
 8001258:	2001      	movs	r0, #1
 800125a:	f031 ff99 	bl	8033190 <RegionAS923SubBandSet>
 800125e:	e7c5      	b.n	80011ec <fuota_init+0x14>
 8001260:	2002      	movs	r0, #2
 8001262:	f031 ff95 	bl	8033190 <RegionAS923SubBandSet>
 8001266:	e7c3      	b.n	80011f0 <fuota_init+0x18>
 8001268:	2003      	movs	r0, #3
 800126a:	f031 ff91 	bl	8033190 <RegionAS923SubBandSet>
 800126e:	e7c1      	b.n	80011f4 <fuota_init+0x1c>
 8001270:	2004      	movs	r0, #4
 8001272:	f031 ff8d 	bl	8033190 <RegionAS923SubBandSet>
 8001276:	e7bf      	b.n	80011f8 <fuota_init+0x20>
 8001278:	4807      	ldr	r0, [pc, #28]	; (8001298 <fuota_init+0xc0>)
 800127a:	f7ff f9df 	bl	800063c <Serial_PutString>
 800127e:	f04f 30ff 	mov.w	r0, #4294967295	; 0xffffffff
 8001282:	e7e8      	b.n	8001256 <fuota_init+0x7e>
 8001284:	20006048 	.word	0x20006048
 8001288:	20006058 	.word	0x20006058
 800128c:	20006664 	.word	0x20006664
 8001290:	2000656c 	.word	0x2000656c
 8001294:	20006000 	.word	0x20006000
 8001298:	08002a6c 	.word	0x08002a6c

0800129c <bootloader_fuota_start>:
 800129c:	b510      	push	{r4, lr}
 800129e:	b084      	sub	sp, #16
 80012a0:	f04f 43b0 	mov.w	r3, #1476395008	; 0x58000000
 80012a4:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 80012a6:	f042 0204 	orr.w	r2, r2, #4
 80012aa:	649a      	str	r2, [r3, #72]	; 0x48
 80012ac:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 80012ae:	f002 0204 	and.w	r2, r2, #4
 80012b2:	9203      	str	r2, [sp, #12]
 80012b4:	9a03      	ldr	r2, [sp, #12]
 80012b6:	6c9a      	ldr	r2, [r3, #72]	; 0x48
 80012b8:	f042 0201 	orr.w	r2, r2, #1
 80012bc:	649a      	str	r2, [r3, #72]	; 0x48
 80012be:	6c9b      	ldr	r3, [r3, #72]	; 0x48
 80012c0:	f003 0301 	and.w	r3, r3, #1
 80012c4:	9302      	str	r3, [sp, #8]
 80012c6:	9b02      	ldr	r3, [sp, #8]
 80012c8:	2200      	movs	r2, #0
 80012ca:	4611      	mov	r1, r2
 80012cc:	200b      	movs	r0, #11
 80012ce:	f021 fd9d 	bl	8022e0c <HAL_NVIC_SetPriority>
 80012d2:	200b      	movs	r0, #11
 80012d4:	f021 fdcc 	bl	8022e70 <HAL_NVIC_EnableIRQ>
 80012d8:	f023 fda0 	bl	8024e1c <UTIL_TIMER_Init>
 80012dc:	f7ff ff7c 	bl	80011d8 <fuota_init>
 80012e0:	f01e fb24 	bl	801f92c <service_lora_fuota_join>
 80012e4:	4c09      	ldr	r4, [pc, #36]	; (800130c <bootloader_fuota_start+0x70>)
 80012e6:	2300      	movs	r3, #0
 80012e8:	9300      	str	r3, [sp, #0]
 80012ea:	4b09      	ldr	r3, [pc, #36]	; (8001310 <bootloader_fuota_start+0x74>)
 80012ec:	2201      	movs	r2, #1
 80012ee:	f04f 31ff 	mov.w	r1, #4294967295	; 0xffffffff
 80012f2:	4620      	mov	r0, r4
 80012f4:	f023 fda2 	bl	8024e3c <UTIL_TIMER_Create>
 80012f8:	f644 6120 	movw	r1, #20000	; 0x4e20
 80012fc:	4620      	mov	r0, r4
 80012fe:	f023 fecf 	bl	80250a0 <UTIL_TIMER_SetPeriod>
 8001302:	4620      	mov	r0, r4
 8001304:	f023 fe7a 	bl	8024ffc <UTIL_TIMER_Start>
 8001308:	b004      	add	sp, #16
 800130a:	bd10      	pop	{r4, pc}
 800130c:	20006678 	.word	0x20006678
 8001310:	08001421 	.word	0x08001421

08001314 <OnClassChange>:
 8001314:	b500      	push	{lr}
 8001316:	b083      	sub	sp, #12
 8001318:	2801      	cmp	r0, #1
 800131a:	d013      	beq.n	8001344 <OnClassChange+0x30>
 800131c:	2802      	cmp	r0, #2
 800131e:	d023      	beq.n	8001368 <OnClassChange+0x54>
 8001320:	4b15      	ldr	r3, [pc, #84]	; (8001378 <OnClassChange+0x64>)
 8001322:	2200      	movs	r2, #0
 8001324:	701a      	strb	r2, [r3, #0]
 8001326:	4b15      	ldr	r3, [pc, #84]	; (800137c <OnClassChange+0x68>)
 8001328:	781b      	ldrb	r3, [r3, #0]
 800132a:	b9d3      	cbnz	r3, 8001362 <OnClassChange+0x4e>
 800132c:	4814      	ldr	r0, [pc, #80]	; (8001380 <OnClassChange+0x6c>)
 800132e:	f7ff f9af 	bl	8000690 <Serial_Printf>
 8001332:	4814      	ldr	r0, [pc, #80]	; (8001384 <OnClassChange+0x70>)
 8001334:	f7ff f9ac 	bl	8000690 <Serial_Printf>
 8001338:	f7ff ffb0 	bl	800129c <bootloader_fuota_start>
 800133c:	4b12      	ldr	r3, [pc, #72]	; (8001388 <OnClassChange+0x74>)
 800133e:	2201      	movs	r2, #1
 8001340:	701a      	strb	r2, [r3, #0]
 8001342:	e00e      	b.n	8001362 <OnClassChange+0x4e>
 8001344:	2100      	movs	r1, #0
 8001346:	f88d 1000 	strb.w	r1, [sp]
 800134a:	f88d 1001 	strb.w	r1, [sp, #1]
 800134e:	9101      	str	r1, [sp, #4]
 8001350:	4668      	mov	r0, sp
 8001352:	f01e fc15 	bl	801fb80 <LmHandlerSend>
 8001356:	4b08      	ldr	r3, [pc, #32]	; (8001378 <OnClassChange+0x64>)
 8001358:	2201      	movs	r2, #1
 800135a:	701a      	strb	r2, [r3, #0]
 800135c:	480b      	ldr	r0, [pc, #44]	; (800138c <OnClassChange+0x78>)
 800135e:	f7ff f997 	bl	8000690 <Serial_Printf>
 8001362:	b003      	add	sp, #12
 8001364:	f85d fb04 	ldr.w	pc, [sp], #4
 8001368:	4b03      	ldr	r3, [pc, #12]	; (8001378 <OnClassChange+0x64>)
 800136a:	2201      	movs	r2, #1
 800136c:	701a      	strb	r2, [r3, #0]
 800136e:	4808      	ldr	r0, [pc, #32]	; (8001390 <OnClassChange+0x7c>)
 8001370:	f7ff f98e 	bl	8000690 <Serial_Printf>
 8001374:	e7f5      	b.n	8001362 <OnClassChange+0x4e>
 8001376:	bf00      	nop
 8001378:	2000665f 	.word	0x2000665f
 800137c:	2000665e 	.word	0x2000665e
 8001380:	08002a8c 	.word	0x08002a8c
 8001384:	08002a9c 	.word	0x08002a9c
 8001388:	20006085 	.word	0x20006085
 800138c:	08002aac 	.word	0x08002aac
 8001390:	08002ac0 	.word	0x08002ac0

08001394 <UplinkProcess>:
 8001394:	b500      	push	{lr}
 8001396:	b083      	sub	sp, #12
 8001398:	f01e fdfc 	bl	801ff94 <LmHandlerIsBusy>
 800139c:	b930      	cbnz	r0, 80013ac <UplinkProcess+0x18>
 800139e:	4a18      	ldr	r2, [pc, #96]	; (8001400 <UplinkProcess+0x6c>)
 80013a0:	7813      	ldrb	r3, [r2, #0]
 80013a2:	b2db      	uxtb	r3, r3
 80013a4:	2100      	movs	r1, #0
 80013a6:	7011      	strb	r1, [r2, #0]
 80013a8:	2b01      	cmp	r3, #1
 80013aa:	d002      	beq.n	80013b2 <UplinkProcess+0x1e>
 80013ac:	b003      	add	sp, #12
 80013ae:	f85d fb04 	ldr.w	pc, [sp], #4
 80013b2:	4b14      	ldr	r3, [pc, #80]	; (8001404 <UplinkProcess+0x70>)
 80013b4:	781b      	ldrb	r3, [r3, #0]
 80013b6:	2b00      	cmp	r3, #0
 80013b8:	d1f8      	bne.n	80013ac <UplinkProcess+0x18>
 80013ba:	4b13      	ldr	r3, [pc, #76]	; (8001408 <UplinkProcess+0x74>)
 80013bc:	781b      	ldrb	r3, [r3, #0]
 80013be:	b9cb      	cbnz	r3, 80013f4 <UplinkProcess+0x60>
 80013c0:	4b12      	ldr	r3, [pc, #72]	; (800140c <UplinkProcess+0x78>)
 80013c2:	781b      	ldrb	r3, [r3, #0]
 80013c4:	b913      	cbnz	r3, 80013cc <UplinkProcess+0x38>
 80013c6:	f01f f849 	bl	802045c <LmhpClockSyncAppTimeReq>
 80013ca:	e7ef      	b.n	80013ac <UplinkProcess+0x18>
 80013cc:	21ff      	movs	r1, #255	; 0xff
 80013ce:	2000      	movs	r0, #0
 80013d0:	f02b fb0e 	bl	802c9f0 <randr>
 80013d4:	4b0e      	ldr	r3, [pc, #56]	; (8001410 <UplinkProcess+0x7c>)
 80013d6:	7018      	strb	r0, [r3, #0]
 80013d8:	480e      	ldr	r0, [pc, #56]	; (8001414 <UplinkProcess+0x80>)
 80013da:	f7ff f92f 	bl	800063c <Serial_PutString>
 80013de:	4a0e      	ldr	r2, [pc, #56]	; (8001418 <UplinkProcess+0x84>)
 80013e0:	466b      	mov	r3, sp
 80013e2:	e892 0003 	ldmia.w	r2, {r0, r1}
 80013e6:	e883 0003 	stmia.w	r3, {r0, r1}
 80013ea:	2100      	movs	r1, #0
 80013ec:	4618      	mov	r0, r3
 80013ee:	f01e fbc7 	bl	801fb80 <LmHandlerSend>
 80013f2:	e7db      	b.n	80013ac <UplinkProcess+0x18>
 80013f4:	4809      	ldr	r0, [pc, #36]	; (800141c <UplinkProcess+0x88>)
 80013f6:	f7ff f921 	bl	800063c <Serial_PutString>
 80013fa:	f7ff fd39 	bl	8000e70 <__NVIC_SystemReset>
 80013fe:	bf00      	nop
 8001400:	20006660 	.word	0x20006660
 8001404:	2000665f 	.word	0x2000665f
 8001408:	2000665e 	.word	0x2000665e
 800140c:	200002e4 	.word	0x200002e4
 8001410:	2000656c 	.word	0x2000656c
 8001414:	08002ad4 	.word	0x08002ad4
 8001418:	080028a8 	.word	0x080028a8
 800141c:	08002ae8 	.word	0x08002ae8

08001420 <timer_callback>:
 8001420:	b508      	push	{r3, lr}
 8001422:	f02c fefb 	bl	802e21c <LoRaMacIsBusy>
 8001426:	b988      	cbnz	r0, 800144c <timer_callback+0x2c>
 8001428:	4b09      	ldr	r3, [pc, #36]	; (8001450 <timer_callback+0x30>)
 800142a:	781b      	ldrb	r3, [r3, #0]
 800142c:	b14b      	cbz	r3, 8001442 <timer_callback+0x22>
 800142e:	4b09      	ldr	r3, [pc, #36]	; (8001454 <timer_callback+0x34>)
 8001430:	2201      	movs	r2, #1
 8001432:	701a      	strb	r2, [r3, #0]
 8001434:	4b08      	ldr	r3, [pc, #32]	; (8001458 <timer_callback+0x38>)
 8001436:	781b      	ldrb	r3, [r3, #0]
 8001438:	4293      	cmp	r3, r2
 800143a:	d107      	bne.n	800144c <timer_callback+0x2c>
 800143c:	f7ff ffaa 	bl	8001394 <UplinkProcess>
 8001440:	e004      	b.n	800144c <timer_callback+0x2c>
 8001442:	4806      	ldr	r0, [pc, #24]	; (800145c <timer_callback+0x3c>)
 8001444:	f7ff f8fa 	bl	800063c <Serial_PutString>
 8001448:	f01e fa70 	bl	801f92c <service_lora_fuota_join>
 800144c:	bd08      	pop	{r3, pc}
 800144e:	bf00      	nop
 8001450:	20006674 	.word	0x20006674
 8001454:	20006660 	.word	0x20006660
 8001458:	20006085 	.word	0x20006085
 800145c:	08002b08 	.word	0x08002b08

08001460 <UART_EndRxTransfer>:
 8001460:	6802      	ldr	r2, [r0, #0]
 8001462:	e852 3f00 	ldrex	r3, [r2]
 8001466:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 800146a:	e842 3100 	strex	r1, r3, [r2]
 800146e:	2900      	cmp	r1, #0
 8001470:	d1f6      	bne.n	8001460 <UART_EndRxTransfer>
 8001472:	6802      	ldr	r2, [r0, #0]
 8001474:	f102 0308 	add.w	r3, r2, #8
 8001478:	e853 3f00 	ldrex	r3, [r3]
 800147c:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001480:	f023 0301 	bic.w	r3, r3, #1
 8001484:	3208      	adds	r2, #8
 8001486:	e842 3100 	strex	r1, r3, [r2]
 800148a:	2900      	cmp	r1, #0
 800148c:	d1f1      	bne.n	8001472 <UART_EndRxTransfer+0x12>
 800148e:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 8001490:	2b01      	cmp	r3, #1
 8001492:	d006      	beq.n	80014a2 <UART_EndRxTransfer+0x42>
 8001494:	2320      	movs	r3, #32
 8001496:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 800149a:	2300      	movs	r3, #0
 800149c:	66c3      	str	r3, [r0, #108]	; 0x6c
 800149e:	6703      	str	r3, [r0, #112]	; 0x70
 80014a0:	4770      	bx	lr
 80014a2:	6802      	ldr	r2, [r0, #0]
 80014a4:	e852 3f00 	ldrex	r3, [r2]
 80014a8:	f023 0310 	bic.w	r3, r3, #16
 80014ac:	e842 3100 	strex	r1, r3, [r2]
 80014b0:	2900      	cmp	r1, #0
 80014b2:	d1f6      	bne.n	80014a2 <UART_EndRxTransfer+0x42>
 80014b4:	e7ee      	b.n	8001494 <UART_EndRxTransfer+0x34>

080014b6 <HAL_UART_DeInit>:
 80014b6:	b1e8      	cbz	r0, 80014f4 <HAL_UART_DeInit+0x3e>
 80014b8:	b538      	push	{r3, r4, r5, lr}
 80014ba:	4605      	mov	r5, r0
 80014bc:	2324      	movs	r3, #36	; 0x24
 80014be:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80014c2:	6802      	ldr	r2, [r0, #0]
 80014c4:	6813      	ldr	r3, [r2, #0]
 80014c6:	f023 0301 	bic.w	r3, r3, #1
 80014ca:	6013      	str	r3, [r2, #0]
 80014cc:	6803      	ldr	r3, [r0, #0]
 80014ce:	2400      	movs	r4, #0
 80014d0:	601c      	str	r4, [r3, #0]
 80014d2:	6803      	ldr	r3, [r0, #0]
 80014d4:	605c      	str	r4, [r3, #4]
 80014d6:	6803      	ldr	r3, [r0, #0]
 80014d8:	609c      	str	r4, [r3, #8]
 80014da:	f7ff faf1 	bl	8000ac0 <HAL_UART_MspDeInit>
 80014de:	f8c5 408c 	str.w	r4, [r5, #140]	; 0x8c
 80014e2:	f8c5 4084 	str.w	r4, [r5, #132]	; 0x84
 80014e6:	f8c5 4088 	str.w	r4, [r5, #136]	; 0x88
 80014ea:	66ec      	str	r4, [r5, #108]	; 0x6c
 80014ec:	f885 4080 	strb.w	r4, [r5, #128]	; 0x80
 80014f0:	4620      	mov	r0, r4
 80014f2:	bd38      	pop	{r3, r4, r5, pc}
 80014f4:	2001      	movs	r0, #1
 80014f6:	4770      	bx	lr

080014f8 <HAL_UART_TxCpltCallback>:
 80014f8:	4770      	bx	lr

080014fa <UART_EndTransmit_IT>:
 80014fa:	b508      	push	{r3, lr}
 80014fc:	6802      	ldr	r2, [r0, #0]
 80014fe:	e852 3f00 	ldrex	r3, [r2]
 8001502:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 8001506:	e842 3100 	strex	r1, r3, [r2]
 800150a:	2900      	cmp	r1, #0
 800150c:	d1f6      	bne.n	80014fc <UART_EndTransmit_IT+0x2>
 800150e:	2320      	movs	r3, #32
 8001510:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8001514:	2300      	movs	r3, #0
 8001516:	6743      	str	r3, [r0, #116]	; 0x74
 8001518:	f7ff ffee 	bl	80014f8 <HAL_UART_TxCpltCallback>
 800151c:	bd08      	pop	{r3, pc}

0800151e <HAL_UART_ErrorCallback>:
 800151e:	4770      	bx	lr

08001520 <UART_DMAAbortOnError>:
 8001520:	b508      	push	{r3, lr}
 8001522:	6a80      	ldr	r0, [r0, #40]	; 0x28
 8001524:	2300      	movs	r3, #0
 8001526:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 800152a:	f8a0 3056 	strh.w	r3, [r0, #86]	; 0x56
 800152e:	f7ff fff6 	bl	800151e <HAL_UART_ErrorCallback>
 8001532:	bd08      	pop	{r3, pc}

08001534 <HAL_UART_AbortReceiveCpltCallback>:
 8001534:	4770      	bx	lr
	...

08001538 <HAL_UART_AbortReceive_IT>:
 8001538:	b510      	push	{r4, lr}
 800153a:	4604      	mov	r4, r0
 800153c:	6822      	ldr	r2, [r4, #0]
 800153e:	e852 3f00 	ldrex	r3, [r2]
 8001542:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001546:	e842 3100 	strex	r1, r3, [r2]
 800154a:	2900      	cmp	r1, #0
 800154c:	d1f6      	bne.n	800153c <HAL_UART_AbortReceive_IT+0x4>
 800154e:	6822      	ldr	r2, [r4, #0]
 8001550:	f102 0308 	add.w	r3, r2, #8
 8001554:	e853 3f00 	ldrex	r3, [r3]
 8001558:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 800155c:	f023 0301 	bic.w	r3, r3, #1
 8001560:	3208      	adds	r2, #8
 8001562:	e842 3100 	strex	r1, r3, [r2]
 8001566:	2900      	cmp	r1, #0
 8001568:	d1f1      	bne.n	800154e <HAL_UART_AbortReceive_IT+0x16>
 800156a:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 800156c:	2b01      	cmp	r3, #1
 800156e:	d01c      	beq.n	80015aa <HAL_UART_AbortReceive_IT+0x72>
 8001570:	6823      	ldr	r3, [r4, #0]
 8001572:	689a      	ldr	r2, [r3, #8]
 8001574:	f012 0f40 	tst.w	r2, #64	; 0x40
 8001578:	d035      	beq.n	80015e6 <HAL_UART_AbortReceive_IT+0xae>
 800157a:	6822      	ldr	r2, [r4, #0]
 800157c:	f102 0308 	add.w	r3, r2, #8
 8001580:	e853 3f00 	ldrex	r3, [r3]
 8001584:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 8001588:	3208      	adds	r2, #8
 800158a:	e842 3100 	strex	r1, r3, [r2]
 800158e:	2900      	cmp	r1, #0
 8001590:	d1f3      	bne.n	800157a <HAL_UART_AbortReceive_IT+0x42>
 8001592:	6fe3      	ldr	r3, [r4, #124]	; 0x7c
 8001594:	b19b      	cbz	r3, 80015be <HAL_UART_AbortReceive_IT+0x86>
 8001596:	4a1b      	ldr	r2, [pc, #108]	; (8001604 <HAL_UART_AbortReceive_IT+0xcc>)
 8001598:	639a      	str	r2, [r3, #56]	; 0x38
 800159a:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 800159c:	f02b f898 	bl	802c6d0 <HAL_DMA_Abort_IT>
 80015a0:	b370      	cbz	r0, 8001600 <HAL_UART_AbortReceive_IT+0xc8>
 80015a2:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 80015a4:	6b83      	ldr	r3, [r0, #56]	; 0x38
 80015a6:	4798      	blx	r3
 80015a8:	e02a      	b.n	8001600 <HAL_UART_AbortReceive_IT+0xc8>
 80015aa:	6822      	ldr	r2, [r4, #0]
 80015ac:	e852 3f00 	ldrex	r3, [r2]
 80015b0:	f023 0310 	bic.w	r3, r3, #16
 80015b4:	e842 3100 	strex	r1, r3, [r2]
 80015b8:	2900      	cmp	r1, #0
 80015ba:	d1f6      	bne.n	80015aa <HAL_UART_AbortReceive_IT+0x72>
 80015bc:	e7d8      	b.n	8001570 <HAL_UART_AbortReceive_IT+0x38>
 80015be:	2300      	movs	r3, #0
 80015c0:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 80015c4:	65a3      	str	r3, [r4, #88]	; 0x58
 80015c6:	6822      	ldr	r2, [r4, #0]
 80015c8:	210f      	movs	r1, #15
 80015ca:	6211      	str	r1, [r2, #32]
 80015cc:	6821      	ldr	r1, [r4, #0]
 80015ce:	698a      	ldr	r2, [r1, #24]
 80015d0:	f042 0208 	orr.w	r2, r2, #8
 80015d4:	618a      	str	r2, [r1, #24]
 80015d6:	2220      	movs	r2, #32
 80015d8:	f8c4 2088 	str.w	r2, [r4, #136]	; 0x88
 80015dc:	66e3      	str	r3, [r4, #108]	; 0x6c
 80015de:	4620      	mov	r0, r4
 80015e0:	f7ff ffa8 	bl	8001534 <HAL_UART_AbortReceiveCpltCallback>
 80015e4:	e00c      	b.n	8001600 <HAL_UART_AbortReceive_IT+0xc8>
 80015e6:	2200      	movs	r2, #0
 80015e8:	f8a4 205e 	strh.w	r2, [r4, #94]	; 0x5e
 80015ec:	65a2      	str	r2, [r4, #88]	; 0x58
 80015ee:	210f      	movs	r1, #15
 80015f0:	6219      	str	r1, [r3, #32]
 80015f2:	2320      	movs	r3, #32
 80015f4:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80015f8:	66e2      	str	r2, [r4, #108]	; 0x6c
 80015fa:	4620      	mov	r0, r4
 80015fc:	f7ff ff9a 	bl	8001534 <HAL_UART_AbortReceiveCpltCallback>
 8001600:	2000      	movs	r0, #0
 8001602:	bd10      	pop	{r4, pc}
 8001604:	08001609 	.word	0x08001609

08001608 <UART_DMARxOnlyAbortCallback>:
 8001608:	b508      	push	{r3, lr}
 800160a:	6a80      	ldr	r0, [r0, #40]	; 0x28
 800160c:	2200      	movs	r2, #0
 800160e:	f8a0 205e 	strh.w	r2, [r0, #94]	; 0x5e
 8001612:	6803      	ldr	r3, [r0, #0]
 8001614:	210f      	movs	r1, #15
 8001616:	6219      	str	r1, [r3, #32]
 8001618:	6801      	ldr	r1, [r0, #0]
 800161a:	698b      	ldr	r3, [r1, #24]
 800161c:	f043 0308 	orr.w	r3, r3, #8
 8001620:	618b      	str	r3, [r1, #24]
 8001622:	2320      	movs	r3, #32
 8001624:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001628:	66c2      	str	r2, [r0, #108]	; 0x6c
 800162a:	f7ff ff83 	bl	8001534 <HAL_UART_AbortReceiveCpltCallback>
 800162e:	bd08      	pop	{r3, pc}

08001630 <HAL_UARTEx_RxEventCallback>:
 8001630:	4770      	bx	lr
	...

08001634 <HAL_UART_IRQHandler>:
 8001634:	b570      	push	{r4, r5, r6, lr}
 8001636:	4604      	mov	r4, r0
 8001638:	6801      	ldr	r1, [r0, #0]
 800163a:	69cb      	ldr	r3, [r1, #28]
 800163c:	6808      	ldr	r0, [r1, #0]
 800163e:	688d      	ldr	r5, [r1, #8]
 8001640:	f640 020f 	movw	r2, #2063	; 0x80f
 8001644:	401a      	ands	r2, r3
 8001646:	d108      	bne.n	800165a <HAL_UART_IRQHandler+0x26>
 8001648:	f013 0f20 	tst.w	r3, #32
 800164c:	d005      	beq.n	800165a <HAL_UART_IRQHandler+0x26>
 800164e:	f010 0f20 	tst.w	r0, #32
 8001652:	d134      	bne.n	80016be <HAL_UART_IRQHandler+0x8a>
 8001654:	f015 5f80 	tst.w	r5, #268435456	; 0x10000000
 8001658:	d131      	bne.n	80016be <HAL_UART_IRQHandler+0x8a>
 800165a:	b12a      	cbz	r2, 8001668 <HAL_UART_IRQHandler+0x34>
 800165c:	4a95      	ldr	r2, [pc, #596]	; (80018b4 <HAL_UART_IRQHandler+0x280>)
 800165e:	402a      	ands	r2, r5
 8001660:	d133      	bne.n	80016ca <HAL_UART_IRQHandler+0x96>
 8001662:	4e95      	ldr	r6, [pc, #596]	; (80018b8 <HAL_UART_IRQHandler+0x284>)
 8001664:	4230      	tst	r0, r6
 8001666:	d130      	bne.n	80016ca <HAL_UART_IRQHandler+0x96>
 8001668:	6ee2      	ldr	r2, [r4, #108]	; 0x6c
 800166a:	2a01      	cmp	r2, #1
 800166c:	f000 80c3 	beq.w	80017f6 <HAL_UART_IRQHandler+0x1c2>
 8001670:	f413 1f80 	tst.w	r3, #1048576	; 0x100000
 8001674:	d003      	beq.n	800167e <HAL_UART_IRQHandler+0x4a>
 8001676:	f415 0f80 	tst.w	r5, #4194304	; 0x400000
 800167a:	f040 815b 	bne.w	8001934 <HAL_UART_IRQHandler+0x300>
 800167e:	f013 0f80 	tst.w	r3, #128	; 0x80
 8001682:	d007      	beq.n	8001694 <HAL_UART_IRQHandler+0x60>
 8001684:	f010 0f80 	tst.w	r0, #128	; 0x80
 8001688:	f040 815b 	bne.w	8001942 <HAL_UART_IRQHandler+0x30e>
 800168c:	f415 0f00 	tst.w	r5, #8388608	; 0x800000
 8001690:	f040 8157 	bne.w	8001942 <HAL_UART_IRQHandler+0x30e>
 8001694:	f013 0f40 	tst.w	r3, #64	; 0x40
 8001698:	d003      	beq.n	80016a2 <HAL_UART_IRQHandler+0x6e>
 800169a:	f010 0f40 	tst.w	r0, #64	; 0x40
 800169e:	f040 8157 	bne.w	8001950 <HAL_UART_IRQHandler+0x31c>
 80016a2:	f413 0f00 	tst.w	r3, #8388608	; 0x800000
 80016a6:	d003      	beq.n	80016b0 <HAL_UART_IRQHandler+0x7c>
 80016a8:	f010 4f80 	tst.w	r0, #1073741824	; 0x40000000
 80016ac:	f040 8154 	bne.w	8001958 <HAL_UART_IRQHandler+0x324>
 80016b0:	f013 7f80 	tst.w	r3, #16777216	; 0x1000000
 80016b4:	d002      	beq.n	80016bc <HAL_UART_IRQHandler+0x88>
 80016b6:	2800      	cmp	r0, #0
 80016b8:	f2c0 8152 	blt.w	8001960 <HAL_UART_IRQHandler+0x32c>
 80016bc:	bd70      	pop	{r4, r5, r6, pc}
 80016be:	6f23      	ldr	r3, [r4, #112]	; 0x70
 80016c0:	2b00      	cmp	r3, #0
 80016c2:	d0fb      	beq.n	80016bc <HAL_UART_IRQHandler+0x88>
 80016c4:	4620      	mov	r0, r4
 80016c6:	4798      	blx	r3
 80016c8:	e7f8      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 80016ca:	f013 0f01 	tst.w	r3, #1
 80016ce:	d009      	beq.n	80016e4 <HAL_UART_IRQHandler+0xb0>
 80016d0:	f410 7f80 	tst.w	r0, #256	; 0x100
 80016d4:	d006      	beq.n	80016e4 <HAL_UART_IRQHandler+0xb0>
 80016d6:	2601      	movs	r6, #1
 80016d8:	620e      	str	r6, [r1, #32]
 80016da:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 80016de:	4331      	orrs	r1, r6
 80016e0:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 80016e4:	f013 0f02 	tst.w	r3, #2
 80016e8:	d00b      	beq.n	8001702 <HAL_UART_IRQHandler+0xce>
 80016ea:	f015 0f01 	tst.w	r5, #1
 80016ee:	d008      	beq.n	8001702 <HAL_UART_IRQHandler+0xce>
 80016f0:	6821      	ldr	r1, [r4, #0]
 80016f2:	2602      	movs	r6, #2
 80016f4:	620e      	str	r6, [r1, #32]
 80016f6:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 80016fa:	f041 0104 	orr.w	r1, r1, #4
 80016fe:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 8001702:	f013 0f04 	tst.w	r3, #4
 8001706:	d00b      	beq.n	8001720 <HAL_UART_IRQHandler+0xec>
 8001708:	f015 0f01 	tst.w	r5, #1
 800170c:	d008      	beq.n	8001720 <HAL_UART_IRQHandler+0xec>
 800170e:	6821      	ldr	r1, [r4, #0]
 8001710:	2604      	movs	r6, #4
 8001712:	620e      	str	r6, [r1, #32]
 8001714:	f8d4 108c 	ldr.w	r1, [r4, #140]	; 0x8c
 8001718:	f041 0102 	orr.w	r1, r1, #2
 800171c:	f8c4 108c 	str.w	r1, [r4, #140]	; 0x8c
 8001720:	f013 0f08 	tst.w	r3, #8
 8001724:	d00b      	beq.n	800173e <HAL_UART_IRQHandler+0x10a>
 8001726:	f010 0f20 	tst.w	r0, #32
 800172a:	d100      	bne.n	800172e <HAL_UART_IRQHandler+0xfa>
 800172c:	b13a      	cbz	r2, 800173e <HAL_UART_IRQHandler+0x10a>
 800172e:	6822      	ldr	r2, [r4, #0]
 8001730:	2108      	movs	r1, #8
 8001732:	6211      	str	r1, [r2, #32]
 8001734:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 8001738:	430a      	orrs	r2, r1
 800173a:	f8c4 208c 	str.w	r2, [r4, #140]	; 0x8c
 800173e:	f413 6f00 	tst.w	r3, #2048	; 0x800
 8001742:	d00c      	beq.n	800175e <HAL_UART_IRQHandler+0x12a>
 8001744:	f010 6f80 	tst.w	r0, #67108864	; 0x4000000
 8001748:	d009      	beq.n	800175e <HAL_UART_IRQHandler+0x12a>
 800174a:	6822      	ldr	r2, [r4, #0]
 800174c:	f44f 6100 	mov.w	r1, #2048	; 0x800
 8001750:	6211      	str	r1, [r2, #32]
 8001752:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 8001756:	f042 0220 	orr.w	r2, r2, #32
 800175a:	f8c4 208c 	str.w	r2, [r4, #140]	; 0x8c
 800175e:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 8001762:	2a00      	cmp	r2, #0
 8001764:	d0aa      	beq.n	80016bc <HAL_UART_IRQHandler+0x88>
 8001766:	f013 0f20 	tst.w	r3, #32
 800176a:	d009      	beq.n	8001780 <HAL_UART_IRQHandler+0x14c>
 800176c:	f010 0f20 	tst.w	r0, #32
 8001770:	d102      	bne.n	8001778 <HAL_UART_IRQHandler+0x144>
 8001772:	f015 5f80 	tst.w	r5, #268435456	; 0x10000000
 8001776:	d003      	beq.n	8001780 <HAL_UART_IRQHandler+0x14c>
 8001778:	6f23      	ldr	r3, [r4, #112]	; 0x70
 800177a:	b10b      	cbz	r3, 8001780 <HAL_UART_IRQHandler+0x14c>
 800177c:	4620      	mov	r0, r4
 800177e:	4798      	blx	r3
 8001780:	f8d4 208c 	ldr.w	r2, [r4, #140]	; 0x8c
 8001784:	6823      	ldr	r3, [r4, #0]
 8001786:	689b      	ldr	r3, [r3, #8]
 8001788:	f013 0f40 	tst.w	r3, #64	; 0x40
 800178c:	d102      	bne.n	8001794 <HAL_UART_IRQHandler+0x160>
 800178e:	f012 0f28 	tst.w	r2, #40	; 0x28
 8001792:	d029      	beq.n	80017e8 <HAL_UART_IRQHandler+0x1b4>
 8001794:	4620      	mov	r0, r4
 8001796:	f7ff fe63 	bl	8001460 <UART_EndRxTransfer>
 800179a:	6823      	ldr	r3, [r4, #0]
 800179c:	689b      	ldr	r3, [r3, #8]
 800179e:	f013 0f40 	tst.w	r3, #64	; 0x40
 80017a2:	d01d      	beq.n	80017e0 <HAL_UART_IRQHandler+0x1ac>
 80017a4:	6822      	ldr	r2, [r4, #0]
 80017a6:	f102 0308 	add.w	r3, r2, #8
 80017aa:	e853 3f00 	ldrex	r3, [r3]
 80017ae:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 80017b2:	3208      	adds	r2, #8
 80017b4:	e842 3100 	strex	r1, r3, [r2]
 80017b8:	2900      	cmp	r1, #0
 80017ba:	d1f3      	bne.n	80017a4 <HAL_UART_IRQHandler+0x170>
 80017bc:	6fe3      	ldr	r3, [r4, #124]	; 0x7c
 80017be:	b15b      	cbz	r3, 80017d8 <HAL_UART_IRQHandler+0x1a4>
 80017c0:	4a3e      	ldr	r2, [pc, #248]	; (80018bc <HAL_UART_IRQHandler+0x288>)
 80017c2:	639a      	str	r2, [r3, #56]	; 0x38
 80017c4:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 80017c6:	f02a ff83 	bl	802c6d0 <HAL_DMA_Abort_IT>
 80017ca:	2800      	cmp	r0, #0
 80017cc:	f43f af76 	beq.w	80016bc <HAL_UART_IRQHandler+0x88>
 80017d0:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 80017d2:	6b83      	ldr	r3, [r0, #56]	; 0x38
 80017d4:	4798      	blx	r3
 80017d6:	e771      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 80017d8:	4620      	mov	r0, r4
 80017da:	f7ff fea0 	bl	800151e <HAL_UART_ErrorCallback>
 80017de:	e76d      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 80017e0:	4620      	mov	r0, r4
 80017e2:	f7ff fe9c 	bl	800151e <HAL_UART_ErrorCallback>
 80017e6:	e769      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 80017e8:	4620      	mov	r0, r4
 80017ea:	f7ff fe98 	bl	800151e <HAL_UART_ErrorCallback>
 80017ee:	2300      	movs	r3, #0
 80017f0:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 80017f4:	e762      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 80017f6:	f013 0f10 	tst.w	r3, #16
 80017fa:	f43f af39 	beq.w	8001670 <HAL_UART_IRQHandler+0x3c>
 80017fe:	f010 0f10 	tst.w	r0, #16
 8001802:	f43f af35 	beq.w	8001670 <HAL_UART_IRQHandler+0x3c>
 8001806:	2310      	movs	r3, #16
 8001808:	620b      	str	r3, [r1, #32]
 800180a:	6823      	ldr	r3, [r4, #0]
 800180c:	689b      	ldr	r3, [r3, #8]
 800180e:	f013 0f40 	tst.w	r3, #64	; 0x40
 8001812:	d055      	beq.n	80018c0 <HAL_UART_IRQHandler+0x28c>
 8001814:	6fe2      	ldr	r2, [r4, #124]	; 0x7c
 8001816:	6813      	ldr	r3, [r2, #0]
 8001818:	685b      	ldr	r3, [r3, #4]
 800181a:	b29b      	uxth	r3, r3
 800181c:	2b00      	cmp	r3, #0
 800181e:	f43f af4d 	beq.w	80016bc <HAL_UART_IRQHandler+0x88>
 8001822:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001826:	4299      	cmp	r1, r3
 8001828:	f67f af48 	bls.w	80016bc <HAL_UART_IRQHandler+0x88>
 800182c:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001830:	6813      	ldr	r3, [r2, #0]
 8001832:	681b      	ldr	r3, [r3, #0]
 8001834:	f013 0f20 	tst.w	r3, #32
 8001838:	d131      	bne.n	800189e <HAL_UART_IRQHandler+0x26a>
 800183a:	6822      	ldr	r2, [r4, #0]
 800183c:	e852 3f00 	ldrex	r3, [r2]
 8001840:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001844:	e842 3100 	strex	r1, r3, [r2]
 8001848:	2900      	cmp	r1, #0
 800184a:	d1f6      	bne.n	800183a <HAL_UART_IRQHandler+0x206>
 800184c:	6822      	ldr	r2, [r4, #0]
 800184e:	f102 0308 	add.w	r3, r2, #8
 8001852:	e853 3f00 	ldrex	r3, [r3]
 8001856:	f023 0301 	bic.w	r3, r3, #1
 800185a:	3208      	adds	r2, #8
 800185c:	e842 3100 	strex	r1, r3, [r2]
 8001860:	2900      	cmp	r1, #0
 8001862:	d1f3      	bne.n	800184c <HAL_UART_IRQHandler+0x218>
 8001864:	6822      	ldr	r2, [r4, #0]
 8001866:	f102 0308 	add.w	r3, r2, #8
 800186a:	e853 3f00 	ldrex	r3, [r3]
 800186e:	f023 0340 	bic.w	r3, r3, #64	; 0x40
 8001872:	3208      	adds	r2, #8
 8001874:	e842 3100 	strex	r1, r3, [r2]
 8001878:	2900      	cmp	r1, #0
 800187a:	d1f3      	bne.n	8001864 <HAL_UART_IRQHandler+0x230>
 800187c:	2320      	movs	r3, #32
 800187e:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001882:	2300      	movs	r3, #0
 8001884:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001886:	6822      	ldr	r2, [r4, #0]
 8001888:	e852 3f00 	ldrex	r3, [r2]
 800188c:	f023 0310 	bic.w	r3, r3, #16
 8001890:	e842 3100 	strex	r1, r3, [r2]
 8001894:	2900      	cmp	r1, #0
 8001896:	d1f6      	bne.n	8001886 <HAL_UART_IRQHandler+0x252>
 8001898:	6fe0      	ldr	r0, [r4, #124]	; 0x7c
 800189a:	f02a fee3 	bl	802c664 <HAL_DMA_Abort>
 800189e:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 80018a2:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 80018a6:	b29b      	uxth	r3, r3
 80018a8:	1ac9      	subs	r1, r1, r3
 80018aa:	b289      	uxth	r1, r1
 80018ac:	4620      	mov	r0, r4
 80018ae:	f7ff febf 	bl	8001630 <HAL_UARTEx_RxEventCallback>
 80018b2:	e703      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 80018b4:	10000001 	.word	0x10000001
 80018b8:	04000120 	.word	0x04000120
 80018bc:	08001521 	.word	0x08001521
 80018c0:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 80018c4:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 80018c8:	b29b      	uxth	r3, r3
 80018ca:	1ac9      	subs	r1, r1, r3
 80018cc:	b289      	uxth	r1, r1
 80018ce:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 80018d2:	b29b      	uxth	r3, r3
 80018d4:	2b00      	cmp	r3, #0
 80018d6:	f43f aef1 	beq.w	80016bc <HAL_UART_IRQHandler+0x88>
 80018da:	2900      	cmp	r1, #0
 80018dc:	f43f aeee 	beq.w	80016bc <HAL_UART_IRQHandler+0x88>
 80018e0:	6822      	ldr	r2, [r4, #0]
 80018e2:	e852 3f00 	ldrex	r3, [r2]
 80018e6:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 80018ea:	e842 3000 	strex	r0, r3, [r2]
 80018ee:	2800      	cmp	r0, #0
 80018f0:	d1f6      	bne.n	80018e0 <HAL_UART_IRQHandler+0x2ac>
 80018f2:	6822      	ldr	r2, [r4, #0]
 80018f4:	f102 0308 	add.w	r3, r2, #8
 80018f8:	e853 3f00 	ldrex	r3, [r3]
 80018fc:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001900:	f023 0301 	bic.w	r3, r3, #1
 8001904:	3208      	adds	r2, #8
 8001906:	e842 3000 	strex	r0, r3, [r2]
 800190a:	2800      	cmp	r0, #0
 800190c:	d1f1      	bne.n	80018f2 <HAL_UART_IRQHandler+0x2be>
 800190e:	2320      	movs	r3, #32
 8001910:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001914:	2300      	movs	r3, #0
 8001916:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001918:	6723      	str	r3, [r4, #112]	; 0x70
 800191a:	6822      	ldr	r2, [r4, #0]
 800191c:	e852 3f00 	ldrex	r3, [r2]
 8001920:	f023 0310 	bic.w	r3, r3, #16
 8001924:	e842 3000 	strex	r0, r3, [r2]
 8001928:	2800      	cmp	r0, #0
 800192a:	d1f6      	bne.n	800191a <HAL_UART_IRQHandler+0x2e6>
 800192c:	4620      	mov	r0, r4
 800192e:	f7ff fe7f 	bl	8001630 <HAL_UARTEx_RxEventCallback>
 8001932:	e6c3      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 8001934:	f44f 1380 	mov.w	r3, #1048576	; 0x100000
 8001938:	620b      	str	r3, [r1, #32]
 800193a:	4620      	mov	r0, r4
 800193c:	f000 fef2 	bl	8002724 <HAL_UARTEx_WakeupCallback>
 8001940:	e6bc      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 8001942:	6f63      	ldr	r3, [r4, #116]	; 0x74
 8001944:	2b00      	cmp	r3, #0
 8001946:	f43f aeb9 	beq.w	80016bc <HAL_UART_IRQHandler+0x88>
 800194a:	4620      	mov	r0, r4
 800194c:	4798      	blx	r3
 800194e:	e6b5      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 8001950:	4620      	mov	r0, r4
 8001952:	f7ff fdd2 	bl	80014fa <UART_EndTransmit_IT>
 8001956:	e6b1      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 8001958:	4620      	mov	r0, r4
 800195a:	f000 fee5 	bl	8002728 <HAL_UARTEx_TxFifoEmptyCallback>
 800195e:	e6ad      	b.n	80016bc <HAL_UART_IRQHandler+0x88>
 8001960:	4620      	mov	r0, r4
 8001962:	f000 fee0 	bl	8002726 <HAL_UARTEx_RxFifoFullCallback>
 8001966:	e6a9      	b.n	80016bc <HAL_UART_IRQHandler+0x88>

08001968 <UART_RxISR_8BIT>:
 8001968:	b508      	push	{r3, lr}
 800196a:	f8b0 3060 	ldrh.w	r3, [r0, #96]	; 0x60
 800196e:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001972:	2a22      	cmp	r2, #34	; 0x22
 8001974:	d005      	beq.n	8001982 <UART_RxISR_8BIT+0x1a>
 8001976:	6802      	ldr	r2, [r0, #0]
 8001978:	6993      	ldr	r3, [r2, #24]
 800197a:	f043 0308 	orr.w	r3, r3, #8
 800197e:	6193      	str	r3, [r2, #24]
 8001980:	bd08      	pop	{r3, pc}
 8001982:	6802      	ldr	r2, [r0, #0]
 8001984:	6a51      	ldr	r1, [r2, #36]	; 0x24
 8001986:	b2db      	uxtb	r3, r3
 8001988:	6d82      	ldr	r2, [r0, #88]	; 0x58
 800198a:	400b      	ands	r3, r1
 800198c:	7013      	strb	r3, [r2, #0]
 800198e:	6d83      	ldr	r3, [r0, #88]	; 0x58
 8001990:	3301      	adds	r3, #1
 8001992:	6583      	str	r3, [r0, #88]	; 0x58
 8001994:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001998:	b29b      	uxth	r3, r3
 800199a:	3b01      	subs	r3, #1
 800199c:	b29b      	uxth	r3, r3
 800199e:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 80019a2:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 80019a6:	b29b      	uxth	r3, r3
 80019a8:	2b00      	cmp	r3, #0
 80019aa:	d1e9      	bne.n	8001980 <UART_RxISR_8BIT+0x18>
 80019ac:	6802      	ldr	r2, [r0, #0]
 80019ae:	e852 3f00 	ldrex	r3, [r2]
 80019b2:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 80019b6:	e842 3100 	strex	r1, r3, [r2]
 80019ba:	2900      	cmp	r1, #0
 80019bc:	d1f6      	bne.n	80019ac <UART_RxISR_8BIT+0x44>
 80019be:	6802      	ldr	r2, [r0, #0]
 80019c0:	f102 0308 	add.w	r3, r2, #8
 80019c4:	e853 3f00 	ldrex	r3, [r3]
 80019c8:	f023 0301 	bic.w	r3, r3, #1
 80019cc:	3208      	adds	r2, #8
 80019ce:	e842 3100 	strex	r1, r3, [r2]
 80019d2:	2900      	cmp	r1, #0
 80019d4:	d1f3      	bne.n	80019be <UART_RxISR_8BIT+0x56>
 80019d6:	2320      	movs	r3, #32
 80019d8:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 80019dc:	2300      	movs	r3, #0
 80019de:	6703      	str	r3, [r0, #112]	; 0x70
 80019e0:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 80019e2:	2b01      	cmp	r3, #1
 80019e4:	d116      	bne.n	8001a14 <UART_RxISR_8BIT+0xac>
 80019e6:	2300      	movs	r3, #0
 80019e8:	66c3      	str	r3, [r0, #108]	; 0x6c
 80019ea:	6802      	ldr	r2, [r0, #0]
 80019ec:	e852 3f00 	ldrex	r3, [r2]
 80019f0:	f023 0310 	bic.w	r3, r3, #16
 80019f4:	e842 3100 	strex	r1, r3, [r2]
 80019f8:	2900      	cmp	r1, #0
 80019fa:	d1f6      	bne.n	80019ea <UART_RxISR_8BIT+0x82>
 80019fc:	6803      	ldr	r3, [r0, #0]
 80019fe:	69da      	ldr	r2, [r3, #28]
 8001a00:	f012 0f10 	tst.w	r2, #16
 8001a04:	d001      	beq.n	8001a0a <UART_RxISR_8BIT+0xa2>
 8001a06:	2210      	movs	r2, #16
 8001a08:	621a      	str	r2, [r3, #32]
 8001a0a:	f8b0 105c 	ldrh.w	r1, [r0, #92]	; 0x5c
 8001a0e:	f7ff fe0f 	bl	8001630 <HAL_UARTEx_RxEventCallback>
 8001a12:	e7b5      	b.n	8001980 <UART_RxISR_8BIT+0x18>
 8001a14:	f7fe ffee 	bl	80009f4 <HAL_UART_RxCpltCallback>
 8001a18:	e7b2      	b.n	8001980 <UART_RxISR_8BIT+0x18>

08001a1a <UART_RxISR_16BIT>:
 8001a1a:	b508      	push	{r3, lr}
 8001a1c:	f8b0 2060 	ldrh.w	r2, [r0, #96]	; 0x60
 8001a20:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 8001a24:	2b22      	cmp	r3, #34	; 0x22
 8001a26:	d005      	beq.n	8001a34 <UART_RxISR_16BIT+0x1a>
 8001a28:	6802      	ldr	r2, [r0, #0]
 8001a2a:	6993      	ldr	r3, [r2, #24]
 8001a2c:	f043 0308 	orr.w	r3, r3, #8
 8001a30:	6193      	str	r3, [r2, #24]
 8001a32:	bd08      	pop	{r3, pc}
 8001a34:	6803      	ldr	r3, [r0, #0]
 8001a36:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8001a38:	6d81      	ldr	r1, [r0, #88]	; 0x58
 8001a3a:	4013      	ands	r3, r2
 8001a3c:	800b      	strh	r3, [r1, #0]
 8001a3e:	6d83      	ldr	r3, [r0, #88]	; 0x58
 8001a40:	3302      	adds	r3, #2
 8001a42:	6583      	str	r3, [r0, #88]	; 0x58
 8001a44:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001a48:	b29b      	uxth	r3, r3
 8001a4a:	3b01      	subs	r3, #1
 8001a4c:	b29b      	uxth	r3, r3
 8001a4e:	f8a0 305e 	strh.w	r3, [r0, #94]	; 0x5e
 8001a52:	f8b0 305e 	ldrh.w	r3, [r0, #94]	; 0x5e
 8001a56:	b29b      	uxth	r3, r3
 8001a58:	2b00      	cmp	r3, #0
 8001a5a:	d1ea      	bne.n	8001a32 <UART_RxISR_16BIT+0x18>
 8001a5c:	6802      	ldr	r2, [r0, #0]
 8001a5e:	e852 3f00 	ldrex	r3, [r2]
 8001a62:	f423 7390 	bic.w	r3, r3, #288	; 0x120
 8001a66:	e842 3100 	strex	r1, r3, [r2]
 8001a6a:	2900      	cmp	r1, #0
 8001a6c:	d1f6      	bne.n	8001a5c <UART_RxISR_16BIT+0x42>
 8001a6e:	6802      	ldr	r2, [r0, #0]
 8001a70:	f102 0308 	add.w	r3, r2, #8
 8001a74:	e853 3f00 	ldrex	r3, [r3]
 8001a78:	f023 0301 	bic.w	r3, r3, #1
 8001a7c:	3208      	adds	r2, #8
 8001a7e:	e842 3100 	strex	r1, r3, [r2]
 8001a82:	2900      	cmp	r1, #0
 8001a84:	d1f3      	bne.n	8001a6e <UART_RxISR_16BIT+0x54>
 8001a86:	2320      	movs	r3, #32
 8001a88:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 8001a8c:	2300      	movs	r3, #0
 8001a8e:	6703      	str	r3, [r0, #112]	; 0x70
 8001a90:	6ec3      	ldr	r3, [r0, #108]	; 0x6c
 8001a92:	2b01      	cmp	r3, #1
 8001a94:	d116      	bne.n	8001ac4 <UART_RxISR_16BIT+0xaa>
 8001a96:	2300      	movs	r3, #0
 8001a98:	66c3      	str	r3, [r0, #108]	; 0x6c
 8001a9a:	6802      	ldr	r2, [r0, #0]
 8001a9c:	e852 3f00 	ldrex	r3, [r2]
 8001aa0:	f023 0310 	bic.w	r3, r3, #16
 8001aa4:	e842 3100 	strex	r1, r3, [r2]
 8001aa8:	2900      	cmp	r1, #0
 8001aaa:	d1f6      	bne.n	8001a9a <UART_RxISR_16BIT+0x80>
 8001aac:	6803      	ldr	r3, [r0, #0]
 8001aae:	69da      	ldr	r2, [r3, #28]
 8001ab0:	f012 0f10 	tst.w	r2, #16
 8001ab4:	d001      	beq.n	8001aba <UART_RxISR_16BIT+0xa0>
 8001ab6:	2210      	movs	r2, #16
 8001ab8:	621a      	str	r2, [r3, #32]
 8001aba:	f8b0 105c 	ldrh.w	r1, [r0, #92]	; 0x5c
 8001abe:	f7ff fdb7 	bl	8001630 <HAL_UARTEx_RxEventCallback>
 8001ac2:	e7b6      	b.n	8001a32 <UART_RxISR_16BIT+0x18>
 8001ac4:	f7fe ff96 	bl	80009f4 <HAL_UART_RxCpltCallback>
 8001ac8:	e7b3      	b.n	8001a32 <UART_RxISR_16BIT+0x18>
	...

08001acc <UART_RxISR_8BIT_FIFOEN>:
 8001acc:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001ad0:	f8b0 6060 	ldrh.w	r6, [r0, #96]	; 0x60
 8001ad4:	6803      	ldr	r3, [r0, #0]
 8001ad6:	69dd      	ldr	r5, [r3, #28]
 8001ad8:	f8d3 9000 	ldr.w	r9, [r3]
 8001adc:	f8d3 8008 	ldr.w	r8, [r3, #8]
 8001ae0:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001ae4:	2a22      	cmp	r2, #34	; 0x22
 8001ae6:	d005      	beq.n	8001af4 <UART_RxISR_8BIT_FIFOEN+0x28>
 8001ae8:	699a      	ldr	r2, [r3, #24]
 8001aea:	f042 0208 	orr.w	r2, r2, #8
 8001aee:	619a      	str	r2, [r3, #24]
 8001af0:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001af4:	4604      	mov	r4, r0
 8001af6:	f8b0 7068 	ldrh.w	r7, [r0, #104]	; 0x68
 8001afa:	e008      	b.n	8001b0e <UART_RxISR_8BIT_FIFOEN+0x42>
 8001afc:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b00:	2b00      	cmp	r3, #0
 8001b02:	d14c      	bne.n	8001b9e <UART_RxISR_8BIT_FIFOEN+0xd2>
 8001b04:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001b08:	b29b      	uxth	r3, r3
 8001b0a:	2b00      	cmp	r3, #0
 8001b0c:	d04e      	beq.n	8001bac <UART_RxISR_8BIT_FIFOEN+0xe0>
 8001b0e:	2f00      	cmp	r7, #0
 8001b10:	f000 8087 	beq.w	8001c22 <UART_RxISR_8BIT_FIFOEN+0x156>
 8001b14:	f015 0f20 	tst.w	r5, #32
 8001b18:	f000 8083 	beq.w	8001c22 <UART_RxISR_8BIT_FIFOEN+0x156>
 8001b1c:	6823      	ldr	r3, [r4, #0]
 8001b1e:	6a59      	ldr	r1, [r3, #36]	; 0x24
 8001b20:	b2f3      	uxtb	r3, r6
 8001b22:	6da2      	ldr	r2, [r4, #88]	; 0x58
 8001b24:	400b      	ands	r3, r1
 8001b26:	7013      	strb	r3, [r2, #0]
 8001b28:	6da3      	ldr	r3, [r4, #88]	; 0x58
 8001b2a:	3301      	adds	r3, #1
 8001b2c:	65a3      	str	r3, [r4, #88]	; 0x58
 8001b2e:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001b32:	b29b      	uxth	r3, r3
 8001b34:	3b01      	subs	r3, #1
 8001b36:	b29b      	uxth	r3, r3
 8001b38:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001b3c:	6823      	ldr	r3, [r4, #0]
 8001b3e:	69dd      	ldr	r5, [r3, #28]
 8001b40:	f015 0f07 	tst.w	r5, #7
 8001b44:	d0de      	beq.n	8001b04 <UART_RxISR_8BIT_FIFOEN+0x38>
 8001b46:	f015 0f01 	tst.w	r5, #1
 8001b4a:	d009      	beq.n	8001b60 <UART_RxISR_8BIT_FIFOEN+0x94>
 8001b4c:	f419 7f80 	tst.w	r9, #256	; 0x100
 8001b50:	d006      	beq.n	8001b60 <UART_RxISR_8BIT_FIFOEN+0x94>
 8001b52:	2201      	movs	r2, #1
 8001b54:	621a      	str	r2, [r3, #32]
 8001b56:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b5a:	4313      	orrs	r3, r2
 8001b5c:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b60:	f015 0f02 	tst.w	r5, #2
 8001b64:	d00b      	beq.n	8001b7e <UART_RxISR_8BIT_FIFOEN+0xb2>
 8001b66:	f018 0f01 	tst.w	r8, #1
 8001b6a:	d008      	beq.n	8001b7e <UART_RxISR_8BIT_FIFOEN+0xb2>
 8001b6c:	6823      	ldr	r3, [r4, #0]
 8001b6e:	2202      	movs	r2, #2
 8001b70:	621a      	str	r2, [r3, #32]
 8001b72:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b76:	f043 0304 	orr.w	r3, r3, #4
 8001b7a:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b7e:	f015 0f04 	tst.w	r5, #4
 8001b82:	d0bb      	beq.n	8001afc <UART_RxISR_8BIT_FIFOEN+0x30>
 8001b84:	f018 0f01 	tst.w	r8, #1
 8001b88:	d0b8      	beq.n	8001afc <UART_RxISR_8BIT_FIFOEN+0x30>
 8001b8a:	6823      	ldr	r3, [r4, #0]
 8001b8c:	2204      	movs	r2, #4
 8001b8e:	621a      	str	r2, [r3, #32]
 8001b90:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001b94:	f043 0302 	orr.w	r3, r3, #2
 8001b98:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001b9c:	e7ae      	b.n	8001afc <UART_RxISR_8BIT_FIFOEN+0x30>
 8001b9e:	4620      	mov	r0, r4
 8001ba0:	f7ff fcbd 	bl	800151e <HAL_UART_ErrorCallback>
 8001ba4:	2300      	movs	r3, #0
 8001ba6:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001baa:	e7ab      	b.n	8001b04 <UART_RxISR_8BIT_FIFOEN+0x38>
 8001bac:	6822      	ldr	r2, [r4, #0]
 8001bae:	e852 3f00 	ldrex	r3, [r2]
 8001bb2:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001bb6:	e842 3100 	strex	r1, r3, [r2]
 8001bba:	2900      	cmp	r1, #0
 8001bbc:	d1f6      	bne.n	8001bac <UART_RxISR_8BIT_FIFOEN+0xe0>
 8001bbe:	6822      	ldr	r2, [r4, #0]
 8001bc0:	f102 0308 	add.w	r3, r2, #8
 8001bc4:	e853 3f00 	ldrex	r3, [r3]
 8001bc8:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001bcc:	f023 0301 	bic.w	r3, r3, #1
 8001bd0:	3208      	adds	r2, #8
 8001bd2:	e842 3100 	strex	r1, r3, [r2]
 8001bd6:	2900      	cmp	r1, #0
 8001bd8:	d1f1      	bne.n	8001bbe <UART_RxISR_8BIT_FIFOEN+0xf2>
 8001bda:	2320      	movs	r3, #32
 8001bdc:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001be0:	2300      	movs	r3, #0
 8001be2:	6723      	str	r3, [r4, #112]	; 0x70
 8001be4:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001be6:	2b01      	cmp	r3, #1
 8001be8:	d003      	beq.n	8001bf2 <UART_RxISR_8BIT_FIFOEN+0x126>
 8001bea:	4620      	mov	r0, r4
 8001bec:	f7fe ff02 	bl	80009f4 <HAL_UART_RxCpltCallback>
 8001bf0:	e78d      	b.n	8001b0e <UART_RxISR_8BIT_FIFOEN+0x42>
 8001bf2:	2300      	movs	r3, #0
 8001bf4:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001bf6:	6822      	ldr	r2, [r4, #0]
 8001bf8:	e852 3f00 	ldrex	r3, [r2]
 8001bfc:	f023 0310 	bic.w	r3, r3, #16
 8001c00:	e842 3100 	strex	r1, r3, [r2]
 8001c04:	2900      	cmp	r1, #0
 8001c06:	d1f6      	bne.n	8001bf6 <UART_RxISR_8BIT_FIFOEN+0x12a>
 8001c08:	6823      	ldr	r3, [r4, #0]
 8001c0a:	69da      	ldr	r2, [r3, #28]
 8001c0c:	f012 0f10 	tst.w	r2, #16
 8001c10:	d001      	beq.n	8001c16 <UART_RxISR_8BIT_FIFOEN+0x14a>
 8001c12:	2210      	movs	r2, #16
 8001c14:	621a      	str	r2, [r3, #32]
 8001c16:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001c1a:	4620      	mov	r0, r4
 8001c1c:	f7ff fd08 	bl	8001630 <HAL_UARTEx_RxEventCallback>
 8001c20:	e775      	b.n	8001b0e <UART_RxISR_8BIT_FIFOEN+0x42>
 8001c22:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001c26:	b29b      	uxth	r3, r3
 8001c28:	2b00      	cmp	r3, #0
 8001c2a:	f43f af61 	beq.w	8001af0 <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c2e:	f8b4 2068 	ldrh.w	r2, [r4, #104]	; 0x68
 8001c32:	429a      	cmp	r2, r3
 8001c34:	f67f af5c 	bls.w	8001af0 <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c38:	6822      	ldr	r2, [r4, #0]
 8001c3a:	f102 0308 	add.w	r3, r2, #8
 8001c3e:	e853 3f00 	ldrex	r3, [r3]
 8001c42:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001c46:	3208      	adds	r2, #8
 8001c48:	e842 3100 	strex	r1, r3, [r2]
 8001c4c:	2900      	cmp	r1, #0
 8001c4e:	d1f3      	bne.n	8001c38 <UART_RxISR_8BIT_FIFOEN+0x16c>
 8001c50:	4b05      	ldr	r3, [pc, #20]	; (8001c68 <UART_RxISR_8BIT_FIFOEN+0x19c>)
 8001c52:	6723      	str	r3, [r4, #112]	; 0x70
 8001c54:	6822      	ldr	r2, [r4, #0]
 8001c56:	e852 3f00 	ldrex	r3, [r2]
 8001c5a:	f043 0320 	orr.w	r3, r3, #32
 8001c5e:	e842 3100 	strex	r1, r3, [r2]
 8001c62:	2900      	cmp	r1, #0
 8001c64:	d1f6      	bne.n	8001c54 <UART_RxISR_8BIT_FIFOEN+0x188>
 8001c66:	e743      	b.n	8001af0 <UART_RxISR_8BIT_FIFOEN+0x24>
 8001c68:	08001969 	.word	0x08001969

08001c6c <UART_RxISR_16BIT_FIFOEN>:
 8001c6c:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 8001c70:	f8b0 6060 	ldrh.w	r6, [r0, #96]	; 0x60
 8001c74:	6803      	ldr	r3, [r0, #0]
 8001c76:	69dd      	ldr	r5, [r3, #28]
 8001c78:	f8d3 9000 	ldr.w	r9, [r3]
 8001c7c:	f8d3 8008 	ldr.w	r8, [r3, #8]
 8001c80:	f8d0 2088 	ldr.w	r2, [r0, #136]	; 0x88
 8001c84:	2a22      	cmp	r2, #34	; 0x22
 8001c86:	d005      	beq.n	8001c94 <UART_RxISR_16BIT_FIFOEN+0x28>
 8001c88:	699a      	ldr	r2, [r3, #24]
 8001c8a:	f042 0208 	orr.w	r2, r2, #8
 8001c8e:	619a      	str	r2, [r3, #24]
 8001c90:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
 8001c94:	4604      	mov	r4, r0
 8001c96:	f8b0 7068 	ldrh.w	r7, [r0, #104]	; 0x68
 8001c9a:	e008      	b.n	8001cae <UART_RxISR_16BIT_FIFOEN+0x42>
 8001c9c:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001ca0:	2b00      	cmp	r3, #0
 8001ca2:	d14b      	bne.n	8001d3c <UART_RxISR_16BIT_FIFOEN+0xd0>
 8001ca4:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001ca8:	b29b      	uxth	r3, r3
 8001caa:	2b00      	cmp	r3, #0
 8001cac:	d04d      	beq.n	8001d4a <UART_RxISR_16BIT_FIFOEN+0xde>
 8001cae:	2f00      	cmp	r7, #0
 8001cb0:	f000 8086 	beq.w	8001dc0 <UART_RxISR_16BIT_FIFOEN+0x154>
 8001cb4:	f015 0f20 	tst.w	r5, #32
 8001cb8:	f000 8082 	beq.w	8001dc0 <UART_RxISR_16BIT_FIFOEN+0x154>
 8001cbc:	6823      	ldr	r3, [r4, #0]
 8001cbe:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8001cc0:	6da2      	ldr	r2, [r4, #88]	; 0x58
 8001cc2:	4033      	ands	r3, r6
 8001cc4:	8013      	strh	r3, [r2, #0]
 8001cc6:	6da3      	ldr	r3, [r4, #88]	; 0x58
 8001cc8:	3302      	adds	r3, #2
 8001cca:	65a3      	str	r3, [r4, #88]	; 0x58
 8001ccc:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001cd0:	b29b      	uxth	r3, r3
 8001cd2:	3b01      	subs	r3, #1
 8001cd4:	b29b      	uxth	r3, r3
 8001cd6:	f8a4 305e 	strh.w	r3, [r4, #94]	; 0x5e
 8001cda:	6823      	ldr	r3, [r4, #0]
 8001cdc:	69dd      	ldr	r5, [r3, #28]
 8001cde:	f015 0f07 	tst.w	r5, #7
 8001ce2:	d0df      	beq.n	8001ca4 <UART_RxISR_16BIT_FIFOEN+0x38>
 8001ce4:	f015 0f01 	tst.w	r5, #1
 8001ce8:	d009      	beq.n	8001cfe <UART_RxISR_16BIT_FIFOEN+0x92>
 8001cea:	f419 7f80 	tst.w	r9, #256	; 0x100
 8001cee:	d006      	beq.n	8001cfe <UART_RxISR_16BIT_FIFOEN+0x92>
 8001cf0:	2201      	movs	r2, #1
 8001cf2:	621a      	str	r2, [r3, #32]
 8001cf4:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001cf8:	4313      	orrs	r3, r2
 8001cfa:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001cfe:	f015 0f02 	tst.w	r5, #2
 8001d02:	d00b      	beq.n	8001d1c <UART_RxISR_16BIT_FIFOEN+0xb0>
 8001d04:	f018 0f01 	tst.w	r8, #1
 8001d08:	d008      	beq.n	8001d1c <UART_RxISR_16BIT_FIFOEN+0xb0>
 8001d0a:	6823      	ldr	r3, [r4, #0]
 8001d0c:	2202      	movs	r2, #2
 8001d0e:	621a      	str	r2, [r3, #32]
 8001d10:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d14:	f043 0304 	orr.w	r3, r3, #4
 8001d18:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d1c:	f015 0f04 	tst.w	r5, #4
 8001d20:	d0bc      	beq.n	8001c9c <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d22:	f018 0f01 	tst.w	r8, #1
 8001d26:	d0b9      	beq.n	8001c9c <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d28:	6823      	ldr	r3, [r4, #0]
 8001d2a:	2204      	movs	r2, #4
 8001d2c:	621a      	str	r2, [r3, #32]
 8001d2e:	f8d4 308c 	ldr.w	r3, [r4, #140]	; 0x8c
 8001d32:	f043 0302 	orr.w	r3, r3, #2
 8001d36:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d3a:	e7af      	b.n	8001c9c <UART_RxISR_16BIT_FIFOEN+0x30>
 8001d3c:	4620      	mov	r0, r4
 8001d3e:	f7ff fbee 	bl	800151e <HAL_UART_ErrorCallback>
 8001d42:	2300      	movs	r3, #0
 8001d44:	f8c4 308c 	str.w	r3, [r4, #140]	; 0x8c
 8001d48:	e7ac      	b.n	8001ca4 <UART_RxISR_16BIT_FIFOEN+0x38>
 8001d4a:	6822      	ldr	r2, [r4, #0]
 8001d4c:	e852 3f00 	ldrex	r3, [r2]
 8001d50:	f423 7380 	bic.w	r3, r3, #256	; 0x100
 8001d54:	e842 3100 	strex	r1, r3, [r2]
 8001d58:	2900      	cmp	r1, #0
 8001d5a:	d1f6      	bne.n	8001d4a <UART_RxISR_16BIT_FIFOEN+0xde>
 8001d5c:	6822      	ldr	r2, [r4, #0]
 8001d5e:	f102 0308 	add.w	r3, r2, #8
 8001d62:	e853 3f00 	ldrex	r3, [r3]
 8001d66:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001d6a:	f023 0301 	bic.w	r3, r3, #1
 8001d6e:	3208      	adds	r2, #8
 8001d70:	e842 3100 	strex	r1, r3, [r2]
 8001d74:	2900      	cmp	r1, #0
 8001d76:	d1f1      	bne.n	8001d5c <UART_RxISR_16BIT_FIFOEN+0xf0>
 8001d78:	2320      	movs	r3, #32
 8001d7a:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 8001d7e:	2300      	movs	r3, #0
 8001d80:	6723      	str	r3, [r4, #112]	; 0x70
 8001d82:	6ee3      	ldr	r3, [r4, #108]	; 0x6c
 8001d84:	2b01      	cmp	r3, #1
 8001d86:	d003      	beq.n	8001d90 <UART_RxISR_16BIT_FIFOEN+0x124>
 8001d88:	4620      	mov	r0, r4
 8001d8a:	f7fe fe33 	bl	80009f4 <HAL_UART_RxCpltCallback>
 8001d8e:	e78e      	b.n	8001cae <UART_RxISR_16BIT_FIFOEN+0x42>
 8001d90:	2300      	movs	r3, #0
 8001d92:	66e3      	str	r3, [r4, #108]	; 0x6c
 8001d94:	6822      	ldr	r2, [r4, #0]
 8001d96:	e852 3f00 	ldrex	r3, [r2]
 8001d9a:	f023 0310 	bic.w	r3, r3, #16
 8001d9e:	e842 3100 	strex	r1, r3, [r2]
 8001da2:	2900      	cmp	r1, #0
 8001da4:	d1f6      	bne.n	8001d94 <UART_RxISR_16BIT_FIFOEN+0x128>
 8001da6:	6823      	ldr	r3, [r4, #0]
 8001da8:	69da      	ldr	r2, [r3, #28]
 8001daa:	f012 0f10 	tst.w	r2, #16
 8001dae:	d001      	beq.n	8001db4 <UART_RxISR_16BIT_FIFOEN+0x148>
 8001db0:	2210      	movs	r2, #16
 8001db2:	621a      	str	r2, [r3, #32]
 8001db4:	f8b4 105c 	ldrh.w	r1, [r4, #92]	; 0x5c
 8001db8:	4620      	mov	r0, r4
 8001dba:	f7ff fc39 	bl	8001630 <HAL_UARTEx_RxEventCallback>
 8001dbe:	e776      	b.n	8001cae <UART_RxISR_16BIT_FIFOEN+0x42>
 8001dc0:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 8001dc4:	b29b      	uxth	r3, r3
 8001dc6:	2b00      	cmp	r3, #0
 8001dc8:	f43f af62 	beq.w	8001c90 <UART_RxISR_16BIT_FIFOEN+0x24>
 8001dcc:	f8b4 2068 	ldrh.w	r2, [r4, #104]	; 0x68
 8001dd0:	429a      	cmp	r2, r3
 8001dd2:	f67f af5d 	bls.w	8001c90 <UART_RxISR_16BIT_FIFOEN+0x24>
 8001dd6:	6822      	ldr	r2, [r4, #0]
 8001dd8:	f102 0308 	add.w	r3, r2, #8
 8001ddc:	e853 3f00 	ldrex	r3, [r3]
 8001de0:	f023 5380 	bic.w	r3, r3, #268435456	; 0x10000000
 8001de4:	3208      	adds	r2, #8
 8001de6:	e842 3100 	strex	r1, r3, [r2]
 8001dea:	2900      	cmp	r1, #0
 8001dec:	d1f3      	bne.n	8001dd6 <UART_RxISR_16BIT_FIFOEN+0x16a>
 8001dee:	4b06      	ldr	r3, [pc, #24]	; (8001e08 <UART_RxISR_16BIT_FIFOEN+0x19c>)
 8001df0:	6723      	str	r3, [r4, #112]	; 0x70
 8001df2:	6822      	ldr	r2, [r4, #0]
 8001df4:	e852 3f00 	ldrex	r3, [r2]
 8001df8:	f043 0320 	orr.w	r3, r3, #32
 8001dfc:	e842 3100 	strex	r1, r3, [r2]
 8001e00:	2900      	cmp	r1, #0
 8001e02:	d1f6      	bne.n	8001df2 <UART_RxISR_16BIT_FIFOEN+0x186>
 8001e04:	e744      	b.n	8001c90 <UART_RxISR_16BIT_FIFOEN+0x24>
 8001e06:	bf00      	nop
 8001e08:	08001a1b 	.word	0x08001a1b

08001e0c <UART_SetConfig>:
 8001e0c:	b570      	push	{r4, r5, r6, lr}
 8001e0e:	4604      	mov	r4, r0
 8001e10:	6801      	ldr	r1, [r0, #0]
 8001e12:	6883      	ldr	r3, [r0, #8]
 8001e14:	6902      	ldr	r2, [r0, #16]
 8001e16:	4313      	orrs	r3, r2
 8001e18:	6942      	ldr	r2, [r0, #20]
 8001e1a:	4313      	orrs	r3, r2
 8001e1c:	69c2      	ldr	r2, [r0, #28]
 8001e1e:	4313      	orrs	r3, r2
 8001e20:	6808      	ldr	r0, [r1, #0]
 8001e22:	4a9d      	ldr	r2, [pc, #628]	; (8002098 <UART_SetConfig+0x28c>)
 8001e24:	4002      	ands	r2, r0
 8001e26:	4313      	orrs	r3, r2
 8001e28:	600b      	str	r3, [r1, #0]
 8001e2a:	6822      	ldr	r2, [r4, #0]
 8001e2c:	6853      	ldr	r3, [r2, #4]
 8001e2e:	f423 5340 	bic.w	r3, r3, #12288	; 0x3000
 8001e32:	68e1      	ldr	r1, [r4, #12]
 8001e34:	430b      	orrs	r3, r1
 8001e36:	6053      	str	r3, [r2, #4]
 8001e38:	69a1      	ldr	r1, [r4, #24]
 8001e3a:	6822      	ldr	r2, [r4, #0]
 8001e3c:	4b97      	ldr	r3, [pc, #604]	; (800209c <UART_SetConfig+0x290>)
 8001e3e:	429a      	cmp	r2, r3
 8001e40:	d001      	beq.n	8001e46 <UART_SetConfig+0x3a>
 8001e42:	6a23      	ldr	r3, [r4, #32]
 8001e44:	4319      	orrs	r1, r3
 8001e46:	6893      	ldr	r3, [r2, #8]
 8001e48:	f023 436e 	bic.w	r3, r3, #3992977408	; 0xee000000
 8001e4c:	f423 6330 	bic.w	r3, r3, #2816	; 0xb00
 8001e50:	430b      	orrs	r3, r1
 8001e52:	6093      	str	r3, [r2, #8]
 8001e54:	6822      	ldr	r2, [r4, #0]
 8001e56:	6ad3      	ldr	r3, [r2, #44]	; 0x2c
 8001e58:	f023 030f 	bic.w	r3, r3, #15
 8001e5c:	6a61      	ldr	r1, [r4, #36]	; 0x24
 8001e5e:	430b      	orrs	r3, r1
 8001e60:	62d3      	str	r3, [r2, #44]	; 0x2c
 8001e62:	6823      	ldr	r3, [r4, #0]
 8001e64:	4a8e      	ldr	r2, [pc, #568]	; (80020a0 <UART_SetConfig+0x294>)
 8001e66:	4293      	cmp	r3, r2
 8001e68:	d01c      	beq.n	8001ea4 <UART_SetConfig+0x98>
 8001e6a:	4a8e      	ldr	r2, [pc, #568]	; (80020a4 <UART_SetConfig+0x298>)
 8001e6c:	4293      	cmp	r3, r2
 8001e6e:	d031      	beq.n	8001ed4 <UART_SetConfig+0xc8>
 8001e70:	4a8a      	ldr	r2, [pc, #552]	; (800209c <UART_SetConfig+0x290>)
 8001e72:	4293      	cmp	r3, r2
 8001e74:	d04b      	beq.n	8001f0e <UART_SetConfig+0x102>
 8001e76:	2210      	movs	r2, #16
 8001e78:	4988      	ldr	r1, [pc, #544]	; (800209c <UART_SetConfig+0x290>)
 8001e7a:	428b      	cmp	r3, r1
 8001e7c:	d068      	beq.n	8001f50 <UART_SetConfig+0x144>
 8001e7e:	69e0      	ldr	r0, [r4, #28]
 8001e80:	f5b0 4f00 	cmp.w	r0, #32768	; 0x8000
 8001e84:	f000 80a5 	beq.w	8001fd2 <UART_SetConfig+0x1c6>
 8001e88:	2a08      	cmp	r2, #8
 8001e8a:	f200 811f 	bhi.w	80020cc <UART_SetConfig+0x2c0>
 8001e8e:	e8df f012 	tbh	[pc, r2, lsl #1]
 8001e92:	00d3      	.short	0x00d3
 8001e94:	00d100f5 	.word	0x00d100f5
 8001e98:	00f8011d 	.word	0x00f8011d
 8001e9c:	011d011d 	.word	0x011d011d
 8001ea0:	00fb011d 	.word	0x00fb011d
 8001ea4:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001ea8:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001eac:	f002 0203 	and.w	r2, r2, #3
 8001eb0:	f442 3240 	orr.w	r2, r2, #196608	; 0x30000
 8001eb4:	f5a2 3240 	sub.w	r2, r2, #196608	; 0x30000
 8001eb8:	2a03      	cmp	r2, #3
 8001eba:	d809      	bhi.n	8001ed0 <UART_SetConfig+0xc4>
 8001ebc:	e8df f002 	tbb	[pc, r2]
 8001ec0:	063c0402 	.word	0x063c0402
 8001ec4:	2201      	movs	r2, #1
 8001ec6:	e7d7      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001ec8:	2204      	movs	r2, #4
 8001eca:	e7d5      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001ecc:	2208      	movs	r2, #8
 8001ece:	e7d3      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001ed0:	2210      	movs	r2, #16
 8001ed2:	e7d1      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001ed4:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001ed8:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001edc:	f002 020c 	and.w	r2, r2, #12
 8001ee0:	f442 2240 	orr.w	r2, r2, #786432	; 0xc0000
 8001ee4:	f5a2 2240 	sub.w	r2, r2, #786432	; 0xc0000
 8001ee8:	2a0c      	cmp	r2, #12
 8001eea:	d80e      	bhi.n	8001f0a <UART_SetConfig+0xfe>
 8001eec:	e8df f002 	tbb	[pc, r2]
 8001ef0:	0d0d0d07 	.word	0x0d0d0d07
 8001ef4:	0d0d0d09 	.word	0x0d0d0d09
 8001ef8:	0d0d0d26 	.word	0x0d0d0d26
 8001efc:	0b          	.byte	0x0b
 8001efd:	00          	.byte	0x00
 8001efe:	2200      	movs	r2, #0
 8001f00:	e7ba      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f02:	2204      	movs	r2, #4
 8001f04:	e7b8      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f06:	2208      	movs	r2, #8
 8001f08:	e7b6      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f0a:	2210      	movs	r2, #16
 8001f0c:	e7b4      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f0e:	f04f 42b0 	mov.w	r2, #1476395008	; 0x58000000
 8001f12:	f8d2 2088 	ldr.w	r2, [r2, #136]	; 0x88
 8001f16:	f402 6240 	and.w	r2, r2, #3072	; 0xc00
 8001f1a:	f5b2 6f00 	cmp.w	r2, #2048	; 0x800
 8001f1e:	d00f      	beq.n	8001f40 <UART_SetConfig+0x134>
 8001f20:	d805      	bhi.n	8001f2e <UART_SetConfig+0x122>
 8001f22:	b17a      	cbz	r2, 8001f44 <UART_SetConfig+0x138>
 8001f24:	f5b2 6f80 	cmp.w	r2, #1024	; 0x400
 8001f28:	d10e      	bne.n	8001f48 <UART_SetConfig+0x13c>
 8001f2a:	2204      	movs	r2, #4
 8001f2c:	e7a4      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f2e:	f5b2 6f40 	cmp.w	r2, #3072	; 0xc00
 8001f32:	d10b      	bne.n	8001f4c <UART_SetConfig+0x140>
 8001f34:	2208      	movs	r2, #8
 8001f36:	e79f      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f38:	2202      	movs	r2, #2
 8001f3a:	e79d      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f3c:	2202      	movs	r2, #2
 8001f3e:	e79b      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f40:	2202      	movs	r2, #2
 8001f42:	e799      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f44:	2200      	movs	r2, #0
 8001f46:	e797      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f48:	2210      	movs	r2, #16
 8001f4a:	e795      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f4c:	2210      	movs	r2, #16
 8001f4e:	e793      	b.n	8001e78 <UART_SetConfig+0x6c>
 8001f50:	2a08      	cmp	r2, #8
 8001f52:	f200 809c 	bhi.w	800208e <UART_SetConfig+0x282>
 8001f56:	e8df f002 	tbb	[pc, r2]
 8001f5a:	9a08      	.short	0x9a08
 8001f5c:	9a379a3a 	.word	0x9a379a3a
 8001f60:	9a9a      	.short	0x9a9a
 8001f62:	05          	.byte	0x05
 8001f63:	00          	.byte	0x00
 8001f64:	f44f 4000 	mov.w	r0, #32768	; 0x8000
 8001f68:	e004      	b.n	8001f74 <UART_SetConfig+0x168>
 8001f6a:	f024 faa7 	bl	80264bc <HAL_RCC_GetPCLK1Freq>
 8001f6e:	2800      	cmp	r0, #0
 8001f70:	f000 808f 	beq.w	8002092 <UART_SetConfig+0x286>
 8001f74:	6a62      	ldr	r2, [r4, #36]	; 0x24
 8001f76:	4b4c      	ldr	r3, [pc, #304]	; (80020a8 <UART_SetConfig+0x29c>)
 8001f78:	f833 2012 	ldrh.w	r2, [r3, r2, lsl #1]
 8001f7c:	fbb0 f3f2 	udiv	r3, r0, r2
 8001f80:	6865      	ldr	r5, [r4, #4]
 8001f82:	eb05 0145 	add.w	r1, r5, r5, lsl #1
 8001f86:	4299      	cmp	r1, r3
 8001f88:	f200 8094 	bhi.w	80020b4 <UART_SetConfig+0x2a8>
 8001f8c:	ebb3 3f05 	cmp.w	r3, r5, lsl #12
 8001f90:	f200 8092 	bhi.w	80020b8 <UART_SetConfig+0x2ac>
 8001f94:	2600      	movs	r6, #0
 8001f96:	4633      	mov	r3, r6
 8001f98:	4631      	mov	r1, r6
 8001f9a:	f01c fc79 	bl	801e890 <__aeabi_uldivmod>
 8001f9e:	0209      	lsls	r1, r1, #8
 8001fa0:	ea41 6110 	orr.w	r1, r1, r0, lsr #24
 8001fa4:	0200      	lsls	r0, r0, #8
 8001fa6:	086b      	lsrs	r3, r5, #1
 8001fa8:	18c0      	adds	r0, r0, r3
 8001faa:	462a      	mov	r2, r5
 8001fac:	4633      	mov	r3, r6
 8001fae:	f141 0100 	adc.w	r1, r1, #0
 8001fb2:	f01c fc6d 	bl	801e890 <__aeabi_uldivmod>
 8001fb6:	f5a0 7240 	sub.w	r2, r0, #768	; 0x300
 8001fba:	4b3c      	ldr	r3, [pc, #240]	; (80020ac <UART_SetConfig+0x2a0>)
 8001fbc:	429a      	cmp	r2, r3
 8001fbe:	d87d      	bhi.n	80020bc <UART_SetConfig+0x2b0>
 8001fc0:	6823      	ldr	r3, [r4, #0]
 8001fc2:	60d8      	str	r0, [r3, #12]
 8001fc4:	4630      	mov	r0, r6
 8001fc6:	e050      	b.n	800206a <UART_SetConfig+0x25e>
 8001fc8:	f023 fe68 	bl	8025c9c <HAL_RCC_GetSysClockFreq>
 8001fcc:	e7cf      	b.n	8001f6e <UART_SetConfig+0x162>
 8001fce:	4838      	ldr	r0, [pc, #224]	; (80020b0 <UART_SetConfig+0x2a4>)
 8001fd0:	e7d0      	b.n	8001f74 <UART_SetConfig+0x168>
 8001fd2:	2a08      	cmp	r2, #8
 8001fd4:	d874      	bhi.n	80020c0 <UART_SetConfig+0x2b4>
 8001fd6:	e8df f002 	tbb	[pc, r2]
 8001fda:	2707      	.short	0x2707
 8001fdc:	732a7305 	.word	0x732a7305
 8001fe0:	7373      	.short	0x7373
 8001fe2:	0b          	.byte	0x0b
 8001fe3:	00          	.byte	0x00
 8001fe4:	4832      	ldr	r0, [pc, #200]	; (80020b0 <UART_SetConfig+0x2a4>)
 8001fe6:	e003      	b.n	8001ff0 <UART_SetConfig+0x1e4>
 8001fe8:	f024 fa68 	bl	80264bc <HAL_RCC_GetPCLK1Freq>
 8001fec:	2800      	cmp	r0, #0
 8001fee:	d069      	beq.n	80020c4 <UART_SetConfig+0x2b8>
 8001ff0:	6a62      	ldr	r2, [r4, #36]	; 0x24
 8001ff2:	4b2d      	ldr	r3, [pc, #180]	; (80020a8 <UART_SetConfig+0x29c>)
 8001ff4:	f833 3012 	ldrh.w	r3, [r3, r2, lsl #1]
 8001ff8:	fbb0 f0f3 	udiv	r0, r0, r3
 8001ffc:	6862      	ldr	r2, [r4, #4]
 8001ffe:	0853      	lsrs	r3, r2, #1
 8002000:	eb03 0040 	add.w	r0, r3, r0, lsl #1
 8002004:	fbb0 f0f2 	udiv	r0, r0, r2
 8002008:	b280      	uxth	r0, r0
 800200a:	f1a0 0210 	sub.w	r2, r0, #16
 800200e:	f64f 73ef 	movw	r3, #65519	; 0xffef
 8002012:	429a      	cmp	r2, r3
 8002014:	d858      	bhi.n	80020c8 <UART_SetConfig+0x2bc>
 8002016:	f020 030f 	bic.w	r3, r0, #15
 800201a:	f3c0 0042 	ubfx	r0, r0, #1, #3
 800201e:	4318      	orrs	r0, r3
 8002020:	6823      	ldr	r3, [r4, #0]
 8002022:	60d8      	str	r0, [r3, #12]
 8002024:	2000      	movs	r0, #0
 8002026:	e020      	b.n	800206a <UART_SetConfig+0x25e>
 8002028:	f024 fa58 	bl	80264dc <HAL_RCC_GetPCLK2Freq>
 800202c:	e7de      	b.n	8001fec <UART_SetConfig+0x1e0>
 800202e:	f023 fe35 	bl	8025c9c <HAL_RCC_GetSysClockFreq>
 8002032:	e7db      	b.n	8001fec <UART_SetConfig+0x1e0>
 8002034:	481e      	ldr	r0, [pc, #120]	; (80020b0 <UART_SetConfig+0x2a4>)
 8002036:	e003      	b.n	8002040 <UART_SetConfig+0x234>
 8002038:	f024 fa40 	bl	80264bc <HAL_RCC_GetPCLK1Freq>
 800203c:	2800      	cmp	r0, #0
 800203e:	d047      	beq.n	80020d0 <UART_SetConfig+0x2c4>
 8002040:	6a62      	ldr	r2, [r4, #36]	; 0x24
 8002042:	4b19      	ldr	r3, [pc, #100]	; (80020a8 <UART_SetConfig+0x29c>)
 8002044:	f833 3012 	ldrh.w	r3, [r3, r2, lsl #1]
 8002048:	fbb0 f0f3 	udiv	r0, r0, r3
 800204c:	6863      	ldr	r3, [r4, #4]
 800204e:	eb00 0053 	add.w	r0, r0, r3, lsr #1
 8002052:	fbb0 f0f3 	udiv	r0, r0, r3
 8002056:	b280      	uxth	r0, r0
 8002058:	f1a0 0210 	sub.w	r2, r0, #16
 800205c:	f64f 73ef 	movw	r3, #65519	; 0xffef
 8002060:	429a      	cmp	r2, r3
 8002062:	d837      	bhi.n	80020d4 <UART_SetConfig+0x2c8>
 8002064:	6823      	ldr	r3, [r4, #0]
 8002066:	60d8      	str	r0, [r3, #12]
 8002068:	2000      	movs	r0, #0
 800206a:	2301      	movs	r3, #1
 800206c:	f8a4 306a 	strh.w	r3, [r4, #106]	; 0x6a
 8002070:	f8a4 3068 	strh.w	r3, [r4, #104]	; 0x68
 8002074:	2300      	movs	r3, #0
 8002076:	6723      	str	r3, [r4, #112]	; 0x70
 8002078:	6763      	str	r3, [r4, #116]	; 0x74
 800207a:	bd70      	pop	{r4, r5, r6, pc}
 800207c:	f024 fa2e 	bl	80264dc <HAL_RCC_GetPCLK2Freq>
 8002080:	e7dc      	b.n	800203c <UART_SetConfig+0x230>
 8002082:	f023 fe0b 	bl	8025c9c <HAL_RCC_GetSysClockFreq>
 8002086:	e7d9      	b.n	800203c <UART_SetConfig+0x230>
 8002088:	f44f 4000 	mov.w	r0, #32768	; 0x8000
 800208c:	e7d8      	b.n	8002040 <UART_SetConfig+0x234>
 800208e:	2001      	movs	r0, #1
 8002090:	e7eb      	b.n	800206a <UART_SetConfig+0x25e>
 8002092:	2000      	movs	r0, #0
 8002094:	e7e9      	b.n	800206a <UART_SetConfig+0x25e>
 8002096:	bf00      	nop
 8002098:	cfff69f3 	.word	0xcfff69f3
 800209c:	40008000 	.word	0x40008000
 80020a0:	40013800 	.word	0x40013800
 80020a4:	40004400 	.word	0x40004400
 80020a8:	08002b18 	.word	0x08002b18
 80020ac:	000ffcff 	.word	0x000ffcff
 80020b0:	00f42400 	.word	0x00f42400
 80020b4:	2001      	movs	r0, #1
 80020b6:	e7d8      	b.n	800206a <UART_SetConfig+0x25e>
 80020b8:	2001      	movs	r0, #1
 80020ba:	e7d6      	b.n	800206a <UART_SetConfig+0x25e>
 80020bc:	2001      	movs	r0, #1
 80020be:	e7d4      	b.n	800206a <UART_SetConfig+0x25e>
 80020c0:	2001      	movs	r0, #1
 80020c2:	e7d2      	b.n	800206a <UART_SetConfig+0x25e>
 80020c4:	2000      	movs	r0, #0
 80020c6:	e7d0      	b.n	800206a <UART_SetConfig+0x25e>
 80020c8:	2001      	movs	r0, #1
 80020ca:	e7ce      	b.n	800206a <UART_SetConfig+0x25e>
 80020cc:	2001      	movs	r0, #1
 80020ce:	e7cc      	b.n	800206a <UART_SetConfig+0x25e>
 80020d0:	2000      	movs	r0, #0
 80020d2:	e7ca      	b.n	800206a <UART_SetConfig+0x25e>
 80020d4:	2001      	movs	r0, #1
 80020d6:	e7c8      	b.n	800206a <UART_SetConfig+0x25e>

080020d8 <UART_AdvFeatureConfig>:
 80020d8:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80020da:	f013 0f01 	tst.w	r3, #1
 80020de:	d006      	beq.n	80020ee <UART_AdvFeatureConfig+0x16>
 80020e0:	6802      	ldr	r2, [r0, #0]
 80020e2:	6853      	ldr	r3, [r2, #4]
 80020e4:	f423 3300 	bic.w	r3, r3, #131072	; 0x20000
 80020e8:	6ac1      	ldr	r1, [r0, #44]	; 0x2c
 80020ea:	430b      	orrs	r3, r1
 80020ec:	6053      	str	r3, [r2, #4]
 80020ee:	6a83      	ldr	r3, [r0, #40]	; 0x28
 80020f0:	f013 0f02 	tst.w	r3, #2
 80020f4:	d006      	beq.n	8002104 <UART_AdvFeatureConfig+0x2c>
 80020f6:	6802      	ldr	r2, [r0, #0]
 80020f8:	6853      	ldr	r3, [r2, #4]
 80020fa:	f423 3380 	bic.w	r3, r3, #65536	; 0x10000
 80020fe:	6b01      	ldr	r1, [r0, #48]	; 0x30
 8002100:	430b      	orrs	r3, r1
 8002102:	6053      	str	r3, [r2, #4]
 8002104:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002106:	f013 0f04 	tst.w	r3, #4
 800210a:	d006      	beq.n	800211a <UART_AdvFeatureConfig+0x42>
 800210c:	6802      	ldr	r2, [r0, #0]
 800210e:	6853      	ldr	r3, [r2, #4]
 8002110:	f423 2380 	bic.w	r3, r3, #262144	; 0x40000
 8002114:	6b41      	ldr	r1, [r0, #52]	; 0x34
 8002116:	430b      	orrs	r3, r1
 8002118:	6053      	str	r3, [r2, #4]
 800211a:	6a83      	ldr	r3, [r0, #40]	; 0x28
 800211c:	f013 0f08 	tst.w	r3, #8
 8002120:	d006      	beq.n	8002130 <UART_AdvFeatureConfig+0x58>
 8002122:	6802      	ldr	r2, [r0, #0]
 8002124:	6853      	ldr	r3, [r2, #4]
 8002126:	f423 4300 	bic.w	r3, r3, #32768	; 0x8000
 800212a:	6b81      	ldr	r1, [r0, #56]	; 0x38
 800212c:	430b      	orrs	r3, r1
 800212e:	6053      	str	r3, [r2, #4]
 8002130:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002132:	f013 0f10 	tst.w	r3, #16
 8002136:	d006      	beq.n	8002146 <UART_AdvFeatureConfig+0x6e>
 8002138:	6802      	ldr	r2, [r0, #0]
 800213a:	6893      	ldr	r3, [r2, #8]
 800213c:	f423 5380 	bic.w	r3, r3, #4096	; 0x1000
 8002140:	6bc1      	ldr	r1, [r0, #60]	; 0x3c
 8002142:	430b      	orrs	r3, r1
 8002144:	6093      	str	r3, [r2, #8]
 8002146:	6a83      	ldr	r3, [r0, #40]	; 0x28
 8002148:	f013 0f20 	tst.w	r3, #32
 800214c:	d006      	beq.n	800215c <UART_AdvFeatureConfig+0x84>
 800214e:	6802      	ldr	r2, [r0, #0]
 8002150:	6893      	ldr	r3, [r2, #8]
 8002152:	f423 5300 	bic.w	r3, r3, #8192	; 0x2000
 8002156:	6c01      	ldr	r1, [r0, #64]	; 0x40
 8002158:	430b      	orrs	r3, r1
 800215a:	6093      	str	r3, [r2, #8]
 800215c:	6a83      	ldr	r3, [r0, #40]	; 0x28
 800215e:	f013 0f40 	tst.w	r3, #64	; 0x40
 8002162:	d00a      	beq.n	800217a <UART_AdvFeatureConfig+0xa2>
 8002164:	6802      	ldr	r2, [r0, #0]
 8002166:	6853      	ldr	r3, [r2, #4]
 8002168:	f423 1380 	bic.w	r3, r3, #1048576	; 0x100000
 800216c:	6c41      	ldr	r1, [r0, #68]	; 0x44
 800216e:	430b      	orrs	r3, r1
 8002170:	6053      	str	r3, [r2, #4]
 8002172:	6c43      	ldr	r3, [r0, #68]	; 0x44
 8002174:	f5b3 1f80 	cmp.w	r3, #1048576	; 0x100000
 8002178:	d00b      	beq.n	8002192 <UART_AdvFeatureConfig+0xba>
 800217a:	6a83      	ldr	r3, [r0, #40]	; 0x28
 800217c:	f013 0f80 	tst.w	r3, #128	; 0x80
 8002180:	d006      	beq.n	8002190 <UART_AdvFeatureConfig+0xb8>
 8002182:	6802      	ldr	r2, [r0, #0]
 8002184:	6853      	ldr	r3, [r2, #4]
 8002186:	f423 2300 	bic.w	r3, r3, #524288	; 0x80000
 800218a:	6cc1      	ldr	r1, [r0, #76]	; 0x4c
 800218c:	430b      	orrs	r3, r1
 800218e:	6053      	str	r3, [r2, #4]
 8002190:	4770      	bx	lr
 8002192:	6802      	ldr	r2, [r0, #0]
 8002194:	6853      	ldr	r3, [r2, #4]
 8002196:	f423 03c0 	bic.w	r3, r3, #6291456	; 0x600000
 800219a:	6c81      	ldr	r1, [r0, #72]	; 0x48
 800219c:	430b      	orrs	r3, r1
 800219e:	6053      	str	r3, [r2, #4]
 80021a0:	e7eb      	b.n	800217a <UART_AdvFeatureConfig+0xa2>

080021a2 <UART_WaitOnFlagUntilTimeout>:
 80021a2:	e92d 43f8 	stmdb	sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
 80021a6:	4605      	mov	r5, r0
 80021a8:	460f      	mov	r7, r1
 80021aa:	4616      	mov	r6, r2
 80021ac:	4699      	mov	r9, r3
 80021ae:	f8dd 8020 	ldr.w	r8, [sp, #32]
 80021b2:	682c      	ldr	r4, [r5, #0]
 80021b4:	69e4      	ldr	r4, [r4, #28]
 80021b6:	ea37 0304 	bics.w	r3, r7, r4
 80021ba:	bf0c      	ite	eq
 80021bc:	f04f 0c01 	moveq.w	ip, #1
 80021c0:	f04f 0c00 	movne.w	ip, #0
 80021c4:	45b4      	cmp	ip, r6
 80021c6:	d157      	bne.n	8002278 <UART_WaitOnFlagUntilTimeout+0xd6>
 80021c8:	f1b8 3fff 	cmp.w	r8, #4294967295	; 0xffffffff
 80021cc:	d0f1      	beq.n	80021b2 <UART_WaitOnFlagUntilTimeout+0x10>
 80021ce:	f023 fb39 	bl	8025844 <HAL_GetTick>
 80021d2:	eba0 0009 	sub.w	r0, r0, r9
 80021d6:	4540      	cmp	r0, r8
 80021d8:	d82f      	bhi.n	800223a <UART_WaitOnFlagUntilTimeout+0x98>
 80021da:	f1b8 0f00 	cmp.w	r8, #0
 80021de:	d02c      	beq.n	800223a <UART_WaitOnFlagUntilTimeout+0x98>
 80021e0:	682b      	ldr	r3, [r5, #0]
 80021e2:	681a      	ldr	r2, [r3, #0]
 80021e4:	f012 0f04 	tst.w	r2, #4
 80021e8:	d0e3      	beq.n	80021b2 <UART_WaitOnFlagUntilTimeout+0x10>
 80021ea:	69da      	ldr	r2, [r3, #28]
 80021ec:	f412 6f00 	tst.w	r2, #2048	; 0x800
 80021f0:	d0df      	beq.n	80021b2 <UART_WaitOnFlagUntilTimeout+0x10>
 80021f2:	f44f 6200 	mov.w	r2, #2048	; 0x800
 80021f6:	621a      	str	r2, [r3, #32]
 80021f8:	682a      	ldr	r2, [r5, #0]
 80021fa:	e852 3f00 	ldrex	r3, [r2]
 80021fe:	f423 73d0 	bic.w	r3, r3, #416	; 0x1a0
 8002202:	e842 3100 	strex	r1, r3, [r2]
 8002206:	2900      	cmp	r1, #0
 8002208:	d1f6      	bne.n	80021f8 <UART_WaitOnFlagUntilTimeout+0x56>
 800220a:	682a      	ldr	r2, [r5, #0]
 800220c:	f102 0308 	add.w	r3, r2, #8
 8002210:	e853 3f00 	ldrex	r3, [r3]
 8002214:	f023 0301 	bic.w	r3, r3, #1
 8002218:	3208      	adds	r2, #8
 800221a:	e842 3100 	strex	r1, r3, [r2]
 800221e:	2900      	cmp	r1, #0
 8002220:	d1f3      	bne.n	800220a <UART_WaitOnFlagUntilTimeout+0x68>
 8002222:	2320      	movs	r3, #32
 8002224:	f8c5 3084 	str.w	r3, [r5, #132]	; 0x84
 8002228:	f8c5 3088 	str.w	r3, [r5, #136]	; 0x88
 800222c:	f8c5 308c 	str.w	r3, [r5, #140]	; 0x8c
 8002230:	2300      	movs	r3, #0
 8002232:	f885 3080 	strb.w	r3, [r5, #128]	; 0x80
 8002236:	2003      	movs	r0, #3
 8002238:	e01f      	b.n	800227a <UART_WaitOnFlagUntilTimeout+0xd8>
 800223a:	682a      	ldr	r2, [r5, #0]
 800223c:	e852 3f00 	ldrex	r3, [r2]
 8002240:	f423 73d0 	bic.w	r3, r3, #416	; 0x1a0
 8002244:	e842 3100 	strex	r1, r3, [r2]
 8002248:	2900      	cmp	r1, #0
 800224a:	d1f6      	bne.n	800223a <UART_WaitOnFlagUntilTimeout+0x98>
 800224c:	682a      	ldr	r2, [r5, #0]
 800224e:	f102 0308 	add.w	r3, r2, #8
 8002252:	e853 3f00 	ldrex	r3, [r3]
 8002256:	f023 0301 	bic.w	r3, r3, #1
 800225a:	3208      	adds	r2, #8
 800225c:	e842 3100 	strex	r1, r3, [r2]
 8002260:	2900      	cmp	r1, #0
 8002262:	d1f3      	bne.n	800224c <UART_WaitOnFlagUntilTimeout+0xaa>
 8002264:	2320      	movs	r3, #32
 8002266:	f8c5 3084 	str.w	r3, [r5, #132]	; 0x84
 800226a:	f8c5 3088 	str.w	r3, [r5, #136]	; 0x88
 800226e:	2300      	movs	r3, #0
 8002270:	f885 3080 	strb.w	r3, [r5, #128]	; 0x80
 8002274:	2003      	movs	r0, #3
 8002276:	e000      	b.n	800227a <UART_WaitOnFlagUntilTimeout+0xd8>
 8002278:	2000      	movs	r0, #0
 800227a:	e8bd 83f8 	ldmia.w	sp!, {r3, r4, r5, r6, r7, r8, r9, pc}

0800227e <HAL_UART_Transmit>:
 800227e:	e92d 41f0 	stmdb	sp!, {r4, r5, r6, r7, r8, lr}
 8002282:	b082      	sub	sp, #8
 8002284:	461e      	mov	r6, r3
 8002286:	f8d0 3084 	ldr.w	r3, [r0, #132]	; 0x84
 800228a:	2b20      	cmp	r3, #32
 800228c:	d158      	bne.n	8002340 <HAL_UART_Transmit+0xc2>
 800228e:	4604      	mov	r4, r0
 8002290:	460d      	mov	r5, r1
 8002292:	4690      	mov	r8, r2
 8002294:	2900      	cmp	r1, #0
 8002296:	d057      	beq.n	8002348 <HAL_UART_Transmit+0xca>
 8002298:	2a00      	cmp	r2, #0
 800229a:	d057      	beq.n	800234c <HAL_UART_Transmit+0xce>
 800229c:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 80022a0:	2b01      	cmp	r3, #1
 80022a2:	d055      	beq.n	8002350 <HAL_UART_Transmit+0xd2>
 80022a4:	2301      	movs	r3, #1
 80022a6:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80022aa:	2300      	movs	r3, #0
 80022ac:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 80022b0:	2321      	movs	r3, #33	; 0x21
 80022b2:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80022b6:	f023 fac5 	bl	8025844 <HAL_GetTick>
 80022ba:	4607      	mov	r7, r0
 80022bc:	f8a4 8054 	strh.w	r8, [r4, #84]	; 0x54
 80022c0:	f8a4 8056 	strh.w	r8, [r4, #86]	; 0x56
 80022c4:	68a3      	ldr	r3, [r4, #8]
 80022c6:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80022ca:	d005      	beq.n	80022d8 <HAL_UART_Transmit+0x5a>
 80022cc:	f04f 0800 	mov.w	r8, #0
 80022d0:	2300      	movs	r3, #0
 80022d2:	f884 3080 	strb.w	r3, [r4, #128]	; 0x80
 80022d6:	e014      	b.n	8002302 <HAL_UART_Transmit+0x84>
 80022d8:	6923      	ldr	r3, [r4, #16]
 80022da:	b113      	cbz	r3, 80022e2 <HAL_UART_Transmit+0x64>
 80022dc:	f04f 0800 	mov.w	r8, #0
 80022e0:	e7f6      	b.n	80022d0 <HAL_UART_Transmit+0x52>
 80022e2:	46a8      	mov	r8, r5
 80022e4:	2500      	movs	r5, #0
 80022e6:	e7f3      	b.n	80022d0 <HAL_UART_Transmit+0x52>
 80022e8:	f838 3b02 	ldrh.w	r3, [r8], #2
 80022ec:	6822      	ldr	r2, [r4, #0]
 80022ee:	f3c3 0308 	ubfx	r3, r3, #0, #9
 80022f2:	6293      	str	r3, [r2, #40]	; 0x28
 80022f4:	f8b4 2056 	ldrh.w	r2, [r4, #86]	; 0x56
 80022f8:	b292      	uxth	r2, r2
 80022fa:	3a01      	subs	r2, #1
 80022fc:	b292      	uxth	r2, r2
 80022fe:	f8a4 2056 	strh.w	r2, [r4, #86]	; 0x56
 8002302:	f8b4 3056 	ldrh.w	r3, [r4, #86]	; 0x56
 8002306:	b29b      	uxth	r3, r3
 8002308:	b173      	cbz	r3, 8002328 <HAL_UART_Transmit+0xaa>
 800230a:	9600      	str	r6, [sp, #0]
 800230c:	463b      	mov	r3, r7
 800230e:	2200      	movs	r2, #0
 8002310:	2180      	movs	r1, #128	; 0x80
 8002312:	4620      	mov	r0, r4
 8002314:	f7ff ff45 	bl	80021a2 <UART_WaitOnFlagUntilTimeout>
 8002318:	b9e0      	cbnz	r0, 8002354 <HAL_UART_Transmit+0xd6>
 800231a:	2d00      	cmp	r5, #0
 800231c:	d0e4      	beq.n	80022e8 <HAL_UART_Transmit+0x6a>
 800231e:	f815 2b01 	ldrb.w	r2, [r5], #1
 8002322:	6823      	ldr	r3, [r4, #0]
 8002324:	629a      	str	r2, [r3, #40]	; 0x28
 8002326:	e7e5      	b.n	80022f4 <HAL_UART_Transmit+0x76>
 8002328:	9600      	str	r6, [sp, #0]
 800232a:	463b      	mov	r3, r7
 800232c:	2200      	movs	r2, #0
 800232e:	2140      	movs	r1, #64	; 0x40
 8002330:	4620      	mov	r0, r4
 8002332:	f7ff ff36 	bl	80021a2 <UART_WaitOnFlagUntilTimeout>
 8002336:	b978      	cbnz	r0, 8002358 <HAL_UART_Transmit+0xda>
 8002338:	2320      	movs	r3, #32
 800233a:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 800233e:	e000      	b.n	8002342 <HAL_UART_Transmit+0xc4>
 8002340:	2002      	movs	r0, #2
 8002342:	b002      	add	sp, #8
 8002344:	e8bd 81f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, pc}
 8002348:	2001      	movs	r0, #1
 800234a:	e7fa      	b.n	8002342 <HAL_UART_Transmit+0xc4>
 800234c:	2001      	movs	r0, #1
 800234e:	e7f8      	b.n	8002342 <HAL_UART_Transmit+0xc4>
 8002350:	2002      	movs	r0, #2
 8002352:	e7f6      	b.n	8002342 <HAL_UART_Transmit+0xc4>
 8002354:	2003      	movs	r0, #3
 8002356:	e7f4      	b.n	8002342 <HAL_UART_Transmit+0xc4>
 8002358:	2003      	movs	r0, #3
 800235a:	e7f2      	b.n	8002342 <HAL_UART_Transmit+0xc4>

0800235c <HAL_UART_Receive>:
 800235c:	e92d 43f0 	stmdb	sp!, {r4, r5, r6, r7, r8, r9, lr}
 8002360:	b083      	sub	sp, #12
 8002362:	461e      	mov	r6, r3
 8002364:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 8002368:	2b20      	cmp	r3, #32
 800236a:	f040 8081 	bne.w	8002470 <HAL_UART_Receive+0x114>
 800236e:	4604      	mov	r4, r0
 8002370:	460d      	mov	r5, r1
 8002372:	4690      	mov	r8, r2
 8002374:	2900      	cmp	r1, #0
 8002376:	d07f      	beq.n	8002478 <HAL_UART_Receive+0x11c>
 8002378:	2a00      	cmp	r2, #0
 800237a:	d07f      	beq.n	800247c <HAL_UART_Receive+0x120>
 800237c:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 8002380:	2b01      	cmp	r3, #1
 8002382:	d07d      	beq.n	8002480 <HAL_UART_Receive+0x124>
 8002384:	2301      	movs	r3, #1
 8002386:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 800238a:	2300      	movs	r3, #0
 800238c:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 8002390:	2222      	movs	r2, #34	; 0x22
 8002392:	f8c0 2088 	str.w	r2, [r0, #136]	; 0x88
 8002396:	66c3      	str	r3, [r0, #108]	; 0x6c
 8002398:	f023 fa54 	bl	8025844 <HAL_GetTick>
 800239c:	4607      	mov	r7, r0
 800239e:	f8a4 805c 	strh.w	r8, [r4, #92]	; 0x5c
 80023a2:	f8a4 805e 	strh.w	r8, [r4, #94]	; 0x5e
 80023a6:	68a3      	ldr	r3, [r4, #8]
 80023a8:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80023ac:	d006      	beq.n	80023bc <HAL_UART_Receive+0x60>
 80023ae:	b9a3      	cbnz	r3, 80023da <HAL_UART_Receive+0x7e>
 80023b0:	6922      	ldr	r2, [r4, #16]
 80023b2:	b972      	cbnz	r2, 80023d2 <HAL_UART_Receive+0x76>
 80023b4:	22ff      	movs	r2, #255	; 0xff
 80023b6:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023ba:	e014      	b.n	80023e6 <HAL_UART_Receive+0x8a>
 80023bc:	6922      	ldr	r2, [r4, #16]
 80023be:	b922      	cbnz	r2, 80023ca <HAL_UART_Receive+0x6e>
 80023c0:	f240 12ff 	movw	r2, #511	; 0x1ff
 80023c4:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023c8:	e00d      	b.n	80023e6 <HAL_UART_Receive+0x8a>
 80023ca:	22ff      	movs	r2, #255	; 0xff
 80023cc:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023d0:	e009      	b.n	80023e6 <HAL_UART_Receive+0x8a>
 80023d2:	227f      	movs	r2, #127	; 0x7f
 80023d4:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023d8:	e005      	b.n	80023e6 <HAL_UART_Receive+0x8a>
 80023da:	f1b3 5f80 	cmp.w	r3, #268435456	; 0x10000000
 80023de:	d00d      	beq.n	80023fc <HAL_UART_Receive+0xa0>
 80023e0:	2200      	movs	r2, #0
 80023e2:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 80023e6:	f8b4 8060 	ldrh.w	r8, [r4, #96]	; 0x60
 80023ea:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80023ee:	d00f      	beq.n	8002410 <HAL_UART_Receive+0xb4>
 80023f0:	f04f 0900 	mov.w	r9, #0
 80023f4:	2300      	movs	r3, #0
 80023f6:	f884 3080 	strb.w	r3, [r4, #128]	; 0x80
 80023fa:	e01e      	b.n	800243a <HAL_UART_Receive+0xde>
 80023fc:	6922      	ldr	r2, [r4, #16]
 80023fe:	b91a      	cbnz	r2, 8002408 <HAL_UART_Receive+0xac>
 8002400:	227f      	movs	r2, #127	; 0x7f
 8002402:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 8002406:	e7ee      	b.n	80023e6 <HAL_UART_Receive+0x8a>
 8002408:	223f      	movs	r2, #63	; 0x3f
 800240a:	f8a4 2060 	strh.w	r2, [r4, #96]	; 0x60
 800240e:	e7ea      	b.n	80023e6 <HAL_UART_Receive+0x8a>
 8002410:	6923      	ldr	r3, [r4, #16]
 8002412:	b113      	cbz	r3, 800241a <HAL_UART_Receive+0xbe>
 8002414:	f04f 0900 	mov.w	r9, #0
 8002418:	e7ec      	b.n	80023f4 <HAL_UART_Receive+0x98>
 800241a:	46a9      	mov	r9, r5
 800241c:	2500      	movs	r5, #0
 800241e:	e7e9      	b.n	80023f4 <HAL_UART_Receive+0x98>
 8002420:	6823      	ldr	r3, [r4, #0]
 8002422:	6a5b      	ldr	r3, [r3, #36]	; 0x24
 8002424:	ea08 0303 	and.w	r3, r8, r3
 8002428:	f829 3b02 	strh.w	r3, [r9], #2
 800242c:	f8b4 205e 	ldrh.w	r2, [r4, #94]	; 0x5e
 8002430:	b292      	uxth	r2, r2
 8002432:	3a01      	subs	r2, #1
 8002434:	b292      	uxth	r2, r2
 8002436:	f8a4 205e 	strh.w	r2, [r4, #94]	; 0x5e
 800243a:	f8b4 305e 	ldrh.w	r3, [r4, #94]	; 0x5e
 800243e:	b29b      	uxth	r3, r3
 8002440:	b18b      	cbz	r3, 8002466 <HAL_UART_Receive+0x10a>
 8002442:	9600      	str	r6, [sp, #0]
 8002444:	463b      	mov	r3, r7
 8002446:	2200      	movs	r2, #0
 8002448:	2120      	movs	r1, #32
 800244a:	4620      	mov	r0, r4
 800244c:	f7ff fea9 	bl	80021a2 <UART_WaitOnFlagUntilTimeout>
 8002450:	b9c0      	cbnz	r0, 8002484 <HAL_UART_Receive+0x128>
 8002452:	2d00      	cmp	r5, #0
 8002454:	d0e4      	beq.n	8002420 <HAL_UART_Receive+0xc4>
 8002456:	6823      	ldr	r3, [r4, #0]
 8002458:	6a5a      	ldr	r2, [r3, #36]	; 0x24
 800245a:	fa5f f388 	uxtb.w	r3, r8
 800245e:	4013      	ands	r3, r2
 8002460:	f805 3b01 	strb.w	r3, [r5], #1
 8002464:	e7e2      	b.n	800242c <HAL_UART_Receive+0xd0>
 8002466:	2320      	movs	r3, #32
 8002468:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 800246c:	2000      	movs	r0, #0
 800246e:	e000      	b.n	8002472 <HAL_UART_Receive+0x116>
 8002470:	2002      	movs	r0, #2
 8002472:	b003      	add	sp, #12
 8002474:	e8bd 83f0 	ldmia.w	sp!, {r4, r5, r6, r7, r8, r9, pc}
 8002478:	2001      	movs	r0, #1
 800247a:	e7fa      	b.n	8002472 <HAL_UART_Receive+0x116>
 800247c:	2001      	movs	r0, #1
 800247e:	e7f8      	b.n	8002472 <HAL_UART_Receive+0x116>
 8002480:	2002      	movs	r0, #2
 8002482:	e7f6      	b.n	8002472 <HAL_UART_Receive+0x116>
 8002484:	2003      	movs	r0, #3
 8002486:	e7f4      	b.n	8002472 <HAL_UART_Receive+0x116>

08002488 <UART_CheckIdleState>:
 8002488:	b530      	push	{r4, r5, lr}
 800248a:	b083      	sub	sp, #12
 800248c:	4604      	mov	r4, r0
 800248e:	2300      	movs	r3, #0
 8002490:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 8002494:	f023 f9d6 	bl	8025844 <HAL_GetTick>
 8002498:	4605      	mov	r5, r0
 800249a:	6822      	ldr	r2, [r4, #0]
 800249c:	6812      	ldr	r2, [r2, #0]
 800249e:	f012 0f08 	tst.w	r2, #8
 80024a2:	d10f      	bne.n	80024c4 <UART_CheckIdleState+0x3c>
 80024a4:	6823      	ldr	r3, [r4, #0]
 80024a6:	681b      	ldr	r3, [r3, #0]
 80024a8:	f013 0f04 	tst.w	r3, #4
 80024ac:	d118      	bne.n	80024e0 <UART_CheckIdleState+0x58>
 80024ae:	2320      	movs	r3, #32
 80024b0:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 80024b4:	f8c4 3088 	str.w	r3, [r4, #136]	; 0x88
 80024b8:	2000      	movs	r0, #0
 80024ba:	66e0      	str	r0, [r4, #108]	; 0x6c
 80024bc:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 80024c0:	b003      	add	sp, #12
 80024c2:	bd30      	pop	{r4, r5, pc}
 80024c4:	f06f 437e 	mvn.w	r3, #4261412864	; 0xfe000000
 80024c8:	9300      	str	r3, [sp, #0]
 80024ca:	4603      	mov	r3, r0
 80024cc:	2200      	movs	r2, #0
 80024ce:	f44f 1100 	mov.w	r1, #2097152	; 0x200000
 80024d2:	4620      	mov	r0, r4
 80024d4:	f7ff fe65 	bl	80021a2 <UART_WaitOnFlagUntilTimeout>
 80024d8:	2800      	cmp	r0, #0
 80024da:	d0e3      	beq.n	80024a4 <UART_CheckIdleState+0x1c>
 80024dc:	2003      	movs	r0, #3
 80024de:	e7ef      	b.n	80024c0 <UART_CheckIdleState+0x38>
 80024e0:	f06f 437e 	mvn.w	r3, #4261412864	; 0xfe000000
 80024e4:	9300      	str	r3, [sp, #0]
 80024e6:	462b      	mov	r3, r5
 80024e8:	2200      	movs	r2, #0
 80024ea:	f44f 0180 	mov.w	r1, #4194304	; 0x400000
 80024ee:	4620      	mov	r0, r4
 80024f0:	f7ff fe57 	bl	80021a2 <UART_WaitOnFlagUntilTimeout>
 80024f4:	2800      	cmp	r0, #0
 80024f6:	d0da      	beq.n	80024ae <UART_CheckIdleState+0x26>
 80024f8:	2003      	movs	r0, #3
 80024fa:	e7e1      	b.n	80024c0 <UART_CheckIdleState+0x38>

080024fc <HAL_UART_Init>:
 80024fc:	b378      	cbz	r0, 800255e <HAL_UART_Init+0x62>
 80024fe:	b510      	push	{r4, lr}
 8002500:	4604      	mov	r4, r0
 8002502:	f8d0 3084 	ldr.w	r3, [r0, #132]	; 0x84
 8002506:	b30b      	cbz	r3, 800254c <HAL_UART_Init+0x50>
 8002508:	2324      	movs	r3, #36	; 0x24
 800250a:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 800250e:	6822      	ldr	r2, [r4, #0]
 8002510:	6813      	ldr	r3, [r2, #0]
 8002512:	f023 0301 	bic.w	r3, r3, #1
 8002516:	6013      	str	r3, [r2, #0]
 8002518:	4620      	mov	r0, r4
 800251a:	f7ff fc77 	bl	8001e0c <UART_SetConfig>
 800251e:	2801      	cmp	r0, #1
 8002520:	d013      	beq.n	800254a <HAL_UART_Init+0x4e>
 8002522:	6aa3      	ldr	r3, [r4, #40]	; 0x28
 8002524:	b9bb      	cbnz	r3, 8002556 <HAL_UART_Init+0x5a>
 8002526:	6822      	ldr	r2, [r4, #0]
 8002528:	6853      	ldr	r3, [r2, #4]
 800252a:	f423 4390 	bic.w	r3, r3, #18432	; 0x4800
 800252e:	6053      	str	r3, [r2, #4]
 8002530:	6822      	ldr	r2, [r4, #0]
 8002532:	6893      	ldr	r3, [r2, #8]
 8002534:	f023 032a 	bic.w	r3, r3, #42	; 0x2a
 8002538:	6093      	str	r3, [r2, #8]
 800253a:	6822      	ldr	r2, [r4, #0]
 800253c:	6813      	ldr	r3, [r2, #0]
 800253e:	f043 0301 	orr.w	r3, r3, #1
 8002542:	6013      	str	r3, [r2, #0]
 8002544:	4620      	mov	r0, r4
 8002546:	f7ff ff9f 	bl	8002488 <UART_CheckIdleState>
 800254a:	bd10      	pop	{r4, pc}
 800254c:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002550:	f7fe fa68 	bl	8000a24 <HAL_UART_MspInit>
 8002554:	e7d8      	b.n	8002508 <HAL_UART_Init+0xc>
 8002556:	4620      	mov	r0, r4
 8002558:	f7ff fdbe 	bl	80020d8 <UART_AdvFeatureConfig>
 800255c:	e7e3      	b.n	8002526 <HAL_UART_Init+0x2a>
 800255e:	2001      	movs	r0, #1
 8002560:	4770      	bx	lr
	...

08002564 <UART_Start_Receive_IT>:
 8002564:	b410      	push	{r4}
 8002566:	6581      	str	r1, [r0, #88]	; 0x58
 8002568:	f8a0 205c 	strh.w	r2, [r0, #92]	; 0x5c
 800256c:	f8a0 205e 	strh.w	r2, [r0, #94]	; 0x5e
 8002570:	2300      	movs	r3, #0
 8002572:	6703      	str	r3, [r0, #112]	; 0x70
 8002574:	6883      	ldr	r3, [r0, #8]
 8002576:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 800257a:	d006      	beq.n	800258a <UART_Start_Receive_IT+0x26>
 800257c:	b9a3      	cbnz	r3, 80025a8 <UART_Start_Receive_IT+0x44>
 800257e:	6903      	ldr	r3, [r0, #16]
 8002580:	b973      	cbnz	r3, 80025a0 <UART_Start_Receive_IT+0x3c>
 8002582:	23ff      	movs	r3, #255	; 0xff
 8002584:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002588:	e014      	b.n	80025b4 <UART_Start_Receive_IT+0x50>
 800258a:	6903      	ldr	r3, [r0, #16]
 800258c:	b923      	cbnz	r3, 8002598 <UART_Start_Receive_IT+0x34>
 800258e:	f240 13ff 	movw	r3, #511	; 0x1ff
 8002592:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002596:	e00d      	b.n	80025b4 <UART_Start_Receive_IT+0x50>
 8002598:	23ff      	movs	r3, #255	; 0xff
 800259a:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 800259e:	e009      	b.n	80025b4 <UART_Start_Receive_IT+0x50>
 80025a0:	237f      	movs	r3, #127	; 0x7f
 80025a2:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 80025a6:	e005      	b.n	80025b4 <UART_Start_Receive_IT+0x50>
 80025a8:	f1b3 5f80 	cmp.w	r3, #268435456	; 0x10000000
 80025ac:	d02d      	beq.n	800260a <UART_Start_Receive_IT+0xa6>
 80025ae:	2300      	movs	r3, #0
 80025b0:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 80025b4:	2300      	movs	r3, #0
 80025b6:	f8c0 308c 	str.w	r3, [r0, #140]	; 0x8c
 80025ba:	2322      	movs	r3, #34	; 0x22
 80025bc:	f8c0 3088 	str.w	r3, [r0, #136]	; 0x88
 80025c0:	6801      	ldr	r1, [r0, #0]
 80025c2:	f101 0308 	add.w	r3, r1, #8
 80025c6:	e853 3f00 	ldrex	r3, [r3]
 80025ca:	f043 0301 	orr.w	r3, r3, #1
 80025ce:	3108      	adds	r1, #8
 80025d0:	e841 3400 	strex	r4, r3, [r1]
 80025d4:	2c00      	cmp	r4, #0
 80025d6:	d1f3      	bne.n	80025c0 <UART_Start_Receive_IT+0x5c>
 80025d8:	6e43      	ldr	r3, [r0, #100]	; 0x64
 80025da:	f1b3 5f00 	cmp.w	r3, #536870912	; 0x20000000
 80025de:	d01e      	beq.n	800261e <UART_Start_Receive_IT+0xba>
 80025e0:	6883      	ldr	r3, [r0, #8]
 80025e2:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 80025e6:	d043      	beq.n	8002670 <UART_Start_Receive_IT+0x10c>
 80025e8:	4b24      	ldr	r3, [pc, #144]	; (800267c <UART_Start_Receive_IT+0x118>)
 80025ea:	6703      	str	r3, [r0, #112]	; 0x70
 80025ec:	2300      	movs	r3, #0
 80025ee:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80025f2:	6802      	ldr	r2, [r0, #0]
 80025f4:	e852 3f00 	ldrex	r3, [r2]
 80025f8:	f443 7390 	orr.w	r3, r3, #288	; 0x120
 80025fc:	e842 3100 	strex	r1, r3, [r2]
 8002600:	2900      	cmp	r1, #0
 8002602:	d1f6      	bne.n	80025f2 <UART_Start_Receive_IT+0x8e>
 8002604:	2000      	movs	r0, #0
 8002606:	bc10      	pop	{r4}
 8002608:	4770      	bx	lr
 800260a:	6903      	ldr	r3, [r0, #16]
 800260c:	b91b      	cbnz	r3, 8002616 <UART_Start_Receive_IT+0xb2>
 800260e:	237f      	movs	r3, #127	; 0x7f
 8002610:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 8002614:	e7ce      	b.n	80025b4 <UART_Start_Receive_IT+0x50>
 8002616:	233f      	movs	r3, #63	; 0x3f
 8002618:	f8a0 3060 	strh.w	r3, [r0, #96]	; 0x60
 800261c:	e7ca      	b.n	80025b4 <UART_Start_Receive_IT+0x50>
 800261e:	f8b0 3068 	ldrh.w	r3, [r0, #104]	; 0x68
 8002622:	4293      	cmp	r3, r2
 8002624:	d8dc      	bhi.n	80025e0 <UART_Start_Receive_IT+0x7c>
 8002626:	6883      	ldr	r3, [r0, #8]
 8002628:	f5b3 5f80 	cmp.w	r3, #4096	; 0x1000
 800262c:	d01a      	beq.n	8002664 <UART_Start_Receive_IT+0x100>
 800262e:	4b14      	ldr	r3, [pc, #80]	; (8002680 <UART_Start_Receive_IT+0x11c>)
 8002630:	6703      	str	r3, [r0, #112]	; 0x70
 8002632:	2300      	movs	r3, #0
 8002634:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002638:	6802      	ldr	r2, [r0, #0]
 800263a:	e852 3f00 	ldrex	r3, [r2]
 800263e:	f443 7380 	orr.w	r3, r3, #256	; 0x100
 8002642:	e842 3100 	strex	r1, r3, [r2]
 8002646:	2900      	cmp	r1, #0
 8002648:	d1f6      	bne.n	8002638 <UART_Start_Receive_IT+0xd4>
 800264a:	6802      	ldr	r2, [r0, #0]
 800264c:	f102 0308 	add.w	r3, r2, #8
 8002650:	e853 3f00 	ldrex	r3, [r3]
 8002654:	f043 5380 	orr.w	r3, r3, #268435456	; 0x10000000
 8002658:	3208      	adds	r2, #8
 800265a:	e842 3100 	strex	r1, r3, [r2]
 800265e:	2900      	cmp	r1, #0
 8002660:	d1f3      	bne.n	800264a <UART_Start_Receive_IT+0xe6>
 8002662:	e7cf      	b.n	8002604 <UART_Start_Receive_IT+0xa0>
 8002664:	6903      	ldr	r3, [r0, #16]
 8002666:	2b00      	cmp	r3, #0
 8002668:	d1e1      	bne.n	800262e <UART_Start_Receive_IT+0xca>
 800266a:	4b06      	ldr	r3, [pc, #24]	; (8002684 <UART_Start_Receive_IT+0x120>)
 800266c:	6703      	str	r3, [r0, #112]	; 0x70
 800266e:	e7e0      	b.n	8002632 <UART_Start_Receive_IT+0xce>
 8002670:	6903      	ldr	r3, [r0, #16]
 8002672:	2b00      	cmp	r3, #0
 8002674:	d1b8      	bne.n	80025e8 <UART_Start_Receive_IT+0x84>
 8002676:	4b04      	ldr	r3, [pc, #16]	; (8002688 <UART_Start_Receive_IT+0x124>)
 8002678:	6703      	str	r3, [r0, #112]	; 0x70
 800267a:	e7b7      	b.n	80025ec <UART_Start_Receive_IT+0x88>
 800267c:	08001969 	.word	0x08001969
 8002680:	08001acd 	.word	0x08001acd
 8002684:	08001c6d 	.word	0x08001c6d
 8002688:	08001a1b 	.word	0x08001a1b

0800268c <HAL_UART_Receive_IT>:
 800268c:	b538      	push	{r3, r4, r5, lr}
 800268e:	f8d0 3088 	ldr.w	r3, [r0, #136]	; 0x88
 8002692:	2b20      	cmp	r3, #32
 8002694:	d117      	bne.n	80026c6 <HAL_UART_Receive_IT+0x3a>
 8002696:	b1c1      	cbz	r1, 80026ca <HAL_UART_Receive_IT+0x3e>
 8002698:	b1ca      	cbz	r2, 80026ce <HAL_UART_Receive_IT+0x42>
 800269a:	2300      	movs	r3, #0
 800269c:	66c3      	str	r3, [r0, #108]	; 0x6c
 800269e:	6803      	ldr	r3, [r0, #0]
 80026a0:	4c0c      	ldr	r4, [pc, #48]	; (80026d4 <HAL_UART_Receive_IT+0x48>)
 80026a2:	42a3      	cmp	r3, r4
 80026a4:	d00c      	beq.n	80026c0 <HAL_UART_Receive_IT+0x34>
 80026a6:	685b      	ldr	r3, [r3, #4]
 80026a8:	f413 0f00 	tst.w	r3, #8388608	; 0x800000
 80026ac:	d008      	beq.n	80026c0 <HAL_UART_Receive_IT+0x34>
 80026ae:	6804      	ldr	r4, [r0, #0]
 80026b0:	e854 3f00 	ldrex	r3, [r4]
 80026b4:	f043 6380 	orr.w	r3, r3, #67108864	; 0x4000000
 80026b8:	e844 3500 	strex	r5, r3, [r4]
 80026bc:	2d00      	cmp	r5, #0
 80026be:	d1f6      	bne.n	80026ae <HAL_UART_Receive_IT+0x22>
 80026c0:	f7ff ff50 	bl	8002564 <UART_Start_Receive_IT>
 80026c4:	e000      	b.n	80026c8 <HAL_UART_Receive_IT+0x3c>
 80026c6:	2002      	movs	r0, #2
 80026c8:	bd38      	pop	{r3, r4, r5, pc}
 80026ca:	2001      	movs	r0, #1
 80026cc:	e7fc      	b.n	80026c8 <HAL_UART_Receive_IT+0x3c>
 80026ce:	2001      	movs	r0, #1
 80026d0:	e7fa      	b.n	80026c8 <HAL_UART_Receive_IT+0x3c>
 80026d2:	bf00      	nop
 80026d4:	40008000 	.word	0x40008000

080026d8 <UARTEx_SetNbDataToProcess>:
 80026d8:	6e43      	ldr	r3, [r0, #100]	; 0x64
 80026da:	b92b      	cbnz	r3, 80026e8 <UARTEx_SetNbDataToProcess+0x10>
 80026dc:	2301      	movs	r3, #1
 80026de:	f8a0 306a 	strh.w	r3, [r0, #106]	; 0x6a
 80026e2:	f8a0 3068 	strh.w	r3, [r0, #104]	; 0x68
 80026e6:	4770      	bx	lr
 80026e8:	b430      	push	{r4, r5}
 80026ea:	6803      	ldr	r3, [r0, #0]
 80026ec:	689a      	ldr	r2, [r3, #8]
 80026ee:	f3c2 6242 	ubfx	r2, r2, #25, #3
 80026f2:	6899      	ldr	r1, [r3, #8]
 80026f4:	0f49      	lsrs	r1, r1, #29
 80026f6:	4d09      	ldr	r5, [pc, #36]	; (800271c <UARTEx_SetNbDataToProcess+0x44>)
 80026f8:	5c6b      	ldrb	r3, [r5, r1]
 80026fa:	00db      	lsls	r3, r3, #3
 80026fc:	4c08      	ldr	r4, [pc, #32]	; (8002720 <UARTEx_SetNbDataToProcess+0x48>)
 80026fe:	5c61      	ldrb	r1, [r4, r1]
 8002700:	fb93 f3f1 	sdiv	r3, r3, r1
 8002704:	f8a0 306a 	strh.w	r3, [r0, #106]	; 0x6a
 8002708:	5cab      	ldrb	r3, [r5, r2]
 800270a:	00db      	lsls	r3, r3, #3
 800270c:	5ca2      	ldrb	r2, [r4, r2]
 800270e:	fb93 f3f2 	sdiv	r3, r3, r2
 8002712:	f8a0 3068 	strh.w	r3, [r0, #104]	; 0x68
 8002716:	bc30      	pop	{r4, r5}
 8002718:	4770      	bx	lr
 800271a:	bf00      	nop
 800271c:	08002b38 	.word	0x08002b38
 8002720:	08002b30 	.word	0x08002b30

08002724 <HAL_UARTEx_WakeupCallback>:
 8002724:	4770      	bx	lr

08002726 <HAL_UARTEx_RxFifoFullCallback>:
 8002726:	4770      	bx	lr

08002728 <HAL_UARTEx_TxFifoEmptyCallback>:
 8002728:	4770      	bx	lr

0800272a <HAL_UARTEx_DisableFifoMode>:
 800272a:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 800272e:	2b01      	cmp	r3, #1
 8002730:	d018      	beq.n	8002764 <HAL_UARTEx_DisableFifoMode+0x3a>
 8002732:	2301      	movs	r3, #1
 8002734:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002738:	2324      	movs	r3, #36	; 0x24
 800273a:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 800273e:	6803      	ldr	r3, [r0, #0]
 8002740:	681a      	ldr	r2, [r3, #0]
 8002742:	6819      	ldr	r1, [r3, #0]
 8002744:	f021 0101 	bic.w	r1, r1, #1
 8002748:	6019      	str	r1, [r3, #0]
 800274a:	f022 5200 	bic.w	r2, r2, #536870912	; 0x20000000
 800274e:	2300      	movs	r3, #0
 8002750:	6643      	str	r3, [r0, #100]	; 0x64
 8002752:	6801      	ldr	r1, [r0, #0]
 8002754:	600a      	str	r2, [r1, #0]
 8002756:	2220      	movs	r2, #32
 8002758:	f8c0 2084 	str.w	r2, [r0, #132]	; 0x84
 800275c:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 8002760:	4618      	mov	r0, r3
 8002762:	4770      	bx	lr
 8002764:	2002      	movs	r0, #2
 8002766:	4770      	bx	lr

08002768 <HAL_UARTEx_SetTxFifoThreshold>:
 8002768:	b538      	push	{r3, r4, r5, lr}
 800276a:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 800276e:	2b01      	cmp	r3, #1
 8002770:	d01d      	beq.n	80027ae <HAL_UARTEx_SetTxFifoThreshold+0x46>
 8002772:	4604      	mov	r4, r0
 8002774:	2301      	movs	r3, #1
 8002776:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 800277a:	2324      	movs	r3, #36	; 0x24
 800277c:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 8002780:	6803      	ldr	r3, [r0, #0]
 8002782:	681d      	ldr	r5, [r3, #0]
 8002784:	681a      	ldr	r2, [r3, #0]
 8002786:	f022 0201 	bic.w	r2, r2, #1
 800278a:	601a      	str	r2, [r3, #0]
 800278c:	6802      	ldr	r2, [r0, #0]
 800278e:	6893      	ldr	r3, [r2, #8]
 8002790:	f023 4360 	bic.w	r3, r3, #3758096384	; 0xe0000000
 8002794:	4319      	orrs	r1, r3
 8002796:	6091      	str	r1, [r2, #8]
 8002798:	f7ff ff9e 	bl	80026d8 <UARTEx_SetNbDataToProcess>
 800279c:	6823      	ldr	r3, [r4, #0]
 800279e:	601d      	str	r5, [r3, #0]
 80027a0:	2320      	movs	r3, #32
 80027a2:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 80027a6:	2000      	movs	r0, #0
 80027a8:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 80027ac:	bd38      	pop	{r3, r4, r5, pc}
 80027ae:	2002      	movs	r0, #2
 80027b0:	e7fc      	b.n	80027ac <HAL_UARTEx_SetTxFifoThreshold+0x44>

080027b2 <HAL_UARTEx_SetRxFifoThreshold>:
 80027b2:	b538      	push	{r3, r4, r5, lr}
 80027b4:	f890 3080 	ldrb.w	r3, [r0, #128]	; 0x80
 80027b8:	2b01      	cmp	r3, #1
 80027ba:	d01d      	beq.n	80027f8 <HAL_UARTEx_SetRxFifoThreshold+0x46>
 80027bc:	4604      	mov	r4, r0
 80027be:	2301      	movs	r3, #1
 80027c0:	f880 3080 	strb.w	r3, [r0, #128]	; 0x80
 80027c4:	2324      	movs	r3, #36	; 0x24
 80027c6:	f8c0 3084 	str.w	r3, [r0, #132]	; 0x84
 80027ca:	6803      	ldr	r3, [r0, #0]
 80027cc:	681d      	ldr	r5, [r3, #0]
 80027ce:	681a      	ldr	r2, [r3, #0]
 80027d0:	f022 0201 	bic.w	r2, r2, #1
 80027d4:	601a      	str	r2, [r3, #0]
 80027d6:	6802      	ldr	r2, [r0, #0]
 80027d8:	6893      	ldr	r3, [r2, #8]
 80027da:	f023 6360 	bic.w	r3, r3, #234881024	; 0xe000000
 80027de:	4319      	orrs	r1, r3
 80027e0:	6091      	str	r1, [r2, #8]
 80027e2:	f7ff ff79 	bl	80026d8 <UARTEx_SetNbDataToProcess>
 80027e6:	6823      	ldr	r3, [r4, #0]
 80027e8:	601d      	str	r5, [r3, #0]
 80027ea:	2320      	movs	r3, #32
 80027ec:	f8c4 3084 	str.w	r3, [r4, #132]	; 0x84
 80027f0:	2000      	movs	r0, #0
 80027f2:	f884 0080 	strb.w	r0, [r4, #128]	; 0x80
 80027f6:	bd38      	pop	{r3, r4, r5, pc}
 80027f8:	2002      	movs	r0, #2
 80027fa:	e7fc      	b.n	80027f6 <HAL_UARTEx_SetRxFifoThreshold+0x44>

080027fc <Reset_Handler>:
 80027fc:	480d      	ldr	r0, [pc, #52]	; (8002834 <LoopForever+0x2>)
 80027fe:	4685      	mov	sp, r0
 8002800:	f01e ff40 	bl	8021684 <SystemInit>
 8002804:	480c      	ldr	r0, [pc, #48]	; (8002838 <LoopForever+0x6>)
 8002806:	490d      	ldr	r1, [pc, #52]	; (800283c <LoopForever+0xa>)
 8002808:	4a0d      	ldr	r2, [pc, #52]	; (8002840 <LoopForever+0xe>)
 800280a:	2300      	movs	r3, #0
 800280c:	e002      	b.n	8002814 <LoopCopyDataInit>

0800280e <CopyDataInit>:
 800280e:	58d4      	ldr	r4, [r2, r3]
 8002810:	50c4      	str	r4, [r0, r3]
 8002812:	3304      	adds	r3, #4

08002814 <LoopCopyDataInit>:
 8002814:	18c4      	adds	r4, r0, r3
 8002816:	428c      	cmp	r4, r1
 8002818:	d3f9      	bcc.n	800280e <CopyDataInit>
 800281a:	4a0a      	ldr	r2, [pc, #40]	; (8002844 <LoopForever+0x12>)
 800281c:	4c0a      	ldr	r4, [pc, #40]	; (8002848 <LoopForever+0x16>)
 800281e:	2300      	movs	r3, #0
 8002820:	e001      	b.n	8002826 <LoopFillZerobss>

08002822 <FillZerobss>:
 8002822:	6013      	str	r3, [r2, #0]
 8002824:	3204      	adds	r2, #4

08002826 <LoopFillZerobss>:
 8002826:	42a2      	cmp	r2, r4
 8002828:	d3fb      	bcc.n	8002822 <FillZerobss>
 800282a:	f7fd fca5 	bl	8000178 <__libc_init_array>
 800282e:	f7fd fe37 	bl	80004a0 <main>

08002832 <LoopForever>:
 8002832:	e7fe      	b.n	8002832 <LoopForever>
 8002834:	2000fc00 	.word	0x2000fc00
 8002838:	20006000 	.word	0x20006000
 800283c:	20006068 	.word	0x20006068
 8002840:	08005020 	.word	0x08005020
 8002844:	20006068 	.word	0x20006068
 8002848:	20006690 	.word	0x20006690

0800284c <ADC_IRQHandler>:
 800284c:	e7fe      	b.n	800284c <ADC_IRQHandler>
	...

08002850 <strcasecmp>:
 8002850:	b530      	push	{r4, r5, lr}
 8002852:	4d0b      	ldr	r5, [pc, #44]	; (8002880 <strcasecmp+0x30>)
 8002854:	4604      	mov	r4, r0
 8002856:	f814 3b01 	ldrb.w	r3, [r4], #1
 800285a:	5d5a      	ldrb	r2, [r3, r5]
 800285c:	f002 0203 	and.w	r2, r2, #3
 8002860:	2a01      	cmp	r2, #1
 8002862:	f811 2b01 	ldrb.w	r2, [r1], #1
 8002866:	5ca8      	ldrb	r0, [r5, r2]
 8002868:	f000 0003 	and.w	r0, r0, #3
 800286c:	bf08      	it	eq
 800286e:	3320      	addeq	r3, #32
 8002870:	2801      	cmp	r0, #1
 8002872:	bf08      	it	eq
 8002874:	3220      	addeq	r2, #32
 8002876:	1a98      	subs	r0, r3, r2
 8002878:	d101      	bne.n	800287e <strcasecmp+0x2e>
 800287a:	2a00      	cmp	r2, #0
 800287c:	d1eb      	bne.n	8002856 <strcasecmp+0x6>
 800287e:	bd30      	pop	{r4, r5, pc}
 8002880:	08002b41 	.word	0x08002b41

08002884 <_init>:
 8002884:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8002886:	bf00      	nop
 8002888:	bcf8      	pop	{r3, r4, r5, r6, r7}
 800288a:	bc08      	pop	{r3}
 800288c:	469e      	mov	lr, r3
 800288e:	4770      	bx	lr

08002890 <_fini>:
 8002890:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 8002892:	bf00      	nop
 8002894:	bcf8      	pop	{r3, r4, r5, r6, r7}
 8002896:	bc08      	pop	{r3}
 8002898:	469e      	mov	lr, r3
 800289a:	4770      	bx	lr
 800289c:	0000      	movs	r0, r0
	...
