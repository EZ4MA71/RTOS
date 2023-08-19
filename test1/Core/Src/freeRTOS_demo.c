#include "freeRTOS_demo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "gpio.h"

/******************************************************************************************************/
/*FreeRTOS����*/

/* START_TASK ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define start_task_stack_size 128
#define start_task_prio 1
TaskHandle_t start_task_handler;
void start_task( void * pvParameters );

/* TASK1 ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define task1_stack_size 128
#define task1_prio 2
TaskHandle_t task1_handler;
void task1( void * pvParameters );

/* TASK2 ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define task2_stack_size 128
#define task2_prio 2
TaskHandle_t task2_handler;
void task2( void * pvParameters );


/******************************************************************************************************/


/******************************************************************************************************/
/**
 * @brief       FreeRTOS������ں���
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void freertos_demo(void)
{
	xTaskCreate( (TaskFunction_t				) start_task,     						//���������
               (char *								) "start_task", 							//������
               (configSTACK_DEPTH_TYPE) start_task_stack_size,			//����ջ��С
               (void *								) NULL,   										//����������
               (UBaseType_t						) start_task_prio,						//�������ȼ�
               (TaskHandle_t *				) &start_task_handler );			//������
							 
	vTaskStartScheduler();
}

/******************************************************************************************************/
/**
 * @brief       ���񴴽�����
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void start_task( void * pvParameters )
{
	xTaskCreate( (TaskFunction_t				) task1,     						//���������
               (char *								) "task1", 							//������
               (configSTACK_DEPTH_TYPE) task1_stack_size,			//����ջ��С
               (void *								) NULL,   										//����������
               (UBaseType_t						) task1_prio,						//�������ȼ�
               (TaskHandle_t *				) &task1_handler );			//������
	
	xTaskCreate( (TaskFunction_t				) task2,     						//���������
               (char *								) "task2", 							//������
               (configSTACK_DEPTH_TYPE) task2_stack_size,			//����ջ��С
               (void *								) NULL,   										//����������
               (UBaseType_t						) task2_prio,						//�������ȼ�
               (TaskHandle_t *				) &task2_handler );			//������
	vTaskDelete(NULL);
}

/******************************************************************************************************/
/**
 * @brief       ����1����
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void task1( void * pvParameters )
{
	while(1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
		vTaskDelay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
		vTaskDelay(500);
	}
	
	
}


/******************************************************************************************************/
/**
 * @brief       ����2����
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void task2( void * pvParameters )
{
	while(1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
		vTaskDelay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
		vTaskDelay(500);
	}

}
