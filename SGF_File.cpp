/*
 *  SGF_File.cpp
 *  GenSGFProperties
 *
 *  Created by Ken Friedenbach on 2/26/07.
 *  Copyright 2007 Ken Friedenbach. All rights reserved.
 *
 */

#include <cstddef>
#include "SGF_File.h"

const char * SGF_property_type_names[] =
{
	"SGF_no_prop_type",
	"SGF_root_prop_type",
	"SGF_setup_prop_type",
	"SGF_game_info_prop_type",
	"SGF_move_prop_type",
	NULL
};

const char * SGF_qualifier_type_names[] =
{
	"SGF_no_qual",
	"SGF_inherit",
	"SGF_LOA_only",
	"SGF_Go_only",
	"SGC_extension",
	NULL
};



const char * SGF_note_type_names[] =
{
	"SGF_std",
	"SGFF4_new",
	"SGFF4_changed",
	"SGF_non_std",
	NULL
};

const char * SGF_value_type_names[] =
{
	"SGF_no_value",
	// text values 
	"SGF_simpletext",
	"SGF_text",
	// color values 
	"SGF_color",
	// number values 
	"SGF_number",
	"SGF_ST_number",
	"SGF_FF_number",
	"SGF_game_number",
	"SGF_double",
	"SGF_real",
	// point, etc. 
	"SGF_point",
	"SGF_move",
	"SGF_stone",
	// lists of point, etc. 
	"SGF_point_list",
	"SGF_point_elist",
	"SGF_stone_list",
	// composed values 
	"SGF_comp_simtxt",
	"SGF_num_or_comp_num",
	"SGF_none_or_comp_num_simtxt",
	// lists of composed values 
	"SGF_list_comp_point",
	"SGF_list_comp_point_simtxt",
	// SGC extension 
	"SGC_compressed_list_point",
	NULL
};

const char * SGF_RU_type_names[] =
{
	"no RU value",	// SGF_no_RU, 
	"AGA",			// SGF_AGA_RU,		rules of the American Go Association
	"Chinese",		// SGF_CHINESE_RU,
	"Ing Goe",		// SGF_ING_GOE_RU,	the Ing rules of Goe
	"Japanese",		// SGF_JAPANESE_RU,	the Nihon Ki-in rule set
	"NZ",			// SGF_NZ_RU,		New Zealand rules
	"Old Chinese",	// SGF_OLD_CHINESE_RU,	from GoGoD
	"Old Japanese", // SGF_OLD_JAPANESE_RU,	from GoGoD
	"Relay Go",		// SGF_RELAY_GO_RU,		from GoGoD
	"Pair Go",		// SGF_PAIR_GO_RU,		from GoGoD
	"Team Go",		// SGF_TEAM_GO_RU,		from GoGoD
	"Sunjang",		// SGF_SUNJANG_RU,		from GoGoD
	"Tang",			// SGF_TANG_RU,			from GoGoD (Japanese + group tax)
	"Uchikomi",		// SGF_UCHIKOMI_RU,		from GoGoD
	"W gives komi",	// SGF_W_GIVES_KOMI_RU,	from GoGoD
	"W wins jigo",	// SGF_W_WINS_JIGO_RU,	from GoGoD
	"unknown RU value", // SGF_unkwn_RU
	NULL
};

const char * SGF_RE_type_names[] =
{
	"no RE value",
	"B+",			// SGF_B_PLUS_RE
	"B+F",			// SGF_B_PLUS_FORFEIT_RE
	"B+n",			// SGF_B_PLUS_NUM_RE
	"B+R",			// SGF_B_PLUS_RESIGN_RE
	"B+T",			// SGF_B_PLUS_TIME_RE
	"Draw",			// SGF_DRAW_RE
	"Left unfinished",	// SGF_Unfinished_RE
	"Void",			// SGF_VOID_RE
	"?",			// SGF_UNKNOWN_RE
	"W+",			// SGF_W_PLUS_RE
	"W+F",			// SGF_W_PLUS_FORFEIT_RE
	"W+n",			// SGF_W_PLUS_NUM_RE
	"W+R",			// SGF_W_PLUS_RESIGN_RE
	"W+T",			// SGF_W_PLUS_TIME_RE
	"unknown RE value",
	NULL
};

