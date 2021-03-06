/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2015, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#if !defined(MM_StartupManagerImpl_HPP_)
#define MM_StartupManagerImpl_HPP_

#include "StartupManager.hpp"

class MM_CollectorLanguageInterface;
class MM_ConfigurationLanguageInterface;
class MM_MarkingScheme;
class OMR_VM;
class MM_VerboseManagerBase;

class MM_StartupManagerImpl : public MM_StartupManager
{
	/*
	 * Data members
	 */
private:

protected:
public:
	static const uintptr_t defaultMinimumHeapSize = (uintptr_t) 4*1024*1024;
	static const uintptr_t defaultMaximumHeapSize = (uintptr_t) 1*1024*1024*1024;

	/*
	 * Function members
	 */

private:

protected:
	virtual bool handleOption(MM_GCExtensionsBase *extensions, char *option);
	virtual char * getOptions(void);

public:
	virtual MM_ConfigurationLanguageInterface * createConfigurationLanguageInterface(MM_EnvironmentBase *env);
	virtual MM_Configuration *createConfiguration(MM_EnvironmentBase *env, MM_ConfigurationLanguageInterface *cli);
	virtual MM_CollectorLanguageInterface * createCollectorLanguageInterface(MM_EnvironmentBase *env);
	virtual MM_VerboseManagerBase * createVerboseManager(MM_EnvironmentBase* env);

	MM_StartupManagerImpl(OMR_VM *omrVM)
		: MM_StartupManager(omrVM, defaultMinimumHeapSize, defaultMaximumHeapSize)
	{
	}
};

#endif /* MM_StartupManagerImpl_HPP_ */
