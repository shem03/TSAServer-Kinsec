#ifndef _PLUGIN_ERROR_H_
#define _PLUGIN_ERROR_H_

namespace Plugin {

/* sdaf */
typedef enum{
	PLUGIN_FALSE		= 0, /* ����ֵ���Ǵ��� */
	
	PLUGIN_TRUE			= 1,
	PLUGIN_OK			= 0,
	PLUGIN_ERROR		= -1, /* δָ������ */
	
	PLUGIN_NOT_FOUND	= -2,
	PLUGIN_NOT_ALLOW	= -3,
	PLUGIN_NOT_ENOUGH_MEMORY	= -4,
	PLUGIN_OUT_OF_MEMORY		= -5,
	PLUGIN_OUT_OF_INDEX			= -6,
	PLUGIN_NOT_IMPLEMENT		= -7,
	PLUGIN_INVALID_PARAM		= -8,
}enumPluginError;

/* ��ⷵ�ص�ֵ�Ƿ���ȷ */
#define IsPluginError(x)		(x<0)

} // namespace Plugin


#endif // ! _PLUGIN_ERROR_H_
