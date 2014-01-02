/*
 *  SGF_File.h
 *  GenSGFProperties
 *
 *  Created by Ken Friedenbach on 2/26/07.
 *  Copyright 2007-2014 Ken Friedenbach. All rights reserved.
 *
 */
 
#ifndef _SGF_FILE_H_
#define _SGF_FILE_H_

typedef enum SGF_property_type
{
	SGF_no_prop_type, // - => none
	SGF_root_prop_type,
	SGF_setup_prop_type,
	SGF_game_info_prop_type,
	SGF_move_prop_type
} t_SGF_property;
extern const char * SGF_property_type_names[];

typedef enum SGF_qualifier_type
{
	SGF_no_qual,
	SGF_inherit,
	SGF_LOA_only,
	SGF_Go_only,
	SGC_extension
} t_SGF_qualifier;
extern const char * SGF_qualifier_type_names[];

typedef enum SGF_note_type 
{
	SGF_std,
	SGFF4_new,
	SGFF4_changed,
	SGF_non_std
} t_SGF_note;
extern const char * SGF_note_type_names[];

typedef enum SGF_value_type 
{
	SGF_no_value,
	// text values 
	SGF_simpletext,
	SGF_text,
	// color values 
	SGF_color,
	// number values 
	SGF_number,
	SGF_ST_number,
	SGF_FF_number,
	SGF_game_number,
	SGF_double,
	SGF_real,
	// point, etc. 
	SGF_point,
	SGF_move,
	SGF_stone,
	// lists of point, etc. 
	SGF_point_list,
	SGF_point_elist,
	SGF_stone_list,
	// composed values 
	SGF_comp_simtxt,
	SGF_num_or_comp_num,
	SGF_none_or_comp_num_simtxt,
	// lists of composed values 
	SGF_list_comp_point,
	SGF_list_comp_point_simtxt,
	// SGC extension 
	SGC_compressed_list_point
} t_SGF_value;
extern const char * SGF_value_type_names[];

typedef enum SGF_RU_type
{
	SGF_no_RU,
	SGF_AGA_RU,
	SGF_CHINESE_RU,
	SGF_ING_GOE_RU,
	SGF_JAPANESE_RU,
	SGF_NZ_RU,
	SGF_OLD_CHINESE_RU,
	SGF_OLD_JAPANESE_RU,
	SGF_RELAY_GO_RU,
	SGF_PAIR_GO_RU,
	SGF_TEAM_GO_RU,
	SGF_SUNJANG_RU,
	SGF_TANG_RU,
	SGF_UCHIKOMI_RU,
	SGF_W_GIVES_KOMI_RU,
	SGF_W_WINS_JIGO_RU,
	SGF_unkwn_RU
} SGF_RU_type_t;
#define MAX_RU_TYPE	((int)SGF_unkwn_RU)
extern const char * SGF_RU_type_names[];

typedef enum SGF_RE_type
{
	SGF_no_RE,
	SGF_B_PLUS_RE,
	SGF_B_PLUS_FORFEIT_RE,
	SGF_B_PLUS_NUM_RE,
	SGF_B_PLUS_RESIGN_RE,
	SGF_B_PLUS_TIME_RE,
	SGF_DRAW_RE,
	SGF_UNFINISHED_RE,
	SGF_VOID_RE,
	SGF_UNKNOWN_RE,
	SGF_W_PLUS_RE,
	SGF_W_PLUS_FORFEIT_RE,
	SGF_W_PLUS_NUM_RE,
	SGF_W_PLUS_RESIGN_RE,
	SGF_W_PLUS_TIME_RE,
	SGF_unkwn_RE
} SGF_RE_type_t;
#define MAX_RE_TYPE	((int)SGF_unkwn_RE)
extern const char * SGF_RE_type_names[];

