//###############################################################################################################
// 파일명      : code_rw2.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : communication pointer define(float read/write code)
//###############################################################################################################

#include "Define.h"


void init_code_rw2()
{
#if 1
//  int tmp=501;
/*--------------------------------------*/
/*  flash ram read/write(integer-type)  */
/*--------------------------------------*/
//  tmp = WI_SYSTEM_POS;

        data_ptr[501] = &History[0][0];             // 501
        data_ptr[502] = &History[0][1];             // 502
        data_ptr[503] = &History[0][2];             // 503
        data_ptr[504] = &History[0][3];             // 504
        data_ptr[505] = &History[0][4];             // 505
        data_ptr[506] = &History[0][5];             // 506
        data_ptr[507] = &History[0][6];             // 507
        data_ptr[508] = &History[0][7];             // 508
        data_ptr[509] = &History[0][8];             // 509
        data_ptr[510] = &History[0][9];             // 510

        data_ptr[511] = &History[0][10];            // 511
        data_ptr[512] = &History[0][11];            // 512
        data_ptr[513] = &History[0][12];            // 513
        data_ptr[514] = &History[0][13];            // 514
        data_ptr[515] = &History[0][14];            // 515
        data_ptr[516] = &History[0][15];            // 516
        data_ptr[517] = &History[0][16];            // 517
        data_ptr[518] = &History[0][17];            // 518
        data_ptr[519] = &History[0][18];            // 519
        data_ptr[520] = &History[0][19];            // 520

        data_ptr[521] = &History[1][0];             // 521
        data_ptr[522] = &History[1][1];             // 522
        data_ptr[523] = &History[1][2];             // 523
        data_ptr[524] = &History[1][3];             // 524
        data_ptr[525] = &History[1][4];             // 525
        data_ptr[526] = &History[1][5];             // 526
        data_ptr[527] = &History[1][6];             // 527
        data_ptr[528] = &History[1][7];             // 528
        data_ptr[529] = &History[1][8];             // 529
        data_ptr[530] = &History[1][9];             // 530

        data_ptr[531] = &History[1][10];            // 531
        data_ptr[532] = &History[1][11];            // 532
        data_ptr[533] = &History[1][12];            // 533
        data_ptr[534] = &History[1][13];            // 534
        data_ptr[535] = &History[1][14];            // 535
        data_ptr[536] = &History[1][15];            // 536
        data_ptr[537] = &History[1][16];            // 537
        data_ptr[538] = &History[1][17];            // 538
        data_ptr[539] = &History[1][18];            // 539
        data_ptr[540] = &History[1][19];            // 540

        data_ptr[541] = &History[2][0];             // 541
        data_ptr[542] = &History[2][1];             // 542
        data_ptr[543] = &History[2][2];             // 543
        data_ptr[544] = &History[2][3];             // 544
        data_ptr[545] = &History[2][4];             // 545
        data_ptr[546] = &History[2][5];             // 546
        data_ptr[547] = &History[2][6];             // 547
        data_ptr[548] = &History[2][7];             // 548
        data_ptr[549] = &History[2][8];             // 549
        data_ptr[550] = &History[2][9];             // 550

        data_ptr[551] = &History[2][10];            // 551
        data_ptr[552] = &History[2][11];            // 552
        data_ptr[553] = &History[2][12];            // 553
        data_ptr[554] = &History[2][13];            // 554
        data_ptr[555] = &History[2][14];            // 555
        data_ptr[556] = &History[2][15];            // 556
        data_ptr[557] = &History[2][16];            // 557
        data_ptr[558] = &History[2][17];            // 558
        data_ptr[559] = &History[2][18];            // 559
        data_ptr[560] = &History[2][19];            // 560

        data_ptr[561] = &History[3][0];             // 561
        data_ptr[562] = &History[3][1];             // 562
        data_ptr[563] = &History[3][2];             // 563
        data_ptr[564] = &History[3][3];             // 564
        data_ptr[565] = &History[3][4];             // 565
        data_ptr[566] = &History[3][5];             // 566
        data_ptr[567] = &History[3][6];             // 567
        data_ptr[568] = &History[3][7];             // 568
        data_ptr[569] = &History[3][8];             // 569
        data_ptr[570] = &History[3][9];             // 570

        data_ptr[571] = &History[3][10];            // 571
        data_ptr[572] = &History[3][11];            // 572
        data_ptr[573] = &History[3][12];            // 573
        data_ptr[574] = &History[3][13];            // 574
        data_ptr[575] = &History[3][14];            // 575
        data_ptr[576] = &History[3][15];            // 576
        data_ptr[577] = &History[3][16];            // 577
        data_ptr[578] = &History[3][17];            // 578
        data_ptr[579] = &History[3][18];            // 579
        data_ptr[580] = &History[3][19];            // 580

        data_ptr[581] = &History[4][0];             // 581
        data_ptr[582] = &History[4][1];             // 582
        data_ptr[583] = &History[4][2];             // 583
        data_ptr[584] = &History[4][3];             // 584
        data_ptr[585] = &History[4][4];             // 585
        data_ptr[586] = &History[4][5];             // 586
        data_ptr[587] = &History[4][6];             // 587
        data_ptr[588] = &History[4][7];             // 588
        data_ptr[589] = &History[4][8];             // 589
        data_ptr[590] = &History[4][9];             // 590

        data_ptr[591] = &History[4][10];            // 591
        data_ptr[592] = &History[4][11];            // 592
        data_ptr[593] = &History[4][12];            // 593
        data_ptr[594] = &History[4][13];            // 594
        data_ptr[595] = &History[4][14];            // 595
        data_ptr[596] = &History[4][15];            // 596
        data_ptr[597] = &History[4][16];            // 597
        data_ptr[598] = &History[4][17];            // 598
        data_ptr[599] = &History[4][18];            // 599
        data_ptr[600] = &History[4][19];            // 600

        data_ptr[601] = &History[5][0];         // 601
        data_ptr[602] = &History[5][1];         // 602
        data_ptr[603] = &History[5][2];         // 603
        data_ptr[604] = &History[5][3];         // 604
        data_ptr[605] = &History[5][4];         // 605
        data_ptr[606] = &History[5][5];         // 606
        data_ptr[607] = &History[5][6];         // 607
        data_ptr[608] = &History[5][7];         // 608
        data_ptr[609] = &History[5][8];         // 609
        data_ptr[610] = &History[5][9];         // 610

        data_ptr[611] = &History[5][10];        // 611
        data_ptr[612] = &History[5][11];        // 612
        data_ptr[613] = &History[5][12];        // 613
        data_ptr[614] = &History[5][13];        // 614
        data_ptr[615] = &History[5][14];        // 615
        data_ptr[616] = &History[5][15];        // 616
        data_ptr[617] = &History[5][16];        // 617
        data_ptr[618] = &History[5][17];        // 618
        data_ptr[619] = &History[5][18];        // 619
        data_ptr[620] = &History[5][19];        // 620

        data_ptr[621] = &History[6][0];         // 621
        data_ptr[622] = &History[6][1];         // 622
        data_ptr[623] = &History[6][2];         // 623
        data_ptr[624] = &History[6][3];         // 624
        data_ptr[625] = &History[6][4];         // 625
        data_ptr[626] = &History[6][5];         // 626
        data_ptr[627] = &History[6][6];         // 627
        data_ptr[628] = &History[6][7];         // 628
        data_ptr[629] = &History[6][8];         // 629
        data_ptr[630] = &History[6][9];         // 630

        data_ptr[631] = &History[6][10];        // 631
        data_ptr[632] = &History[6][11];        // 632
        data_ptr[633] = &History[6][12];        // 633
        data_ptr[634] = &History[6][13];        // 634
        data_ptr[635] = &History[6][14];        // 635
        data_ptr[636] = &History[6][15];        // 636
        data_ptr[637] = &History[6][16];        // 637
        data_ptr[638] = &History[6][17];        // 638
        data_ptr[639] = &History[6][18];        // 639
        data_ptr[640] = &History[6][19];        // 640

        data_ptr[641] = &History[7][0];         // 641
        data_ptr[642] = &History[7][1];         // 642
        data_ptr[643] = &History[7][2];         // 643
        data_ptr[644] = &History[7][3];         // 644
        data_ptr[645] = &History[7][4];         // 645
        data_ptr[646] = &History[7][5];         // 646
        data_ptr[647] = &History[7][6];         // 647
        data_ptr[648] = &History[7][7];         // 648
        data_ptr[649] = &History[7][8];         // 649
        data_ptr[650] = &History[7][9];         // 650

        data_ptr[651] = &History[7][10];        // 651
        data_ptr[652] = &History[7][11];        // 652
        data_ptr[653] = &History[7][12];        // 653
        data_ptr[654] = &History[7][13];        // 654
        data_ptr[655] = &History[7][14];        // 655
        data_ptr[656] = &History[7][15];        // 656
        data_ptr[657] = &History[7][16];        // 657
        data_ptr[658] = &History[7][17];        // 658
        data_ptr[659] = &History[7][18];        // 659
        data_ptr[660] = &History[7][19];        // 660

        data_ptr[661] = &History[8][0];         // 661
        data_ptr[662] = &History[8][1];         // 662
        data_ptr[663] = &History[8][2];         // 663
        data_ptr[664] = &History[8][3];         // 664
        data_ptr[665] = &History[8][4];         // 665
        data_ptr[666] = &History[8][5];         // 666
        data_ptr[667] = &History[8][6];         // 667
        data_ptr[668] = &History[8][7];         // 668
        data_ptr[669] = &History[8][8];         // 669
        data_ptr[670] = &History[8][9];         // 670

        data_ptr[671] = &History[8][10];        // 671
        data_ptr[672] = &History[8][11];        // 672
        data_ptr[673] = &History[8][12];        // 673
        data_ptr[674] = &History[8][13];        // 674
        data_ptr[675] = &History[8][14];        // 675
        data_ptr[676] = &History[8][15];        // 676
        data_ptr[677] = &History[8][16];        // 677
        data_ptr[678] = &History[8][17];        // 678
        data_ptr[679] = &History[8][18];        // 679
        data_ptr[680] = &History[8][19];        // 680

        data_ptr[681] = &History[9][0];         // 681
        data_ptr[682] = &History[9][1];         // 682
        data_ptr[683] = &History[9][2];         // 683
        data_ptr[684] = &History[9][3];         // 684
        data_ptr[685] = &History[9][4];         // 685
        data_ptr[686] = &History[9][5];         // 686
        data_ptr[687] = &History[9][6];         // 687
        data_ptr[688] = &History[9][7];         // 688
        data_ptr[689] = &History[9][8];         // 689
        data_ptr[690] = &History[9][9];         // 690

        data_ptr[691] = &History[9][10];        // 691
        data_ptr[692] = &History[9][11];        // 692
        data_ptr[693] = &History[9][12];        // 693
        data_ptr[694] = &History[9][13];        // 694
        data_ptr[695] = &History[9][14];        // 695
        data_ptr[696] = &History[9][15];        // 696
        data_ptr[697] = &History[9][16];        // 697
        data_ptr[698] = &History[9][17];        // 698
        data_ptr[699] = &History[9][18];        // 699
        data_ptr[700] = &History[9][19];        // 700
#endif
//  tmp = WI_DAC_POS;

#if 0
        data_ptr[701] = &DA_code[0];            // 701
        data_ptr[702] = &DA_code[1];            // 702
        data_ptr[703] = &DA_code[2];            // 703
        data_ptr[704] = &DA_code[3];            // 704
        data_ptr[705] = &idummy;                // 705
        data_ptr[706] = &idummy;                // 706
        data_ptr[707] = &idummy;                // 707
        data_ptr[708] = &idummy;                // 708
        data_ptr[709] = &idummy;                // 709
        data_ptr[710] = &idummy;                // 710

//  tmp = WI_DIG_INOUT_POS;

        data_ptr[711] = &Din_exor;              // 711
        data_ptr[712] = &Din_control_power;     // 712
        data_ptr[713] = &Din_arrester;          // 713
        data_ptr[714] = &Din_charge_MC;         // 714
        data_ptr[715] = &Din_main_MCCB;         // 715
        data_ptr[716] = &Din_remote_local;      // 716
        data_ptr[717] = &Din_ES;                // 717
        data_ptr[718] = &Din_seq_ready;         // 718
        data_ptr[719] = &Din_conv_status;       // 719
        data_ptr[720] = &idummy;                // 720

        data_ptr[721] = &idummy;                // 721
        data_ptr[722] = &idummy;                // 722
        data_ptr[723] = &idummy;                // 723
        data_ptr[724] = &Din_heatsink_thermal;  //724
        data_ptr[725] = &Din_main_control_MCCB; //725
        data_ptr[726] = &idummy;                //726
        data_ptr[727] = &idummy;                //727
        data_ptr[728] = &idummy;                //728
        data_ptr[729] = &idummy;                //729
        data_ptr[730] = &idummy;                //730

        data_ptr[731] = &Dout_exor;             // 731
        data_ptr[732] = &Dout_charge_MC;        // 732
        data_ptr[733] = &idummy;        // 733
        data_ptr[734] = &Dout_interlock;        // 734
        data_ptr[735] = &idummy;                // 735
        data_ptr[735] = &Dout_conv_run_stop;    // 735
        data_ptr[736] = &Dout_INV_seq_ready;    // 736
        data_ptr[737] = &idummy;    // 737
        data_ptr[738] = &idummy;                // 738
        data_ptr[739] = &idummy;                // 739
        data_ptr[740] = &idummy;                // 740

        data_ptr[741] = &INV_seq_ready;         // 741
        data_ptr[742] = &idummy;                // 742
        data_ptr[743] = &idummy;                // 743
        data_ptr[744] = &idummy;                // 744
        data_ptr[745] = &idummy;                // 745
        data_ptr[746] = &idummy;                // 746
        data_ptr[747] = &idummy;                // 747
        data_ptr[748] = &idummy;                // 748
        data_ptr[749] = &idummy;                // 749
        data_ptr[750] = &idummy;                // 750

        data_ptr[751] = &idummy;                /* 751  */
        data_ptr[752] = &idummy;                /* 752  */
        data_ptr[753] = &idummy;                /* 753  */
        data_ptr[754] = &idummy;                /* 754  */
        data_ptr[755] = &idummy;                /* 755  */
        data_ptr[756] = &idummy;                /* 756  */
        data_ptr[757] = &idummy;                /* 757  */
        data_ptr[758] = &idummy;                /* 758  */
        data_ptr[759] = &idummy;                /* 759  */
        data_ptr[760] = &idummy;                /* 760  */

//  tmp = WI_MULTIPLE_POS;

        data_ptr[761] = &idummy;                // 761
        data_ptr[762] = &idummy;                // 762
        data_ptr[763] = &idummy;                // 763
        data_ptr[764] = &idummy;                /* 764  */
        data_ptr[765] = &idummy;                /* 765  */
        data_ptr[766] = &idummy;                /* 766  */
        data_ptr[767] = &idummy;                /* 767  */
        data_ptr[768] = &idummy;                /* 768  */
        data_ptr[769] = &idummy;                /* 769  */
        data_ptr[770] = &idummy;                /* 770  */

        data_ptr[771] = &idummy;                /* 771  */
        data_ptr[772] = &idummy;                /* 772  */
        data_ptr[773] = &idummy;                /* 773  */
        data_ptr[774] = &idummy;                /* 774  */
        data_ptr[775] = &idummy;                /* 775  */
        data_ptr[776] = &idummy;                /* 776  */
        data_ptr[777] = &idummy;                /* 777  */
        data_ptr[778] = &idummy;                /* 778  */
        data_ptr[779] = &idummy;                /* 779  */
        data_ptr[780] = &idummy;                /* 780  */

        data_ptr[781] = &idummy;                /* 781  */
        data_ptr[782] = &idummy;                /* 782  */
        data_ptr[783] = &idummy;                /* 783  */
        data_ptr[784] = &idummy;                /* 784  */
        data_ptr[785] = &idummy;                /* 785  */
        data_ptr[786] = &idummy;                /* 786  */
        data_ptr[787] = &idummy;                /* 787  */
        data_ptr[788] = &idummy;                /* 788  */
        data_ptr[789] = &idummy;                /* 789  */
        data_ptr[790] = &idummy;                /* 790  */

        data_ptr[791] = &Trace_code[0];         /* 791  */
        data_ptr[792] = &Trace_code[1];         /* 792  */
        data_ptr[793] = &Trace_code[2];         /* 793  */
        data_ptr[794] = &Trace_code[3];         /* 794  */
        data_ptr[795] = &Trace_code[4];         /* 795  */
        data_ptr[796] = &Trace_code[5];         /* 796  */
        data_ptr[797] = &Trace_code[6];         /* 797  */
        data_ptr[798] = &Trace_code[7];         /* 798  */
        data_ptr[799] = &Trace_code[8];         /* 799  */
      //data_ptr[800~899] = for CPU2 function.
        data_ptr[900] = &idummy;                /* 900  */

//  tmp = WI_MONITOR_POS;

        data_ptr[901] = &Code_waves[0];         /* 901  */
        data_ptr[902] = &Code_waves[1];         /* 902  */
        data_ptr[903] = &Code_waves[2];         /* 903  */
        data_ptr[904] = &Code_waves[3];         /* 904  */
        data_ptr[905] = &idummy;                /* 905  */
        data_ptr[906] = &idummy;                /* 906  */
        data_ptr[907] = &idummy;                /* 907  */
        data_ptr[908] = &idummy;                /* 908  */
        data_ptr[909] = &idummy;                /* 909  */
        data_ptr[910] = &idummy;                /* 910  */

        data_ptr[911] = &idummy;                /* 911  */
        data_ptr[912] = &idummy;                /* 912  */
        data_ptr[913] = &idummy;                /* 913  */
        data_ptr[914] = &idummy;                /* 914  */
        data_ptr[915] = &idummy;                /* 915  */
        data_ptr[916] = &idummy;                /* 916  */
        data_ptr[917] = &idummy;                /* 917  */
        data_ptr[918] = &idummy;                /* 918  */
        data_ptr[919] = &idummy;                /* 919  */
        data_ptr[920] = &idummy;                /* 920  */

        data_ptr[921] = &idummy;                /* 921  */
        data_ptr[922] = &idummy;                /* 922  */
        data_ptr[923] = &idummy;                /* 923  */
        data_ptr[924] = &idummy;                /* 924  */
        data_ptr[925] = &idummy;                /* 925  */
        data_ptr[926] = &idummy;                /* 926  */
        data_ptr[927] = &idummy;                /* 927  */
        data_ptr[928] = &idummy;                /* 928  */
        data_ptr[929] = &idummy;                /* 929  */
        data_ptr[930] = &idummy;                /* 930  */

        data_ptr[931] = &idummy;                /* 931  */
        data_ptr[932] = &idummy;                /* 932  */
        data_ptr[933] = &idummy;                /* 933  */
        data_ptr[934] = &idummy;                /* 934  */
        data_ptr[935] = &idummy;                /* 935  */
        data_ptr[936] = &idummy;                /* 936  */
        data_ptr[937] = &idummy;                /* 937  */
        data_ptr[938] = &idummy;                /* 938  */
        data_ptr[939] = &idummy;                /* 939  */
        data_ptr[940] = &idummy;                /* 940  */

        data_ptr[941] = &idummy;                /* 941  */
        data_ptr[942] = &idummy;                /* 942  */
        data_ptr[943] = &idummy;                /* 943  */
        data_ptr[944] = &idummy;                /* 944  */
        data_ptr[945] = &idummy;                /* 945  */
        data_ptr[946] = &idummy;                /* 946  */
        data_ptr[947] = &idummy;                /* 947  */
        data_ptr[948] = &idummy;                /* 948  */
        data_ptr[949] = &idummy;                /* 949  */
        data_ptr[950] = &idummy;                /* 950  */

        data_ptr[951] = &idummy;                /* 951  */
        data_ptr[952] = &idummy;                /* 952  */
        data_ptr[953] = &idummy;                /* 953  */
        data_ptr[954] = &idummy;                /* 954  */
        data_ptr[955] = &idummy;                /* 955  */
        data_ptr[956] = &idummy;                /* 956  */
        data_ptr[957] = &idummy;                /* 957  */
        data_ptr[958] = &idummy;                /* 958  */
        data_ptr[959] = &idummy;                /* 959  */
        data_ptr[960] = &idummy;                /* 960  */

        data_ptr[961] = &idummy;                /* 961  */
        data_ptr[962] = &idummy;                /* 962  */
        data_ptr[963] = &idummy;                /* 963  */
        data_ptr[964] = &idummy;                /* 964  */
        data_ptr[965] = &idummy;                /* 965  */
        data_ptr[966] = &idummy;                /* 966  */
        data_ptr[967] = &idummy;                /* 967  */
        data_ptr[968] = &idummy;                /* 968  */
        data_ptr[969] = &idummy;                /* 969  */
        data_ptr[970] = &idummy;                /* 970  */

        data_ptr[971] = &idummy;                /* 971  */
        data_ptr[972] = &idummy;                /* 972  */
        data_ptr[973] = &idummy;                /* 973  */
        data_ptr[974] = &idummy;                /* 974  */
        data_ptr[975] = &idummy;                /* 975  */
        data_ptr[976] = &idummy;                /* 976  */
        data_ptr[977] = &idummy;                /* 977  */
        data_ptr[978] = &idummy;                /* 978  */
        data_ptr[979] = &idummy;                /* 979  */
        data_ptr[980] = &idummy;                /* 980  */

        data_ptr[981] = &CMD_Inv_OP_set;        /* 981  */
        data_ptr[982] = &idummy;                /* 982  */
        data_ptr[983] = &Vdc_ref_PLC;           /* 983  */
        data_ptr[984] = &BaudRate_PLC;          /* 984  */
        data_ptr[985] = &Flag_gating_test;      /* 985  */
        data_ptr[986] = &idummy;                /* 986  */
        data_ptr[987] = &idummy;                /* 987  */
        data_ptr[988] = &idummy;                /* 988  */
        data_ptr[989] = &idummy;                /* 989  */
        data_ptr[990] = &idummy;                /* 990  */

        data_ptr[991] = &idummy;                /* 991  */
        data_ptr[992] = &idummy;                /* 992  */
        data_ptr[993] = &idummy;                /* 993  */
        data_ptr[994] = &idummy;                /* 994  */
        data_ptr[995] = &idummy;                /* 995  */
        data_ptr[996] = &idummy;                /* 996  */
        data_ptr[997] = &idummy;                /* 997  */
        data_ptr[998] = &idummy;                /* 998  */
        data_ptr[999] = &idummy;                /* 999  */
        data_ptr[1000] = &idummy;               /* 1000 */
#endif
}

