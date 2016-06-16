//
//  img4.h
//  img4tool
//
//  Created by tihmstar on 15.06.16.
//  Copyright © 2016 tihmstar. All rights reserved.
//

#ifndef img4_h
#define img4_h

#include <stdio.h>
#define LEN_XTND  0x80		/* Indefinite or long form */
typedef unsigned char byte;

//TagClass
#define kASN1TagClassUniversal       0
#define kASN1TagClassApplication     1
#define kASN1TagClassContextSpecific 2
#define kASN1TagClassPrivate        3

//primitive
#define kASN1Primitive  0
#define kASN1Contructed 1

//tagNumber
#define kASN1TagEnd_of_Content	0
#define kASN1TagBOOLEAN         1
#define kASN1TagINTEGER         2
#define kASN1TagBIT             3
#define kASN1TagOCTET           4
#define kASN1TagNULL            5
#define kASN1TagOBJECT          6
#define kASN1TagObject          7
#define kASN1TagEXTERNAL        8
#define kASN1TagREAL            9
#define kASN1TagENUMERATED      10 //0x0A
#define kASN1TagEMBEDDED        11 //0x0B
#define kASN1TagUTF8String      12 //0x0C
#define kASN1TagRELATIVE_OID	13 //0x0D
#define kASN1TagReserved        (14 | 15) //(0x0E | 0x0F)
#define kASN1TagSEQUENCE        16 //0x10
#define kASN1TagSET             17 //0x11
#define kASN1TagNumericString	18 //0x12
#define kASN1TagPrintableString	19 //0x13
#define kASN1TagT61String       20 //0x14
#define kASN1TagVideotexString	21 //0x15
#define kASN1TagIA5String       22 //0x16
#define kASN1TagUTCTime         23 //0x17
#define kASN1TagGeneralizedTime	24 //0x18
#define kASN1TagGraphicString	25 //0x19
#define kASN1TagVisibleString	26 //0x1A
#define kASN1TagGeneralString	27 //0x1B
#define kASN1TagUniversalString	28 //0x1C
#define kASN1TagCHARACTER       29 //0x1D
#define kASN1TagBMPString       30 //0x1E

typedef struct{
    byte tagNumber : 5;
    byte isConstructed : 1;
    byte tagClass : 2;
}t_asn1Tag;

typedef struct{
    byte len : 7;
    byte isLong : 1;
}t_asn1Length;

typedef struct{
    size_t dataLen;
    size_t sizeBytes;
} t_asn1ElemLen;

//asn1
t_asn1ElemLen asn1Len(char buf[4]);
char *ans1GetString(char *buf, char **outString, size_t *strlen);



//img4
void printIM4P(char *buf, size_t len);
int extractFileFromIM4P(char *buf, size_t len, char *dstFilename);
void printElemsInIMG4(char *buf, size_t buflen);

#endif /* img4_h */