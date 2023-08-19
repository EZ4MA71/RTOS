#include "freeRTOS_demo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "gpio.h"

/******************************************************************************************************/
/*FreeRTOS配置*/

/* START_TASK 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define start_task_stack_size 128
#define start_task_prio 1
TaskHandle_t start_task_handler;
void start_task( void * pvParameters );

/* TASK1 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define task1_stack_size 128
#define task1_prio 2
TaskHandle_t task1_handler;
void task1( void * pvParameters );

/* TASK2 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define task2_stack_size 128
#define task2_prio 2
TaskHandle_t task2_handler;
void task2( void * pvParameters );


/******************************************************************************************************/


/******************************************************************************************************/
/**
 * @brief       FreeRTOS例程入口函数
 * @param       无
 * @retval      无
 */
/******************************************************************************************************/
void freertos_demo(void)
{
	xTaskCreate( (TaskFunction_t				) start_task,     						//任务函数入口
               (char *								) "start_task", 							//任务名
               (configSTACK_DEPTH_TYPE) start_task_stack_size,			//分配栈大小
               (void *								) NULL,   										//任务函数参数
               (UBaseType_t						) start_task_prio,						//任务优先级
               (TaskHandle_t *				) &start_task_handler );			//任务句柄
							 
	vTaskStartScheduler();
}

/******************************************************************************************************/
/**
 * @brief       任务创建函数
 * @param       无
 * @retval      无
 */
/******************************************************************************************************/
void start_task( void * pvParameters )
{
	xTaskCreate( (TaskFunction_t				) task1,     						//任务函数入口
               (char *								) "task1", 							//任务名
               (configSTACK_DEPTH_TYPE) task1_stack_size,			//分配栈大小
               (void *								) NULL,   										//任务函数参数
               (UBaseType_t						) task1_prio,						//任务优先级
               (TaskHandle_t *				) &task1_handler );			//任务句柄
	
	xTaskCreate( (TaskFunction_t				) task2,     						//任务函数入口
               (char *								) "task2", 							//任务名
               (configSTACK_DEPTH_TYPE) task2_stack_size,			//分配栈大小
               (void *								) NULL,   										//任务函数参数
               (UBaseType_t						) task2_prio,						//任务优先级
               (TaskHandle_t *				) &task2_handler );			//任务句柄
	vTaskDelete(NULL);
}

/******************************************************************************************************/
/**
 * @brief       任务1函数
 * @param       无
 * @retval      无
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
 * @brief       任务2函数
 * @param       无
 * @retval      无
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
