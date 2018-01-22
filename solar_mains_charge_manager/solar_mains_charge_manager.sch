<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.4.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Arduino-clone">
<description>Arduino Clone pinheaders
By cl@xganon.com
http://www.xganon.com</description>
<packages>
<package name="NANO">
<pad name="TX0" x="5.08" y="-8.89" drill="0.8" shape="long"/>
<pad name="RX1" x="5.08" y="-6.35" drill="0.8" shape="long"/>
<pad name="RST1" x="5.08" y="-3.81" drill="0.8" shape="long"/>
<pad name="GND1" x="5.08" y="-1.27" drill="0.8" shape="long"/>
<pad name="D2" x="5.08" y="1.27" drill="0.8" shape="long"/>
<pad name="D3" x="5.08" y="3.81" drill="0.8" shape="long"/>
<pad name="D4" x="5.08" y="6.35" drill="0.8" shape="long"/>
<pad name="D5" x="5.08" y="8.89" drill="0.8" shape="long"/>
<pad name="D6" x="5.08" y="11.43" drill="0.8" shape="long"/>
<pad name="D7" x="5.08" y="13.97" drill="0.8" shape="long"/>
<pad name="D8" x="5.08" y="16.51" drill="0.8" shape="long"/>
<pad name="D9" x="5.08" y="19.05" drill="0.8" shape="long"/>
<pad name="RAW" x="-10.16" y="-8.89" drill="0.8" shape="long"/>
<pad name="GND" x="-10.16" y="-6.35" drill="0.8" shape="long"/>
<pad name="RST" x="-10.16" y="-3.81" drill="0.8" shape="long"/>
<pad name="A3" x="-10.16" y="11.43" drill="0.8" shape="long"/>
<pad name="A2" x="-10.16" y="13.97" drill="0.8" shape="long"/>
<pad name="A1" x="-10.16" y="16.51" drill="0.8" shape="long"/>
<pad name="A0" x="-10.16" y="19.05" drill="0.8" shape="long"/>
<pad name="D13" x="-10.16" y="26.67" drill="0.8" shape="long"/>
<pad name="D12" x="5.08" y="26.67" drill="0.8" shape="long"/>
<pad name="D11" x="5.08" y="24.13" drill="0.8" shape="long"/>
<pad name="D10" x="5.08" y="21.59" drill="0.8" shape="long"/>
<pad name="3.3V" x="-10.16" y="24.13" drill="0.8" shape="long" rot="R180"/>
<pad name="AREF" x="-10.16" y="21.59" drill="0.8" shape="long" rot="R180"/>
<pad name="5V" x="-10.16" y="-1.27" drill="0.8" shape="long"/>
<pad name="ICSP2" x="-5.08" y="-7.62" drill="0.8" rot="R90"/>
<pad name="ICSP4" x="-2.54" y="-7.62" drill="0.8" rot="R90"/>
<pad name="ICSP6" x="0" y="-7.62" drill="0.8" rot="R90"/>
<pad name="A4" x="-10.16" y="8.89" drill="0.8" shape="long" rot="R180"/>
<pad name="A5" x="-10.16" y="6.35" drill="0.8" shape="long" rot="R180"/>
<pad name="A6" x="-10.16" y="3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="A7" x="-10.16" y="1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="ICSP1" x="-5.08" y="-10.16" drill="0.8" rot="R90"/>
<pad name="ICSP3" x="-2.54" y="-10.16" drill="0.8" rot="R90"/>
<pad name="ICSP5" x="0" y="-10.16" drill="0.8" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="NANO">
<pin name="3.3V" x="-22.86" y="12.7" visible="pin" length="middle"/>
<pin name="AREF" x="-22.86" y="10.16" visible="pin" length="middle"/>
<pin name="ICSP1" x="-10.16" y="-27.94" visible="off" length="point" rot="R270"/>
<pin name="ICSP2" x="-10.16" y="-25.4" visible="off" length="point" rot="R270"/>
<pin name="ICSP3" x="-7.62" y="-27.94" visible="off" length="point" rot="R270"/>
<pin name="ICSP4" x="-7.62" y="-25.4" visible="off" length="point" rot="R270"/>
<pin name="TX0" x="10.16" y="-20.32" visible="pin" length="middle" rot="R180"/>
<pin name="RX1" x="10.16" y="-17.78" visible="pin" length="middle" rot="R180"/>
<pin name="RST1" x="10.16" y="-15.24" visible="pin" length="middle" rot="R180"/>
<pin name="GND2" x="10.16" y="-12.7" visible="pin" length="middle" rot="R180"/>
<pin name="D2" x="10.16" y="-10.16" visible="pin" length="middle" rot="R180"/>
<pin name="D3" x="10.16" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="D4" x="10.16" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D5" x="10.16" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D6" x="10.16" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="D7" x="10.16" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="D8" x="10.16" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D9" x="10.16" y="7.62" visible="pin" length="middle" rot="R180"/>
<pin name="RAW" x="-22.86" y="-20.32" visible="pin" length="middle"/>
<pin name="GND" x="-22.86" y="-17.78" visible="pin" length="middle"/>
<pin name="RST" x="-22.86" y="-15.24" visible="pin" length="middle"/>
<pin name="5.5V" x="-22.86" y="-12.7" visible="pin" length="middle"/>
<pin name="A3" x="-22.86" y="0" visible="pin" length="middle"/>
<pin name="A2" x="-22.86" y="2.54" visible="pin" length="middle"/>
<pin name="A1" x="-22.86" y="5.08" visible="pin" length="middle"/>
<pin name="A0" x="-22.86" y="7.62" visible="pin" length="middle"/>
<pin name="D13" x="-22.86" y="15.24" visible="pin" length="middle"/>
<pin name="D12" x="10.16" y="15.24" visible="pin" length="middle" rot="R180"/>
<pin name="D11" x="10.16" y="12.7" visible="pin" length="middle" rot="R180"/>
<pin name="D10" x="10.16" y="10.16" visible="pin" length="middle" rot="R180"/>
<pin name="A7" x="-22.86" y="-10.16" visible="pin" length="middle"/>
<pin name="A6" x="-22.86" y="-7.62" visible="pin" length="middle"/>
<pin name="A5" x="-22.86" y="-5.08" visible="pin" length="middle"/>
<pin name="A4" x="-22.86" y="-2.54" visible="pin" length="middle"/>
<pin name="ICSP5" x="-5.08" y="-27.94" visible="off" length="point" rot="R270"/>
<pin name="ICSP6" x="-5.08" y="-25.4" visible="off" length="point" rot="R270"/>
<wire x1="-17.78" y1="17.78" x2="-17.78" y2="-30.48" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-30.48" x2="5.08" y2="-30.48" width="0.254" layer="94"/>
<wire x1="5.08" y1="-30.48" x2="5.08" y2="17.78" width="0.254" layer="94"/>
<wire x1="5.08" y1="17.78" x2="-17.78" y2="17.78" width="0.254" layer="94"/>
<text x="-12.7" y="20.32" size="1.778" layer="95">Arduino Nano</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="NANO">
<description>Arduino Nano</description>
<gates>
<gate name="G$1" symbol="NANO" x="7.62" y="2.54"/>
</gates>
<devices>
<device name="" package="NANO">
<connects>
<connect gate="G$1" pin="3.3V" pad="3.3V"/>
<connect gate="G$1" pin="5.5V" pad="5V"/>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="AREF" pad="AREF"/>
<connect gate="G$1" pin="D10" pad="D10"/>
<connect gate="G$1" pin="D11" pad="D11"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D3" pad="D3"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D5" pad="D5"/>
<connect gate="G$1" pin="D6" pad="D6"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="D9" pad="D9"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND2" pad="GND1"/>
<connect gate="G$1" pin="ICSP1" pad="ICSP1"/>
<connect gate="G$1" pin="ICSP2" pad="ICSP2"/>
<connect gate="G$1" pin="ICSP3" pad="ICSP3"/>
<connect gate="G$1" pin="ICSP4" pad="ICSP4"/>
<connect gate="G$1" pin="ICSP5" pad="ICSP5"/>
<connect gate="G$1" pin="ICSP6" pad="ICSP6"/>
<connect gate="G$1" pin="RAW" pad="RAW"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="RST1" pad="RST1"/>
<connect gate="G$1" pin="RX1" pad="RX1"/>
<connect gate="G$1" pin="TX0" pad="TX0"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-molex" urn="urn:adsk.eagle:library:165">
<description>&lt;b&gt;Molex Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="22-23-2031" library_version="1">
<description>.100" (2.54mm) Center Header - 3 Pin</description>
<wire x1="-3.81" y1="3.175" x2="3.81" y2="3.175" width="0.254" layer="21"/>
<wire x1="3.81" y1="3.175" x2="3.81" y2="1.27" width="0.254" layer="21"/>
<wire x1="3.81" y1="1.27" x2="3.81" y2="-3.175" width="0.254" layer="21"/>
<wire x1="3.81" y1="-3.175" x2="-3.81" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-3.81" y1="-3.175" x2="-3.81" y2="1.27" width="0.254" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="-3.81" y2="3.175" width="0.254" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="3.81" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-2.54" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="0" y="0" drill="1" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="0" drill="1" shape="long" rot="R90"/>
<text x="-3.81" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.81" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="22-23-2041" library_version="1">
<description>.100" (2.54mm) Center Header - 4 Pin</description>
<wire x1="-5.08" y1="3.175" x2="5.08" y2="3.175" width="0.254" layer="21"/>
<wire x1="5.08" y1="3.175" x2="5.08" y2="1.27" width="0.254" layer="21"/>
<wire x1="5.08" y1="1.27" x2="5.08" y2="-3.175" width="0.254" layer="21"/>
<wire x1="5.08" y1="-3.175" x2="-5.08" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-5.08" y1="-3.175" x2="-5.08" y2="1.27" width="0.254" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="-5.08" y2="3.175" width="0.254" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="5.08" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-3.81" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="1" shape="long" rot="R90"/>
<text x="-5.08" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="53047-15" library_version="1">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 1.25 mm (.049 inch) pitch header&lt;p&gt;
straight&lt;br&gt;
Sourcxe: http://www.molex.com/pdm_docs/sd/530470210_sd.pdf</description>
<wire x1="-10.15" y1="-1.5" x2="10.15" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="10.15" y1="-1.5" x2="10.15" y2="1.5" width="0.2032" layer="21"/>
<wire x1="10.15" y1="1.5" x2="-10.15" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-10.15" y1="1.5" x2="-10.15" y2="-1.5" width="0.2032" layer="21"/>
<wire x1="-10.125" y1="-0.25" x2="-9.75" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="-9.75" y1="-0.25" x2="-9.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="9.75" y1="-0.25" x2="10.125" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="9.75" y1="-0.25" x2="9.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-10.125" y1="0.375" x2="-9.75" y2="0.375" width="0.0508" layer="21"/>
<wire x1="9.75" y1="0.375" x2="10.125" y2="0.375" width="0.0508" layer="21"/>
<wire x1="-9.75" y1="0.375" x2="-9.75" y2="1.125" width="0.0508" layer="21"/>
<wire x1="-9.75" y1="1.125" x2="9.75" y2="1.125" width="0.0508" layer="21"/>
<wire x1="9.75" y1="1.125" x2="9.75" y2="0.375" width="0.0508" layer="21"/>
<wire x1="9.75" y1="1.125" x2="10" y2="1.375" width="0.0508" layer="21"/>
<wire x1="-9.75" y1="1.125" x2="-10" y2="1.375" width="0.0508" layer="21"/>
<pad name="1" x="8.75" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="2" x="7.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="3" x="6.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="4" x="5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="5" x="3.75" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="6" x="2.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="7" x="1.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="8" x="0" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="9" x="-1.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="10" x="-2.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="11" x="-3.75" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="12" x="-5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="13" x="-6.25" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="14" x="-7.5" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="15" x="-8.75" y="0.45" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<text x="-10" y="1.75" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.25" y="1.75" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-10.125" y1="-1.5" x2="10.125" y2="-1.125" layer="21"/>
</package>
<package name="53048-15" library_version="1">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 1.25 mm (.049 inch) pitch header&lt;p&gt;
right angle</description>
<wire x1="-10.15" y1="-2.25" x2="-9.625" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="9.625" y1="-2.25" x2="10.15" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="10.15" y1="-2.25" x2="10.15" y2="3.125" width="0.2032" layer="21"/>
<wire x1="10.15" y1="3.125" x2="10" y2="3.125" width="0.2032" layer="21"/>
<wire x1="10" y1="3.125" x2="-10" y2="3.125" width="0.2032" layer="21"/>
<wire x1="-10" y1="3.125" x2="-10.15" y2="3.125" width="0.2032" layer="21"/>
<wire x1="-10.15" y1="3.125" x2="-10.15" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="-10.125" y1="1.5" x2="-9.625" y2="1.5" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="1.5" x2="-9.375" y2="1.5" width="0.0508" layer="21"/>
<wire x1="-9.375" y1="1.5" x2="-9.375" y2="0.625" width="0.0508" layer="21"/>
<wire x1="-9.375" y1="0.625" x2="9.375" y2="0.625" width="0.0508" layer="21"/>
<wire x1="9.375" y1="1.5" x2="9.625" y2="1.5" width="0.0508" layer="21"/>
<wire x1="9.625" y1="1.5" x2="10.125" y2="1.5" width="0.0508" layer="21"/>
<wire x1="9.375" y1="1.5" x2="9.375" y2="0.625" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="-1" x2="9.625" y2="-1" width="0.2032" layer="51"/>
<wire x1="-9" y1="-1.5" x2="-9.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-7.75" y1="-1.5" x2="-7.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-7.875" y1="-1.625" x2="-8.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-8.5" y1="-1.5" x2="-8.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-6.5" y1="-1.5" x2="-6.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-6.625" y1="-1.625" x2="-7.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-7.25" y1="-1.5" x2="-7.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-5.25" y1="-1.5" x2="-5.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-5.375" y1="-1.625" x2="-5.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-6" y1="-1.5" x2="-5.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-4" y1="-1.5" x2="-4.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-4.125" y1="-1.625" x2="-4.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-4.75" y1="-1.5" x2="-4.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-2.75" y1="-1.5" x2="-2.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-2.875" y1="-1.625" x2="-3.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-3.5" y1="-1.5" x2="-3.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-1.5" y1="-1.5" x2="-1.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-1.625" y1="-1.625" x2="-2.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-2.25" y1="-1.5" x2="-2.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-0.25" y1="-1.5" x2="-0.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-0.375" y1="-1.625" x2="-0.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-1" y1="-1.5" x2="-0.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="1" y1="-1.5" x2="0.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="0.875" y1="-1.625" x2="0.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="0.25" y1="-1.5" x2="0.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="2.25" y1="-1.5" x2="2.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="2.125" y1="-1.625" x2="1.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="1.5" y1="-1.5" x2="1.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="3.5" y1="-1.5" x2="3.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="3.375" y1="-1.625" x2="2.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="2.75" y1="-1.5" x2="2.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="4.75" y1="-1.5" x2="4.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="4.625" y1="-1.625" x2="4.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="4" y1="-1.5" x2="4.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="6" y1="-1.5" x2="5.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="5.875" y1="-1.625" x2="5.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="5.25" y1="-1.5" x2="5.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="7.25" y1="-1.5" x2="7.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="7.125" y1="-1.625" x2="6.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="6.5" y1="-1.5" x2="6.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="8.5" y1="-1.5" x2="8.375" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="8.375" y1="-1.625" x2="7.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="7.75" y1="-1.5" x2="7.875" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="9.625" y1="-1.625" x2="9.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="9" y1="-1.5" x2="9.125" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-9.125" y1="-1.625" x2="-9.625" y2="-1.625" width="0.2032" layer="51"/>
<wire x1="-10.125" y1="-1" x2="-9.625" y2="-1" width="0.2032" layer="21"/>
<wire x1="-9.625" y1="-1" x2="-9.625" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="9.625" y1="-1" x2="10.125" y2="-1" width="0.2032" layer="21"/>
<wire x1="9.625" y1="-1" x2="9.625" y2="-2.25" width="0.2032" layer="21"/>
<wire x1="-9.625" y1="1.5" x2="-9.625" y2="2.75" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="2.75" x2="9.625" y2="2.75" width="0.0508" layer="21"/>
<wire x1="9.625" y1="2.75" x2="9.625" y2="1.5" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="2.75" x2="-10" y2="3.125" width="0.0508" layer="21"/>
<wire x1="9.625" y1="2.75" x2="10" y2="3.125" width="0.0508" layer="21"/>
<wire x1="-8.875" y1="1.5" x2="-8.75" y2="2" width="0.2032" layer="21"/>
<wire x1="-8.75" y1="2" x2="-8.625" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-7.625" y1="1.5" x2="-7.5" y2="2" width="0.2032" layer="21"/>
<wire x1="-7.5" y1="2" x2="-7.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-6.375" y1="1.5" x2="-6.25" y2="2" width="0.2032" layer="21"/>
<wire x1="-6.25" y1="2" x2="-6.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-5.125" y1="1.5" x2="-5" y2="2" width="0.2032" layer="21"/>
<wire x1="-5" y1="2" x2="-4.875" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-3.875" y1="1.5" x2="-3.75" y2="2" width="0.2032" layer="21"/>
<wire x1="-3.75" y1="2" x2="-3.625" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-2.625" y1="1.5" x2="-2.5" y2="2" width="0.2032" layer="21"/>
<wire x1="-2.5" y1="2" x2="-2.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-1.375" y1="1.5" x2="-1.25" y2="2" width="0.2032" layer="21"/>
<wire x1="-1.25" y1="2" x2="-1.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="-0.125" y1="1.5" x2="0" y2="2" width="0.2032" layer="21"/>
<wire x1="0" y1="2" x2="0.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="1.125" y1="1.5" x2="1.25" y2="2" width="0.2032" layer="21"/>
<wire x1="1.25" y1="2" x2="1.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="2.375" y1="1.5" x2="2.5" y2="2" width="0.2032" layer="21"/>
<wire x1="2.5" y1="2" x2="2.625" y2="1.5" width="0.2032" layer="21"/>
<wire x1="3.625" y1="1.5" x2="3.75" y2="2" width="0.2032" layer="21"/>
<wire x1="3.75" y1="2" x2="3.875" y2="1.5" width="0.2032" layer="21"/>
<wire x1="4.875" y1="1.5" x2="5" y2="2" width="0.2032" layer="21"/>
<wire x1="5" y1="2" x2="5.125" y2="1.5" width="0.2032" layer="21"/>
<wire x1="6.125" y1="1.5" x2="6.25" y2="2" width="0.2032" layer="21"/>
<wire x1="6.25" y1="2" x2="6.375" y2="1.5" width="0.2032" layer="21"/>
<wire x1="7.375" y1="1.5" x2="7.5" y2="2" width="0.2032" layer="21"/>
<wire x1="7.5" y1="2" x2="7.625" y2="1.5" width="0.2032" layer="21"/>
<wire x1="8.625" y1="1.5" x2="8.75" y2="2" width="0.2032" layer="21"/>
<wire x1="8.75" y1="2" x2="8.875" y2="1.5" width="0.2032" layer="21"/>
<pad name="1" x="8.75" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="2" x="7.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="3" x="6.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="4" x="5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="5" x="3.75" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="6" x="2.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="7" x="1.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="8" x="0" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="9" x="-1.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="10" x="-2.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="11" x="-3.75" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="12" x="-5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="13" x="-6.25" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="14" x="-7.5" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<pad name="15" x="-8.75" y="-1.25" drill="0.5" diameter="0.6984" shape="long" rot="R90"/>
<text x="-8.75" y="3.375" size="1.27" layer="25">&gt;NAME</text>
<text x="-9.375" y="-3.625" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-9" y1="-1.5" x2="-8.5" y2="-1" layer="51"/>
<rectangle x1="-9" y1="0.625" x2="-8.5" y2="1.5" layer="21"/>
<rectangle x1="-7.75" y1="-1.5" x2="-7.25" y2="-1" layer="51"/>
<rectangle x1="-6.5" y1="-1.5" x2="-6" y2="-1" layer="51"/>
<rectangle x1="-5.25" y1="-1.5" x2="-4.75" y2="-1" layer="51"/>
<rectangle x1="-4" y1="-1.5" x2="-3.5" y2="-1" layer="51"/>
<rectangle x1="-2.75" y1="-1.5" x2="-2.25" y2="-1" layer="51"/>
<rectangle x1="-1.5" y1="-1.5" x2="-1" y2="-1" layer="51"/>
<rectangle x1="-0.25" y1="-1.5" x2="0.25" y2="-1" layer="51"/>
<rectangle x1="1" y1="-1.5" x2="1.5" y2="-1" layer="51"/>
<rectangle x1="2.25" y1="-1.5" x2="2.75" y2="-1" layer="51"/>
<rectangle x1="3.5" y1="-1.5" x2="4" y2="-1" layer="51"/>
<rectangle x1="4.75" y1="-1.5" x2="5.25" y2="-1" layer="51"/>
<rectangle x1="6" y1="-1.5" x2="6.5" y2="-1" layer="51"/>
<rectangle x1="7.25" y1="-1.5" x2="7.75" y2="-1" layer="51"/>
<rectangle x1="8.5" y1="-1.5" x2="9" y2="-1" layer="51"/>
<rectangle x1="-7.75" y1="0.625" x2="-7.25" y2="1.5" layer="21"/>
<rectangle x1="-6.5" y1="0.625" x2="-6" y2="1.5" layer="21"/>
<rectangle x1="-5.25" y1="0.625" x2="-4.75" y2="1.5" layer="21"/>
<rectangle x1="-4" y1="0.625" x2="-3.5" y2="1.5" layer="21"/>
<rectangle x1="-2.75" y1="0.625" x2="-2.25" y2="1.5" layer="21"/>
<rectangle x1="-1.5" y1="0.625" x2="-1" y2="1.5" layer="21"/>
<rectangle x1="-0.25" y1="0.625" x2="0.25" y2="1.5" layer="21"/>
<rectangle x1="1" y1="0.625" x2="1.5" y2="1.5" layer="21"/>
<rectangle x1="2.25" y1="0.625" x2="2.75" y2="1.5" layer="21"/>
<rectangle x1="3.5" y1="0.625" x2="4" y2="1.5" layer="21"/>
<rectangle x1="4.75" y1="0.625" x2="5.25" y2="1.5" layer="21"/>
<rectangle x1="6" y1="0.625" x2="6.5" y2="1.5" layer="21"/>
<rectangle x1="7.25" y1="0.625" x2="7.75" y2="1.5" layer="21"/>
<rectangle x1="8.5" y1="0.625" x2="9" y2="1.5" layer="21"/>
</package>
<package name="53261-15" library_version="1">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 1.25 mm (.049 inch) pitch header&lt;p&gt;
SMT&lt;p&gt;
right angle</description>
<wire x1="-10.15" y1="-1.375" x2="-9.625" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-9.625" y1="-1.375" x2="9.625" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="9.625" y1="-1.375" x2="10.15" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="10.15" y1="-1.375" x2="10.15" y2="2.625" width="0.2032" layer="21"/>
<wire x1="10.15" y1="2.625" x2="10" y2="2.625" width="0.2032" layer="21"/>
<wire x1="10" y1="2.625" x2="-10" y2="2.625" width="0.2032" layer="21"/>
<wire x1="-10" y1="2.625" x2="-10.15" y2="2.625" width="0.2032" layer="21"/>
<wire x1="-10.15" y1="2.625" x2="-10.15" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-10.125" y1="1.625" x2="-9.625" y2="1.625" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="1.625" x2="-9.375" y2="1.625" width="0.0508" layer="21"/>
<wire x1="-9.375" y1="1.625" x2="-9.375" y2="1" width="0.0508" layer="21"/>
<wire x1="-9.375" y1="1" x2="9.375" y2="1" width="0.0508" layer="21"/>
<wire x1="9.375" y1="1.625" x2="9.625" y2="1.625" width="0.0508" layer="21"/>
<wire x1="9.625" y1="1.625" x2="10.125" y2="1.625" width="0.0508" layer="21"/>
<wire x1="9.375" y1="1.625" x2="9.375" y2="1" width="0.0508" layer="21"/>
<wire x1="-10.125" y1="-0.75" x2="-9.625" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="-0.75" x2="-9.625" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="9.625" y1="-0.75" x2="10.125" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="9.625" y1="-0.75" x2="9.625" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="1.625" x2="-9.625" y2="2.25" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="2.25" x2="9.625" y2="2.25" width="0.0508" layer="21"/>
<wire x1="9.625" y1="2.25" x2="9.625" y2="1.625" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="2.25" x2="-10" y2="2.625" width="0.0508" layer="21"/>
<wire x1="9.625" y1="2.25" x2="10" y2="2.625" width="0.0508" layer="21"/>
<wire x1="-9" y1="-1.25" x2="-9" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-9" y1="-0.75" x2="-8.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-8.5" y1="-0.75" x2="-8.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-7.75" y1="-1.25" x2="-7.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-7.75" y1="-0.75" x2="-7.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-7.25" y1="-0.75" x2="-7.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-6.5" y1="-1.25" x2="-6.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-6.5" y1="-0.75" x2="-6" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-6" y1="-0.75" x2="-6" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-5.25" y1="-1.25" x2="-5.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-5.25" y1="-0.75" x2="-4.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-4.75" y1="-0.75" x2="-4.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-4" y1="-1.25" x2="-4" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-4" y1="-0.75" x2="-3.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-3.5" y1="-0.75" x2="-3.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-2.75" y1="-1.25" x2="-2.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-2.75" y1="-0.75" x2="-2.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-2.25" y1="-0.75" x2="-2.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-1.5" y1="-1.25" x2="-1.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-1.5" y1="-0.75" x2="-1" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-1" y1="-0.75" x2="-1" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-0.25" y1="-1.25" x2="-0.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="-0.25" y1="-0.75" x2="0.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="0.25" y1="-0.75" x2="0.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="1" y1="-1.25" x2="1" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="1" y1="-0.75" x2="1.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="1.5" y1="-0.75" x2="1.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="2.25" y1="-1.25" x2="2.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="2.25" y1="-0.75" x2="2.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="2.75" y1="-0.75" x2="2.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="3.5" y1="-1.25" x2="3.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="3.5" y1="-0.75" x2="4" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="4" y1="-0.75" x2="4" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="4.75" y1="-1.25" x2="4.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="4.75" y1="-0.75" x2="5.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="5.25" y1="-0.75" x2="5.25" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="6" y1="-1.25" x2="6" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="6" y1="-0.75" x2="6.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="6.5" y1="-0.75" x2="6.5" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="7.25" y1="-1.25" x2="7.25" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="7.25" y1="-0.75" x2="7.75" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="7.75" y1="-0.75" x2="7.75" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="8.5" y1="-1.25" x2="8.5" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="8.5" y1="-0.75" x2="9" y2="-0.75" width="0.0508" layer="21"/>
<wire x1="9" y1="-0.75" x2="9" y2="-1.25" width="0.0508" layer="21"/>
<wire x1="-10.25" y1="2.25" x2="-12.125" y2="2.25" width="0.2032" layer="51"/>
<wire x1="-12.125" y1="2.25" x2="-12.125" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="-12.125" y1="-0.75" x2="-10.25" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="10.25" y1="-0.75" x2="12.125" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="12.125" y1="-0.75" x2="12.125" y2="2.25" width="0.2032" layer="51"/>
<wire x1="12.125" y1="2.25" x2="10.25" y2="2.25" width="0.2032" layer="51"/>
<smd name="1" x="8.75" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="2" x="7.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="3" x="6.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="4" x="5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="5" x="3.75" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="6" x="2.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="7" x="1.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="8" x="0" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="9" x="-1.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="10" x="-2.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="11" x="-3.75" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="12" x="-5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="13" x="-6.25" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="14" x="-7.5" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="15" x="-8.75" y="-2.5" dx="0.8" dy="2" layer="1"/>
<smd name="S1" x="11.25" y="0.625" dx="2.1" dy="3" layer="1"/>
<smd name="S2" x="-11.25" y="0.625" dx="2.1" dy="3" layer="1"/>
<text x="-8.75" y="2.875" size="1.27" layer="25">&gt;NAME</text>
<text x="-8.875" y="-0.5" size="1.27" layer="27">&gt;VALUE</text>
<text x="10.75" y="-0.25" size="1.9304" layer="51">1</text>
<rectangle x1="-9" y1="1" x2="-8.5" y2="1.875" layer="21"/>
<rectangle x1="-7.75" y1="1" x2="-7.25" y2="1.875" layer="21"/>
<rectangle x1="-6.5" y1="1" x2="-6" y2="1.875" layer="21"/>
<rectangle x1="-5.25" y1="1" x2="-4.75" y2="1.875" layer="21"/>
<rectangle x1="-4" y1="1" x2="-3.5" y2="1.875" layer="21"/>
<rectangle x1="-2.75" y1="1" x2="-2.25" y2="1.875" layer="21"/>
<rectangle x1="-1.5" y1="1" x2="-1" y2="1.875" layer="21"/>
<rectangle x1="-0.25" y1="1" x2="0.25" y2="1.875" layer="21"/>
<rectangle x1="1" y1="1" x2="1.5" y2="1.875" layer="21"/>
<rectangle x1="2.25" y1="1" x2="2.75" y2="1.875" layer="21"/>
<rectangle x1="3.5" y1="1" x2="4" y2="1.875" layer="21"/>
<rectangle x1="4.75" y1="1" x2="5.25" y2="1.875" layer="21"/>
<rectangle x1="6" y1="1" x2="6.5" y2="1.875" layer="21"/>
<rectangle x1="7.25" y1="1" x2="7.75" y2="1.875" layer="21"/>
<rectangle x1="8.5" y1="1" x2="9" y2="1.875" layer="21"/>
</package>
<package name="53398-15" library_version="1">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 1.25 mm (.049 inch) pitch header&lt;p&gt;
SMT&lt;p&gt;
straight</description>
<wire x1="-10.15" y1="-1.375" x2="-9.625" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-9.625" y1="-1.375" x2="-9.375" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-9.375" y1="-1.375" x2="9.375" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="9.375" y1="-1.375" x2="9.625" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="9.625" y1="-1.375" x2="10.15" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="10.15" y1="-1.375" x2="10.15" y2="2.125" width="0.2032" layer="21"/>
<wire x1="10.15" y1="2.125" x2="10" y2="2.125" width="0.2032" layer="21"/>
<wire x1="10" y1="2.125" x2="-10" y2="2.125" width="0.2032" layer="21"/>
<wire x1="-10" y1="2.125" x2="-10.15" y2="2.125" width="0.2032" layer="21"/>
<wire x1="-10.15" y1="2.125" x2="-10.15" y2="-1.375" width="0.2032" layer="21"/>
<wire x1="-10.125" y1="1" x2="-9.625" y2="1" width="0.0508" layer="21"/>
<wire x1="9.625" y1="1" x2="10.125" y2="1" width="0.0508" layer="21"/>
<wire x1="-10.125" y1="-0.25" x2="-9.625" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="-0.25" x2="-9.625" y2="-1" width="0.0508" layer="21"/>
<wire x1="9.625" y1="-0.25" x2="10.125" y2="-0.25" width="0.0508" layer="21"/>
<wire x1="9.625" y1="-0.25" x2="9.625" y2="-1" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="1" x2="-9.625" y2="1.75" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="1.75" x2="9.625" y2="1.75" width="0.0508" layer="21"/>
<wire x1="9.625" y1="1.75" x2="9.625" y2="1" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="1.75" x2="-10" y2="2.125" width="0.0508" layer="21"/>
<wire x1="9.625" y1="1.75" x2="10" y2="2.125" width="0.0508" layer="21"/>
<wire x1="-10.25" y1="2.125" x2="-12.125" y2="2.125" width="0.2032" layer="51"/>
<wire x1="-12.125" y1="2.125" x2="-12.125" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="-12.125" y1="-0.75" x2="-10.25" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="10.25" y1="-0.75" x2="12.125" y2="-0.75" width="0.2032" layer="51"/>
<wire x1="12.125" y1="-0.75" x2="12.125" y2="2.125" width="0.2032" layer="51"/>
<wire x1="12.125" y1="2.125" x2="10.25" y2="2.125" width="0.2032" layer="51"/>
<wire x1="-10.125" y1="-1" x2="-9.625" y2="-1" width="0.0508" layer="21"/>
<wire x1="-9.625" y1="-1" x2="-9.375" y2="-1" width="0.0508" layer="21"/>
<wire x1="-9.375" y1="-1" x2="-9.375" y2="-1.375" width="0.0508" layer="21"/>
<wire x1="9.625" y1="-1" x2="10.125" y2="-1" width="0.0508" layer="21"/>
<wire x1="9.375" y1="-1" x2="9.625" y2="-1" width="0.0508" layer="21"/>
<wire x1="9.375" y1="-1" x2="9.375" y2="-1.375" width="0.0508" layer="21"/>
<smd name="1" x="8.75" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="2" x="7.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="3" x="6.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="4" x="5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="5" x="3.75" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="6" x="2.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="7" x="1.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="8" x="0" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="9" x="-1.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="10" x="-2.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="11" x="-3.75" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="12" x="-5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="13" x="-6.25" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="14" x="-7.5" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="15" x="-8.75" y="-2.5" dx="0.8" dy="1.8" layer="1"/>
<smd name="S1" x="11.25" y="0.625" dx="2.1" dy="3" layer="1"/>
<smd name="S2" x="-11.25" y="0.625" dx="2.1" dy="3" layer="1"/>
<text x="-9.875" y="2.375" size="1.27" layer="25">&gt;NAME</text>
<text x="-9.375" y="-1" size="1.27" layer="27">&gt;VALUE</text>
<text x="10.625" y="-0.25" size="1.9304" layer="51">1</text>
<rectangle x1="-9" y1="0.375" x2="-8.5" y2="1" layer="21"/>
<rectangle x1="-7.75" y1="0.375" x2="-7.25" y2="1" layer="21"/>
<rectangle x1="-6.5" y1="0.375" x2="-6" y2="1" layer="21"/>
<rectangle x1="-5.25" y1="0.375" x2="-4.75" y2="1" layer="21"/>
<rectangle x1="-4" y1="0.375" x2="-3.5" y2="1" layer="21"/>
<rectangle x1="-2.75" y1="0.375" x2="-2.25" y2="1" layer="21"/>
<rectangle x1="-1.5" y1="0.375" x2="-1" y2="1" layer="21"/>
<rectangle x1="-0.25" y1="0.375" x2="0.25" y2="1" layer="21"/>
<rectangle x1="1" y1="0.375" x2="1.5" y2="1" layer="21"/>
<rectangle x1="2.25" y1="0.375" x2="2.75" y2="1" layer="21"/>
<rectangle x1="3.5" y1="0.375" x2="4" y2="1" layer="21"/>
<rectangle x1="4.75" y1="0.375" x2="5.25" y2="1" layer="21"/>
<rectangle x1="6" y1="0.375" x2="6.5" y2="1" layer="21"/>
<rectangle x1="7.25" y1="0.375" x2="7.75" y2="1" layer="21"/>
<rectangle x1="8.5" y1="0.375" x2="9" y2="1" layer="21"/>
</package>
<package name="22-23-2021" library_version="1">
<description>.100" (2.54mm) Center Headers - 2 Pin</description>
<wire x1="-2.54" y1="3.175" x2="2.54" y2="3.175" width="0.254" layer="21"/>
<wire x1="2.54" y1="3.175" x2="2.54" y2="1.27" width="0.254" layer="21"/>
<wire x1="2.54" y1="1.27" x2="2.54" y2="-3.175" width="0.254" layer="21"/>
<wire x1="2.54" y1="-3.175" x2="-2.54" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-2.54" y1="-3.175" x2="-2.54" y2="1.27" width="0.254" layer="21"/>
<wire x1="-2.54" y1="1.27" x2="-2.54" y2="3.175" width="0.254" layer="21"/>
<wire x1="-2.54" y1="1.27" x2="2.54" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="1" shape="long" rot="R90"/>
<text x="-2.54" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="MV" library_version="1">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M" library_version="1">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="22-23-2031" prefix="X" library_version="1">
<description>.100" (2.54mm) Center Header - 3 Pin</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2031">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2031" constant="no"/>
<attribute name="OC_FARNELL" value="1462950" constant="no"/>
<attribute name="OC_NEWARK" value="30C0862" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="22-23-2041" prefix="X" library_version="1">
<description>.100" (2.54mm) Center Header - 4 Pin</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2041">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2041" constant="no"/>
<attribute name="OC_FARNELL" value="1462920" constant="no"/>
<attribute name="OC_NEWARK" value="38C0355" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="53?-15" prefix="X" library_version="1">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 1.25 mm (.049 inch) pitch header</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="15.24" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="12.7" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="10.16" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="0" y="7.62" addlevel="always" swaplevel="1"/>
<gate name="-5" symbol="M" x="0" y="5.08" addlevel="always" swaplevel="1"/>
<gate name="-6" symbol="M" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-7" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-8" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-9" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
<gate name="-10" symbol="M" x="0" y="-7.62" addlevel="always" swaplevel="1"/>
<gate name="-11" symbol="M" x="0" y="-10.16" addlevel="always" swaplevel="1"/>
<gate name="-12" symbol="M" x="0" y="-12.7" addlevel="always" swaplevel="1"/>
<gate name="-13" symbol="M" x="0" y="-15.24" addlevel="always" swaplevel="1"/>
<gate name="-14" symbol="M" x="0" y="-17.78" addlevel="always" swaplevel="1"/>
<gate name="-15" symbol="M" x="0" y="-20.32" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="047" package="53047-15">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-14" pin="S" pad="14"/>
<connect gate="-15" pin="S" pad="15"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="53047-1510-C" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="79K4146" constant="no"/>
</technology>
</technologies>
</device>
<device name="048" package="53048-15">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-14" pin="S" pad="14"/>
<connect gate="-15" pin="S" pad="15"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="53048-1510" constant="no"/>
<attribute name="OC_FARNELL" value="9732942" constant="no"/>
<attribute name="OC_NEWARK" value="98K9840" constant="no"/>
</technology>
</technologies>
</device>
<device name="261" package="53261-15">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-14" pin="S" pad="14"/>
<connect gate="-15" pin="S" pad="15"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="1125365" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="398" package="53398-15">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-10" pin="S" pad="10"/>
<connect gate="-11" pin="S" pad="11"/>
<connect gate="-12" pin="S" pad="12"/>
<connect gate="-13" pin="S" pad="13"/>
<connect gate="-14" pin="S" pad="14"/>
<connect gate="-15" pin="S" pad="15"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
<connect gate="-9" pin="S" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="53398-1590" constant="no"/>
<attribute name="OC_FARNELL" value="1125358" constant="no"/>
<attribute name="OC_NEWARK" value="57H5433" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="22-23-2021" prefix="X" library_version="1">
<description>.100" (2.54mm) Center Header - 2 Pin</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2021">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2021" constant="no"/>
<attribute name="OC_FARNELL" value="1462926" constant="no"/>
<attribute name="OC_NEWARK" value="25C3832" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Arduino-clone" deviceset="NANO" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="X5" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2031" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="X3" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2031" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="X6" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2041" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="X7" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="53?-15" device="047"/>
<part name="X8" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="53?-15" device="047"/>
<part name="X10" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2041" device=""/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="X2" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2021" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="107.95" y="73.66"/>
<instance part="GND2" gate="1" x="78.74" y="48.26"/>
<instance part="X5" gate="-1" x="52.07" y="38.1" rot="R180"/>
<instance part="X5" gate="-2" x="52.07" y="40.64" rot="R180"/>
<instance part="X5" gate="-3" x="52.07" y="43.18" rot="R180"/>
<instance part="GND5" gate="1" x="57.15" y="33.02"/>
<instance part="X3" gate="-1" x="147.32" y="83.82"/>
<instance part="X3" gate="-2" x="147.32" y="81.28"/>
<instance part="X3" gate="-3" x="147.32" y="78.74"/>
<instance part="GND9" gate="1" x="161.29" y="80.01"/>
<instance part="X6" gate="-1" x="134.62" y="73.66"/>
<instance part="X6" gate="-2" x="134.62" y="71.12"/>
<instance part="X6" gate="-3" x="134.62" y="68.58"/>
<instance part="X6" gate="-4" x="134.62" y="66.04"/>
<instance part="GND10" gate="1" x="146.05" y="72.39"/>
<instance part="X7" gate="-1" x="73.66" y="53.34" rot="R180"/>
<instance part="X7" gate="-2" x="73.66" y="55.88" rot="R180"/>
<instance part="X7" gate="-3" x="73.66" y="58.42" rot="R180"/>
<instance part="X7" gate="-4" x="73.66" y="60.96" rot="R180"/>
<instance part="X7" gate="-5" x="73.66" y="63.5" rot="R180"/>
<instance part="X7" gate="-6" x="73.66" y="66.04" rot="R180"/>
<instance part="X7" gate="-7" x="73.66" y="68.58" rot="R180"/>
<instance part="X7" gate="-8" x="73.66" y="71.12" rot="R180"/>
<instance part="X7" gate="-9" x="73.66" y="73.66" rot="R180"/>
<instance part="X7" gate="-10" x="73.66" y="76.2" rot="R180"/>
<instance part="X7" gate="-11" x="73.66" y="78.74" rot="R180"/>
<instance part="X7" gate="-12" x="73.66" y="81.28" rot="R180"/>
<instance part="X7" gate="-13" x="73.66" y="83.82" rot="R180"/>
<instance part="X7" gate="-14" x="73.66" y="86.36" rot="R180"/>
<instance part="X7" gate="-15" x="73.66" y="88.9" rot="R180"/>
<instance part="X8" gate="-1" x="121.92" y="88.9"/>
<instance part="X8" gate="-2" x="121.92" y="86.36"/>
<instance part="X8" gate="-3" x="121.92" y="83.82"/>
<instance part="X8" gate="-4" x="121.92" y="81.28"/>
<instance part="X8" gate="-5" x="121.92" y="78.74"/>
<instance part="X8" gate="-6" x="121.92" y="76.2"/>
<instance part="X8" gate="-7" x="121.92" y="73.66"/>
<instance part="X8" gate="-8" x="121.92" y="71.12"/>
<instance part="X8" gate="-9" x="121.92" y="68.58"/>
<instance part="X8" gate="-10" x="121.92" y="66.04"/>
<instance part="X8" gate="-11" x="121.92" y="63.5"/>
<instance part="X8" gate="-12" x="121.92" y="60.96"/>
<instance part="X8" gate="-13" x="121.92" y="58.42"/>
<instance part="X8" gate="-14" x="121.92" y="55.88"/>
<instance part="X8" gate="-15" x="121.92" y="53.34"/>
<instance part="X10" gate="-1" x="45.72" y="50.8" rot="R180"/>
<instance part="X10" gate="-2" x="45.72" y="53.34" rot="R180"/>
<instance part="X10" gate="-3" x="45.72" y="55.88" rot="R180"/>
<instance part="X10" gate="-4" x="45.72" y="58.42" rot="R180"/>
<instance part="GND11" gate="1" x="49.53" y="46.99"/>
<instance part="X2" gate="-1" x="59.69" y="83.82" rot="R180"/>
<instance part="X2" gate="-2" x="59.69" y="86.36" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="78.74" y1="50.8" x2="78.74" y2="55.88" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="78.74" y1="55.88" x2="85.09" y2="55.88" width="0.1524" layer="91"/>
<pinref part="X7" gate="-2" pin="S"/>
<wire x1="76.2" y1="55.88" x2="78.74" y2="55.88" width="0.1524" layer="91"/>
<junction x="78.74" y="55.88"/>
</segment>
<segment>
<pinref part="X5" gate="-1" pin="S"/>
<wire x1="54.61" y1="38.1" x2="57.15" y2="38.1" width="0.1524" layer="91"/>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="57.15" y1="38.1" x2="57.15" y2="35.56" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="X3" gate="-1" pin="S"/>
<wire x1="144.78" y1="83.82" x2="142.24" y2="83.82" width="0.1524" layer="91"/>
<wire x1="142.24" y1="83.82" x2="142.24" y2="86.36" width="0.1524" layer="91"/>
<wire x1="142.24" y1="86.36" x2="161.29" y2="86.36" width="0.1524" layer="91"/>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="161.29" y1="82.55" x2="161.29" y2="86.36" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="146.05" y1="74.93" x2="146.05" y2="76.2" width="0.1524" layer="91"/>
<wire x1="146.05" y1="76.2" x2="129.54" y2="76.2" width="0.1524" layer="91"/>
<wire x1="129.54" y1="76.2" x2="129.54" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X6" gate="-1" pin="S"/>
<wire x1="129.54" y1="73.66" x2="132.08" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="X10" gate="-1" pin="S"/>
<pinref part="GND11" gate="1" pin="GND"/>
<wire x1="48.26" y1="50.8" x2="49.53" y2="50.8" width="0.1524" layer="91"/>
<wire x1="49.53" y1="50.8" x2="49.53" y2="49.53" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D13"/>
<wire x1="85.09" y1="88.9" x2="85.09" y2="100.33" width="0.1524" layer="91"/>
<wire x1="85.09" y1="100.33" x2="125.73" y2="100.33" width="0.1524" layer="91"/>
<wire x1="125.73" y1="100.33" x2="125.73" y2="43.18" width="0.1524" layer="91"/>
<pinref part="X7" gate="-15" pin="S"/>
<wire x1="76.2" y1="88.9" x2="85.09" y2="88.9" width="0.1524" layer="91"/>
<junction x="85.09" y="88.9"/>
</segment>
</net>
<net name="12V" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RAW"/>
<wire x1="85.09" y1="53.34" x2="82.55" y2="53.34" width="0.1524" layer="91"/>
<label x="82.55" y="50.8" size="1.778" layer="95"/>
<pinref part="X7" gate="-1" pin="S"/>
<wire x1="76.2" y1="53.34" x2="85.09" y2="53.34" width="0.1524" layer="91"/>
<junction x="85.09" y="53.34"/>
</segment>
<segment>
<pinref part="X5" gate="-3" pin="S"/>
<wire x1="54.61" y1="43.18" x2="58.42" y2="43.18" width="0.1524" layer="91"/>
<label x="58.42" y="43.18" size="1.778" layer="95"/>
</segment>
</net>
<net name="BAT" class="0">
<segment>
<pinref part="X5" gate="-2" pin="S"/>
<label x="57.15" y="40.64" size="1.778" layer="95"/>
<wire x1="58.42" y1="40.64" x2="54.61" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="X10" gate="-2" pin="S"/>
<wire x1="48.26" y1="53.34" x2="50.8" y2="53.34" width="0.1524" layer="91"/>
<label x="48.26" y="53.34" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D12"/>
<wire x1="118.11" y1="88.9" x2="119.38" y2="88.9" width="0.1524" layer="91"/>
<wire x1="119.38" y1="88.9" x2="152.4" y2="88.9" width="0.1524" layer="91"/>
<wire x1="152.4" y1="88.9" x2="152.4" y2="111.76" width="0.1524" layer="91"/>
<wire x1="152.4" y1="111.76" x2="158.75" y2="111.76" width="0.1524" layer="91"/>
<pinref part="X8" gate="-1" pin="S"/>
<junction x="119.38" y="88.9"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="X3" gate="-2" pin="S"/>
<wire x1="144.78" y1="81.28" x2="139.7" y2="81.28" width="0.1524" layer="91"/>
<wire x1="139.7" y1="81.28" x2="139.7" y2="86.36" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D11"/>
<wire x1="139.7" y1="86.36" x2="119.38" y2="86.36" width="0.1524" layer="91"/>
<pinref part="X8" gate="-2" pin="S"/>
<wire x1="119.38" y1="86.36" x2="118.11" y2="86.36" width="0.1524" layer="91"/>
<junction x="119.38" y="86.36"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="X3" gate="-3" pin="S"/>
<wire x1="144.78" y1="78.74" x2="137.16" y2="78.74" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D10"/>
<wire x1="137.16" y1="78.74" x2="137.16" y2="83.82" width="0.1524" layer="91"/>
<wire x1="137.16" y1="83.82" x2="119.38" y2="83.82" width="0.1524" layer="91"/>
<pinref part="X8" gate="-3" pin="S"/>
<wire x1="119.38" y1="83.82" x2="118.11" y2="83.82" width="0.1524" layer="91"/>
<junction x="119.38" y="83.82"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<wire x1="127" y1="68.58" x2="127" y2="81.28" width="0.1524" layer="91"/>
<wire x1="127" y1="81.28" x2="119.38" y2="81.28" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D9"/>
<pinref part="X6" gate="-3" pin="S"/>
<wire x1="119.38" y1="81.28" x2="118.11" y2="81.28" width="0.1524" layer="91"/>
<wire x1="127" y1="68.58" x2="132.08" y2="68.58" width="0.1524" layer="91"/>
<pinref part="X8" gate="-4" pin="S"/>
<junction x="119.38" y="81.28"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D8"/>
<wire x1="118.11" y1="78.74" x2="119.38" y2="78.74" width="0.1524" layer="91"/>
<wire x1="119.38" y1="78.74" x2="124.46" y2="78.74" width="0.1524" layer="91"/>
<wire x1="124.46" y1="78.74" x2="124.46" y2="66.04" width="0.1524" layer="91"/>
<pinref part="X6" gate="-4" pin="S"/>
<wire x1="124.46" y1="66.04" x2="132.08" y2="66.04" width="0.1524" layer="91"/>
<pinref part="X8" gate="-5" pin="S"/>
<junction x="119.38" y="78.74"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="X6" gate="-2" pin="S"/>
<wire x1="132.08" y1="71.12" x2="132.08" y2="48.26" width="0.1524" layer="91"/>
<wire x1="132.08" y1="48.26" x2="116.84" y2="48.26" width="0.1524" layer="91"/>
<wire x1="116.84" y1="48.26" x2="116.84" y2="40.64" width="0.1524" layer="91"/>
<wire x1="116.84" y1="40.64" x2="73.66" y2="40.64" width="0.1524" layer="91"/>
<wire x1="73.66" y1="40.64" x2="73.66" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="RST"/>
<wire x1="73.66" y1="58.42" x2="76.2" y2="58.42" width="0.1524" layer="91"/>
<pinref part="X7" gate="-3" pin="S"/>
<wire x1="76.2" y1="58.42" x2="85.09" y2="58.42" width="0.1524" layer="91"/>
<junction x="76.2" y="58.42"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D7"/>
<pinref part="X8" gate="-6" pin="S"/>
<wire x1="118.11" y1="76.2" x2="119.38" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D6"/>
<pinref part="X8" gate="-7" pin="S"/>
<wire x1="118.11" y1="73.66" x2="119.38" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D5"/>
<pinref part="X8" gate="-8" pin="S"/>
<wire x1="118.11" y1="71.12" x2="119.38" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D4"/>
<pinref part="X8" gate="-9" pin="S"/>
<wire x1="118.11" y1="68.58" x2="119.38" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D3"/>
<pinref part="X8" gate="-10" pin="S"/>
<wire x1="118.11" y1="66.04" x2="119.38" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D2"/>
<pinref part="X8" gate="-11" pin="S"/>
<wire x1="118.11" y1="63.5" x2="119.38" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND2"/>
<pinref part="X8" gate="-12" pin="S"/>
<wire x1="118.11" y1="60.96" x2="119.38" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RST1"/>
<pinref part="X8" gate="-13" pin="S"/>
<wire x1="118.11" y1="58.42" x2="119.38" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RX1"/>
<pinref part="X8" gate="-14" pin="S"/>
<wire x1="118.11" y1="55.88" x2="119.38" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$31" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="TX0"/>
<pinref part="X8" gate="-15" pin="S"/>
<wire x1="118.11" y1="53.34" x2="119.38" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$32" class="0">
<segment>
<pinref part="X7" gate="-4" pin="S"/>
<pinref part="U$1" gate="G$1" pin="5.5V"/>
<wire x1="76.2" y1="60.96" x2="85.09" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$33" class="0">
<segment>
<pinref part="X7" gate="-5" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A7"/>
<wire x1="76.2" y1="63.5" x2="85.09" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$34" class="0">
<segment>
<pinref part="X7" gate="-6" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A6"/>
<wire x1="76.2" y1="66.04" x2="85.09" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$35" class="0">
<segment>
<pinref part="X7" gate="-7" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A5"/>
<wire x1="76.2" y1="68.58" x2="85.09" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$36" class="0">
<segment>
<pinref part="X7" gate="-8" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A4"/>
<wire x1="76.2" y1="71.12" x2="85.09" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$37" class="0">
<segment>
<pinref part="X7" gate="-9" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A3"/>
<wire x1="76.2" y1="73.66" x2="85.09" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$38" class="0">
<segment>
<pinref part="X7" gate="-10" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A2"/>
<wire x1="76.2" y1="76.2" x2="85.09" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$39" class="0">
<segment>
<pinref part="X7" gate="-11" pin="S"/>
<pinref part="U$1" gate="G$1" pin="A1"/>
<wire x1="76.2" y1="78.74" x2="85.09" y2="78.74" width="0.1524" layer="91"/>
<wire x1="76.2" y1="78.74" x2="68.58" y2="78.74" width="0.1524" layer="91"/>
<junction x="76.2" y="78.74"/>
</segment>
</net>
<net name="N$41" class="0">
<segment>
<pinref part="X10" gate="-4" pin="S"/>
<wire x1="48.26" y1="58.42" x2="49.53" y2="58.42" width="0.1524" layer="91"/>
<wire x1="49.53" y1="58.42" x2="49.53" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$42" class="0">
<segment>
<pinref part="X10" gate="-3" pin="S"/>
<wire x1="48.26" y1="55.88" x2="52.07" y2="55.88" width="0.1524" layer="91"/>
<wire x1="52.07" y1="55.88" x2="52.07" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$40" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A0"/>
<pinref part="X7" gate="-12" pin="S"/>
<wire x1="76.2" y1="81.28" x2="85.09" y2="81.28" width="0.1524" layer="91"/>
<wire x1="52.07" y1="81.28" x2="76.2" y2="81.28" width="0.1524" layer="91"/>
<junction x="76.2" y="81.28"/>
</segment>
</net>
<net name="12V1" class="0">
<segment>
<pinref part="X2" gate="-1" pin="S"/>
<wire x1="62.23" y1="83.82" x2="63.5" y2="83.82" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="AREF"/>
<pinref part="X7" gate="-13" pin="S"/>
<wire x1="63.5" y1="83.82" x2="64.77" y2="83.82" width="0.1524" layer="91"/>
<wire x1="76.2" y1="83.82" x2="85.09" y2="83.82" width="0.1524" layer="91"/>
<wire x1="64.77" y1="83.82" x2="76.2" y2="83.82" width="0.1524" layer="91"/>
<junction x="76.2" y="83.82"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="X2" gate="-2" pin="S"/>
<wire x1="62.23" y1="86.36" x2="63.5" y2="86.36" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="3.3V"/>
<pinref part="X7" gate="-14" pin="S"/>
<wire x1="63.5" y1="86.36" x2="64.77" y2="86.36" width="0.1524" layer="91"/>
<wire x1="76.2" y1="86.36" x2="85.09" y2="86.36" width="0.1524" layer="91"/>
<wire x1="64.77" y1="86.36" x2="76.2" y2="86.36" width="0.1524" layer="91"/>
<junction x="76.2" y="86.36"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
