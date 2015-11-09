/**********************************************************************
* 版权所有 (C)2015, Zhou Zhaoxiong。
*
* 文件名称：FindStackDirection.c
* 文件标识：无
* 内容摘要：测试栈的增长方向
* 其它说明：无
* 当前版本：V1.0
* 作    者：Zhou Zhaoxiong
* 完成日期：20151109
*
**********************************************************************/
#include <stdio.h>

// 重定义数据类型
typedef unsigned char  UINT8;
typedef signed   int   INT32;

// 函数声明
void FindStackDirection(void);


/**********************************************************************
* 功能描述：主函数
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期        版本号      修改人              修改内容
* ---------------------------------------------------------------
* 20151109        V1.0     Zhou Zhaoxiong          创建
***********************************************************************/
INT32 main()
{
    FindStackDirection();
    
    return 0; 
}


/**********************************************************************
* 功能描述：查找栈增长方向
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期        版本号      修改人              修改内容
* ---------------------------------------------------------------
* 20151109        V1.0     Zhou Zhaoxiong          创建
***********************************************************************/
void FindStackDirection(void)
{
	UINT8  iStackAddr        = 0;        // 用于获取栈地址
    static UINT8 *pStackAddr = NULL;     // 用于存放第一个iStackAddr的地址 
	
    if (pStackAddr == NULL)              // 第一次进入
    {                          
        pStackAddr = &iStackAddr;        // 保存iStackAddr的地址
        FindStackDirection();            // 递归 
    }
	else                                 // 第二次进入 
    {  
        if (&iStackAddr > pStackAddr)        // 第二次iStackDirection的地址大于第一次iStackDirection, 那么说明栈增长方向是向上的
		{   
			printf("Stack grows up!\n");
	    }
        else if (&iStackAddr < pStackAddr)   // 第二次iStackDirection的地址小于第一次iStackDirection, 那么说明栈增长方向是向下的
		{  
			printf("Stack grows down!\n");
		}
		else
		{
		    printf("Bad stack!\n");
		}
    }
} 