const char * SGF_Rank_type_names[] =
{
	"no Rank value", // SGF_NO_Rank_value
	"Expectant Official", // SGF_EXPECTANT_OFFICIAL,
	"Meijin", // SGF_MEIJIN,
	"Guoshou", // SGF_GUOSHOU,
	"9p", // SGF_9DAN_PRO,
	"8p", // SGF_8DAN_PRO,
	"7p", // SGF_7DAN_PRO,
	"6p", // SGF_6DAN_PRO,
	"5p", // SGF_5DAN_PRO,
	"4p", // SGF_4DAN_PRO,
	"3p", // SGF_3DAN_PRO,
	"2p", // SGF_2DAN_PRO,
	"1p", // SGF_1DAN_PRO,
	"9d", // SGF_9DAN,
	"8d", // SGF_8DAN,
	"7d", // SGF_7DAN,
	"6d", // SGF_6DAN,
	"5d", // SGF_5DAN,
	"4d", // SGF_4DAN,
	"3d", // SGF_3DAN,
	"2d", // SGF_2DAN,
	"1d", // SGF_1DAN,
	"9d ama", // SGF_9DAN_AMA,
	"8d ama", // SGF_8DAN_AMA,
	"7d ama", // SGF_7DAN_AMA,
	"6d ama", // SGF_6DAN_AMA,
	"5d ama", // SGF_5DAN_AMA,
	"4d ama", // SGF_4DAN_AMA,
	"3d ama", // SGF_3DAN_AMA,
	"2d ama", // SGF_2DAN_AMA,
	"1d ama", // SGF_1DAN_AMA,
	"1k", // SGF_1KYU,
	"2k", // SGF_2KYU,
	"3k", // SGF_3KYU,
	"4k", // SGF_4KYU,
	"5k", // SGF_5KYU,
	"6k", // SGF_6KYU,
	"7k", // SGF_7KYU,
	"8k", // SGF_8KYU,
	"9k", // SGF_9KYU,
	"10k", // SGF_10KYU,
	"11k", // SGF_11KYU,
	"12k", // SGF_12KYU,
	"13k", // SGF_13KYU,
	"14k", // SGF_14KYU,
	"15k", // SGF_15KYU,
	"16k", // SGF_16KYU,
	"17k", // SGF_17KYU,
	"18k", // SGF_18KYU,
	"19k", // SGF_19KYU,
	"20k", // SGF_20KYU,
	"21k", // SGF_21KYU,
	"22k", // SGF_22KYU,
	"23k", // SGF_23KYU,
	"24k", // SGF_24KYU,
	"25k", // SGF_25KYU,
	"26k", // SGF_26KYU,
	"27k", // SGF_27KYU,
	"28k", // SGF_28KYU,
	"29k", // SGF_29KYU,
	"30k", // SGF_30KYU,
	"31k", // SGF_31KYU,
	"32k", // SGF_32KYU,
	"33k", // SGF_33KYU,
	"34k", // SGF_34KYU,
	"35k", // SGF_35KYU,
	"unknown rank", // SGF_UNKN_RANK_VALUE
	NULL
};

const char * SGF_US_type_names[] =
{
	"no user value",	// SGF_NO_US_value,
	"GoGoD",			// SGF_GoGoD_value,
	"GoGoD95",			// SGF_GoGoD95_value,
	"unknown user",		// SGF_UNKN_US_VALUE
NULL
};