typedef enum SGF_Rank_type
{
	SGF_NO_Rank_value,
	SGF_EXPECTANT_OFFICIAL,
	SGF_MEIJIN,
	SGF_GUOSHOU,
	SGF_9DAN_PRO,
	SGF_8DAN_PRO,
	SGF_7DAN_PRO,
	SGF_6DAN_PRO,
	SGF_5DAN_PRO,
	SGF_4DAN_PRO,
	SGF_3DAN_PRO,
	SGF_2DAN_PRO,
	SGF_1DAN_PRO,
	SGF_9DAN,
	SGF_8DAN,
	SGF_7DAN,
	SGF_6DAN,
	SGF_5DAN,
	SGF_4DAN,
	SGF_3DAN,
	SGF_2DAN,
	SGF_1DAN,
	SGF_9DAN_AMA,
	SGF_8DAN_AMA,
	SGF_7DAN_AMA,
	SGF_6DAN_AMA,
	SGF_5DAN_AMA,
	SGF_4DAN_AMA,
	SGF_3DAN_AMA,
	SGF_2DAN_AMA,
	SGF_1DAN_AMA,
	SGF_1KYU,
	SGF_2KYU,
	SGF_3KYU,
	SGF_4KYU,
	SGF_5KYU,
	SGF_6KYU,
	SGF_7KYU,
	SGF_8KYU,
	SGF_9KYU,
	SGF_10KYU,
	SGF_11KYU,
	SGF_12KYU,
	SGF_13KYU,
	SGF_14KYU,
	SGF_15KYU,
	SGF_16KYU,
	SGF_17KYU,
	SGF_18KYU,
	SGF_19KYU,
	SGF_20KYU,
	SGF_21KYU,
	SGF_22KYU,
	SGF_23KYU,
	SGF_24KYU,
	SGF_25KYU,
	SGF_26KYU,
	SGF_27KYU,
	SGF_28KYU,
	SGF_29KYU,
	SGF_30KYU,
	SGF_31KYU,
	SGF_32KYU,
	SGF_33KYU,
	SGF_34KYU,
	SGF_35KYU,
	SGF_UNKN_RANK_VALUE
} SGF_Rank_type_t;
#define MAX_Rank_TYPE	((int)SGF_UNKN_RANK_VALUE)
extern const char * SGF_Rank_type_names[];

