typedef unsigned long XID;
typedef unsigned long Atom;
typedef unsigned long VisualID;
typedef unsigned long Time;
typedef XID Window;
typedef XID Font;
typedef XID Pixmap;
typedef unsigned char KeyCode;
typedef XID Drawable;
typedef XID Cursor;
typedef XID Colormap;
typedef XID GContext;
typedef XID KeySym;

#define AllTemporary	0L
#define AnyButton	0L
#define AnyKey	0L
#define AnyPropertyType	0L
#define CopyFromParent	0L
#define CurrentTime	0L
#define NoSymbol	0L
#define None	0L
#define PointerWindow	0L
#define InputFocus	1L
#define ParentRelative	1L
#define PointerRoot	1L

#define KeyPressMask	(1L<<0)
#define KeyReleaseMask	(1L<<1)
#define Button3MotionMask	(1L<<10)
#define Button4MotionMask	(1L<<11)
#define Button5MotionMask	(1L<<12)
#define ButtonMotionMask	(1L<<13)
#define KeymapStateMask	(1L<<14)
#define ExposureMask	(1L<<15)
#define VisibilityChangeMask	(1L<<16)
#define StructureNotifyMask	(1L<<17)
#define ResizeRedirectMask	(1L<<18)
#define SubstructureNotifyMask	(1L<<19)
#define ButtonPressMask	(1L<<2)
#define SubstructureRedirectMask	(1L<<20)
#define FocusChangeMask	(1L<<21)
#define PropertyChangeMask	(1L<<22)
#define ColormapChangeMask	(1L<<23)
#define ButtonReleaseMask	(1L<<3)
#define EnterWindowMask	(1L<<4)
#define LeaveWindowMask	(1L<<5)
#define PointerMotionMask	(1L<<6)
#define PointerMotionHintMask	(1L<<7)
#define Button1MotionMask	(1L<<8)
#define Button2MotionMask	(1L<<9)

#define NoEventMask	0L
#define FocusOut	10
#define KeymapNotify	11
#define Expose	12
#define GraphicsExpose	13
#define NoExpose	14
#define VisibilityNotify	15
#define CreateNotify	16
#define DestroyNotify	17
#define UnmapNotify	18
#define MapNotify	19
#define KeyPress	2
#define MapRequest	20
#define ReparentNotify	21
#define ConfigureNotify	22
#define ConfigureRequest	23
#define GravityNotify	24
#define ResizeRequest	25
#define CirculateNotify	26
#define CirculateRequest	27
#define PropertyNotify	28
#define SelectionClear	29
#define KeyRelease	3
#define SelectionRequest	30
#define SelectionNotify	31
#define ColormapNotify	32
#define ClientMessage	33
#define MappingNotify	34
#define LASTEvent	35
#define ButtonPress	4
#define ButtonRelease	5
#define MotionNotify	6
#define EnterNotify	7
#define LeaveNotify	8
#define FocusIn	9

#define ShiftMask	(1<<0)
#define LockMask	(1<<1)
#define ControlMask	(1<<2)
#define Mod1Mask	(1<<3)
#define Mod2Mask	(1<<4)
#define Mod3Mask	(1<<5)
#define Mod4Mask	(1<<6)
#define Mod5Mask	(1<<7)

#define ShiftMapIndex	0
#define LockMapIndex	1
#define ControlMapIndex	2
#define Mod1MapIndex	3
#define Mod2MapIndex	4
#define Mod3MapIndex	5
#define Mod4MapIndex	6
#define Mod5MapIndex	7

#define Button3Mask	(1<<10)
#define Button4Mask	(1<<11)
#define Button5Mask	(1<<12)
#define AnyModifier	(1<<15)
#define Button1Mask	(1<<8)
#define Button2Mask	(1<<9)

#define Button1	1
#define Button2	2
#define Button3	3
#define Button4	4
#define Button5	5

