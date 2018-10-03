<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
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
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ACELEROMETER">
<packages>
<package name="ACELEROMETER">
<pad name="VCC" x="-22.86" y="2.54" drill="0.8" diameter="1.4224"/>
<pad name="GND" x="-20.32" y="2.54" drill="0.8" diameter="1.4224"/>
<pad name="SCL" x="-17.78" y="2.54" drill="0.8" diameter="1.4224"/>
<pad name="SDA" x="-15.24" y="2.54" drill="0.8" diameter="1.4224"/>
<pad name="INT" x="-12.7" y="2.54" drill="0.8" diameter="1.4224"/>
<wire x1="-29.21" y1="1.27" x2="-6.35" y2="1.27" width="0.127" layer="20"/>
<wire x1="-29.21" y1="1.27" x2="-29.21" y2="12.7" width="0.127" layer="20"/>
<wire x1="-6.35" y1="1.27" x2="-6.35" y2="12.7" width="0.127" layer="20"/>
<wire x1="-6.35" y1="12.7" x2="-29.21" y2="12.7" width="0.127" layer="20"/>
<circle x="-26.67" y="10.16" radius="1.79605" width="0.127" layer="20"/>
<circle x="-8.89" y="10.16" radius="1.79605" width="0.127" layer="20"/>
<wire x1="-20.32" y1="8.89" x2="-15.24" y2="8.89" width="0.127" layer="20"/>
<wire x1="-15.24" y1="8.89" x2="-15.24" y2="7.62" width="0.127" layer="20"/>
<wire x1="-15.24" y1="7.62" x2="-15.24" y2="6.35" width="0.127" layer="20"/>
<wire x1="-15.24" y1="6.35" x2="-16.51" y2="6.35" width="0.127" layer="20"/>
<wire x1="-16.51" y1="6.35" x2="-17.78" y2="6.35" width="0.127" layer="20"/>
<wire x1="-17.78" y1="6.35" x2="-19.05" y2="6.35" width="0.127" layer="20"/>
<wire x1="-19.05" y1="6.35" x2="-20.32" y2="6.35" width="0.127" layer="20"/>
<wire x1="-20.32" y1="6.35" x2="-20.32" y2="7.62" width="0.127" layer="20"/>
<wire x1="-20.32" y1="7.62" x2="-20.32" y2="8.89" width="0.127" layer="20"/>
<wire x1="-20.32" y1="7.62" x2="-22.86" y2="7.62" width="0.127" layer="20"/>
<wire x1="-22.86" y1="7.62" x2="-22.86" y2="3.81" width="0.127" layer="20"/>
<wire x1="-20.32" y1="3.81" x2="-20.32" y2="5.08" width="0.127" layer="20"/>
<wire x1="-20.32" y1="5.08" x2="-19.05" y2="5.08" width="0.127" layer="20"/>
<wire x1="-19.05" y1="5.08" x2="-19.05" y2="6.35" width="0.127" layer="20"/>
<wire x1="-17.78" y1="3.81" x2="-17.78" y2="6.35" width="0.127" layer="20"/>
<wire x1="-15.24" y1="3.81" x2="-15.24" y2="5.08" width="0.127" layer="20"/>
<wire x1="-15.24" y1="5.08" x2="-16.51" y2="5.08" width="0.127" layer="20"/>
<wire x1="-16.51" y1="5.08" x2="-16.51" y2="6.35" width="0.127" layer="20"/>
<wire x1="-15.24" y1="7.62" x2="-12.7" y2="7.62" width="0.127" layer="20"/>
<wire x1="-12.7" y1="7.62" x2="-12.7" y2="3.81" width="0.127" layer="20"/>
<rectangle x1="-26.67" y1="3.81" x2="-25.4" y2="6.35" layer="20"/>
<rectangle x1="-22.86" y1="10.16" x2="-20.32" y2="11.43" layer="20"/>
<rectangle x1="-11.43" y1="5.08" x2="-10.16" y2="7.62" layer="20"/>
<rectangle x1="-10.16" y1="3.81" x2="-8.89" y2="5.08" layer="20"/>
<hole x="-22.86" y="2.54" drill="0.6"/>
<hole x="-20.32" y="2.54" drill="0.6"/>
<hole x="-17.78" y="2.54" drill="0.6"/>
<hole x="-15.24" y="2.54" drill="0.6"/>
<hole x="-12.7" y="2.54" drill="0.6"/>
<pad name="P$1" x="-26.67" y="10.16" drill="2.8" diameter="3.81"/>
<pad name="P$2" x="-8.89" y="10.16" drill="2.8" diameter="3.81"/>
</package>
</packages>
<symbols>
<symbol name="ACELEROMETER">
<wire x1="-50.8" y1="17.78" x2="-50.8" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-50.8" y1="-5.08" x2="-38.1" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-38.1" y1="-5.08" x2="-33.02" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-5.08" x2="-27.94" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-27.94" y1="-5.08" x2="-22.86" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-5.08" x2="-17.78" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-5.08" x2="-7.62" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-7.62" y1="-5.08" x2="-7.62" y2="17.78" width="0.254" layer="94"/>
<wire x1="-7.62" y1="17.78" x2="-50.8" y2="17.78" width="0.254" layer="94"/>
<circle x="-45.72" y="12.7" radius="3.5921" width="0.254" layer="94"/>
<circle x="-12.7" y="12.7" radius="3.5921" width="0.254" layer="94"/>
<polygon width="0.254" layer="94">
<vertex x="-35.56" y="12.7"/>
<vertex x="-22.86" y="12.7"/>
<vertex x="-22.86" y="2.54"/>
<vertex x="-35.56" y="2.54"/>
</polygon>
<pin name="SCL" x="-27.94" y="-10.16" length="middle" rot="R90"/>
<pin name="GND" x="-33.02" y="-10.16" length="middle" rot="R90"/>
<pin name="VCC" x="-38.1" y="-10.16" length="middle" rot="R90"/>
<pin name="SDA" x="-22.86" y="-10.16" length="middle" rot="R90"/>
<pin name="INT" x="-17.78" y="-10.16" length="middle" rot="R90"/>
<wire x1="-33.02" y1="-5.08" x2="-33.02" y2="2.54" width="0.254" layer="94"/>
<wire x1="-27.94" y1="-5.08" x2="-27.94" y2="2.54" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-5.08" x2="-22.86" y2="0" width="0.254" layer="94"/>
<wire x1="-22.86" y1="0" x2="-20.32" y2="0" width="0.254" layer="94"/>
<wire x1="-20.32" y1="0" x2="-20.32" y2="5.08" width="0.254" layer="94"/>
<wire x1="-20.32" y1="5.08" x2="-22.86" y2="5.08" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-5.08" x2="-17.78" y2="7.62" width="0.254" layer="94"/>
<wire x1="-17.78" y1="7.62" x2="-22.86" y2="7.62" width="0.254" layer="94"/>
<wire x1="-38.1" y1="-5.08" x2="-38.1" y2="7.62" width="0.254" layer="94"/>
<wire x1="-38.1" y1="7.62" x2="-35.56" y2="7.62" width="0.254" layer="94"/>
<rectangle x1="-45.72" y1="0" x2="-43.18" y2="5.08" layer="94"/>
<rectangle x1="-40.64" y1="12.7" x2="-38.1" y2="15.24" layer="94"/>
<rectangle x1="-15.24" y1="2.54" x2="-12.7" y2="7.62" layer="94"/>
<rectangle x1="-12.7" y1="0" x2="-10.16" y2="2.54" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ACELEROMETER">
<gates>
<gate name="G$1" symbol="ACELEROMETER" x="27.94" y="-7.62"/>
</gates>
<devices>
<device name="" package="ACELEROMETER">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="INT" pad="INT"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="BOOSTER">
<packages>
<package name="POLOLU_STEP_UP_DOWN">
<pad name="EN" x="-17.78" y="6.35" drill="0.8" diameter="1.4224"/>
<pad name="VCC1" x="-15.24" y="6.35" drill="0.8" diameter="1.4224" rot="R90"/>
<pad name="VCC" x="-12.7" y="6.35" drill="0.8" diameter="1.4224"/>
<pad name="GND" x="-10.16" y="6.35" drill="0.8" diameter="1.4224"/>
<pad name="GND2" x="-7.62" y="6.35" drill="0.8" diameter="1.4224"/>
<pad name="GND3" x="-7.62" y="-26.67" drill="0.8" diameter="1.4224"/>
<pad name="GND4" x="-10.16" y="-26.67" drill="0.8" diameter="1.4224"/>
<pad name="VOUT" x="-12.7" y="-26.67" drill="0.8" diameter="1.4224"/>
<pad name="VOUT1" x="-15.24" y="-26.67" drill="0.8" diameter="1.4224"/>
<wire x1="-21.59" y1="10.16" x2="-3.81" y2="10.16" width="0.127" layer="21"/>
<wire x1="-3.81" y1="10.16" x2="-3.81" y2="-30.48" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-30.48" x2="-21.59" y2="-30.48" width="0.127" layer="21"/>
<wire x1="-21.59" y1="-30.48" x2="-21.59" y2="10.16" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-3.81" x2="-11.43" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-3.81" x2="-6.35" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-3.81" x2="-6.35" y2="-11.43" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-11.43" x2="-13.97" y2="-11.43" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-11.43" x2="-13.97" y2="-6.35" width="0.127" layer="21"/>
<circle x="-10.16" y="-7.62" radius="2.83980625" width="0.127" layer="21"/>
<rectangle x1="-19.05" y1="-7.62" x2="-16.51" y2="-5.08" layer="21"/>
<circle x="-17.78" y="1.27" radius="1.79605" width="0.127" layer="21"/>
<circle x="-17.78" y="-21.59" radius="1.79605" width="0.127" layer="21"/>
<polygon width="0.127" layer="21">
<vertex x="-8.89" y="-13.97"/>
<vertex x="-6.35" y="-13.97"/>
<vertex x="-6.35" y="-19.05"/>
<vertex x="-8.89" y="-19.05"/>
</polygon>
<polygon width="0.127" layer="21">
<vertex x="-12.7" y="2.54"/>
<vertex x="-8.89" y="2.54"/>
<vertex x="-8.89" y="0"/>
<vertex x="-8.89" y="-1.27"/>
<vertex x="-12.7" y="-1.27"/>
</polygon>
<wire x1="-13.97" y1="-6.35" x2="-13.97" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-1.27" x2="-11.43" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-3.81" x2="-10.16" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-3.81" x2="-10.16" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-5.08" x2="-17.78" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-12.7" y1="1.27" x2="-15.24" y2="1.27" width="0.127" layer="21"/>
<wire x1="-16.51" y1="-6.35" x2="-13.97" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-19.05" x2="-17.78" y2="-15.24" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-15.24" x2="-17.78" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-15.24" x2="-17.78" y2="-15.24" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-25.4" x2="-15.24" y2="-22.86" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-22.86" x2="-12.7" y2="-22.86" width="0.127" layer="21"/>
<wire x1="-12.7" y1="-22.86" x2="-12.7" y2="-25.4" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-25.4" x2="-10.16" y2="-22.86" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-22.86" x2="-7.62" y2="-22.86" width="0.127" layer="21"/>
<wire x1="-7.62" y1="-22.86" x2="-7.62" y2="-25.4" width="0.127" layer="21"/>
<wire x1="-10.16" y1="5.08" x2="-10.16" y2="3.81" width="0.127" layer="21"/>
<wire x1="-10.16" y1="3.81" x2="-7.62" y2="3.81" width="0.127" layer="21"/>
<wire x1="-7.62" y1="3.81" x2="-7.62" y2="5.08" width="0.127" layer="21"/>
<wire x1="-15.24" y1="5.08" x2="-15.24" y2="3.81" width="0.127" layer="21"/>
<wire x1="-15.24" y1="3.81" x2="-12.7" y2="3.81" width="0.127" layer="21"/>
<wire x1="-12.7" y1="3.81" x2="-12.7" y2="5.08" width="0.127" layer="21"/>
<wire x1="-7.62" y1="-22.86" x2="-5.08" y2="-22.86" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-22.86" x2="-5.08" y2="3.81" width="0.127" layer="21"/>
<wire x1="-5.08" y1="3.81" x2="-7.62" y2="3.81" width="0.127" layer="21"/>
<wire x1="-19.05" y1="6.35" x2="-20.32" y2="6.35" width="0.127" layer="21"/>
<wire x1="-20.32" y1="6.35" x2="-20.32" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-20.32" y1="-6.35" x2="-19.05" y2="-6.35" width="0.127" layer="21"/>
<hole x="-17.78" y="6.35" drill="0.6"/>
<hole x="-15.24" y="6.35" drill="0.6"/>
<hole x="-12.7" y="6.35" drill="0.6"/>
<hole x="-10.16" y="6.35" drill="0.6"/>
<hole x="-7.62" y="6.35" drill="0.6"/>
<hole x="-7.62" y="-26.67" drill="0.6"/>
<hole x="-10.16" y="-26.67" drill="0.6"/>
<hole x="-12.7" y="-26.67" drill="0.6"/>
<hole x="-15.24" y="-26.67" drill="0.6"/>
</package>
</packages>
<symbols>
<symbol name="POLOLU_STEP_UP_DOWM">
<wire x1="-35.56" y1="22.86" x2="-20.32" y2="22.86" width="0.254" layer="94"/>
<wire x1="-20.32" y1="22.86" x2="-20.32" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-20.32" y1="-15.24" x2="-35.56" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-35.56" y1="-15.24" x2="-35.56" y2="22.86" width="0.254" layer="94"/>
<wire x1="-27.94" y1="12.7" x2="-22.86" y2="12.7" width="0.254" layer="94"/>
<wire x1="-22.86" y1="12.7" x2="-22.86" y2="7.62" width="0.254" layer="94"/>
<wire x1="-22.86" y1="7.62" x2="-27.94" y2="7.62" width="0.254" layer="94"/>
<wire x1="-27.94" y1="7.62" x2="-27.94" y2="12.7" width="0.254" layer="94"/>
<wire x1="-33.02" y1="10.16" x2="-30.48" y2="10.16" width="0.254" layer="94"/>
<wire x1="-30.48" y1="10.16" x2="-30.48" y2="7.62" width="0.254" layer="94"/>
<wire x1="-30.48" y1="7.62" x2="-33.02" y2="7.62" width="0.254" layer="94"/>
<wire x1="-33.02" y1="7.62" x2="-33.02" y2="10.16" width="0.254" layer="94"/>
<circle x="-30.48" y="17.78" radius="2.54" width="0.254" layer="94"/>
<circle x="-30.48" y="-7.62" radius="2.54" width="0.254" layer="94"/>
<rectangle x1="-25.4" y1="-2.54" x2="-22.86" y2="2.54" layer="94"/>
<pin name="EN" x="-33.02" y="27.94" length="middle" rot="R270"/>
<pin name="VCC1" x="-30.48" y="27.94" length="middle" rot="R270"/>
<pin name="VCC" x="-27.94" y="27.94" length="middle" rot="R270"/>
<pin name="GND" x="-25.4" y="27.94" length="middle" rot="R270"/>
<pin name="GND2" x="-22.86" y="27.94" length="middle" rot="R270"/>
<pin name="VOUT" x="-33.02" y="-20.32" length="middle" rot="R90"/>
<pin name="VOUT1" x="-30.48" y="-20.32" length="middle" rot="R90"/>
<pin name="GND4" x="-27.94" y="-20.32" length="middle" rot="R90"/>
<pin name="GND3" x="-25.4" y="-20.32" length="middle" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="POLOLU_STEP_UP_DOWN">
<gates>
<gate name="G$1" symbol="POLOLU_STEP_UP_DOWM" x="27.94" y="-2.54"/>
</gates>
<devices>
<device name="" package="POLOLU_STEP_UP_DOWN">
<connects>
<connect gate="G$1" pin="EN" pad="EN"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="GND3" pad="GND3"/>
<connect gate="G$1" pin="GND4" pad="GND4"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="VCC1" pad="VCC1"/>
<connect gate="G$1" pin="VOUT" pad="VOUT"/>
<connect gate="G$1" pin="VOUT1" pad="VOUT1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="CHARGER">
<packages>
<package name="CHARGER">
<pad name="BAT+" x="-19.05" y="6.35" drill="0.8" diameter="1.4224"/>
<pad name="VCC" x="-19.05" y="-6.35" drill="0.8" diameter="1.4224"/>
<pad name="BAT-" x="-1.27" y="6.35" drill="0.8" diameter="1.4224"/>
<pad name="GND" x="-1.27" y="-6.35" drill="0.8" diameter="1.4224"/>
<wire x1="-20.32" y1="-11.43" x2="-20.32" y2="7.62" width="0.127" layer="21"/>
<wire x1="-20.32" y1="7.62" x2="0" y2="7.62" width="0.127" layer="21"/>
<wire x1="0" y1="7.62" x2="0" y2="-11.43" width="0.127" layer="21"/>
<wire x1="0" y1="-11.43" x2="-5.08" y2="-11.43" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-11.43" x2="-15.24" y2="-11.43" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-11.43" x2="-20.32" y2="-11.43" width="0.127" layer="21"/>
<wire x1="-11.43" y1="3.81" x2="-3.81" y2="3.81" width="0.127" layer="21"/>
<wire x1="-3.81" y1="3.81" x2="-3.81" y2="2.54" width="0.127" layer="21"/>
<wire x1="-3.81" y1="2.54" x2="-3.81" y2="1.27" width="0.127" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="-3.81" y2="0" width="0.127" layer="21"/>
<wire x1="-3.81" y1="0" x2="-3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-1.27" x2="-3.81" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-2.54" x2="-11.43" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-2.54" x2="-11.43" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-1.27" x2="-11.43" y2="0" width="0.127" layer="21"/>
<wire x1="-11.43" y1="0" x2="-11.43" y2="1.27" width="0.127" layer="21"/>
<wire x1="-11.43" y1="1.27" x2="-11.43" y2="2.54" width="0.127" layer="21"/>
<wire x1="-11.43" y1="2.54" x2="-11.43" y2="3.81" width="0.127" layer="21"/>
<wire x1="-11.43" y1="2.54" x2="-12.7" y2="2.54" width="0.127" layer="21"/>
<wire x1="-11.43" y1="1.27" x2="-12.7" y2="1.27" width="0.127" layer="21"/>
<wire x1="-11.43" y1="0" x2="-12.7" y2="0" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-1.27" x2="-12.7" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-1.27" x2="-3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-2.54" y1="0" x2="-3.81" y2="0" width="0.127" layer="21"/>
<wire x1="-2.54" y1="1.27" x2="-3.81" y2="1.27" width="0.127" layer="21"/>
<wire x1="-2.54" y1="2.54" x2="-3.81" y2="2.54" width="0.127" layer="21"/>
<wire x1="-17.78" y1="3.81" x2="-15.24" y2="3.81" width="0.127" layer="21"/>
<wire x1="-15.24" y1="3.81" x2="-15.24" y2="2.54" width="0.127" layer="21"/>
<wire x1="-15.24" y1="2.54" x2="-17.78" y2="2.54" width="0.127" layer="21"/>
<wire x1="-17.78" y1="2.54" x2="-17.78" y2="3.81" width="0.127" layer="21"/>
<wire x1="-17.78" y1="1.27" x2="-15.24" y2="1.27" width="0.127" layer="21"/>
<wire x1="-15.24" y1="1.27" x2="-15.24" y2="0" width="0.127" layer="21"/>
<wire x1="-15.24" y1="0" x2="-17.78" y2="0" width="0.127" layer="21"/>
<wire x1="-17.78" y1="0" x2="-17.78" y2="1.27" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-1.27" x2="-15.24" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-1.27" x2="-15.24" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-2.54" x2="-17.78" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-2.54" x2="-17.78" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-3.81" x2="-15.24" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-3.81" x2="-15.24" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-5.08" x2="-17.78" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-17.78" y1="-5.08" x2="-17.78" y2="-3.81" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-11.43" x2="-15.24" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-15.24" y1="-6.35" x2="-5.08" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-6.35" x2="-5.08" y2="-11.43" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-7.62" x2="-11.43" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-7.62" x2="-11.43" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-8.89" x2="-13.97" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-8.89" x2="-13.97" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-7.62" x2="-6.35" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-7.62" x2="-6.35" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-8.89" x2="-8.89" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-8.89" x2="-8.89" y2="-7.62" width="0.127" layer="21"/>
<hole x="-19.05" y="6.35" drill="0.6"/>
<hole x="-19.05" y="-6.35" drill="0.6"/>
<hole x="-1.27" y="-6.35" drill="0.6"/>
<hole x="-1.27" y="6.35" drill="0.6"/>
</package>
</packages>
<symbols>
<symbol name="CHARGER">
<wire x1="-43.18" y1="15.24" x2="-10.16" y2="15.24" width="0.254" layer="94"/>
<wire x1="-10.16" y1="15.24" x2="-10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-17.78" x2="-20.32" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-20.32" y1="-17.78" x2="-33.02" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-17.78" x2="-43.18" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-43.18" y1="-17.78" x2="-43.18" y2="15.24" width="0.254" layer="94"/>
<wire x1="-30.48" y1="7.62" x2="-17.78" y2="7.62" width="0.254" layer="94"/>
<wire x1="-17.78" y1="7.62" x2="-17.78" y2="5.08" width="0.254" layer="94"/>
<wire x1="-17.78" y1="5.08" x2="-17.78" y2="2.54" width="0.254" layer="94"/>
<wire x1="-17.78" y1="2.54" x2="-17.78" y2="0" width="0.254" layer="94"/>
<wire x1="-17.78" y1="0" x2="-17.78" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-2.54" x2="-17.78" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-5.08" x2="-30.48" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-5.08" x2="-30.48" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-2.54" x2="-30.48" y2="0" width="0.254" layer="94"/>
<wire x1="-30.48" y1="0" x2="-30.48" y2="2.54" width="0.254" layer="94"/>
<wire x1="-30.48" y1="2.54" x2="-30.48" y2="5.08" width="0.254" layer="94"/>
<wire x1="-30.48" y1="7.62" x2="-30.48" y2="5.08" width="0.254" layer="94"/>
<wire x1="-30.48" y1="5.08" x2="-33.02" y2="5.08" width="0.254" layer="94"/>
<wire x1="-30.48" y1="2.54" x2="-33.02" y2="2.54" width="0.254" layer="94"/>
<wire x1="-30.48" y1="0" x2="-33.02" y2="0" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-2.54" x2="-33.02" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-2.54" x2="-17.78" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-15.24" y1="0" x2="-17.78" y2="0" width="0.254" layer="94"/>
<wire x1="-15.24" y1="2.54" x2="-17.78" y2="2.54" width="0.254" layer="94"/>
<wire x1="-15.24" y1="5.08" x2="-17.78" y2="5.08" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-17.78" x2="-33.02" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-33.02" y1="-10.16" x2="-20.32" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-20.32" y1="-10.16" x2="-20.32" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-12.7" x2="-27.94" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-27.94" y1="-12.7" x2="-27.94" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-27.94" y1="-15.24" x2="-30.48" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-15.24" x2="-30.48" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-15.24" x2="-25.4" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-12.7" x2="-22.86" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-12.7" x2="-22.86" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-22.86" y1="-15.24" x2="-25.4" y2="-15.24" width="0.254" layer="94"/>
<wire x1="-40.64" y1="7.62" x2="-35.56" y2="7.62" width="0.254" layer="94"/>
<wire x1="-35.56" y1="7.62" x2="-35.56" y2="5.08" width="0.254" layer="94"/>
<wire x1="-35.56" y1="5.08" x2="-40.64" y2="5.08" width="0.254" layer="94"/>
<wire x1="-40.64" y1="5.08" x2="-40.64" y2="7.62" width="0.254" layer="94"/>
<wire x1="-40.64" y1="12.7" x2="-35.56" y2="12.7" width="0.254" layer="94"/>
<wire x1="-35.56" y1="12.7" x2="-35.56" y2="10.16" width="0.254" layer="94"/>
<wire x1="-35.56" y1="10.16" x2="-40.64" y2="10.16" width="0.254" layer="94"/>
<wire x1="-40.64" y1="10.16" x2="-40.64" y2="12.7" width="0.254" layer="94"/>
<wire x1="-40.64" y1="-7.62" x2="-35.56" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-35.56" y1="-7.62" x2="-35.56" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-35.56" y1="-5.08" x2="-40.64" y2="-5.08" width="0.254" layer="94"/>
<wire x1="-40.64" y1="-5.08" x2="-40.64" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-40.64" y1="0" x2="-40.64" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-40.64" y1="-2.54" x2="-35.56" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-35.56" y1="-2.54" x2="-35.56" y2="0" width="0.254" layer="94"/>
<wire x1="-35.56" y1="0" x2="-40.64" y2="0" width="0.254" layer="94"/>
<pin name="BAT-" x="-5.08" y="12.7" length="middle" rot="R180"/>
<pin name="GND" x="-5.08" y="-15.24" length="middle" rot="R180"/>
<pin name="BAT+" x="-48.26" y="12.7" length="middle"/>
<pin name="VCC" x="-48.26" y="-15.24" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CHARGER">
<gates>
<gate name="G$1" symbol="CHARGER" x="25.4" y="0"/>
</gates>
<devices>
<device name="" package="CHARGER">
<connects>
<connect gate="G$1" pin="BAT+" pad="BAT+"/>
<connect gate="G$1" pin="BAT-" pad="BAT-"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SIM8OOL">
<packages>
<package name="SIM8OOL">
<pad name="NET" x="-17.78" y="6.35" drill="0.8" diameter="1.6764"/>
<pad name="VCC" x="-17.78" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="RST" x="-17.78" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="RXD" x="-17.78" y="-1.27" drill="0.8" diameter="1.6764"/>
<pad name="TXD" x="-17.78" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="GND" x="-17.78" y="-6.35" drill="0.8" diameter="1.6764"/>
<pad name="SPK" x="2.54" y="-8.89" drill="0.8" diameter="1.6764"/>
<pad name="SPK1" x="2.54" y="-6.35" drill="0.8" diameter="1.6764"/>
<pad name="MCN" x="2.54" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="MCP" x="2.54" y="-1.27" drill="0.8" diameter="1.6764"/>
<pad name="DTR" x="2.54" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="RING" x="2.54" y="3.81" drill="0.8" diameter="1.6764"/>
<wire x1="-19.05" y1="12.7" x2="3.81" y2="12.7" width="0.127" layer="21"/>
<wire x1="3.81" y1="12.7" x2="3.81" y2="-10.16" width="0.127" layer="21"/>
<wire x1="3.81" y1="-10.16" x2="-19.05" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-10.16" x2="-19.05" y2="12.7" width="0.127" layer="21"/>
<wire x1="-16.51" y1="5.08" x2="1.27" y2="5.08" width="0.127" layer="21"/>
<wire x1="1.27" y1="5.08" x2="1.27" y2="-8.89" width="0.127" layer="21"/>
<wire x1="1.27" y1="-8.89" x2="-16.51" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-16.51" y1="-8.89" x2="-16.51" y2="5.08" width="0.127" layer="21"/>
<rectangle x1="-15.24" y1="7.62" x2="-8.89" y2="11.43" layer="20"/>
<rectangle x1="-7.62" y1="8.89" x2="-6.35" y2="11.43" layer="20"/>
<rectangle x1="-5.08" y1="8.89" x2="-3.81" y2="11.43" layer="20"/>
<rectangle x1="-2.54" y1="8.89" x2="-1.27" y2="11.43" layer="20"/>
<rectangle x1="0" y1="8.89" x2="1.27" y2="11.43" layer="20"/>
<text x="-6.35" y="2.54" size="1.27" layer="20">SIM8OOL</text>
<hole x="-17.78" y="6.35" drill="0.6"/>
<hole x="-17.78" y="3.81" drill="0.6"/>
<hole x="-17.78" y="1.27" drill="0.6"/>
<hole x="-17.78" y="-1.27" drill="0.6"/>
<hole x="-17.78" y="-3.81" drill="0.6"/>
<hole x="-17.78" y="-6.35" drill="0.6"/>
<hole x="2.54" y="3.81" drill="0.6"/>
<hole x="2.54" y="1.27" drill="0.6"/>
<hole x="2.54" y="-1.27" drill="0.6"/>
<hole x="2.54" y="-3.81" drill="0.6"/>
<hole x="2.54" y="-6.35" drill="0.6"/>
<hole x="2.54" y="-8.89" drill="0.6"/>
</package>
</packages>
<symbols>
<symbol name="SIM8">
<wire x1="-35.56" y1="25.4" x2="2.54" y2="25.4" width="0.254" layer="94"/>
<wire x1="2.54" y1="25.4" x2="2.54" y2="-12.7" width="0.254" layer="94"/>
<wire x1="2.54" y1="-12.7" x2="-35.56" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-35.56" y1="-12.7" x2="-35.56" y2="25.4" width="0.254" layer="94"/>
<wire x1="-25.4" y1="22.86" x2="-25.4" y2="12.7" width="0.254" layer="94"/>
<wire x1="-25.4" y1="12.7" x2="-15.24" y2="12.7" width="0.254" layer="94"/>
<wire x1="-15.24" y1="12.7" x2="-15.24" y2="22.86" width="0.254" layer="94"/>
<wire x1="-15.24" y1="22.86" x2="-25.4" y2="22.86" width="0.254" layer="94"/>
<wire x1="-12.7" y1="20.32" x2="-12.7" y2="15.24" width="0.254" layer="94"/>
<wire x1="-12.7" y1="15.24" x2="-10.16" y2="15.24" width="0.254" layer="94"/>
<wire x1="-10.16" y1="15.24" x2="-10.16" y2="20.32" width="0.254" layer="94"/>
<wire x1="-10.16" y1="20.32" x2="-12.7" y2="20.32" width="0.254" layer="94"/>
<wire x1="-7.62" y1="20.32" x2="-7.62" y2="15.24" width="0.254" layer="94"/>
<wire x1="-7.62" y1="15.24" x2="-5.08" y2="15.24" width="0.254" layer="94"/>
<wire x1="-5.08" y1="15.24" x2="-5.08" y2="20.32" width="0.254" layer="94"/>
<wire x1="-5.08" y1="20.32" x2="-7.62" y2="20.32" width="0.254" layer="94"/>
<wire x1="-2.54" y1="20.32" x2="-2.54" y2="15.24" width="0.254" layer="94"/>
<wire x1="-2.54" y1="15.24" x2="0" y2="15.24" width="0.254" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="20.32" width="0.254" layer="94"/>
<wire x1="0" y1="20.32" x2="-2.54" y2="20.32" width="0.254" layer="94"/>
<circle x="-30.48" y="20.32" radius="2.54" width="0.254" layer="94"/>
<text x="-15.24" y="5.08" size="1.778" layer="94">SIM8OOL</text>
<wire x1="-30.48" y1="10.16" x2="-2.54" y2="10.16" width="0.254" layer="94"/>
<wire x1="-2.54" y1="10.16" x2="-2.54" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-10.16" x2="-30.48" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-30.48" y1="-10.16" x2="-30.48" y2="10.16" width="0.254" layer="94"/>
<pin name="GND" x="-40.64" y="-5.08" length="middle"/>
<pin name="TXD" x="-40.64" y="0" length="middle"/>
<pin name="RXD" x="-40.64" y="5.08" length="middle"/>
<pin name="RST" x="-40.64" y="10.16" length="middle"/>
<pin name="VCC" x="-40.64" y="15.24" length="middle"/>
<pin name="NET" x="-40.64" y="20.32" length="middle"/>
<pin name="SPK" x="7.62" y="-10.16" length="middle" rot="R180"/>
<pin name="SPK1" x="7.62" y="-5.08" length="middle" rot="R180"/>
<pin name="MCN" x="7.62" y="0" length="middle" rot="R180"/>
<pin name="MCP" x="7.62" y="5.08" length="middle" rot="R180"/>
<pin name="DTR" x="7.62" y="10.16" length="middle" rot="R180"/>
<pin name="RING" x="7.62" y="15.24" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SIM8OOL">
<gates>
<gate name="G$1" symbol="SIM8" x="15.24" y="-2.54"/>
</gates>
<devices>
<device name="" package="SIM8OOL">
<connects>
<connect gate="G$1" pin="DTR" pad="DTR"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="MCN" pad="MCN"/>
<connect gate="G$1" pin="MCP" pad="MCP"/>
<connect gate="G$1" pin="NET" pad="NET"/>
<connect gate="G$1" pin="RING" pad="RING"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="RXD" pad="RXD"/>
<connect gate="G$1" pin="SPK" pad="SPK"/>
<connect gate="G$1" pin="SPK1" pad="SPK1"/>
<connect gate="G$1" pin="TXD" pad="TXD"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="ULTRA_MINI">
<packages>
<package name="ULTRA_MINI">
<wire x1="0" y1="0" x2="37.73" y2="0" width="0.127" layer="20"/>
<wire x1="37.73" y1="0" x2="37.73" y2="17.73" width="0.127" layer="20"/>
<wire x1="37.73" y1="17.73" x2="0" y2="17.73" width="0.127" layer="20"/>
<wire x1="0" y1="17.73" x2="0" y2="0" width="0.127" layer="20"/>
<pad name="D13" x="1.27" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D12" x="3.81" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D11" x="6.35" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D10" x="8.89" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D9" x="11.43" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D8" x="13.97" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D7" x="16.51" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D6" x="19.05" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D5" x="21.59" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D4" x="24.13" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D3" x="26.67" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D2" x="29.21" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D1" x="31.75" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="D0" x="34.29" y="1.27" drill="0.8" diameter="1.6764"/>
<pad name="GND1" x="1.27" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="GND" x="3.81" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="3V3" x="6.35" y="16.51" drill="0.8" diameter="1.6764" rot="R90"/>
<pad name="VIN" x="8.89" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="VREF" x="11.43" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A6" x="13.97" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A7" x="16.51" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A0" x="19.05" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A1" x="21.59" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A2" x="24.13" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A3" x="26.67" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A4" x="29.21" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="A5" x="31.75" y="16.51" drill="0.8" diameter="1.6764"/>
<pad name="RST" x="34.29" y="16.51" drill="0.8" diameter="1.6764"/>
<hole x="1.27" y="16.51" drill="0.6"/>
<hole x="3.81" y="16.51" drill="0.6"/>
<hole x="6.35" y="16.51" drill="0.6"/>
<hole x="8.89" y="16.51" drill="0.6"/>
<hole x="11.43" y="16.51" drill="0.6"/>
<hole x="13.97" y="16.51" drill="0.6"/>
<hole x="16.51" y="16.51" drill="0.6"/>
<hole x="19.05" y="16.51" drill="0.6"/>
<hole x="21.59" y="16.51" drill="0.6"/>
<hole x="24.13" y="16.51" drill="0.6"/>
<hole x="26.67" y="16.51" drill="0.6"/>
<hole x="29.21" y="16.51" drill="0.6"/>
<hole x="31.75" y="16.51" drill="0.6"/>
<hole x="34.29" y="16.51" drill="0.6"/>
<hole x="1.27" y="1.27" drill="0.6"/>
<hole x="3.81" y="1.27" drill="0.6"/>
<hole x="6.35" y="1.27" drill="0.6"/>
<hole x="8.89" y="1.27" drill="0.6"/>
<hole x="13.97" y="1.27" drill="0.6"/>
<hole x="11.43" y="1.27" drill="0.6"/>
<hole x="16.51" y="1.27" drill="0.6"/>
<hole x="19.05" y="1.27" drill="0.6"/>
<hole x="21.59" y="1.27" drill="0.6"/>
<hole x="34.29" y="1.27" drill="0.6"/>
<hole x="31.75" y="1.27" drill="0.6"/>
<hole x="29.21" y="1.27" drill="0.6"/>
<hole x="26.67" y="1.27" drill="0.6"/>
<hole x="24.13" y="1.27" drill="0.6"/>
<text x="1.27" y="8.89" size="1.27" layer="20">Arduino Ultra Mini</text>
</package>
</packages>
<symbols>
<symbol name="ULTRA_MINI">
<wire x1="-119.38" y1="30.48" x2="-119.38" y2="55.88" width="0.254" layer="94"/>
<pin name="D0" x="-114.3" y="60.96" length="middle" rot="R270"/>
<pin name="D1" x="-109.22" y="60.96" length="middle" rot="R270"/>
<pin name="D2" x="-104.14" y="60.96" length="middle" rot="R270"/>
<pin name="D3" x="-99.06" y="60.96" length="middle" rot="R270"/>
<pin name="D4" x="-93.98" y="60.96" length="middle" rot="R270"/>
<pin name="D5" x="-88.9" y="60.96" length="middle" rot="R270"/>
<pin name="D6" x="-83.82" y="60.96" length="middle" rot="R270"/>
<pin name="D7" x="-78.74" y="60.96" length="middle" rot="R270"/>
<pin name="D8" x="-73.66" y="60.96" length="middle" rot="R270"/>
<pin name="D9" x="-68.58" y="60.96" length="middle" rot="R270"/>
<pin name="D10" x="-63.5" y="60.96" length="middle" rot="R270"/>
<pin name="D11" x="-58.42" y="60.96" length="middle" rot="R270"/>
<pin name="D12" x="-53.34" y="60.96" length="middle" rot="R270"/>
<wire x1="-119.38" y1="55.88" x2="-43.18" y2="55.88" width="0.254" layer="94"/>
<wire x1="-43.18" y1="30.48" x2="-119.38" y2="30.48" width="0.254" layer="94"/>
<pin name="RST" x="-114.3" y="25.4" length="middle" rot="R90"/>
<pin name="A5" x="-109.22" y="25.4" length="middle" rot="R90"/>
<pin name="A4" x="-104.14" y="25.4" length="middle" rot="R90"/>
<pin name="A3" x="-99.06" y="25.4" length="middle" rot="R90"/>
<pin name="A2" x="-93.98" y="25.4" length="middle" rot="R90"/>
<pin name="A1" x="-88.9" y="25.4" length="middle" rot="R90"/>
<pin name="A0" x="-83.82" y="25.4" length="middle" rot="R90"/>
<pin name="A7" x="-78.74" y="25.4" length="middle" rot="R90"/>
<pin name="A6" x="-73.66" y="25.4" length="middle" rot="R90"/>
<pin name="VREF" x="-68.58" y="25.4" length="middle" rot="R90"/>
<pin name="VIN" x="-63.5" y="25.4" length="middle" rot="R90"/>
<pin name="3V3" x="-58.42" y="25.4" length="middle" rot="R90"/>
<pin name="GND" x="-53.34" y="25.4" length="middle" rot="R90"/>
<wire x1="-43.18" y1="55.88" x2="-43.18" y2="30.48" width="0.254" layer="94"/>
<pin name="D13" x="-48.26" y="60.96" length="middle" rot="R270"/>
<pin name="GND1" x="-48.26" y="25.4" length="middle" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ULTRA_MINI">
<description>ARDUINO_ULTRA_MINI.
Rocketscream.