typedef enum SGF_OH_type
{
	SGF_NO_OH_VALUE,

	SGF_2_OH_VALUE,
	SGF_D_2_D_OH_VALUE,

	SGF_3_OH_VALUE,
	SGF_D_3_D_OH_VALUE,

	SGF_4_OH_VALUE,
	SGF_D_4_D_OH_VALUE,

	SGF_5_OH_VALUE,
	SGF_D_5_OH_D_VALUE,

	SGF_6_OH_VALUE,
	SGF_D_6_D_OH_VALUE,

	SGF_7_OH_VALUE,
	SGF_D_7_D_OH_VALUE,

	SGF_8_OH_VALUE,
	SGF_D_8_D_OH_VALUE,

	SGF_9_OH_VALUE,
	SGF_D_9_D_OH_VALUE,

	SGF_11_OH_VALUE,
	SGF_D_11_D_OH_VALUE,

	SGF_B_OH_VALUE,
	SGF_D_B_D_OH_VALUE,
// ERROR? (Count = 2)	SGF_D_B_OH_VALUE,
// ERROR? (Count = 1)	SGF_FIRST_MOVE_OH_VALUE,

	SGF_B_W_OH_VALUE,
	SGF_B_D_W_OH_VALUE,
	
	SGF_B_W_B_OH_VALUE,
	SGF_B_D_W_D_B_OH_VALUE,
	SGF_B_B_W_OH_VALUE,
	SGF_B_D_B_D_W_OH_VALUE,
	
	SGF_LPar_B_RPar_B_W_OH_VALUE,
	SGF_LPar_B_RPar_D_B_D_W_OH_VALUE,

	SGF_B_LPar_B_RPar_W_OH_VALUE,
	SGF_B_D_LPar_B_RPar_D_W_OH_VALUE,
// ERROR? (Count = 1)		SGF_B_LBrc_B_RBrc_W_OH_VALUE,
	SGF_B_B_LPar_W_RPar_OH_VALUE,
	SGF_B_D_B_D_LPar_W_RPar_OH_VALUE,
// ERROR? (Count = 1)	SGF_LPar_B_RPar_D_B_D_B_OH_VALUE,
	SGF_LPar_B_RPar_W_B_OH_VALUE,
	SGF_LPar_B_RPar_D_W_D_B_OH_VALUE,
	SGF_B_LPar_W_RPar_B_OH_VALUE,
	SGF_B_D_LPar_W_RPar_D_B_OH_VALUE,
	SGF_B_D_LBrc_W_RBrc_D_B_OH_VALUE,
	SGF_B_W_LPar_B_RPar_OH_VALUE,
	SGF_B_D_W_D_LPar_B_RPar_OH_VALUE,
	
	SGF_B_D_2_D_B_OH_VALUE,
	SGF_LPar_B_RPar_D_2_D_B_OH_VALUE,
	SGF_LPar_B_RPar_2_B_OH_VALUE,
	SGF_LBrc_B_RBrc_2_B_OH_VALUE,
	SGF_B_D_LPar_2_RPar_D_B_OH_VALUE,
	SGF_B_LPar_2_RPar_B_OH_VALUE,
	SGF_B_D_2_D_LPar_B_RPar_OH_VALUE,
	SGF_B_B_LPar_B_RPar_OH_VALUE,

	SGF_2_B_2_OH_VALUE,
	SGF_2_D_B_D_2_OH_VALUE,
	SGF_LPar_2_RPar_B_2_OH_VALUE,
	SGF_LBrc_2_RBrc_B_2_OH_VALUE,
	SGF_LPar_2_RPar_D_B_D_2_OH_VALUE,
	SGF_2_D_LPar_B_RPar_D_2_OH_VALUE,
	SGF_2_D_2_D_LPar_B_RPar_OH_VALUE,
	SGF_B_D_LPar_2_RPar_D_2_OH_VALUE,
	SGF_LPar_B_RPar_D_2_D_2_OH_VALUE,
	
// Error? (Count = 21)
	SGF_LBrc_B_RBrc_D_W_D_B_OH_VALUE,

	
	SGF_B_2_OH_VALUE,
	SGF_B_D_2_OH_VALUE,
	SGF_2_B_OH_VALUE,
	SGF_2_D_B_OH_VALUE,

	SGF_LPar_B_RPar_2_OH_VALUE,
	SGF_LPar_B_RPar_D_2_OH_VALUE,
// Error? (Count = 8)	SGF_LBrc_B_RBrc_D_2_OH_VALUE,
	SGF_B_LPar_2_RPar_OH_VALUE,
	SGF_B_D_LPar_2_RPar_OH_VALUE,
// Error? (Count = 6)	SGF_B_D_LBrc_2_RBrc_OH_VALUE,
	SGF_2_LPar_B_RPar_OH_VALUE,
	SGF_2_D_LPar_B_RPar_OH_VALUE,
	SGF_LPar_2_RPar_B_OH_VALUE,

	SGF_LPAR_2_RPAR_D_3_D_2_OH_VALUE,
	SGF_2_D_LPAR_3_RPAR_D_2_OH_VALUE,
	SGF_2_D_3_D_LPAR_2_RPAR_OH_VALUE,
	
	SGF_2_D_3_D_3_OH_VALUE,
	SGF_LPAR_3_RPAR_D_2_D_3_OH_VALUE,

	SGF_LPAR_2_RPAR_3_OH_VALUE,
	SGF_LPAR_2_RPAR_D_3_OH_VALUE,
	SGF_2_LPAR_3_RPAR_OH_VALUE,
	SGF_2_D_LPAR_3_RPAR_OH_VALUE,
	SGF_3_LPAR_2_RPAR_OH_VALUE,
	SGF_3_D_LPAR_2_RPAR_OH_VALUE,
	SGF_LPAR_3_RPAR_2_OH_VALUE,
	SGF_LPAR_3_RPAR_D_2_OH_VALUE,
	
	SGF_LPAR_3_RPAR_4_OH_VALUE,
	SGF_LPAR_3_RPAR_D_4_OH_VALUE,
	SGF_3_LPAR_4_RPAR_OH_VALUE,
	SGF_3_D_LPAR_4_RPAR_OH_VALUE,

	SGF_UNKN_OH_VALUE
} SGF_OH_type_t;
#define MAX_OH_TYPE ((int) SGF_UNKN_OH_VALUE)
extern const char * SGF_OH_type_names[];

typedef enum SGF_US_type
{
	SGF_NO_US_value,
	SGF_GoGoD_value,
	SGF_GoGoD95_value,
	SGF_UNKN_US_VALUE
} SGF_US_type_t;
#define MAX_US_TYPE	((int)SGF_UNKN_US_VALUE)
extern const char * SGF_US_type_names[];