#define NotifyNormal	0
#define NotifyGrab	1
#define NotifyHint	1
#define NotifyUngrab	2
#define NotifyWhileGrabbed	3

#define NotifyAncestor	0
#define NotifyVirtual	1
#define NotifyInferior	2
#define NotifyNonlinear	3
#define NotifyNonlinearVirtual	4
#define NotifyPointer	5
#define NotifyPointerRoot	6
#define NotifyDetailNone	7

#define VisibilityUnobscured	0
#define VisibilityPartiallyObscured	1
#define VisibilityFullyObscured	2

#define PlaceOnTop	0
#define PlaceOnBottom	1

#define FamilyInternet	0
#define FamilyDECnet	1
#define FamilyChaos	2

#define PropModeReplace	0
#define PropertyNewValue	0
#define PropertyDelete	1

#define ColormapUninstalled	0
#define ColormapInstalled	1

#define GrabModeSync	0
#define GrabModeAsync	1

#define GrabSuccess	0
#define AlreadyGrabbed	1
#define GrabInvalidTime	2
#define GrabNotViewable	3
#define GrabFrozen	4

#define AsyncPointer	0
#define SyncPointer	1
#define ReplayPointer	2
#define AsyncKeyboard	3
#define SyncKeyboard	4
#define ReplayKeyboard	5
#define AsyncBoth	6
#define SyncBoth	7

#define RevertToNone	(int)None
#define RevertToPointerRoot	(int)PointerRoot
#define RevertToParent	2

#define Success	0
#define BadRequest	1
#define BadAccess	10
#define BadAlloc	11
#define BadColor	12
#define FirstExtensionError	128
#define BadGC	13
#define BadIDChoice	14
#define BadName	15
#define BadLength	16
#define BadImplementation	17
#define BadValue	2
#define LastExtensionError	255
#define BadWindow	3
#define BadPixmap	4
#define BadAtom	5
#define BadCursor	6
#define BadFont	7
#define BadMatch	8
#define BadDrawable	9

#define CWX	(1<<0)
#define InputOutput	1
#define InputOnly	2

#define CWBackPixmap	(1L<<0)
#define CWBackPixel	(1L<<1)
#define CWSaveUnder	(1L<<10)
#define CWEventMask	(1L<<11)
#define CWDontPropagate	(1L<<12)
#define CWColormap	(1L<<13)
#define CWCursor	(1L<<14)
#define CWBorderPixmap	(1L<<2)
#define CWBorderPixel	(1L<<3)
#define CWBitGravity	(1L<<4)
#define CWWinGravity	(1L<<5)
#define CWBackingStore	(1L<<6)
#define CWBackingPlanes	(1L<<7)
#define CWBackingPixel	(1L<<8)
#define CWOverrideRedirect	(1L<<9)

#define CWY	(1<<1)
#define CWWidth	(1<<2)
#define CWHeight	(1<<3)
#define CWBorderWidth	(1<<4)
#define CWSibling	(1<<5)
#define CWStackMode	(1<<6)

#define ForgetGravity	0
#define UnmapGravity	0
#define NorthWestGravity	1
#define StaticGravity	10
#define NorthGravity	2
#define NorthEastGravity	3
#define WestGravity	4
#define CenterGravity	5
#define EastGravity	6
#define SouthWestGravity	7
#define SouthGravity	8
#define SouthEastGravity	9

#define NotUseful	0
#define WhenMapped	1
#define Always	2

#define IsUnmapped	0
#define IsUnviewable	1
#define IsViewable	2

#define SetModeInsert	0
#define SetModeDelete	1

#define DestroyAll	0
#define RetainPermanent	1
#define RetainTemporary	2

#define Above	0
#define Below	1
#define TopIf	2
#define BottomIf	3

#define RaiseLowest	0
#define LowerHighest	1

#define PropModePrepend	1
#define PropModeAppend	2

