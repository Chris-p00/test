//###############################################################################################################
// 파일명      : code_r12.c
// 회사명      : G-Philos
// 작성날짜  : 2009.12.02
// 작성자      : S.H.Moon
// 수정날짜  : 2021.01.04
// 수정자      : Lee Sang Cheol
// 설명         : communication pointer define(float read code(2/2))
//###############################################################################################################

#include "Define.h"

void init_code_r12()
{

#if 1
//  int tmp=1501;
/*--------------------------------------*/
/*  read(float-type)                    */
/*--------------------------------------*/
//  tmp = RF_VOLTAGE_POS;

        data_ptr[1501] = &Eab;                  // 1501
        data_ptr[1502] = &Ebc;                  // 1502
        data_ptr[1503] = &Eca;                  // 1503
        data_ptr[1504] = &dummy;                // 1504
        data_ptr[1505] = &Esa;                  // 1505
        data_ptr[1506] = &Esb;                  // 1506
        data_ptr[1507] = &Esc;                  // 1507
        data_ptr[1508] = &Eab_flt;              // 1508
        data_ptr[1509] = &Ebc_flt;              // 1509
        data_ptr[1510] = &Eca_flt;              // 1510

        data_ptr[1511] = &Vds;                  // 1511
        data_ptr[1512] = &Vqs;                  // 1512
        data_ptr[1513] = &Vde;                  // 1513
        data_ptr[1514] = &Vqe;                  // 1514
        data_ptr[1515] = &Vds_flt;              // 1515
        data_ptr[1516] = &Vqs_flt;              // 1516
        data_ptr[1517] = &Vde_flt;              // 1517
        data_ptr[1518] = &Vqe_flt;              // 1518
//      data_ptr[1519] = &Vsa_rms;              // 1519
//      data_ptr[1520] = &Vla_rms;              // 1520

        data_ptr[1521] = &Eab_rms;              // 1521
        data_ptr[1522] = &Ebc_rms;              // 1522
        data_ptr[1523] = &Eca_rms;              // 1523
//      data_ptr[1524] = &Esa_unb;              // 1524
//      data_ptr[1525] = &Esb_unb;              // 1525
//      data_ptr[1526] = &Esc_unb;              // 1526
//      data_ptr[1527] = &Va;                   // 1527
//      data_ptr[1528] = &Va_flt;               // 1528
        data_ptr[1529] = &dummy;                // 1529
        data_ptr[1530] = &Err_Vde;              // 1530

        data_ptr[1531] = &Vde_ref;              // 1531
        data_ptr[1532] = &Vqe_ref;              // 1532
//      data_ptr[1533] = &Vde_real;             // 1533
//      data_ptr[1534] = &Vqe_real;             // 1534
        data_ptr[1535] = &Vds_ref;              // 1535
        data_ptr[1536] = &Vqs_ref;              // 1536
        data_ptr[1537] = &Va_ref;               // 1537
        data_ptr[1538] = &Vb_ref;               // 1538
        data_ptr[1539] = &Vc_ref;               // 1539
        data_ptr[1540] = &dummy;                // 1540

        data_ptr[1541] = &Vfds_ref;             // 1541
        data_ptr[1542] = &Vfqs_ref;             // 1542
        data_ptr[1543] = &Esa_rms;              // 1543
        data_ptr[1544] = &Esb_rms;              // 1544
        data_ptr[1545] = &Esc_rms;              // 1545
        data_ptr[1546] = &dummy;                // 1546
        data_ptr[1547] = &dummy;                // 1547
        data_ptr[1548] = &dummy;                // 1548
        data_ptr[1549] = &dummy;                // 1549
        data_ptr[1550] = &dummy;                // 1550

        data_ptr[1551] = &PF_util;              // 1551
        data_ptr[1552] = &PF_util_avg;          // 1552
        data_ptr[1553] = &Pinv_DQ_avg;          // 1553
        data_ptr[1554] = &Pout;                 // 1554
        data_ptr[1555] = &Pinv_DQ;              // 1555
//      data_ptr[1556] = &Power_out;            // 1556
        data_ptr[1557] = &dummy;                // 1557
        data_ptr[1558] = &dummy;                // 1558
        data_ptr[1559] = &dummy;                // 1559
        data_ptr[1560] = &dummy;                // 1560

        data_ptr[1561] = &Vde_flt_C;            // 1561
        data_ptr[1562] = &Theta_C;              // 1562
        data_ptr[1563] = &Sin_theta_C;              // 1563
        data_ptr[1564] = &Cos_theta_C;              // 1564
        data_ptr[1565] = &Vds_apf;              // 1565
        data_ptr[1566] = &Vqs_apf;              // 1566
        data_ptr[1567] = &Vds_p;                // 1567
        data_ptr[1568] = &Vqs_p;                // 1568
        data_ptr[1569] = &Vds_n;                // 1569
        data_ptr[1570] = &Vqs_n;                // 1570

        data_ptr[1571] = &Vde_p;                /* 1571 */
        data_ptr[1572] = &Vqe_p;                /* 1572 */
        data_ptr[1573] = &Vde_n;                /* 1573 */
        data_ptr[1574] = &Vqe_n;                /* 1574 */
        data_ptr[1575] = &dummy;                /* 1575 */
        data_ptr[1576] = &dummy;                /* 1576 */
        data_ptr[1577] = &dummy;                /* 1577 */
        data_ptr[1578] = &dummy;                /* 1578 */
        data_ptr[1579] = &dummy;                /* 1579 */
        data_ptr[1580] = &dummy;                /* 1580 */

        data_ptr[1581] = &Theta_h;              /* 1581 */
        data_ptr[1582] = &Theta_n;              /* 1582 */
        data_ptr[1583] = &Sin_theta_n;          /* 1583 */
        data_ptr[1584] = &Cos_theta_n;          /* 1584 */
        data_ptr[1585] = &Theta_C_n;            /* 1585 */
        data_ptr[1586] = &Sin_theta_C_n;        /* 1586 */
        data_ptr[1587] = &Cos_theta_C_n;        /* 1587 */
        data_ptr[1588] = &dummy;                /* 1588 */
        data_ptr[1589] = &dummy;                /* 1589 */
        data_ptr[1590] = &dummy;                /* 1590 */

        data_ptr[1591] = &Ids_apf;              /* 1591 */
        data_ptr[1592] = &Iqs_apf;              /* 1592 */
        data_ptr[1593] = &Ids_p;                /* 1593 */
        data_ptr[1594] = &Iqs_p;                /* 1594 */
        data_ptr[1595] = &Ids_n;                /* 1595 */
        data_ptr[1596] = &Iqs_n;                /* 1596 */
        data_ptr[1597] = &Ide_p;                /* 1597 */
        data_ptr[1598] = &Iqe_p;                /* 1598 */
        data_ptr[1599] = &Ide_n;                /* 1599 */
        data_ptr[1600] = &Iqe_n;                /* 1600 */




        data_ptr[1601] = &pVfe1[DX][CREF];      // 1601         // current controller
        data_ptr[1602] = &pVfe1[QX][CREF];      // 1602
        data_ptr[1603] = &dummy;                // 1603
        data_ptr[1604] = &dummy;                // 1604
        data_ptr[1605] = &pVfe1[DX][CFB];       // 1605
        data_ptr[1606] = &pVfe1[QX][CFB];       // 1606
        data_ptr[1607] = &pVfe1[DX][CFF];       // 1607
        data_ptr[1608] = &pVfe1[QX][CFF];       // 1608
        data_ptr[1609] = &pVfe1[DX][CINT];      // 1609
        data_ptr[1610] = &pVfe1[QX][CINT];      // 1610

        data_ptr[1711] = &pVfe1[DX][CACT];      // 1711
        data_ptr[1712] = &pVfe1[QX][CACT];      // 1712
        data_ptr[1613] = &dummy;                // 1613
        data_ptr[1614] = &dummy;                // 1614
        data_ptr[1615] = &dummy;                // 1615
        data_ptr[1616] = &dummy;                // 1616
        data_ptr[1617] = &dummy;                // 1617
        data_ptr[1618] = &dummy;                // 1618
        data_ptr[1619] = &dummy;                // 1619
        data_ptr[1620] = &dummy;                // 1620

        data_ptr[1621] = &dummy;                // 1621
        data_ptr[1622] = &dummy;                // 1622
        data_ptr[1623] = &dummy;                // 1623
        data_ptr[1624] = &dummy;                // 1624
        data_ptr[1625] = &dummy;                // 1625
        data_ptr[1626] = &dummy;                // 1626
        data_ptr[1627] = &dummy;                // 1627
        data_ptr[1628] = &dummy;                // 1628
        data_ptr[1629] = &dummy;                // 1629
        data_ptr[1630] = &dummy;                // 1630

        data_ptr[1631] = &dummy;                // 1631
        data_ptr[1632] = &dummy;                // 1632
        data_ptr[1633] = &dummy;                // 1633
        data_ptr[1634] = &dummy;                // 1634
        data_ptr[1635] = &dummy;                // 1635
        data_ptr[1636] = &dummy;                // 1636
        data_ptr[1637] = &dummy;                // 1637
        data_ptr[1638] = &dummy;                // 1638
        data_ptr[1639] = &dummy;                // 1639
        data_ptr[1640] = &dummy;                // 1640

        data_ptr[1641] = &dummy;                // 1641
        data_ptr[1642] = &dummy;                // 1642
        data_ptr[1643] = &dummy;                // 1643
        data_ptr[1644] = &dummy;                // 1644
        data_ptr[1645] = &dummy;                // 1645
        data_ptr[1646] = &dummy;                // 1646
        data_ptr[1647] = &dummy;                // 1647
        data_ptr[1648] = &dummy;                // 1648
        data_ptr[1649] = &dummy;                // 1649
        data_ptr[1650] = &dummy;                // 1650

        data_ptr[1651] = &dummy;                // 1651
        data_ptr[1652] = &dummy;                // 1652
        data_ptr[1653] = &dummy;                // 1653
        data_ptr[1654] = &dummy;                // 1654
        data_ptr[1655] = &dummy;                // 1655
        data_ptr[1656] = &dummy;                // 1656
        data_ptr[1657] = &dummy;                // 1657
        data_ptr[1658] = &dummy;                // 1658
        data_ptr[1659] = &dummy;                // 1659
        data_ptr[1660] = &dummy;                // 1660

        data_ptr[1661] = &dummy;                // 1661
        data_ptr[1662] = &dummy;                // 1662
        data_ptr[1663] = &dummy;                // 1663
        data_ptr[1664] = &dummy;                // 1664
        data_ptr[1665] = &dummy;                // 1665
        data_ptr[1666] = &dummy;                // 1666
        data_ptr[1667] = &dummy;                // 1667
        data_ptr[1668] = &dummy;                // 1668
        data_ptr[1669] = &dummy;                // 1669
        data_ptr[1670] = &dummy;                // 1670

        data_ptr[1671] = &dummy;                // 1671
        data_ptr[1672] = &dummy;                // 1672
        data_ptr[1673] = &dummy;                // 1673
        data_ptr[1674] = &dummy;                // 1674
        data_ptr[1675] = &dummy;                // 1675
        data_ptr[1676] = &dummy;                // 1676
        data_ptr[1677] = &dummy;                // 1677
        data_ptr[1678] = &dummy;                // 1678
        data_ptr[1679] = &dummy;                // 1679
        data_ptr[1680] = &dummy;                // 1680

        data_ptr[1681] = &dummy;                // 1681
        data_ptr[1682] = &dummy;                // 1682
        data_ptr[1683] = &dummy;                // 1683
        data_ptr[1684] = &dummy;                // 1684
        data_ptr[1685] = &dummy;                // 1685
        data_ptr[1686] = &dummy;                // 1686
        data_ptr[1687] = &dummy;                // 1687
        data_ptr[1688] = &dummy;                // 1688
        data_ptr[1689] = &dummy;                // 1689
        data_ptr[1690] = &dummy;                // 1690

        data_ptr[1691] = &dummy;                // 1691
        data_ptr[1692] = &dummy;                // 1692
        data_ptr[1693] = &dummy;                // 1693
        data_ptr[1694] = &dummy;                // 1694
        data_ptr[1695] = &dummy;                // 1695
        data_ptr[1696] = &dummy;                // 1696
        data_ptr[1697] = &dummy;                // 1697
        data_ptr[1698] = &dummy;                // 1698
        data_ptr[1699] = &dummy;                // 1699
        data_ptr[1700] = &dummy;                // 1700

        data_ptr[1701] = &dummy;                /* 1701 */
        data_ptr[1702] = &dummy;                /* 1702 */
        data_ptr[1703] = &dummy;                /* 1703 */
        data_ptr[1704] = &dummy;                /* 1704 */
        data_ptr[1705] = &dummy;                /* 1705 */
        data_ptr[1706] = &dummy;                /* 1706 */
        data_ptr[1707] = &dummy;                /* 1707 */
        data_ptr[1708] = &dummy;                /* 1708 */
        data_ptr[1709] = &dummy;                /* 1709 */
        data_ptr[1710] = &dummy;                /* 1710 */

        data_ptr[1711] = &dummy;                /* 1711 */
        data_ptr[1712] = &dummy;                /* 1712 */
        data_ptr[1713] = &dummy;                // 1713
        data_ptr[1714] = &dummy;                // 1714
        data_ptr[1715] = &dummy;                // 1715
        data_ptr[1716] = &dummy;                // 1716
        data_ptr[1717] = &dummy;                // 1717
        data_ptr[1718] = &dummy;                // 1718
        data_ptr[1719] = &dummy;                // 1719
        data_ptr[1720] = &dummy;                // 1720

        data_ptr[1721] = &dummy;                // 1721
        data_ptr[1722] = &dummy;                // 1722
        data_ptr[1723] = &dummy;                // 1723
        data_ptr[1724] = &dummy;                // 1724
        data_ptr[1725] = &dummy;                // 1725
        data_ptr[1726] = &dummy;                // 1726
        data_ptr[1727] = &dummy;                // 1727
        data_ptr[1728] = &dummy;                // 1728
        data_ptr[1729] = &dummy;                // 1729
        data_ptr[1730] = &dummy;                // 1730

        data_ptr[1731] = &dummy;                /* 1731 */
        data_ptr[1732] = &dummy;                /* 1732 */
        data_ptr[1733] = &dummy;                /* 1733 */
        data_ptr[1734] = &dummy;                /* 1734 */
        data_ptr[1735] = &dummy;                /* 1735 */
        data_ptr[1736] = &dummy;                /* 1736 */
        data_ptr[1737] = &dummy;                /* 1737 */
        data_ptr[1738] = &dummy;                /* 1738 */
        data_ptr[1739] = &dummy;                /* 1739 */
        data_ptr[1740] = &dummy;                /* 1740 */

//      data_ptr[1741] = &Vdc_ref;              // 1741
        data_ptr[1742] = &Vdc;                  // 1742
        data_ptr[1743] = &Vdc_flt;              // 1743
//      data_ptr[1744] = &Del_Vdc;              // 1744
        data_ptr[1745] = &Err_Vdc_con;          // 1745
        data_ptr[1746] = &Err_Vdc_inv;          // 1746
        data_ptr[1747] = &Vdc_ref_con;          // 1747
        data_ptr[1748] = &A_ref_flt_avg;        // 1748
        data_ptr[1749] = &Vdc_ref_inv;              // 1749
        data_ptr[1750] = &dummy;                // 1750

//      data_ptr[1751] = &IL1;              // 1751
//      data_ptr[1752] = &IL2;              // 1752
//      data_ptr[1753] = &IL3;              // 1753
        data_ptr[1754] = &dummy;                // 1754
        data_ptr[1755] = &dummy;                // 1755
        data_ptr[1756] = &dummy;                // 1756
        data_ptr[1757] = &dummy;                // 1757
        data_ptr[1758] = &dummy;                // 1758
        data_ptr[1759] = &dummy;                // 1759
        data_ptr[1760] = &dummy;                // 1760

        data_ptr[1761] = &dummy;                // 1761
        data_ptr[1762] = &dummy;                // 1762
        data_ptr[1763] = &dummy;                // 1763
        data_ptr[1764] = &dummy;                // 1764
        data_ptr[1765] = &dummy;                // 1765
        data_ptr[1766] = &dummy;                // 1766
        data_ptr[1767] = &dummy;                // 1767
        data_ptr[1768] = &dummy;                // 1768
        data_ptr[1769] = &dummy;                // 1769
        data_ptr[1770] = &dummy;                // 1770

        data_ptr[1771] = &dummy;                // 1771
        data_ptr[1772] = &dummy;                // 1772
        data_ptr[1773] = &dummy;                // 1773
        data_ptr[1774] = &dummy;                // 1774
        data_ptr[1775] = &dummy;                // 1775
        data_ptr[1776] = &dummy;                // 1776
        data_ptr[1777] = &dummy;                // 1777
        data_ptr[1778] = &dummy;                // 1778
        data_ptr[1779] = &dummy;                // 1779
        data_ptr[1780] = &dummy;                // 1780

        data_ptr[1781] = &dummy;                // 1781
        data_ptr[1782] = &dummy;                // 1782
        data_ptr[1783] = &dummy;                // 1783
        data_ptr[1784] = &dummy;                // 1784
        data_ptr[1785] = &dummy;                // 1785
        data_ptr[1786] = &dummy;                // 1786
        data_ptr[1787] = &dummy;                // 1787
        data_ptr[1788] = &dummy;                // 1788
        data_ptr[1789] = &dummy;                // 1789
        data_ptr[1790] = &dummy;                // 1790

        data_ptr[1791] = &dummy;                /* 1791 */
        data_ptr[1792] = &dummy;                /* 1792 */
        data_ptr[1793] = &dummy;                /* 1793 */
        data_ptr[1794] = &dummy;                /* 1794 */
        data_ptr[1795] = &dummy;                /* 1795 */
        data_ptr[1796] = &dummy;                /* 1796 */
        data_ptr[1797] = &dummy;                /* 1797 */
        data_ptr[1798] = &dummy;                /* 1798 */
        data_ptr[1799] = &dummy;                /* 1799 */
        data_ptr[1800] = &dummy;                // 1800

//  tmp = RF_TEST_POS;

//      data_ptr[1801] = &Mag_sine_test_ramp;   /* 1801 */
//      data_ptr[1802] = &Del_mag_sine_test;    /* 1802 */
        data_ptr[1803] = &dummy;                /* 1803 */
        data_ptr[1804] = &dummy;                /* 1804 */
//      data_ptr[1805] = &Theta_test;           /* 1805 */
//      data_ptr[1806] = &Sin_Theta_test;       /* 1806 */
//      data_ptr[1807] = &Cos_Theta_test;       /* 1807 */
//      data_ptr[1808] = &Sin_square_test;      /* 1808 */
//      data_ptr[1809] = &Cos_square_test;      /* 1809 */
        data_ptr[1810] = &dummy;                /* 1810 */

        data_ptr[1811] = &dummy;                // 1811
        data_ptr[1812] = &dummy;                // 1812
        data_ptr[1813] = &dummy;                /* 1813 */
        data_ptr[1814] = &dummy;                /* 1814 */
        data_ptr[1815] = &dummy;                /* 1815 */
        data_ptr[1816] = &dummy;                /* 1816 */
        data_ptr[1817] = &dummy;                /* 1817 */
        data_ptr[1818] = &dummy;                /* 1818 */
        data_ptr[1819] = &dummy;                /* 1819 */
        data_ptr[1820] = &dummy;                /* 1820 */

//      data_ptr[1821] = &Ta_inv;               /* 1821 */
//      data_ptr[1822] = &Tb_inv;               /* 1822 */
//      data_ptr[1823] = &Tc_inv;               /* 1823 */
        data_ptr[1824] = &dummy;                /* 1824 */
        data_ptr[1825] = &dummy;                /* 1825 */
        data_ptr[1826] = &dummy;                /* 1826 */
        data_ptr[1827] = &dummy;                /* 1827 */
        data_ptr[1828] = &dummy;                /* 1828 */
        data_ptr[1829] = &dummy;                /* 1829 */
        data_ptr[1830] = &dummy;                /* 1830 */

        data_ptr[1831] = &dummy;                /* 1831 */
        data_ptr[1832] = &dummy;                /* 1832 */
        data_ptr[1833] = &dummy;                /* 1833 */
        data_ptr[1834] = &dummy;                /* 1834 */
        data_ptr[1835] = &dummy;                /* 1835 */
        data_ptr[1836] = &dummy;                /* 1836 */
        data_ptr[1837] = &dummy;                /* 1837 */
        data_ptr[1838] = &dummy;                /* 1838 */
        data_ptr[1839] = &dummy;                /* 1839 */
        data_ptr[1840] = &dummy;                /* 1840 */

        data_ptr[1841] = &dummy;                /* 1841 */
        data_ptr[1842] = &dummy;                /* 1842 */
        data_ptr[1843] = &dummy;                /* 1843 */
        data_ptr[1844] = &dummy;                /* 1844 */
        data_ptr[1845] = &dummy;                /* 1845 */
        data_ptr[1846] = &dummy;                /* 1846 */
        data_ptr[1847] = &dummy;                /* 1847 */
        data_ptr[1848] = &dummy;                /* 1848 */
        data_ptr[1849] = &dummy;                /* 1849 */
        data_ptr[1850] = &dummy;                /* 1850 */

//  tmp = RF_MONITOR_POS;

//      data_ptr[1851] = &Ia_100;               /* 1851 */
//      data_ptr[1852] = &Ib_100;               /* 1852 */
//      data_ptr[1853] = &Ic_100;               /* 1853 */
        data_ptr[1854] = &dummy;                // 1854
        data_ptr[1855] = &dummy;                // 1855
        data_ptr[1856] = &dummy;                // 1856
        data_ptr[1857] = &dummy;                // 1857
        data_ptr[1858] = &dummy;                // 1858
        data_ptr[1859] = &dummy;                // 1859
        data_ptr[1860] = &dummy;                // 1860

        data_ptr[1861] = &dummy;                // 1861
        data_ptr[1862] = &dummy;                // 1862
//      data_ptr[1863] = &Esa_100;              /* 1863 */
//      data_ptr[1864] = &Esb_100;              /* 1864 */
//      data_ptr[1865] = &Esc_100;              /* 1865 */
        data_ptr[1866] = &dummy;                /* 1866 */
        data_ptr[1867] = &dummy;                /* 1867 */
        data_ptr[1868] = &dummy;                /* 1868 */
        data_ptr[1869] = &dummy;                /* 1869 */
        data_ptr[1870] = &dummy;                /* 1870 */

        data_ptr[1871] = &dummy;                /* 1871 */
        data_ptr[1872] = &dummy;                /* 1872 */
        data_ptr[1873] = &dummy;                /* 1873 */
        data_ptr[1874] = &dummy;                /* 1874 */
        data_ptr[1875] = &dummy;                /* 1875 */
        data_ptr[1876] = &dummy;                /* 1876 */
        data_ptr[1877] = &dummy;                /* 1877 */
        data_ptr[1878] = &dummy;                /* 1878 */
        data_ptr[1879] = &dummy;                /* 1879 */
        data_ptr[1880] = &dummy;                /* 1880 */

        data_ptr[1881] = &dummy;                // 1881
        data_ptr[1882] = &dummy;                // 1882
        data_ptr[1883] = &dummy;                // 1883
        data_ptr[1884] = &dummy;                // 1884
        data_ptr[1885] = &dummy;                // 1885
        data_ptr[1886] = &dummy;                // 1886
        data_ptr[1887] = &dummy;                // 1887
        data_ptr[1888] = &dummy;                // 1888
        data_ptr[1889] = &dummy;                // 1889
        data_ptr[1890] = &dummy;                // 1890

        data_ptr[1891] = &dummy;                // 1891
        data_ptr[1892] = &dummy;                // 1892
        data_ptr[1893] = &dummy;                // 1893
        data_ptr[1894] = &dummy;                // 1894
        data_ptr[1895] = &dummy;                // 1895
        data_ptr[1896] = &dummy;                // 1896
        data_ptr[1897] = &dummy;                // 1897
        data_ptr[1898] = &dummy;                // 1898
        data_ptr[1899] = &dummy;                // 1899
        data_ptr[1900] = &dummy;                // 1900

//      data_ptr[1901] = &Thermal;              // 1901
        data_ptr[1902] = &dummy;                // 1902
        data_ptr[1903] = &dummy;                // 1903
        data_ptr[1904] = &dummy;                // 1904
        data_ptr[1905] = &dummy;                // 1905
        data_ptr[1906] = &dummy;                // 1906
        data_ptr[1907] = &dummy;                // 1907
        data_ptr[1908] = &dummy;                // 1908
        data_ptr[1909] = &dummy;                // 1909
        data_ptr[1910] = &dummy;                // 1910

        data_ptr[1911] = &dummy;                // 1911
        data_ptr[1912] = &dummy;                // 1912
        data_ptr[1913] = &dummy;                // 1913
        data_ptr[1914] = &dummy;                // 1914
        data_ptr[1915] = &dummy;                // 1915
        data_ptr[1916] = &dummy;                // 1916
        data_ptr[1917] = &dummy;                // 1917
        data_ptr[1918] = &dummy;                // 1918
        data_ptr[1919] = &dummy;                // 1919
        data_ptr[1920] = &dummy;                // 1920

        data_ptr[1921] = &dummy;                // 1921
        data_ptr[1922] = &dummy;                // 1922
        data_ptr[1923] = &dummy;                // 1923
        data_ptr[1924] = &dummy;                // 1924
        data_ptr[1925] = &dummy;                // 1925
        data_ptr[1926] = &dummy;                // 1926
        data_ptr[1927] = &dummy;                // 1927
        data_ptr[1928] = &dummy;                // 1928
        data_ptr[1929] = &dummy;                // 1929
        data_ptr[1930] = &dummy;                // 1930

        data_ptr[1931] = &dummy;                // 1931
        data_ptr[1932] = &dummy;                // 1932
        data_ptr[1933] = &dummy;                // 1933
        data_ptr[1934] = &dummy;                // 1934
        data_ptr[1935] = &dummy;                // 1935
        data_ptr[1936] = &dummy;                // 1936
        data_ptr[1937] = &dummy;                // 1937
        data_ptr[1938] = &dummy;                // 1938
        data_ptr[1939] = &dummy;                // 1939
        data_ptr[1940] = &dummy;                // 1940

        data_ptr[1941] = &dummy;                // 1941
        data_ptr[1942] = &dummy;                // 1942
        data_ptr[1943] = &dummy;                // 1943
        data_ptr[1944] = &dummy;                // 1944
        data_ptr[1945] = &dummy;                // 1945
        data_ptr[1946] = &dummy;                // 1946
        data_ptr[1947] = &dummy;                // 1947
        data_ptr[1948] = &dummy;                // 1948
        data_ptr[1949] = &dummy;                // 1949
        data_ptr[1950] = &dummy;                // 1950

        data_ptr[1951] = &dummy;                /* 1951 */
        data_ptr[1952] = &dummy;                /* 1952 */
        data_ptr[1953] = &dummy;                /* 1953 */
        data_ptr[1954] = &dummy;                /* 1954 */
        data_ptr[1955] = &dummy;                /* 1955 */
        data_ptr[1956] = &dummy;                /* 1956 */
        data_ptr[1957] = &dummy;                /* 1957 */
        data_ptr[1958] = &dummy;                /* 1958 */
        data_ptr[1959] = &dummy;                /* 1959 */
        data_ptr[1960] = &dummy;                /* 1960 */

        data_ptr[1961] = &dummy;                /* 1961 */
        data_ptr[1962] = &dummy;                /* 1962 */
        data_ptr[1963] = &dummy;                /* 1963 */
        data_ptr[1964] = &dummy;                /* 1964 */
        data_ptr[1965] = &dummy;                /* 1965 */
        data_ptr[1966] = &dummy;                /* 1966 */
        data_ptr[1967] = &dummy;                /* 1967 */
        data_ptr[1968] = &dummy;                /* 1968 */
        data_ptr[1969] = &dummy;                /* 1969 */
        data_ptr[1970] = &dummy;                /* 1970 */

        data_ptr[1971] = &dummy;                /* 1971 */
        data_ptr[1972] = &dummy;                /* 1972 */
        data_ptr[1973] = &dummy;                /* 1973 */
        data_ptr[1974] = &dummy;                /* 1974 */
        data_ptr[1975] = &dummy;                /* 1975 */
        data_ptr[1976] = &dummy;                /* 1976 */
        data_ptr[1977] = &dummy;                /* 1977 */
        data_ptr[1978] = &dummy;                /* 1978 */
        data_ptr[1979] = &dummy;                /* 1979 */
        data_ptr[1980] = &dummy;                /* 1980 */

        data_ptr[1981] = &dummy;                /* 1981 */
        data_ptr[1982] = &dummy;                /* 1982 */
        data_ptr[1983] = &dummy;                /* 1983 */
        data_ptr[1984] = &dummy;                /* 1984 */
        data_ptr[1985] = &dummy;                /* 1985 */
        data_ptr[1986] = &dummy;                /* 1986 */
        data_ptr[1987] = &dummy;                /* 1987 */
        data_ptr[1988] = &dummy;                /* 1988 */
        data_ptr[1989] = &dummy;                /* 1989 */
        data_ptr[1990] = &dummy;                /* 1990 */

        data_ptr[1991] = &dummy;                /* 1991 */
        data_ptr[1992] = &dummy;                /* 1992 */
        data_ptr[1993] = &dummy;                /* 1993 */
        data_ptr[1994] = &dummy;                /* 1994 */
        data_ptr[1995] = &dummy;                /* 1995 */
        data_ptr[1996] = &dummy;                /* 1996 */
        data_ptr[1997] = &dummy;                /* 1997 */
        data_ptr[1998] = &dummy;                /* 1998 */
        data_ptr[1999] = &dummy;                /* 1999 */
        data_ptr[2000] = &dummy;                /* 2000 */
#endif
}


