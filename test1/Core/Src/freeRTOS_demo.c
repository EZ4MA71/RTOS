#include "freeRTOS_demo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "gpio.h"
#include "stdio.h"
#include "key.h"
#include "delay.h"

/******************************************************************************************************/
/*FreeRTOS����*/

/* START_TASK ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define start_task_stack_size 128
#define start_task_prio 1
TaskHandle_t start_task_handler;
void start_task( void * pvParameters );
StackType_t start_task_stack[start_task_stack_size];
StaticTask_t start_task_tcb;
/* TASK1 ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define task1_stack_size 128
#define task1_prio 2
TaskHandle_t task1_handler;
void task1( void * pvParameters );
StackType_t task1_stack[task1_stack_size];
StaticTask_t task1_tcb;

/* TASK2 ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define task2_stack_size 128
#define task2_prio 3
TaskHandle_t task2_handler;
void task2( void * pvParameters );
StackType_t task2_stack[task2_stack_size];
StaticTask_t task2_tcb;

/* TASK3 ���� ����
 * ����: ������ �������ȼ� ��ջ��С ��������
 */
#define task3_stack_size 128
#define task3_prio 4
TaskHandle_t task3_handler;
void task3( void * pvParameters );
StackType_t task3_stack[task3_stack_size];
StaticTask_t task3_tcb;


/* ���������ڴ�����*/
StaticTask_t idle_task_tcb;
StackType_t  idle_task_stack[configMINIMAL_STACK_SIZE];

/* �����ʱ���ڴ�����*/
//StaticTask_t timer_task_tcb;
//StackType_t  timer_task_stack[configTIMER_TASK_STACK_DEPTH];

/******************************************************************************************************/


/******************************************************************************************************/
/**
 * @brief       ���������ڴ���亯��
 * @param       ������ƿ顢�ڴ��ջ��ַ���ڴ��С
 */
/******************************************************************************************************/
void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    uint32_t * pulIdleTaskStackSize )
{
	* ppxIdleTaskTCBBuffer = &idle_task_tcb;
	* ppxIdleTaskStackBuffer = idle_task_stack;
	* pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/******************************************************************************************************/
/**
 * @brief       �����ʱ���ڴ���亯��
 * @param       ������ƿ顢�ڴ��ջ��ַ���ڴ��С
 */
/******************************************************************************************************/
//void vApplicationGetTimerTaskMemory( StaticTask_t ** ppxTimerTaskTCBBuffer,
//                                     StackType_t ** ppxTimerTaskStackBuffer,
//                                     uint32_t * pulTimerTaskStackSize )
//{
//	* ppxTimerTaskTCBBuffer = &idle_task_tcb;
//	* ppxTimerTaskStackBuffer = idle_task_stack;
//	* pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
//}

/******************************************************************************************************/
/**
 * @brief       FreeRTOS������ں���
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void freertos_demo(void)
{
	
//	xTaskCreate( (TaskFunction_t				) start_task,     						//���������
//               (char *								) "start_task", 							//������
//               (configSTACK_DEPTH_TYPE) start_task_stack_size,			//����ջ��С
//               (void *								) NULL,   										//����������
//               (UBaseType_t						) start_task_prio,						//�������ȼ�
//               (TaskHandle_t *				) &start_task_handler );			//������
	
	
	start_task_handler = xTaskCreateStatic( (TaskFunction_t) start_task,        		//������ں���
																					(char *)  "start_task",									//������
																					(uint32_t) start_task_stack_size,				//����ջ��С
																					(void *)  NULL,													//����������
																					(UBaseType_t) start_task_prio,					//�������ȼ�
																					(StackType_t *)  start_task_stack,			//�����ջ
																					(StaticTask_t *)  &start_task_tcb );		//������ƿ�
	
																					
							 
	vTaskStartScheduler();																						//�������������
}

/******************************************************************************************************/
/**
 * @brief       ��̬���񴴽�����
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void start_task( void * pvParameters )
{
														/* ��̬�������� */
//	xTaskCreate( (TaskFunction_t				) task1,     						//���������
//               (char *								) "task1", 							//������
//               (configSTACK_DEPTH_TYPE) task1_stack_size,			//����ջ��С
//               (void *								) NULL,   										//����������
//               (UBaseType_t						) task1_prio,						//�������ȼ�
//               (TaskHandle_t *				) &task1_handler );			//������
//	
//	xTaskCreate( (TaskFunction_t				) task2,     						//���������
//               (char *								) "task2", 							//������
//               (configSTACK_DEPTH_TYPE) task2_stack_size,			//����ջ��С
//               (void *								) NULL,   										//����������
//               (UBaseType_t						) task2_prio,						//�������ȼ�
//               (TaskHandle_t *				) &task2_handler );			//������
	
	
														/* ��̬�������� */
	task1_handler = xTaskCreateStatic( 			(TaskFunction_t) task1,        		//������ں���
																					(char *)  "task1",									//������
																					(uint32_t) task1_stack_size,				//����ջ��С
																					(void *)  NULL,													//����������
																					(UBaseType_t) task1_prio,					//�������ȼ�
																					(StackType_t *)  task1_stack,			//�����ջ
																					(StaticTask_t *)  &task1_tcb );		//������ƿ�
																					
																					
	task2_handler = xTaskCreateStatic( 			(TaskFunction_t) task2,        		//������ں���
																					(char *)  "task2",									//������
																					(uint32_t) task2_stack_size,				//����ջ��С
																					(void *)  NULL,													//����������
																					(UBaseType_t) task2_prio,					//�������ȼ�
																					(StackType_t *)  task2_stack,			//�����ջ
																					(StaticTask_t *)  &task2_tcb );		//������ƿ�
		
	task3_handler = xTaskCreateStatic( 			(TaskFunction_t) task3,        		//������ں���
																					(char *)  "task3",									//������
																					(uint32_t) task3_stack_size,				//����ջ��С
																					(void *)  NULL,													//����������
																					(UBaseType_t) task3_prio,					//�������ȼ�
																					(StackType_t *)  task3_stack,			//�����ջ
																					(StaticTask_t *)  &task3_tcb );		//������ƿ�
																				
	
	
	
	vTaskDelete(start_task_handler);																					//ɾ��������
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
		printf("nihao");
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

/******************************************************************************************************/
/**
 * @brief       ����3����
 * @param       ��
 * @retval      ��
 */
/******************************************************************************************************/
void task3( void * pvParameters )
{
		uint8_t key = 0;
    while(1)
    {
        printf("task3�������У�����\r\n");
        key = key_scan(0);
        if(key == KEY0_PRES)
        {
            if(task1_handler != NULL)
            {
                printf("ɾ��task1����\r\n");
                vTaskDelete(task1_handler);
                task1_handler = NULL;
            }

        }
        vTaskDelay(10);
    }

}



