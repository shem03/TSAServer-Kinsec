#ifndef __PLUGINMGR__
#define __PLUGINMGR__

/**
  * @Name: PluginMgr.h
  * @Copyright: KTXA SoftWare
  * @Author: Hongwei Yu
  * @Date:  2003/04/26 00:02
  * @Description:����������������װ�ء��ͷż��ӿڵĻ�ȡ
*/

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif

//��������λ����Ϣ
struct PLUGINLIB_INFO 
{
public:
	PLUGINLIB_INFO(){szPath[0]=0;szFile[0]=0;}
	KTCHAR szPath[KT_MAX_PATH];			//���·��
	KTCHAR szFile[KT_MAX_PATH];			//����ļ�������ͨ��� ��TKN*.KL
	KTCHAR szReserved[64];
};

class CPluginMangr 
{
public:
	/**
	* װ�ز��
	*/
	virtual KTINT32 load(PLUGINLIB_INFO* pPluginLibInfo, KTIID nIID);
	/**
	* �ͷŲ��
	*/
	void free();

	/**
	* �������������Ĳ������
	*/
	int getCount();

	/**
	* ����ĳһ���������
	*/
	void getInfo(int nIndex, PLUGIN_INFO* pInfo);

	/**
	* ��ȡ���ָ��
	*/
	KTINT32 getInterface(int nIndex,KTIID nIID,IKTUnknow** pUnknow);

	virtual ~CPluginMangr();

	CPluginMangr();

protected:
	struct PLUGINATTR 
	{
		PLUGINATTR(){nHandle=0;pPlugin=NULL;}
		KTHANDLE nHandle;
		IPlugin* pPlugin;
	};
	typedef std::vector<PLUGINATTR> PLUGINATTR_ARRAY;
	
    //����Ҫ��ѡ����
	virtual KTBOOL beforeLoad(IKTUnknow* pUnknow);
    //��ȡ�������Ϣ
	virtual KTBOOL readPluginLibInfo(PLUGINLIB_INFO* pPluginLibInfo,KTString& strPath,KTString& strFile);
	PLUGINATTR_ARRAY m_rPluginAttr;
};

/// Rivison history
/// ----------------------------------------------------------------------------
/// 	Version	       Date        Author      Note
/// ----------------------------------------------------------------------------
///   1.0.0.0  2003/04/26 00:00  Hongwei Yu   created 

#endif 