const char * SGF_OH_type_names[] =
{
	"no OH value",	// 	SGF_NO_OH_VALUE,

	"2",	// SGF_2_OH_VALUE,
	"-2-",	// SGF_D_2_D_OH_VALUE,

	"3",	// SGF_3_OH_VALUE
	"-3-",	// SGF_D_3_D_OH_VALUE

	"4",	// SGF_4_OH_VALUE
	"-4-",	// SGF_D_4_D_OH_VALUE

	"5",	// SGF_5_OH_VALUE
	"-5-",	// SGF_D_5_OH_D_VALUE

	"6",	// SGF_6_OH_VALUE
	"-6-",	// SGF_D_6_D_OH_VALUE

	"7",	// SGF_7_OH_VALUE
	"-7-",	// SGF_D_7_D_OH_VALUE

	"8",	// SGF_8_OH_VALUE
	"-8-",	// SGF_D_8_D_OH_VALUE

	"9",	// SGF_9_OH_VALUE
	"-9-",	// SGF_D_9_D_OH_VALUE

	"11",	// SGF_11_OH_VALUE
	"-11-",	// SGF_D_11_D_OH_VALUE

	"B",	// SGF_B_OH_VALUE
	"-B-",	// SGF_D_B_D_OH_VALUE
// ERROR? (Count = 2)	"-B",	// SGF_D_B_OH_VALUE
// ERROR? (Count = 1)	"First move",	// SGF_FIRST_MOVE_OH_VALUE

	"BW",	// SGF_B_W_OH_VALUE
	"B-W",	// SGF_B_D_W_OH_VALUE

	"BWB",	// SGF_B_W_B_OH_VALUE 
	"B-W-B",	// SGF_B_D_W_D_B_OH_VALUE 
	"BBW",	// SGF_B_B_W_OH_VALUE
	"B-B-W",	// SGF_B_D_B_D_W_OH_VALUE

	"(B)BW",	// SGF_LPar_B_RPar_B_W_OH_VALUE
	"(B)-B-W",	// SGF_LPar_B_RPar_D_B_D_W_OH_VALUE

	"B(B)W",	// SGF_B_LPar_B_RPar_W_OH_VALUE
	"B-(B)-W",	// SGF_B_D_LPar_B_RPar_D_W_OH_VALUE
// ERROR? (Count = 1)	"B{B}W",	// SGF_B_LBrc_B_RBrc_W_OH_VALUE
	"BB(W)",	// SGF_B_B_LPar_W_RPar_OH_VALUE
	"B-B-(W)",	// SGF_B_D_B_D_LPar_W_RPar_OH_VALUE
// Error? (Count = 1)	"(B)-B-B",	// SGF_LPar_B_RPar_D_B_D_B_OH_VALUE
	"(B)WB",	// SGF_LPar_B_RPar_W_B_OH_VALUE
	"(B)-W-B",	// SGF_LPar_B_RPar_D_W_D_B_OH_VALUE
	"B(W)B", // SGF_B_LPar_W_RPar_B_OH_VALUE
	"B-(W)-B",	// SGF_B_D_LPar_W_RPar_D_B_OH_VALUE
	"B-{W}-B",	// SGF_B_D_LBrc_W_RBrc_D_B_OH_VALUE
	"BW(B)",	// SGF_B_W_LPar_B_RPar_OH_VALUE
	"B-W-(B)",	// SGF_B_D_W_D_LPar_B_RPar_OH_VALUE

	"B-2-B",	// SGF_B_D_2_D_B_OH_VALUE
	"(B)-2-B",	// SGF_LPar_B_RPar_D_2_D_B_OH_VALUE
	"(B)2B",	// SGF_LPar_B_RPar_2_B_OH_VALUE
	"{B}2B",	// SGF_LBrc_B_RBrc_2_B_OH_VALUE
	"B-(2)-B",	// SGF_B_D_LPar_2_RPar_D_B_OH_VALUE
	"B(2)B",	// SGF_B_LPar_2_RPar_B_OH_VALUE
	"B-2-(B)",	// SGF_B_D_2_D_LPar_B_RPar_OH_VALUE
	"BB(2)",	// SGF_B_B_LPar_B_RPar_OH_VALUE

	"2B2",	// SGF_2_B_2_OH_VALUE
	"2-B-2",	// SGF_2_D_B_D_2_OH_VALUE
	"(2)B2",	// SGF_LPar_2_RPar_B_2_OH_VALUE
	"{2}B2",	// SGF_LBrc_2_RBrc_B_2_OH_VALUE
	"(2)-B-2",	// SGF_LPar_2_RPar_D_B_D_2_OH_VALUE
	"2-(B)-2",	// SGF_2_D_LPar_B_RPar_D_2_OH_VALUE
	"2-2-(B)",	// SGF_2_D_2_D_LPar_B_RPar_OH_VALUE
	"B-(2)-2",	// SGF_B_D_LPar_2_RPar_D_2_OH_VALUE
	"(B)-2-2",	// SGF_LPar_B_RPar_D_2_D_2_OH_VALUE

// Error? (Count = 21)
	"{B}-W-B",	// SGF_LBrc_B_RBrc_D_W_D_B_OH_VALUE


	"B2",	// SGF_B_2_OH_VALUE
	"B-2",	// SGF_B_D_2_OH_VALUE
	"2B",	// SGF_2_B_OH_VALUE
	"2-B",	// SGF_2_D_B_OH_VALUE

	"(B)2",	// SGF_LPar_B_RPar_2_OH_VALUE
	"(B)-2",	// SGF_LPar_B_RPar_D_2_OH_VALUE
// Error? (Count = 8)	"{B}-2",	// SGF_LBrc_B_RBrc_D_2_OH_VALUE
	"B(2)",	// SGF_B_LPar_2_RPar_OH_VALUE
	"B-(2)",	// SGF_B_D_LPar_2_RPar_OH_VALUE
// Error? (Count = 6)	"B-{2}",	// SGF_B_D_LBrc_2_RBrc_OH_VALUE
	"2(B)",	// SGF_2_LPar_B_RPar_OH_VALUE
	"2-(B)",	// SGF_2_D_LPar_B_RPar_OH_VALUE
	"(2)B",	// SGF_LPar_2_RPar_B_OH_VALUE

	"(2)-3-2",	// SGF_LPAR_2_RPAR_D_3_D_2_OH_VALUE
	"2-(3)-2",	// SGF_2_D_LPAR_3_RPAR_D_2_OH_VALUE
	"2-3-(2)",	// SGF_2_D_3_D_LPAR_2_RPAR_OH_VALUE

	"2-3-3",	// SGF_2_D_3_D_3_OH_VALUE
	"(3)-2-3",	// SGF_LPAR_3_RPAR_D_2_D_3_OH_VALUE

	"(2)3",	// SGF_LPAR_2_RPAR_3_OH_VALUE
	"(2)-3",	// SGF_LPAR_2_RPAR_D_3_OH_VALUE
	"2(3)",	// SGF_2_LPAR_3_RPAR_OH_VALUE
	"2-(3)",	// SGF_2_D_LPAR_3_RPAR_OH_VALUE
	"3(2)",	// SGF_3_LPAR_2_RPAR_OH_VALUE
	"3-(2)",	// SGF_3_D_LPAR_2_RPAR_OH_VALUE
	"(3)2",	// SGF_LPAR_3_RPAR_2_OH_VALUE
	"(3)-2",	// SGF_LPAR_3_RPAR_D_2_OH_VALUE

	"(3)4",	// SGF_LPAR_3_RPAR_4_OH_VALUE
	"(3)-4",	// SGF_LPAR_3_RPAR_D_4_OH_VALUE
	"3(4)",	// SGF_3_LPAR_4_RPAR_OH_VALUE
	"3-(4)",	// SGF_3_D_LPAR_4_RPAR_OH_VALUE

	"unknown OH value",		// SGF_UNKN_OH_VALUE
	NULL
};

sgfPropDef::sgfPropDef( const char * id, 
							t_SGF_note pnote, 
							const char * desc,  
							t_SGF_property ptype,
							t_SGF_qualifier qual, 
							t_SGF_value vtyp
)	:	property_note(pnote), property_ID(id), descripton(desc),
		property_type(ptype), qualifier(qual), value_type(vtyp)
	{ }

#if GENERATING_SGF_HEADER == 0
// The conditional compilation does not stop processing of #include
// So for "cold bootstraping" the following two lines need to be commented out
// Then they can be restored for second build.
#include "SGF_Property_gen.h"

int Num_SGF_Properties = sizeof(the_SGF_Properties)/sizeof(sgfPropDef *);
#endif
