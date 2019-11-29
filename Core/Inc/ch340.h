#ifndef CH340_H
#define CH340_H

#include "usbd_def.h"
#include "usbd_cdc.h"

#define CH341_MODEM_OUT 			 0xA4
#define CH341_REQ_READ_REG     0x95
#define CH341_VERSION		 			 0x5F

void CH340_Requset_Handle(USBD_HandleTypeDef *pdev, USBD_CDC_HandleTypeDef *hcdc, USBD_SetupReqTypedef *req);

#endif
