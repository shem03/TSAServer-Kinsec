#ifndef _PLUGIN_LOADAPI_H_
#define _PLUGIN_LOADAPI_H_

#include "PluginError.h"
#include "PluginBase.h"


namespace Plugin {

#define HPLUGIN						void*
#define INVALID_HPLUGIN_VALUE		((HPLUGIN)-1)

//////////////////////////////////////////////////////////////////////////
///
template<typename T>
class NullPluginSearch{
public:
	NullPluginSearch(){}
	~NullPluginSearch(){}
public:
	bool FindPluginFile(const TCHAR* pName, TCHAR* pFile){
		return false;
	}
};
typedef NullPluginSearch<int>	NULLPLUGINSEARCH;

//////////////////////////////////////////////////////////////////////////
///
template<long MAX_PLUGIN = 256, long MAX_PLUGIN_NAME = 256, typename TSEARCH = NULLPLUGINSEARCH>
class PluginLoaderT{
public:
	PluginLoaderT();
	~PluginLoaderT();

public:
	/* 
	 * ����
	 *  @LoadPlugin	: ����һ�����
	 *
	 * ����
	 *	@pName		: �����ע�����ƻ����ǲ�����ļ�·��
	 *	@bFile		: ָʾpName��ע�������ǲ���ļ�·��, �����ע������
	 *				  ���������ڳ�������λ�ò��Ҳ���ļ�·��
	 *	@hPlugin	: ���ڽ��ռ��صĲ�������������ɹ�������ֵINVALID_HPLUGIN_VALUE
	 *
	 * ����ֵ		
	 *  @Return		: �ɹ����� KTPLUGIN_OK, ���ʧ�ܣ�������KTPLUGIN_NOT_FOUND
	 */
	long LoadPlugin(IN const TCHAR* pName, IN bool bFile, OUT HPLUGIN& hPlugin);

	/*
	 * ����
	 *  @QueryUnload	: ��ѯ����Ƿ����ж�أ�������ԣ���������ж�ز��
	 *
	 * ����
	 *  @hPlugin		: Ҫж�صĲ����������ֵΪINVALID_KTPLUGIN_VALUE��
	 *					  �������������Ѽ��صĲ������ж�ز���
	 * ����ֵ			
	 *	@Return			: ����ɹ����� KTPLUGIN_OK, �������ж�ط���KTPLUGIN_NOT_ALLOW,
	 *					  ���hPluginֵΪINVALID_KTPLUGIN_VALUE,ʼ�շ���KTPLUGIN_OK
	 *
	 */
	long QueryUnload(IN HPLUGIN hPlugin = INVALID_HPLUGIN_VALUE);

	/*
	 * ����
	 *  @GetObject		: �Ӳ���л�ȡһ��ָ���ӿڵĶ���
	 * 
	 * ����
	 *  @hPlugin		: �Ѿ����صĲ�����
	 *  @oid			: Ҫ��ȡ�Ķ����ʶ
	 *  @iid			: Ҫ��ȡ�Ľӿڱ�ʶ
	 *  @pParam			: δָ�����������ݸ������ʵ��Ҫ���롣
	 *  @ppInterface	: �����ȡ�Ľӿ�ָ�롣���ʧ�ܣ�����NULL��
	 * 
	 * ����ֵ
	 *  @Return			: ����ɹ����� KTPLUGIN_OK
	 */
	long GetObject(IN HPLUGIN hPlugin, IN const PLUGINOID oid, 
		IN const PLUGINIID iid, INOUT void* pParam, OUT void** ppInterface);

protected:
	long FindLoadedPlugin(const TCHAR* pName);
	long AllocHPLUGIN();
	long CheckPluginExist(HPLUGIN hPlugin);
	

private:
	TCHAR m_sPlugins[MAX_PLUGIN][MAX_PLUGIN_NAME];
	HMODULE m_hModules[MAX_PLUGIN];
	TSEARCH m_PluginSearch;
};

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
long PluginLoaderT<MAX_PLUGIN, MAX_PLUGIN_NAME, TSEARCH>::LoadPlugin(
	IN const TCHAR* pName, IN bool bFile, OUT HPLUGIN& hPlugin){
	long nIdx = 0;
	HMODULE hModule = 0;
	hPlugin = INVALID_HPLUGIN_VALUE;
	nIdx = FindLoadedPlugin( pName );
	if ( nIdx == -1 ){
		nIdx = AllocHPLUGIN();
		if ( nIdx == -1 ){
			return PLUGIN_NOT_ENOUGH_MEMORY;
		}
		TCHAR szFile[MAX_PATH];
		if ( ! bFile ){
			if ( ! m_PluginSearch.FindPluginFile( pName, szFile ) ){
				return PLUGIN_NOT_FOUND;
			}
			pName = szFile;
		}
		hModule = LoadLibrary( pName );
		if ( hModule == NULL ){
			return PLUGIN_NOT_FOUND;
		}
		m_hModules[nIdx] = hModule;
		lstrcpy( m_sPlugins[nIdx], pName );
	}
	hPlugin = (HPLUGIN)nIdx;
	return PLUGIN_OK;
}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
long PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::QueryUnload(
	IN HPLUGIN hPlugin /* = INVALID_HPLUGIN_VALUE */){
	if ( hPlugin == INVALID_HPLUGIN_VALUE ){
		return PLUGIN_OK;
	}
	return PLUGIN_NOT_ALLOW;
}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
long PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::GetObject(IN HPLUGIN hPlugin, 
	IN const PLUGINOID oid, IN const PLUGINIID iid, INOUT void* pParam, OUT void** ppInterface){
	long nIdx = 0;
	nIdx = CheckPluginExist(hPlugin);
	if ( nIdx == -1 ){
		return PLUGIN_NOT_FOUND;
	}
	LPPluginGetObject fnGetObject = NULL;
	fnGetObject = (LPPluginGetObject)GetProcAddress( m_hModules[nIdx], PLUGIN_GET_OBJECT_A );
	if ( fnGetObject == NULL ){
		return PLUGIN_NOT_IMPLEMENT;
	}
	return fnGetObject( oid, iid, pParam, ppInterface );
}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::PluginLoaderT(){
	ZeroMemory( m_hModules, sizeof(HMODULE)*MAX_PLUGIN );
	ZeroMemory( m_sPlugins, sizeof(TCHAR)*MAX_PLUGIN*MAX_PLUGIN_NAME );
}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::~PluginLoaderT(){

}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
long PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::FindLoadedPlugin(const TCHAR* pName){
	for( long i = 0; i < MAX_PLUGIN; i ++ ){
		if ( lstrcmpi( m_sPlugins[i], pName ) == 0 ){
			return i;
		}
	}
	return -1;
}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
inline long PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::AllocHPLUGIN(){
	for( long i = 0; i < MAX_PLUGIN; i ++ ){
		if ( m_hModules[i] == 0 ){
			return i;
		}
	}
	return -1;
}

template<long MAX_PLUGIN, long MAX_PLUGIN_NAME, typename TSEARCH>
inline long PluginLoaderT<MAX_PLUGIN,MAX_PLUGIN_NAME,TSEARCH>::CheckPluginExist(HPLUGIN hPlugin){
	long nIdx = 0;
	nIdx = (long)hPlugin;
	if ( nIdx < 0 || nIdx >= MAX_PLUGIN ){
		return -1;
	}
	if ( m_hModules[nIdx] == NULL ){
		return -1;
	}
	return nIdx;
}
//////////////////////////////////////////////////////////////////////////
///
typedef PluginLoaderT<> PluginLoader;

} // namespace Plugin

#endif // ! _PLUGIN_LOADAPI_H_