#define GXclear	0x0
#define GXand	0x1
#define GXandReverse	0x2
#define GXcopy	0x3
#define GXandInverted	0x4
#define GXnoop	0x5
#define GXxor	0x6
#define GXor	0x7
#define GXnor	0x8
#define GXequiv	0x9
#define GXinvert	0xa
#define GXorReverse	0xb
#define GXcopyInverted	0xc
#define GXorInverted	0xd
#define GXnand	0xe
#define GXset	0xf

#define LineSolid	0
#define LineOnOffDash	1
#define LineDoubleDash	2

#define CapNotLast	0
#define CapButt	1
#define CapRound	2
#define CapProjecting	3

#define JoinMiter	0
#define JoinRound	1
#define JoinBevel	2

#define FillSolid	0
#define FillTiled	1
#define FillStippled	2
#define FillOpaqueStippled	3

#define EvenOddRule	0
#define WindingRule	1

#define ClipByChildren	0
#define IncludeInferiors	1

#define Unsorted	0
#define XYBitmap	0
#define YSorted	1
#define YXSorted	2
#define YXBanded	3

#define CoordModeOrigin	0
#define CoordModePrevious	1

#define Complex	0
#define Nonconvex	1
#define Convex	2

#define ArcChord	0
#define ArcPieSlice	1

#define GCFunction	(1L<<0)
#define GCPlaneMask	(1L<<1)
#define GCTile	(1L<<10)
#define GCStipple	(1L<<11)
#define GCTileStipXOrigin	(1L<<12)
#define GCTileStipYOrigin	(1L<<13)
#define GCFont	(1L<<14)
#define GCSubwindowMode	(1L<<15)
#define GCGraphicsExposures	(1L<<16)
#define GCClipXOrigin	(1L<<17)
#define GCClipYOrigin	(1L<<18)
#define GCClipMask	(1L<<19)
#define GCForeground	(1L<<2)
#define GCDashOffset	(1L<<20)
#define GCDashList	(1L<<21)
#define GCArcMode	(1L<<22)
#define GCBackground	(1L<<3)
#define GCLineWidth	(1L<<4)
#define GCLineStyle	(1L<<5)
#define GCCapStyle	(1L<<6)
#define GCJoinStyle	(1L<<7)
#define GCFillStyle	(1L<<8)
#define GCFillRule	(1L<<9)
#define GCLastBit	22
#define FontChange	255

#define FontLeftToRight	0
#define FontRightToLeft	1

#define XYPixmap	1
#define ZPixmap	2

#define AllocNone	0
#define AllocAll	1

#define DoRed	(1<<0)
#define DoGreen	(1<<1)
#define DoBlue	(1<<2)

#define CursorShape	0
#define TileShape	1
#define StippleShape	2

#define AutoRepeatModeOff	0
#define LedModeOff	0
#define AutoRepeatModeOn	1
#define LedModeOn	1
#define AutoRepeatModeDefault	2

#define KBKeyClickPercent	(1L<<0)
#define KBBellPercent	(1L<<1)
#define KBBellPitch	(1L<<2)
#define KBBellDuration	(1L<<3)
#define KBLed	(1L<<4)
#define KBLedMode	(1L<<5)
#define KBKey	(1L<<6)
#define KBAutoRepeatMode	(1L<<7)
#define MappingModifier	0
#define MappingSuccess	0
#define MappingBusy	1
#define MappingKeyboard	1
#define MappingFailed	2
#define MappingPointer	2

#define DisableScreenInterval	0
#define DisableScreenSaver	0
#define DontAllowExposures	0
#define DontPreferBlanking	0
#define AllowExposures	1
#define PreferBlanking	1
#define DefaultBlanking	2
#define DefaultExposures	2

#define ScreenSaverReset	0
#define ScreenSaverActive	1

#define HostInsert	0
#define HostDelete	1

#define DisableAccess	0
#define EnableAccess	1

#define StaticGray	0
#define GrayScale	1
#define StaticColor	2
#define PseudoColor	3
#define TrueColor	4
#define DirectColor	5

#define LSBFirst	0
#define MSBFirst	1