class sgfPropDef // : public GOL_symbol
{
	public:
		sgfPropDef( const char * id, 
					t_SGF_note pnote, 
					const char * desc,  
					t_SGF_property ptype,
					t_SGF_qualifier qual, 
					t_SGF_value vtyp);
		const char * get_ID(void) { return property_ID; };
	private:
		t_SGF_note		property_note;
		const char *			property_ID;
		const char *			descripton;
		t_SGF_property			property_type;
		t_SGF_qualifier			qualifier;
		t_SGF_value				value_type;
};

extern sgfPropDef * the_SGF_Properties[];
extern int Num_SGF_Properties;

extern sgfPropDef SGF_prop_AB;
extern sgfPropDef SGF_prop_AE;
extern sgfPropDef SGF_prop_AN;
extern sgfPropDef SGF_prop_AP;
extern sgfPropDef SGF_prop_AR;
extern sgfPropDef SGF_prop_AS;
extern sgfPropDef SGF_prop_AW;
extern sgfPropDef SGF_prop_B;
extern sgfPropDef SGF_prop_BL;
extern sgfPropDef SGF_prop_BM;
extern sgfPropDef SGF_prop_BR;
extern sgfPropDef SGF_prop_BT;
extern sgfPropDef SGF_prop_C;
extern sgfPropDef SGF_prop_CA;
extern sgfPropDef SGF_prop_CP;
extern sgfPropDef SGF_prop_CR;
extern sgfPropDef SGF_prop_DD;
extern sgfPropDef SGF_prop_DM;
extern sgfPropDef SGF_prop_DO;
extern sgfPropDef SGF_prop_DT;
extern sgfPropDef SGF_prop_EV;
extern sgfPropDef SGF_prop_FF;
extern sgfPropDef SGF_prop_FG;
extern sgfPropDef SGF_prop_GB;
extern sgfPropDef SGF_prop_GC;
extern sgfPropDef SGF_prop_GM;
extern sgfPropDef SGF_prop_GN;
extern sgfPropDef SGF_prop_GW;
extern sgfPropDef SGF_prop_HA;
extern sgfPropDef SGF_prop_HO;
extern sgfPropDef SGF_prop_IP;
extern sgfPropDef SGF_prop_IT;
extern sgfPropDef SGF_prop_IY;
extern sgfPropDef SGF_prop_KM;
extern sgfPropDef SGF_prop_KO;
extern sgfPropDef SGF_prop_LB;
extern sgfPropDef SGF_prop_LN;
extern sgfPropDef SGF_prop_MA;
extern sgfPropDef SGF_prop_MN;
extern sgfPropDef SGF_prop_N;
extern sgfPropDef SGF_prop_OB;
extern sgfPropDef SGF_prop_ON;
extern sgfPropDef SGF_prop_OT;
extern sgfPropDef SGF_prop_OW;
extern sgfPropDef SGF_prop_PB;
extern sgfPropDef SGF_prop_PC;
extern sgfPropDef SGF_prop_PL;
extern sgfPropDef SGF_prop_PM;
extern sgfPropDef SGF_prop_PW;
extern sgfPropDef SGF_prop_RE;
extern sgfPropDef SGF_prop_RO;
extern sgfPropDef SGF_prop_RU;
extern sgfPropDef SGF_prop_SE;
extern sgfPropDef SGF_prop_SL;
extern sgfPropDef SGF_prop_S ;
extern sgfPropDef SGF_prop_SQ;
extern sgfPropDef SGF_prop_ST;
extern sgfPropDef SGF_prop_SU;
extern sgfPropDef SGF_prop_SZ;
extern sgfPropDef SGF_prop_TB;
extern sgfPropDef SGF_prop_TE;
extern sgfPropDef SGF_prop_TM;
extern sgfPropDef SGF_prop_TR;
extern sgfPropDef SGF_prop_TW;
extern sgfPropDef SGF_prop_UC;
extern sgfPropDef SGF_prop_US;
extern sgfPropDef SGF_prop_V;
extern sgfPropDef SGF_prop_VW;
extern sgfPropDef SGF_prop_W ;
extern sgfPropDef SGF_prop_WB;
extern sgfPropDef SGF_prop_WC;
extern sgfPropDef SGF_prop_WL;
extern sgfPropDef SGF_prop_WO;
extern sgfPropDef SGF_prop_WR;
extern sgfPropDef SGF_prop_WT;
extern sgfPropDef SGF_prop_WW;

#endif
