/*
 *  ReadMe.txt
 *  GenSGFProperties
 *
 *  Copyright 2007-2014 Ken Friedenbach. All rights reserved.
 *
 */

Description:

	This program generates the standard FF[4] SGF Properties, 
	and an address array in sorted order, for binary search.

	The program reads a data file:
		SGF_Properties_Spec.txt
	which was derived from the webpage:
		http://www.red-bean.com/sgf/proplist.html
	and writes a header file:
		SGF_Property_gen.h

	The project source files:
		SGF_File.h
		SGF_File.cpp
	are used with the generated header file, in projects such as JOSEKI_LIB.
	
	Currently, the non-standard FF[4] nodes supported are:
		S	Sequence		compressed list of point (from Many Faces?)
		OH	Old Handicap	text (from GoGoD)
		WB, WC, WO, WW 
			Win counts		see below

	Do FF[5] properties need to be added?
        So far, no reason found to do so.

Status: January 1, 2014

    Moved in abst-hier workspace, for upload to gitHub.com/Ken1JF
    Also cleaned up code to correct errors confusing size_t and int.
    
Status: October 5, 2009

	Added support for t
		WC "Win Continue" the directory and file name continuation.
	
Status: October 4, 2009

	Added support for the library count properties written by JOSEKI_LIB project.
	
		WB "Wins Black" the number of games Black won.
		WW "Wins White" the number of games White won.
		WO "Wins Other" the number of games with "other" results. (draw, unfinished, unknown, etc.)
		
		While trying to add these properties, found out that the program does not handle tab
		characters between the Description field and the type field. Resulted in error
		messages such as:
			***ERROR*** no property type: ve             number
		Aspects of the problem:
		1. In order to create a file that causes this problem, the File Information button,
		"Editor uses tabs" must be checked. (Otherwise, tabs are replaced with blanks on save.)
		2. Initially, the ERROR message occured on the first pass. But after making a change to
		cause the error, the message occurs on the second pass. (This suggests that the program
		is reading two different versions of the editted file. A cached version that still has
		all blanks, and a saved version with some tabs???)
				 
Status: July 16, 2008

	Notes on Properties and Property values:

		RU "Rules" - there is no standard for representing all rulesets.
			GoGoD uses "Tang (Japanese + group tax)", with some variations in punctuation.
			GoGoD uses "Old Chinese"
			GoGoD uses "Relay Go"
			TODO: complete a list of "standard" names, and logic to recognize variations.

		PL "Player to play" - the FF[3] Specification at:
				http://www.red-bean.com/sgf/ff1_3/ff3.html
			has a peculiarity which in documented in the summary of changes at:
				http://www.red-bean.com/sgf/changes.html

			Kogo's Joseki Dictionary (FF[3]) from:
				http://waterfire.us/joseki.htm
			and the earlier version from GoGoD use PL[1] and PL[2] throughout the file.

			In most places in the FF[3] spec, PL is specified as:
				"PL": player to play first PL[color]
			and color is specified:
				Color = ("B" | "W").
			But in the summary at the bottom a conflicting specification is given:
				PL     Player whose turn it is      PL[color], 1 = Black, 2 = White
			Thus there appear to be two sets for the PL property allowed under FF[3].
			
			This appears to be a known problem, and is handled by
			both Goban (version 3.2.12) from 
				http://www.sente.ch/
			and CGoban (version 3.3.22) from
				http://www.gokgs.com/
			They translate 1 and 2 into B and W when then writes a changed version as FF[4].

		The mixing of PL, AW, and AB properties with move properties is allowed under FF[3],
			and used extensively in Kogo's Joseki Dictionary, but is not allowed under FF[4].
			It appears to be handled correctly by Goban (version 3.2.12), 
			but generates warnings and the removal of some properties by CGoban (version 3.3.22).
		
Status: June 10, 2008

	Added support for the OH (Old Handicap) property introduced by GoGoD.

Status May, 2007

	Include the SGC compressed Sequence (S) property.

	Currently, the program has a 2-char limit on property name sizes. The five
	character KGSxx properties can be added with support from the qualifier.

	