#include "Dictionary.hpp"
#include "Main.hpp"
#include <stdlib.h>
#include <time.h>

//Words from: https://www.playosmo.com/kids-learning/four-letter-words/
//H's from: https://scrabblewordfinder.org/4-letter-words-starting-with/h
//L's from: https://scrabblewordfinder.org/4-letter-words-starting-with/l
//O's from: https://scrabblewordfinder.org/4-letter-words-starting-with/o
//R's from: https://scrabblewordfinder.org/4-letter-words-starting-with/r
//U's from: https://scrabblewordfinder.org/4-letter-words-starting-with/u
//V's from: https://scrabblewordfinder.org/4-letter-words-starting-with/v
//w's from: https://scrabblewordfinder.org/4-letter-words-starting-with/w
static const char* AllWords[] = {
	{"ABET"},
	{"AIRS"},
	{"APES"},
	{"AUNT"},
	{"ABLE"},
	{"AJAR"},
	{"APEX"},
	{"ATOP"},
	{"ACTS"},
	{"ALAS"},
	{"AREA"},
	{"AUTO"},
	{"ADDS"},
	{"ALLY"},
	{"ARMY"},
	{"AVID"},
	{"AFAR"},
	{"ALSO"},
	{"ARMS"},
	{"AWAY"},
	{"AGED"},
	{"AMEN"},
	{"ARID"},
	{"AWED"},
	{"AGES"},
	{"AMID"},
	{"ARTS"},
	{"AXED"},
	{"AHOY"},
	{"ANEW"},
	{"ASKS"},
	{"AXEL"},
	{"AIDS"},
	{"ANTI"},
	{"ASHY"},
	{"AXIS"},
	{"AIMS"},
	{"ANTS"},
	{"ATOM"},
	{"AXES"},
	{"BEEN"},
	{"BANS"},	
	{"BATH"},
	{"BACK"},	
	{"BASH"},	
	{"BOSS"},
	{"BOTH"},	
	{"BUFF"},	
	{"BELT"},
	{"BEST"},	
	{"BURN"},	
	{"BOOM"},
	{"BANK"},	
	{"BULL"},	
	{"BLUR"},
	{"BOOK"},	
	{"BONY"},	
	{"BROW"},
	{"BASE"},	
	{"BLOT"},	
	{"BASS"},
	{"BODY"},	
	{"BEAD"},	
	{"BIAS"},
	{"BILL"},	
	{"BARD"},	
	{"BARE"},
	{"BLUE"},	
	{"BRAY"},	
	{"BOLD"},
	{"BALL"},	
	{"BUNK"},	
	{"BEEF"},
	{"BORN"},	
	{"BURR"},	
	{"BETA"},
	{"BABY"},	
	{"BRAN"},	
	{"BENT"},
	{"BEAT"},	
	{"BALE"},	
	{"BIKE"},
	{"BAND"},	
	{"BODE"},	
	{"BOOT"},
	{"BEAR"},	
	{"BOAR"},	
	{"BEND"},
	{"BELL"},	
	{"BECK"},	
	{"BEAM"},
	{"BUSY"},	
	{"BARN"},	
	{"BITE"},
	{"BOND"},	
	{"BUZZ"},	
	{"BLEW"},
	{"BUSH"},	
	{"BEAN"},	
	{"BAIL"},
	{"BOAT"},	
	{"BIND"},	
	{"BORE"},
	{"BULK"},	
	{"BUCK"},	
	{"BANG"},
	{"BOWL"},	
	{"BATS"},	
	{"BUMP"},
	{"BIRD"},	
	{"BULB"},	
	{"BOUT"},
	{"BLOW"},	
	{"BOLT"},	
	{"BARK"},
	{"BONE"},	
	{"BRED"},	
	{"BREW"},
	{"BALD"},	
	{"BURY"},	
	{"BAIT"},
	{"BOON"},	
	{"BLOG"},	
	{"BILE"},
	{"BEEP"},	
	{"BOIL"},	
	{"BAKE"},
	{"CALL"},	
	{"CHIN"},	
	{"CAME"},
	{"CARD"},	
	{"CHIP"},	
	{"CLAY"},
	{"CAST"},	
	{"CLAW"},	
	{"CLAN"},
	{"CASE"},	
	{"COPE"},	
	{"CLAM"},
	{"CARE"},	
	{"CORE"},	
	{"CLAP"},
	{"CURE"},	
	{"CRIB"},	
	{"CRAB"},
	{"CUTE"},	
	{"CROP"},	
	{"CORD"},
	{"COOL"},	
	{"COST"},	
	{"COAL"},
	{"CURT"},	
	{"COZY"},	
	{"CUBE"},
	{"CURD"},	
	{"COIL"},	
	{"CLIP"},
	{"CURB"},	
	{"COMB"},	
	{"CALF"},
	{"CURL"},	
	{"COME"},	
	{"CALM"},
	{"CORN"},	
	{"CART"},	
	{"CAGE"},
	{"COIR"},	
	{"CAPE"},	
	{"CAKE"},
	{"CASH"},	
	{"CUFF"},	
	{"CUSP"},
	{"CHAT"},	
	{"CHEF"},	
	{"CHEW"},
	{"CHOW"},	
	{"CHOP"},	
	{"CHUM"},
	{"CITE"},	
	{"CLAD"},	
	{"CITY"},
	{"CLUE"},	
	{"CLUB"},	
	{"CLOG"},
	{"COAT"},	
	{"COAX"},	
	{"COIN"},
	{"COOP"},	
	{"CODE"},	
	{"COLD"},
	{"CORK"},	
	{"COUP"},	
	{"CROW"},
	{"DARK"},	
	{"DIME"},	
	{"DAME"},
	{"DIRT"},	
	{"DICE"},	
	{"DEAL"},
	{"DUST"},	
	{"DIET"},	
	{"DONE"},
	{"DENT"},	
	{"DIRE"},	
	{"DUNE"},
	{"DUNG"},	
	{"DUET"},	
	{"DRAB"},
	{"DROP"},	
	{"DOME"},	
	{"DEAF"},
	{"DRIP"},	
	{"DOOR"},	
	{"DART"},
	{"DULL"},	
	{"DEEM"},	
	{"DASH"},
	{"DOOM"},	
	{"DOCK"},	
	{"DISH"},
	{"DUPE"},	
	{"DARE"},	
	{"DOVE"},
	{"DRUM"},	
	{"DIAL"},	
	{"DIVE"},
	{"DOTE"},	
	{"DREW"},	
	{"DUMP"},
	{"DRAW"},	
	{"DAZE"},	
	{"DUCK"},
	{"DENY"},	
	{"DODO"},	
	{"DAFT"},
	{"DATE"},	
	{"DAWN"},	
	{"DATA"},
	{"DECK"},	
	{"DOSE"},	
	{"DUDE"},
	{"DEFY"},	
	{"DEER"},	
	{"DEEP"},
	{"EVEN"},	
	{"EARN"},	
	{"EDIT"},
	{"EACH"},	
	{"EVIL"},	
	{"EPIC"},
	{"EVER"},	
	{"EXIT"},	
	{"EARS"},
	{"EASY"},	
	{"ECHO"},	
	{"EYES"},
	{"ELSE"},	
	{"EXAM"},	
	{"EDDY"},
	{"EAST"},	
	{"ENVY"},	
	{"EMIT"},
	{"EDGE"},	
	{"EATS"},	
	{"EDGY"},
	{"EASE"},	
	{"ETCH"},	
	{"EONS"},
	{"EGGS"},	
	{"ELAN"},	
	{"EGGY"},
	{"FROM"},	
	{"FILL"},	
	{"FROG"},
	{"FOUR"},	
	{"FAIL"},	
	{"FUSE"},
	{"FIVE"},	
	{"FORD"},	
	{"FONT"},
	{"FULL"},	
	{"FEED"},	
	{"FIAT"},
	{"FORM"},	
	{"FORT"},	
	{"FLAP"},
	{"FIND"},	
	{"FATE"},	
	{"FLAW"},
	{"FACT"},	
	{"FAME"},	
	{"FRAY"},
	{"FREE"},	
	{"FLAG"},	
	{"FEND"},
	{"FACE"},	
	{"FLEW"},	
	{"FIFE"},
	{"FEEL"},	
	{"FOLK"},	
	{"FLOP"},
	{"FIRM"},	
	{"FOLD"},	
	{"FERN"},
	{"FOOD"},	
	{"FARE"},	
	{"FLEA"},
	{"FELT"},	
	{"FOUL"},	
	{"FEUD"},
	{"FEET"},	
	{"FOOL"},	
	{"FRET"},
	{"FALL"},	
	{"FLED"},	
	{"FINK"},
	{"FAST"},	
	{"FOAM"},	
	{"FLUE"},
	{"FUND"},	
	{"FOND"},	
	{"FLAK"},
	{"FIRE"},	
	{"FORK"},	
	{"FOWL"},
	{"FINE"},	
	{"FAKE"},	
	{"FLAX"},
	{"FILM"},	
	{"FIST"},	
	{"FANG"},
	{"FLOW"},	
	{"FURY"},	
	{"FETE"},
	{"FOOT"},	
	{"FLEX"},	
	{"FEST"},
	{"FAIR"},	
	{"FLIP"},	
	{"FIZZ"},
	{"FILE"},	
	{"FEAT"},	
	{"FUME"},
	{"FELL"},	
	{"FOIL"},	
	{"FOAL"},
	{"FLAT"},	
	{"FADE"},	
	{"FAVE"},
	{"FEAR"},	
	{"FUSS"},	
	{"FAUX"},
	{"FUEL"},	
	{"FLEE"},	
	{"FAWN"},
	{"FISH"},	
	{"FORE"},	
	{"FUZZ"},
	{"FARM"},	
	{"FLUX"},	
	{"FAZE"},
	{"GOOD"},	
	{"GRAB"},	
	{"GONG"},
	{"GIVE"},	
	{"GAZE"},	
	{"GAWK"},
	{"GAME"},	
	{"GRIM"},	
	{"GASH"},
	{"GAVE"},	
	{"GLOW"},	
	{"GUST"},
	{"GOES"},	
	{"GALA"},	
	{"GRUB"},
	{"GOAL"},	
	{"GILL"},	
	{"GNAW"},
	{"GONE"},	
	{"GLUE"},	
	{"GLIB"},
	{"GROW"},	
	{"GRIN"},	
	{"GUSH"},
	{"GAIN"},	
	{"GORE"},	
	{"GLAM"},
	{"GOLD"},	
	{"GOWN"},	
	{"GLUM"},
	{"GIRL"},	
	{"GOAT"},	
	{"GEEK"},
	{"GREW"},	
	{"GALE"},	
	{"GULP"},
	{"GOLF"},	
	{"GALL"},	
	{"GRAD"},
	{"GIFT"},	
	{"GRAM"},	
	{"GOOP"},
	{"GULF"},	
	{"GASP"},	
	{"GOOF"},
	{"GATE"},	
	{"GRIT"},	
	{"GYRO"},
	{"GENE"},	
	{"GOSH"},	
	{"GOAD"},
	{"GLAD"},	
	{"GAIT"},	
	{"GLOB"},
	{"GEAR"},	
	{"GERM"},	
	{"GILD"},
	{"GRAY"},	
	{"GLEE"},	
	{"GOON"},
	{"GREY"},	
	{"GIST"},	
	{"GAPE"},
	{"GANG"},	
	{"GILT"},	
	{"GNAT"},
	{"GRID"},	
	{"GULL"},	
	{"GEEZ"},
	{"GRIP"},	
	{"GARB"},	
	{"GAFF"},
	{"HACK"},
	{"HAGS"},
	{"HAHA"},
	{"HAIR"},
	{"HALE"},
	{"HALF"},
	{"HALO"},
	{"HALT"},
	{"HAMS"},
	{"HANG"},
	{"HARD"},
	{"HARE"},
	{"HARM"},
	{"HARP"},
	{"HART"},
	{"HASH"},
	{"HATH"},
	{"HATS"},
	{"HAUL"},
	{"HAVE"},
	{"HAZE"},
	{"HAZY"},
	{"HEAD"},
	{"HEAL"},
	{"HEAR"},
	{"HEAT"},
	{"HECK"},
	{"HEED"},
	{"HEFT"},
	{"HEIR"},
	{"HELD"},
	{"HELL"},
	{"HELP"},
	{"HERB"},
	{"HERD"},
	{"HERE"},
	{"HERS"},
	{"HEWN"},
	{"HIDE"},
	{"HIGH"},
	{"HILL"},
	{"HILT"},
	{"HIMS"},
	{"HIND"},
	{"HIPS"},
	{"HIRE"},
	{"HISS"},
	{"HITS"},
	{"HOAR"},
	{"HOAX"},
	{"HOGS"},
	{"HOLD"},
	{"HOLY"},
	{"HOME"},
	{"HONK"},
	{"HOOD"},
	{"HOOK"},
	{"HOOP"},
	{"HOOT"},
	{"HOPE"},
	{"HORN"},
	{"HOSE"},
	{"HOST"},
	{"HOTS"},
	{"HOWL"},
	{"HUGE"},
	{"HUGS"},
	{"HULK"},
	{"HUMS"},
	{"HUNK"},
	{"HUNT"},
	{"HURL"},
	{"HUSH"},
	{"HUSK"},
	{"HUTS"},
	{"HYMN"},
	{"INTO"},	
	{"IDLE"},	
	{"IBEX"},
	{"IDEA"},	
	{"ISLE"},	
	{"INKY"},
	{"ITEM"},	
	{"IRIS"},	
	{"IONS"},
	{"IRON"},	
	{"IDOL"},	
	{"IDLY"},
	{"INCH"},	
	{"ICED"},	
	{"ILLS"},
	{"INFO"},	
	{"ITCH"},	
	{"IMPS"},
	{"ICON"},	
	{"IBIS"},	
	{"IRKS"},
	{"JUST"},	
	{"JAVA"},	
	{"JILT"},
	{"JOHN"},	
	{"JUNK"},	
	{"JIGS"},
	{"JOIN"},	
	{"JEEP"},	
	{"JOTS"},
	{"JACK"},	
	{"JADE"},	
	{"JOBS"},
	{"JEAN"},	
	{"JERK"},	
	{"JAMS"},
	{"JUMP"},	
	{"JEST"},	
	{"JAGS"},
	{"JURY"},	
	{"JOLT"},	
	{"JUGS"},
	{"JAIL"},	
	{"JOCK"},	
	{"JABS"},
	{"JAZZ"},	
	{"JELL"},	
	{"JUTS"},
	{"JOKE"},	
	{"JUDO"},	
	{"JAYS"},
	{"JUNE"},	
	{"JIVE"},	
	{"JARS"},
	{"JULY"},	
	{"JIBE"},	
	{"JETS"},
	{"JEER"},	
	{"JUTE"},	
	{"JAWS"},
	{"JINX"},	
	{"JUKE"},	
	{"JOEY"},
	{"JAMB"},	
	{"JOYS"},	
	{"JOGS"},
	{"JOLT"},	
	{"JOWL"},	
	{"JIFF"},
	{"KING"},	
	{"KNOB"},	
	{"KIND"},
	{"KITE"},	
	{"KALE"},	
	{"KIWI"},
	{"KISS"},	
	{"KEEP"},	
	{"KNOT"},
	{"KILL"},	
	{"KILO"},	
	{"KNIT"},
	{"KICK"},	
	{"KETO"},	
	{"KNEW"},
	{"KEEN"},	
	{"KNEE"},	
	{"KNOW"},
	{"LABS"},
	{"LACE"},
	{"LACK"},
	{"LADS"},
	{"LADY"},
	{"LAGS"},
	{"LAID"},
	{"LAIR"},
	{"LAKE"},
	{"LAMB"},
	{"LAME"},
	{"LAND"},
	{"LANE"},
	{"LAPS"},
	{"LARD"},
	{"LASS"},
	{"LAST"},
	{"LATE"},
	{"LAVA"},
	{"LAWN"},
	{"LAYS"},
	{"LEAD"},
	{"LEAF"},
	{"LEAK"},
	{"LEAN"},
	{"LEEK"},
	{"LEFT"},
	{"LEGS"},
	{"LEPT"},
	{"LESS"},
	{"LETS"},
	{"LIAR"},
	{"LICE"},
	{"LICK"},
	{"LIEN"},
	{"LIES"},
	{"LIFE"},
	{"LIFT"},
	{"LIMB"},
	{"LIME"},
	{"LIMO"},
	{"LINE"},
	{"LINT"},
	{"LIPS"},
	{"LIST"},
	{"LITE"},
	{"LITS"},
	{"LIVE"},
	{"LOAF"},
	{"LOAN"},
	{"LOCK"},
	{"LOFT"},
	{"LOGS"},
	{"LOIN"},
	{"LONE"},
	{"LONG"},
	{"LOOM"},
	{"LOOP"},
	{"LORD"},
	{"LORE"},
	{"LOST"},
	{"LOTS"},
	{"LOUD"},
	{"LOVE"},
	{"LUCK"},
	{"LUMP"},
	{"LUNG"},
	{"LURE"},
	{"LUSH"},
	{"LUTE"},
	{"LYNX"},
	{"MORE"},
	{"MOON"},
	{"MOLE"},
	{"MOST"},
	{"MILD"},
	{"MOOR"},
	{"MADE"},
	{"MESS"},
	{"MUTE"},
	{"MUCH"},
	{"MINI"},
	{"MALT"},
	{"MANY"},
	{"MYTH"},
	{"MEND"},
	{"MAKE"},
	{"MASK"},
	{"MIME"},
	{"MUST"},
	{"MALL"},
	{"MUCK"},
	{"MEET"},
	{"MICE"},
	{"MASH"},
	{"MOVE"},
	{"MELT"},
	{"MULE"},
	{"MEAN"},
	{"MOSS"},
	{"MEEK"},
	{"MAIN"},
	{"MOCK"},
	{"MOOT"},
	{"MIND"},
	{"MESH"},
	{"MACE"},
	{"MARK"},
	{"MEMO"},
	{"MINK"},
	{"MASS"},
	{"MIST"},
	{"MOTH"},
	{"MAIL"},
	{"MAID"},
	{"MELD"},
	{"MISS"},
	{"MINT"},
	{"MITE"},
	{"MALE"},
	{"MOLD"},
	{"MOAN"},
	{"MINE"},
	{"MEGA"},
	{"MOAT"},
	{"MILE"},
	{"MART"},
	{"MICA"},
	{"MODE"},
	{"MAMA"},
	{"MULL"},
	{"MILL"},
	{"MONK"},
	{"MANE"},
	{"MILK"},
	{"MAZE"},
	{"MAXI"},
	{"MEAL"},
	{"MAYO"},
	{"MOLL"},
	{"MERE"},
	{"MAST"},
	{"MUSH"},
	{"MEAT"},
	{"MARE"},
	{"MUSK"},
	{"MENU"},
	{"MUSE"},
	{"MOJO"},
	{"MOOD"},
	{"MATH"},
	{"MIRE"},
	{"NEST"},	
	{"NECK"},	
	{"NAIL"},
	{"NERD"},	
	{"NOTE"},	
	{"NINE"},
	{"NEAT"},	
	{"NAME"},	
	{"NEAR"},
	{"NOSY"},	
	{"NICE"},	
	{"NOPE"},
	{"NONE"},	
	{"NOUN"},	
	{"NEWS"},
	{"NOON"},	
	{"NEWT"},	
	{"NEXT"},
	{"OAFS"},
	{"OAKS"},
	{"OAKY"},
	{"OARS"},
	{"OATH"},
	{"OATS"},
	{"OBEY"},
	{"OBOE"},
	{"ODDS"},
	{"ODOR"},
	{"OGLE"},
	{"OGRE"},
	{"OHMS"},
	{"OILS"},
	{"OILY"},
	{"OINK"},
	{"OINT"},
	{"OKAY"},
	{"OKRA"},
	{"OLDS"},
	{"OLEO"},
	{"OMEN"},
	{"OMIT"},
	{"ONCE"},
	{"ONES"},
	{"ONLY"},
	{"OOPS"},
	{"OOZE"},
	{"OPAL"},
	{"OPEN"},
	{"ORAL"},
	{"ORCA"},
	{"ORES"},
	{"ORZO"},
	{"OUCH"},
	{"OURS"},
	{"OUST"},
	{"OUTS"},
	{"OVAL"},
	{"OVEN"},
	{"OVER"},
	{"OWED"},
	{"OWES"},
	{"OWLS"},
	{"OWNS"},
	{"OXEN"},
	{"PEAS"},
	{"PEAK"},
	{"PONY"},
	{"PITY"},
	{"PILE"},
	{"PALM"},
	{"PARK"},
	{"PART"},
	{"PORT"},
	{"PASS"},
	{"PACK"},
	{"PAIR"},
	{"PALE"},
	{"PAIL"},
	{"PARE"},
	{"PATH"},
	{"PEAR"},
	{"PEST"},
	{"PINE"},
	{"PEER"},
	{"PLAN"},
	{"POKE"},
	{"PLAY"},
	{"POSE"},
	{"POND"},
	{"PANT"},
	{"PAGE"},
	{"POEM"},
	{"POUR"},
	{"PREY"},
	{"PRAY"},
	{"PRIM"},
	{"PENT"},
	{"QUIT"},
	{"QUAD"},
	{"QUIN"},
	{"QUAG"},
	{"QUIZ"},
	{"QUAY"},
	{"QUIP"},
	{"QUOD"},
	{"QATS"},
	{"RACE"},
	{"RACK"},
	{"RAFT"},
	{"RAGE"},
	{"RAGS"},
	{"RAID"},
	{"RAIL"},
	{"RAIN"},
	{"RAKE"},
	{"RAMP"},
	{"RAMS"},
	{"RANK"},
	{"RANT"},
	{"RARE"},
	{"RASH"},
	{"RATE"},
	{"RATS"},
	{"RAZE"},
	{"READ"},
	{"REAL"},
	{"REAM"},
	{"REAP"},
	{"REAR"},
	{"REED"},
	{"REEF"},
	{"REIN"},
	{"RELY"},
	{"RENT"},
	{"RIBS"},
	{"RICE"},
	{"RICH"},
	{"RIDE"},
	{"RIFT"},
	{"RIND"},
	{"RING"},
	{"RINK"},
	{"RIOT"},
	{"RIPE"},
	{"RISE"},
	{"RISK"},
	{"ROAD"},
	{"ROAM"},
	{"ROAR"},
	{"ROBE"},
	{"ROBS"},
	{"ROCK"},
	{"RODS"},
	{"ROLE"},
	{"ROLL"},
	{"ROMP"},
	{"ROOF"},
	{"ROOK"},
	{"ROOM"},
	{"ROOT"},
	{"ROPE"},
	{"ROSE"},
	{"ROSY"},
	{"ROTS"},
	{"ROWS"},
	{"RUBS"},
	{"RUBY"},
	{"RUDE"},
	{"RUDY"},
	{"RUGS"},
	{"RUIN"},
	{"RULE"},
	{"RUMP"},
	{"RUNE"},
	{"RUNG"},
	{"RUNS"},
	{"RUNT"},
	{"RUSE"},
	{"RUSH"},
	{"RUST"},
	{"RUTH"},
	{"RUTS"},
	{"SAID"},	
	{"SEAT"},	
	{"SWIM"},
	{"SOME"},	
	{"SKIN"},	
	{"SWAP"},
	{"SUCH"},	
	{"SUIT"},	
	{"SNAP"},
	{"SAME"},	
	{"SHIP"},	
	{"STIR"},
	{"SITE"},	
	{"SHUT"},	
	{"SEMI"},
	{"SHOW"},	
	{"SALT"},	
	{"SORE"},
	{"SEEN"},	
	{"SONG"},	
	{"SANG"},
	{"SIDE"},	
	{"SOLE"},	
	{"SPUN"},
	{"SURE"},	
	{"SOIL"},	
	{"SAIL"},
	{"SIZE"},	
	{"SICK"},	
	{"SKIP"},
	{"SALE"},	
	{"SOUL"},	
	{"SLID"},
	{"SOLD"},	
	{"SNOW"},	
	{"SWAN"},
	{"SAFE"},	
	{"SAND"},	
	{"SPUR"},
	{"SOON"},	
	{"SEED"},	
	{"SOUR"},
	{"STOP"},	
	{"SAKE"},	
	{"SACK"},
	{"STEP"},	
	{"SLIP"},	
	{"SLAM"},
	{"SELL"},	
	{"SPIN"},	
	{"SANK"},
	{"STAY"},	
	{"SING"},	
	{"SAGE"},
	{"SEEM"},	
	{"SPAN"},	
	{"SURF"},
	{"SENT"},	
	{"SHED"},	
	{"SUNG"},
	{"SORT"},	
	{"SEAL"},	
	{"SIGH"},
	{"SEND"},	
	{"STEM"},	
	{"SODA"},
	{"SIGN"},	
	{"SOLO"},	
	{"SAGA"},
	{"STAR"},	
	{"SOUP"},	
	{"SOFA"},
	{"SAVE"},	
	{"SLOT"},	
	{"SLAP"},
	{"SHOP"},	
	{"SCAN"},	
	{"SUNK"},
	{"SELF"},	
	{"SINK"},	
	{"SCOT"},
	{"SHOT"},	
	{"SOAP"},	
	{"SLAB"},
	{"SEEK"},	
	{"SILK"},	
	{"SWAY"},
	{"SLOW"},	
	{"SHOE"},	
	{"SCAR"},
	{"SOFT"},	
	{"SLIM"},	
	{"SPOT"},
	{"SUCK"},	
	{"SOAR"},	
	{"SPIT"},
	{"THAT"},	
	{"TINY"},	
	{"TORE"},
	{"THIS"},	
	{"TONE"},	
	{"TAPS"},
	{"THEY"},	
	{"TECH"},	
	{"TILE"},
	{"THEM"},	
	{"TALL"},	
	{"TICK"},
	{"THEN"},	
	{"TOLL"},	
	{"TIDY"},
	{"TIME"},	
	{"TANK"},	
	{"TILT"},
	{"THAN"},	
	{"TALE"},	
	{"TACK"},
	{"TAKE"},	
	{"TWIN"},	
	{"TOMB"},
	{"TEAM"},	
	{"TILL"},	
	{"TAMP"},
	{"TOOK"},	
	{"TUNE"},	
	{"TUCK"},
	{"TERM"},	
	{"TUBE"},	
	{"TERN"},
	{"TOLD"},	
	{"TAIL"},	
	{"TUNA"},
	{"TURN"},	
	{"TIER"},	
	{"TUSK"},
	{"TYPE"},	
	{"TRAP"},	
	{"TAME"},
	{"TRUE"},	
	{"TEAR"},	
	{"TART"},
	{"TELL"},	
	{"TIDE"},	
	{"TAUT"},
	{"TEST"},	
	{"TORN"},	
	{"TANG"},
	{"THUS"},	
	{"TOPS"},	
	{"TRAM"},
	{"TALK"},	
	{"TAXI"},	
	{"TOTE"},
	{"TOWN"},	
	{"TRIM"},	
	{"TACT"},
	{"TEXT"},	
	{"TRIO"},	
	{"THUG"},
	{"TASK"},	
	{"TALC"},	
	{"TONG"},
	{"TOUR"},	
	{"TRAY"},	
	{"TOUT"},
	{"TOOL"},	
	{"TENT"},	
	{"TROT"},
	{"TRIP"},	
	{"TURF"},	
	{"THAW"},
	{"TEND"},	
	{"TEEN"},	
	{"TOAD"},
	{"THUD"},	
	{"TOSS"},	
	{"TYRE"},
	{"THIN"},	
	{"TIRE"},	
	{"TOIL"},
	{"TREE"},	
	{"TWIT"},	
	{"TEMP"},
	{"TAPE"},	
	{"TREK"},	
	{"TIFF"},
	{"TARP"},	
	{"TACO"},	
	{"TEAL"},
	{"UFOS"},
	{"UGLY"},
	{"UNIT"},
	{"UPON"},
	{"URGE"},
	{"URNS"},
	{"USED"},
	{"USER"},
	{"USES"},
	{"VAIN"},
	{"VANS"},
	{"VARY"},
	{"VASE"},
	{"VAST"},
	{"VEAL"},
	{"VEER"},
	{"VEIL"},
	{"VEIN"},
	{"VENT"},
	{"VERB"},
	{"VERY"},
	{"VEST"},
	{"VETO"},
	{"VETS"},
	{"VIAL"},
	{"VIBE"},
	{"VICE"},
	{"VILE"},
	{"VINE"},
	{"VLOG"},
	{"VOID"},
	{"VOLT"},
	{"VOTE"},
	{"VOWS"},
	{"WADE"},
	{"WADS"},
	{"WAFT"},
	{"WAGE"},
	{"WAIL"},
	{"WAIT"},
	{"WAKE"},
	{"WALK"},
	{"WALL"},
	{"WANE"},
	{"WANT"},
	{"WARD"},
	{"WARE"},
	{"WARM"},
	{"WARS"},
	{"WART"},
	{"WARY"},
	{"WASH"},
	{"WASP"},
	{"WAVE"},
	{"WAVY"},
	{"WAXY"},
	{"WAYS"},
	{"WEAK"},
	{"WEAN"},
	{"WEAR"},
	{"WEBS"},
	{"WEDS"},
	{"WEED"},
	{"WEEK"},
	{"WEEP"},
	{"WELD"},
	{"WELL"},
	{"WELT"},
	{"WENT"},
	{"WEPT"},
	{"WERE"},
	{"WEST"},
	{"WETS"},
	{"WHAT"},
	{"WHEN"},
	{"WHET"},
	{"WHEW"},
	{"WHEY"},
	{"WHIM"},
	{"WHIP"},
	{"WHIR"},
	{"WHOA"},
	{"WHOM"},
	{"WICK"},
	{"WIDE"},
	{"WIFE"},
	{"WIGS"},
	{"WILD"},
	{"WILL"},
	{"WILT"},
	{"WILY"},
	{"WIMP"},
	{"WIND"},
	{"WINE"},
	{"WING"},
	{"WINK"},
	{"WINS"},
	{"WIPE"},
	{"WIRE"},
	{"WIRY"},
	{"WISE"},
	{"WISH"},
	{"WISP"},
	{"WITH"},
	{"WOES"},
	{"WOGS"},
	{"WOKE"},
	{"WOOD"},
	{"WOOF"},
	{"WOOL"},
	{"WORD"},
	{"WORK"},
	{"WORM"},
	{"WRAP"},
	{"WREN"},
	{"XRAY"},
	{"XBOX"},
	{"YOUR"},	
	{"YELL"},	
	{"YUCA"},
	{"YAWN"},	
	{"YOKE"},	
	{"YEWS"},
	{"YEWS"},	
	{"YOWL"},	
	{"YAMS"},
	{"YEAR"},	
	{"YOLK"},	
	{"YULE"},
	{"YEAH"},	
	{"YANK"},	
	{"YAKS"},
	{"YARD"},	
	{"YORE"},	
	{"YOGI"},
	{"YARN"},	
	{"YUCK"},	
	{"YECH"},
	{"YUAN"},	
	{"YELP"},	
	{"YIPS"},
	{"YANG"},	
	{"YETI"},	
	{"YAPS"},
	{"YOGA"},	
	{"YURT"},	
	{"YAWP"},
	{"ZOOM"},
	{"ZEAL"},
	{"ZONE"},
	{"ZERO"},
	{"ZING"}
};