By Dennis Revolorio on Flatbox</description>
<gates>
<gate name="G$2" symbol="ULTRA_MINI" x="81.28" y="-43.18"/>
</gates>
<devices>
<device name="" package="ULTRA_MINI">
<connects>
<connect gate="G$2" pin="3V3" pad="3V3"/>
<connect gate="G$2" pin="A0" pad="A0"/>
<connect gate="G$2" pin="A1" pad="A1"/>
<connect gate="G$2" pin="A2" pad="A2"/>
<connect gate="G$2" pin="A3" pad="A3"/>
<connect gate="G$2" pin="A4" pad="A4"/>
<connect gate="G$2" pin="A5" pad="A5"/>
<connect gate="G$2" pin="A6" pad="A6"/>
<connect gate="G$2" pin="A7" pad="A7"/>
<connect gate="G$2" pin="D0" pad="D0"/>
<connect gate="G$2" pin="D1" pad="D1"/>
<connect gate="G$2" pin="D10" pad="D10"/>
<connect gate="G$2" pin="D11" pad="D11"/>
<connect gate="G$2" pin="D12" pad="D12"/>
<connect gate="G$2" pin="D13" pad="D13"/>
<connect gate="G$2" pin="D2" pad="D2"/>
<connect gate="G$2" pin="D3" pad="D3"/>
<connect gate="G$2" pin="D4" pad="D4"/>
<connect gate="G$2" pin="D5" pad="D5"/>
<connect gate="G$2" pin="D6" pad="D6"/>
<connect gate="G$2" pin="D7" pad="D7"/>
<connect gate="G$2" pin="D8" pad="D8"/>
<connect gate="G$2" pin="D9" pad="D9"/>
<connect gate="G$2" pin="GND" pad="GND"/>
<connect gate="G$2" pin="GND1" pad="GND1"/>
<connect gate="G$2" pin="RST" pad="RST"/>
<connect gate="G$2" pin="VIN" pad="VIN"/>
<connect gate="G$2" pin="VREF" pad="VREF"/>
</connects>
<technologies>
<technology name=""/>
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
<part name="U$1" library="ACELEROMETER" deviceset="ACELEROMETER" device=""/>
<part name="U$2" library="BOOSTER" deviceset="POLOLU_STEP_UP_DOWN" device=""/>
<part name="U$3" library="CHARGER" deviceset="CHARGER" device=""/>
<part name="U$4" library="SIM8OOL" deviceset="SIM8OOL" device=""/>
<part name="U$5" library="ULTRA_MINI" deviceset="ULTRA_MINI" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="398.78" y="269.24"/>
<instance part="U$2" gate="G$1" x="284.48" y="375.92" rot="R90"/>
<instance part="U$3" gate="G$1" x="187.96" y="271.78"/>
<instance part="U$4" gate="G$1" x="297.18" y="137.16"/>
<instance part="U$5" gate="G$2" x="322.58" y="330.2" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$5" gate="G$2" pin="VIN"/>
<wire x1="297.18" y1="266.7" x2="320.04" y2="266.7" width="0.1524" layer="91"/>
<wire x1="320.04" y1="266.7" x2="320.04" y2="297.18" width="0.1524" layer="91"/>
<wire x1="320.04" y1="297.18" x2="127" y2="297.18" width="0.1524" layer="91"/>
<wire x1="127" y1="297.18" x2="127" y2="284.48" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="BAT+"/>
<wire x1="127" y1="284.48" x2="139.7" y2="284.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="BAT-"/>
<wire x1="182.88" y1="284.48" x2="185.42" y2="284.48" width="0.1524" layer="91"/>
<wire x1="185.42" y1="284.48" x2="185.42" y2="294.64" width="0.1524" layer="91"/>
<wire x1="185.42" y1="294.64" x2="317.5" y2="294.64" width="0.1524" layer="91"/>
<wire x1="317.5" y1="294.64" x2="317.5" y2="276.86" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$2" pin="GND"/>
<wire x1="317.5" y1="276.86" x2="302.26" y2="276.86" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$2" pin="GND1"/>
<wire x1="302.26" y1="276.86" x2="297.18" y2="276.86" width="0.1524" layer="91"/>
<wire x1="297.18" y1="281.94" x2="302.26" y2="281.94" width="0.1524" layer="91"/>
<wire x1="302.26" y1="281.94" x2="302.26" y2="276.86" width="0.1524" layer="91"/>
<junction x="302.26" y="276.86"/>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="365.76" y1="259.08" x2="365.76" y2="251.46" width="0.1524" layer="91"/>
<wire x1="365.76" y1="251.46" x2="330.2" y2="251.46" width="0.1524" layer="91"/>
<wire x1="330.2" y1="251.46" x2="330.2" y2="276.86" width="0.1524" layer="91"/>
<wire x1="330.2" y1="276.86" x2="317.5" y2="276.86" width="0.1524" layer="91"/>
<junction x="317.5" y="276.86"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$5" gate="G$2" pin="3V3"/>
<wire x1="297.18" y1="271.78" x2="332.74" y2="271.78" width="0.1524" layer="91"/>
<wire x1="332.74" y1="271.78" x2="332.74" y2="254" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="VCC"/>
<wire x1="332.74" y1="254" x2="360.68" y2="254" width="0.1524" layer="91"/>
<wire x1="360.68" y1="254" x2="360.68" y2="259.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$5" gate="G$2" pin="D3"/>
<wire x1="261.62" y1="231.14" x2="241.3" y2="231.14" width="0.1524" layer="91"/>
<wire x1="241.3" y1="231.14" x2="241.3" y2="198.12" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="INT"/>
<wire x1="241.3" y1="198.12" x2="381" y2="198.12" width="0.1524" layer="91"/>
<wire x1="381" y1="198.12" x2="381" y2="259.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="SCL"/>
<wire x1="370.84" y1="259.08" x2="370.84" y2="220.98" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$2" pin="A5"/>
<wire x1="370.84" y1="220.98" x2="297.18" y2="220.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$5" gate="G$2" pin="A4"/>
<pinref part="U$1" gate="G$1" pin="SDA"/>
<wire x1="297.18" y1="226.06" x2="375.92" y2="226.06" width="0.1524" layer="91"/>
<wire x1="375.92" y1="226.06" x2="375.92" y2="259.08" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
