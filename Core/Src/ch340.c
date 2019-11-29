#include "ch340.h"

uint32_t ch341_state = 0xdeff;
static uint8_t buf1[2] = {0x30, 0};
static uint8_t buf2[2] = {0xc3, 0};
static uint8_t zero[2] = {0, 0};

void CH340_Requset_Handle(USBD_HandleTypeDef *pdev, USBD_CDC_HandleTypeDef *hcdc, USBD_SetupReqTypedef *req)
{
	uint16_t wValue = req->wValue;

	switch(req->bRequest)
	{
		case CH341_VERSION:
			USBD_CtlSendData(pdev, buf1, req->wLength);
		break;
		case CH341_REQ_READ_REG:
			if(wValue == 0x2518)
				USBD_CtlSendData(pdev, buf2, req->wLength);
			else if(wValue == 0x0706)
				USBD_CtlSendData(pdev, (uint8_t *)&ch341_state, req->wLength);
		break;
		case CH341_MODEM_OUT:
			USBD_CtlSendData(pdev, (uint8_t *)&ch341_state, req->wLength);
		break;
		default:
			USBD_CtlSendData(pdev, (uint8_t *)&zero, req->wLength);
			break;
	}
	return;
}