const char* sWord;
bool sDictionaryInitialized = false;
int letterIndices[LETTERS_IN_ALPHABET] = { 0 };
int secretLetterCount[LETTERS_IN_ALPHABET] = { 0 };

const char* GetSecretWord() {
	return sWord;
}

//Assigns an index to letterIndices for where
//each letter starts in the dictionary.
//i.e., letterIndices[0] ~ letterIndices['A' - 'A'] = 0,
//      letterIndices[1] ~ letterIndices['B' - 'A'] = 40, etc.
void preprocessDictionary() {
	char character = 'A';
	int index = 0;
	while (character <= 'Z') {
		bool found = false;
		while (!found) {
			if (character == AllWords[index][0]) {
				letterIndices[character - 'A'] = index;
				found = true;
			}
			index++;
		}
		character++;
	}
}

void preprocessWord() {
	//This sets up a letter count array that can be used
	//to determine how many of each letter exists in the word.
	memset(&secretLetterCount, 0, sizeof(secretLetterCount));
	for (auto i = 0; i < strlen(sWord); i++) {
		secretLetterCount[sWord[i] - 'A']++;
	}
}

namespace Dictionary {
	void Initialize() {
		srand(time(NULL));
		const int MaxWords = sizeof(AllWords)/sizeof(char*);
		int randIndex = rand() % MaxWords;
		sWord = AllWords[randIndex];
		preprocessWord();

		if (!sDictionaryInitialized) {
			preprocessDictionary();
			sDictionaryInitialized = true;
		}
	}

	const char* GetSecretWord() {
		return sWord;
	}

	const int* GetSecretWordStats() {
		return secretLetterCount;
	}

	bool InDictionary(std::string aString) {
		char startingChar = aString[0];
		int index = letterIndices[startingChar - 'A'];
		bool allowSearch = true;
		bool found = false;

		while (allowSearch && !found) {
			if (AllWords[index][0] != startingChar) {
				allowSearch = false;
			}
			else if(strcmp(aString.c_str(), AllWords[index]) == 0 ){
				found = true;
			}
			index++;
		}
		return found;
	}

	bool InWord(const char* aWord, char aLetter) {
		for (auto i = 0; i < strlen(aWord); i++) {
			if (aWord[i] == aLetter) {
				return true;
			}
		}

		return false;
	}
}