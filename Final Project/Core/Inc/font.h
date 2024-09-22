/*
 * font.h
 *
 *  Created on: Sep 17, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_FONT_H_
#define INC_FONT_H_
#include"main.h"
#include "string.h"

typedef struct {
	uint8_t FontWidth;    /*!< Font width in pixels */
	uint8_t FontHeight;   /*!< Font height in pixels */
	const uint16_t *data; /*!< Pointer to data font data array */
} FontDef_t ;
extern  FontDef_t myFont;
/**
 * @brief  String length and height
 */
typedef struct{
	uint16_t Length;      /*!< String length in units of pixels */
	uint16_t Height;      /*!< String height in units of pixels */
}  FONTS_SIZE_t;

extern FontDef_t Font_7x10;

/**
 * @brief  11 x 18 pixels font size structure
 */
extern FontDef_t Font_11x18;

/**
 * @brief  16 x 26 pixels font size structure
 */
extern FontDef_t Font_16x26;

extern const uint8_t fontData[];


#endif /* INC_FONT_H_ */
