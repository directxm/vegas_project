#ifndef __COCOSBUILDER_LAYER_LOADER_H__
#define __COCOSBUILDER_LAYER_LOADER_H__

#include "CocosBuilderLayer.h"

/* Forward declaration. */
class CCBReader;

class CocosBuilderLayerLoader : public cocosbuilder::LayerLoader {
    public:
		CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CocosBuilderLayerLoader, loader);

    protected:
		CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CocosBuilderLayer);
};

#endif // __COCOSBUILDER_LAYER_LOADER_H__
