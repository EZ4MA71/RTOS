#include "freeRTOS_demo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "gpio.h"
#include "stdio.h"
#include "key.h"
#include "delay.h"

/******************************************************************************************************/
/*FreeRTOS配置*/

/* START_TASK 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define start_task_stack_size 128
#define start_task_prio 1
TaskHandle_t start_task_handler;
void start_task( void * pvParameters );
StackType_t start_task_stack[start_task_stack_size];
StaticTask_t start_task_tcb;
/* TASK1 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define task1_stack_size 128
#define task1_prio 2
TaskHandle_t task1_handler;
void task1( void * pvParameters );
StackType_t task1_stack[task1_stack_size];
StaticTask_t task1_tcb;

/* TASK2 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define task2_stack_size 128
#define task2_prio 3
TaskHandle_t task2_handler;
void task2( void * pvParameters );
StackType_t task2_stack[task2_stack_size];
StaticTask_t task2_tcb;

/* TASK3 任务 配置
 * 包括: 任务句柄 任务优先级 堆栈大小 创建任务
 */
#define task3_stack_size 128
#define task3_prio 4
TaskHandle_t task3_handler;
void task3( void * pvParameters );
StackType_t task3_stack[task3_stack_size];
StaticTask_t task3_tcb;


/* 空闲任务内存配置*/
StaticTask_t idle_task_tcb;
StackType_t  idle_task_stack[configMINIMAL_STACK_SIZE];

/* 软件定时器内存配置*/
//StaticTask_t timer_task_tcb;
//StackType_t  timer_task_stack[configTIMER_TASK_STACK_DEPTH];

/******************************************************************************************************/


/******************************************************************************************************/
/**
 * @brief       空闲任务内存分配函数
 * @param       任务控制块、内存堆栈地址、内存大小
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
 * @brief       软件定时器内存分配函数
 * @param       任务控制块、内存堆栈地址、内存大小
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
 * @brief       FreeRTOS例程入口函数
 * @param       无
 * @retval      无
 */
/******************************************************************************************************/
void freertos_demo(void)
{
	
//	xTaskCreate( (TaskFunction_t				) start_task,     						//任务函数入口
//               (char *								) "start_task", 							//任务名
//               (configSTACK_DEPTH_TYPE) start_task_stack_size,			//分配栈大小
//               (void *								) NULL,   										//任务函数参数
//               (UBaseType_t						) start_task_prio,						//任务优先级
//               (TaskHandle_t *				) &start_task_handler );			//任务句柄
	
	
	start_task_handler = xTaskCreateStatic( (TaskFunction_t) start_task,        		//任务入口函数
																					(char *)  "start_task",									//任务名
																					(uint32_t) start_task_stack_size,				//分配栈大小
																					(void *)  NULL,													//任务函数参数
																					(UBaseType_t) start_task_prio,					//任务优先级
																					(StackType_t *)  start_task_stack,			//任务堆栈
																					(StaticTask_t *)  &start_task_tcb );		//任务控制块
	
																					
							 
	vTaskStartScheduler();																						//开启任务调度器
}

/******************************************************************************************************/
/**
 * @brief       动态任务创建函数
 * @param       无
 * @retval      无
 */
/******************************************************************************************************/
void start_task( void * pvParameters )
{
														/* 动态创建任务 */
//	xTaskCreate( (TaskFunction_t				) task1,     						//任务函数入口
//               (char *								) "task1", 							//任务名
//               (configSTACK_DEPTH_TYPE) task1_stack_size,			//分配栈大小
//               (void *								) NULL,   										//任务函数参数
//               (UBaseType_t						) task1_prio,						//任务优先级
//               (TaskHandle_t *				) &task1_handler );			//任务句柄
//	
//	xTaskCreate( (TaskFunction_t				) task2,     						//任务函数入口
//               (char *								) "task2", 							//任务名
//               (configSTACK_DEPTH_TYPE) task2_stack_size,			//分配栈大小
//               (void *								) NULL,   										//任务函数参数
//               (UBaseType_t						) task2_prio,						//任务优先级
//               (TaskHandle_t *				) &task2_handler );			//任务句柄
	
	
														/* 静态创建任务 */
	task1_handler = xTaskCreateStatic( 			(TaskFunction_t) task1,        		//任务入口函数
																					(char *)  "task1",									//任务名
																					(uint32_t) task1_stack_size,				//分配栈大小
																					(void *)  NULL,													//任务函数参数
																					(UBaseType_t) task1_prio,					//任务优先级
																					(StackType_t *)  task1_stack,			//任务堆栈
																					(StaticTask_t *)  &task1_tcb );		//任务控制块
																					
																					
	task2_handler = xTaskCreateStatic( 			(TaskFunction_t) task2,        		//任务入口函数
																					(char *)  "task2",									//任务名
																					(uint32_t) task2_stack_size,				//分配栈大小
																					(void *)  NULL,													//任务函数参数
																					(UBaseType_t) task2_prio,					//任务优先级
																					(StackType_t *)  task2_stack,			//任务堆栈
																					(StaticTask_t *)  &task2_tcb );		//任务控制块
		
	task3_handler = xTaskCreateStatic( 			(TaskFunction_t) task3,        		//任务入口函数
																					(char *)  "task3",									//任务名
																					(uint32_t) task3_stack_size,				//分配栈大小
																					(void *)  NULL,													//任务函数参数
																					(UBaseType_t) task3_prio,					//任务优先级
																					(StackType_t *)  task3_stack,			//任务堆栈
																					(StaticTask_t *)  &task3_tcb );		//任务控制块
																				
	
	
	
	vTaskDelete(start_task_handler);																					//删除任务本身
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
		printf("nihao");
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

/******************************************************************************************************/
/**
 * @brief       任务3函数
 * @param       无
 * @retval      无
 */
/******************************************************************************************************/
void task3( void * pvParameters )
{
		uint8_t key = 0;
    while(1)
    {
        printf("task3正在运行！！！\r\n");
        key = key_scan(0);
        if(key == KEY0_PRES)
        {
            if(task1_handler != NULL)
            {
                printf("删除task1任务\r\n");
                vTaskDelete(task1_handler);
                task1_handler = NULL;
            }

        }
        vTaskDelay(10);
    }

}



