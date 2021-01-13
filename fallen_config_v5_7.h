#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1500                                   //750 volume with no clashes at 2.3, 1200 also sounds nice, [default: 1500]
const unsigned int maxLedsPerStrip = 180;    //Could be upped by 25% only for ProffieOS 5.x [default: 144]
#define CLASH_THRESHOLD_G 2.5               //Originally 1.9 from Solo Sabers. 2.4 seems okay (2.4 clashes on Vader blasts, 2.5 has issues detecting clash) [default: 1.9 Solo Sabers]

#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD

//Custom defines
#define COLOR_CHANGE_DIRECT                 //Enable "Click to Change" for Dual Phase and other styles designed for it.
#define DISABLE_DIAGNOSTIC_COMMANDS //Reduces memory by disabling diagnostic commands
//#define DISABLE_COLOR_CHANGE            //Disables color change [spectrum], for memory saving
#define MOTION_TIMEOUT 60 * 15 * 1000    //This extends the motion timeout to 15 minutes to allow gesture ignition to remain active [Increase/decrease the "15" value as needed, default: 15]

#define FETT263_SWING_ON                        //To enable Swing On Ignition control (automatically enters Battle Mode, uses Fast On)
#define FETT263_SWING_ON_SPEED 800      //Dictates speed for Swing On [default: 250, recommended: 250-500]
#define FETT263_THRUST_ON                      //To enable Thrust On Ignition control (automatically enters Battle Mode, uses Fast On)
#define FETT263_TWIST_OFF                       //To enable Twist Off Retraction control

#define FETT263_MULTI_PHASE                   //This will enable a preset change while ON to create a "Multi-Phase" saber effect

#endif

//Recommended props by Fett263
#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif


#ifdef CONFIG_PRESETS
Preset presets[] = {

//===Original Era===
  { "Father", "tracks/vtheme.wav",
  StylePtr<Layers<
  AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,
  
  AlphaL<LemonChiffon,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,
  TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Orange>,
  
  ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipe<650>,TrWipeIn<500>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(),
  "Vader"},

  { "FOBlue", "tracks/JFOepic.wav",
	StylePtr<Layers<
  Stripes<10000,-1700,RotateColorsX<Variation,Rgb<0,0,80>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Rgb<0,0,50>>,RotateColorsX<Variation,Blue>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlicker<Rgb<80,240,255>,DodgerBlue>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<AudioFlicker<Rgb<50,180,255>,Rgb<1,54,255>>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,AudioFlicker<Rgb<50,180,255>,Rgb<1,54,255>>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,AudioFlicker<Blue,Rgb<0,0,150>>,Gradient<AudioFlicker<Blue,Rgb<0,0,150>>,BrownNoiseFlicker<White,Strobe<Red,LemonChiffon,50,1>,300>,White>>,TrWipeIn<600>,TrWipe<1400>>,
  
  ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Ivory,Strobe<Red,LemonChiffon,50,1>,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  //On Demand Power Save Full Blade (10% then 20% dimmer)
  EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<3277>>,AlphaL<Black,Int<6554>>,AlphaL<Black,Int<0>>>,
  
  InOutTrL<TrWipeSparkTip<White,200>,TrWipeIn<300>,Black>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(),
  "Blue JFO"},
   
  { "FOCyan", "tracks/JFOepic.wav",
    StylePtr<Layers<
  Stripes<10000,-1700,RotateColorsX<Variation,Rgb<0,25,80>>,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,16,50>>,RotateColorsX<Variation,DeepSkyBlue>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Red>,
  
  ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Azure,Strobe<Blue,LemonChiffon,50,1>,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipeSparkTip<White,200>,TrWipeIn<300>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(),
  "Cyan JFO"},
   
  { "FOGreen", "tracks/JFOepic.wav",
    StylePtr<Layers<
  AudioFlicker<Gradient<Gradient<Rgb<125,255,125>,GreenYellow,GreenYellow>,GreenYellow,GreenYellow,GreenYellow,GreenYellow,GreenYellow,GreenYellow,GreenYellow>,Green>,
  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
  ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<AudioFlicker<Rgb<125,255,125>,GreenYellow>,Strobe<Blue,LemonChiffon,50,1>,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Gradient<AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,Gradient<AudioFlicker<Green,GreenYellow>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>,TrWipeIn<700>,TrWipe<700>>,
  ResponsiveBlastL<BrownNoiseFlicker<Red,Magenta,300>,Int<150>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,50>,TrInstant,TrFade<350>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<16384>>,
  ResponsiveDragL<Gradient<AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,AudioFlicker<Green,GreenYellow>,Gradient<AudioFlicker<Green,GreenYellow>,BrownNoiseFlicker<White,Strobe<Blue,LemonChiffon,50,1>,300>,White>>,TrWipeIn<400>,TrFade<400>>,
  ResponsiveMeltL<Mix<TwistAngle<>,Red,Orange>,TrWipeIn<600>,TrSmoothFade<600>>,
  InOutTrL<TrWipe<200>,TrWipeIn<300>>,
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<10000>>,Int<0>,Scale<BatteryLevel,Int<16384>,Int<7500>>>>>>(),
  "Green JFO"},
  
  { "2ndSis, "tracks/JFO12.wav",
	StylePtr<Layers<
  Stripes<10000,-1700,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,RotateColorsX<Variation,Red>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<AudioFlicker<Rgb<255,75,75>,Tomato>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<AudioFlicker<Rgb<255,56,47>,Rgb<255,23,9>>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,AudioFlicker<Rgb<255,56,47>,Rgb<255,23,9>>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Orange>,
  
  ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Azure,Strobe<Blue,LemonChiffon,50,1>,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipe<200>,TrWipeIn<300>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(),
  "Second Sister"},

//===Prequel Era===   
  { "Yoda", "tracks/YvsD.wav",
	StylePtr<Layers<
  AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,192,0>>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Red>,
  
  ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipe<300>,TrWipeIn<500>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(),
  "Yoda"},
  
  { "Ahsoka", ""
	StylePtr<Layers<
  AudioFlicker<RotateColorsX<Variation,Rgb<75,150,200>>,RotateColorsX<Variation,Rgb<37,75,100>>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,150,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Red>,
  
  ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipe<150>,TrWipeIn<500>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>().
  "Ahsoka"}  
   
//===Sequel Era===      
  { "9Graflex", "tracks/track3g.wav",
	StylePtr<Layers<
  AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,136>>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Red>,
  
  ResponsiveBlastL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipe<300>,TrWipeIn<500>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(), 
  "Sequel Graflex"},
   
  { "KyloV2", "tracks/track3k.wav",
    StylePtr<Layers<
  StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveStabL<Orange>,
  
  ResponsiveBlastL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipe<150>,TrWipeIn<500>>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(), 
  "Kylo"}
  
//===Non-Canon===
  { "Nichirin", "tracks/kamado.wav",
  StylePtr<InOutTr<Layers<
  Mix<BladeAngle<>,HumpFlicker<StyleFire<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Red>,0,2,FireConfig<10,2000,5>,FireConfig<10,2000,5>,FireConfig<0,2000,10>,FireConfig<0,2000,5>>,HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<160,120,0>>,50>,200>,HumpFlicker<StyleFire<OrangeRed,Orange,0,4,FireConfig<40,3000,5>,FireConfig<40,3000,5>,FireConfig<40,3000,10>,FireConfig<0,3000,5>>,HumpFlicker<OrangeRed,Rgb<160,120,0>,20>,200>>,
  
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
  
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
  
  ResponsiveBlastL<White>,
  
  ResponsiveClashL<White,TrInstant,TrFade<400>>,
  
  ResponsiveStabL<Orange>,
  
  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
  
  ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,
  
  ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  ResponsiveMeltL<Mix<TwistAngle<>,Red,Yellow>,TrWipeIn<600>,TrSmoothFade<600>>>,
  
  TrWipe<130>,TrWipeIn<500>>>(),
  "Hinokami Kagura"},
  
  { "Newtype", "tracks/newtype.wav",
  StylePtr<Layers<
  Stripes<6000,-3000,RotateColorsX<Variation,Rgb<128,0,22>>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb<60,0,11>>>,
  
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<AudioFlicker<Pink,HotPink>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<BrownNoiseFlicker<White,Green,300>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<AudioFlickerL<AudioFlicker<Pink,HotPink>>,BrownNoiseFlicker<White,Green,300>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<BrownNoiseFlicker<White,Green,300>,AudioFlickerL<AudioFlicker<Pink,HotPink>>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  AlphaL<RotateColorsX<Variation,Rgb<255,90,100>>,Bump<Int<0>,Int<8000>>>,
  
  ResponsiveStabL<Orange>,
  
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  
  ResponsiveClashL<TransitionEffect<AudioFlicker<Pink,HotPink>,BrownNoiseFlicker<White,Green,300>,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  
  InOutTrL<TrWipeSparkTip<HotPink,500>,TrWipeIn<500>>,
  
  TransitionEffectL<TrConcat<TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepPink>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepPink>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepPink>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>,
  
  AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>>>(),
  "Newtype Deep Pink"},
  
};
BladeConfig blades[] = {
 { 0, WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>, DefaultPinClass, 1000000>(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif