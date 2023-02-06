/*
 * func.h
 *
 *  Created on: Dec 12, 2022
 *      Author: dung
 */

#ifndef INC_FUNC_H_
#define INC_FUNC_H_
#include <stdbool.h>

typedef enum
{
	STM_NOT_OK,
	STM_OK
} stm_err_t;

typedef struct
{
	char utc_time[12];
	char latitude[12];
	char NorS;
	char longtitude[12];
	char EorW;
	char fix_status;
	char NoSatellites;
} quectel_struct_t;

typedef enum
{
    QUECTEL_START_DATA,
	QUECTEL_DATA,
	QUECTEL_END_DATA
} quectel_state_t;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern char data_rx;
extern char data_gps_rx[100];
extern int k;
extern quectel_state_t quectel_state;

stm_err_t sim_read_resp(uint8_t *data_format, uint32_t delay, bool check);
void sim_send_mess(uint8_t *data_mess, uint8_t *number);
stm_err_t sim_init(void);
void quectel_procees_gps(quectel_struct_t *gps, char *data_gps, char *data_lat, char *data_long);
void quectel_recv_gps(void);
void quectel_callback(void);
void quectel_init(void);

#endif /* INC_FUNC_H_ */
