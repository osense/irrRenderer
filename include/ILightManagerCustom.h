// This file is part of the "irrRenderer".
// For conditions of distribution and use, see copyright notice in irrRenderer.h

#ifndef ILIGHTMANAGERCUSTOM_H
#define ILIGHTMANAGERCUSTOM_H

#include <irrlicht.h>
#include "CPostProcessingEffectChain.h"
#include "CPostProcessingEffect.h"
#include "IQuadSceneNode.h"
#include "MaterialCallbacks.h"

namespace irr
{
namespace scene
{

class ILightManagerCustom : public irr::scene::ILightManager
{
    public:
        ILightManagerCustom(irr::IrrlichtDevice* device);

        ~ILightManagerCustom();

        virtual void OnPreRender(core::array<ISceneNode*> & lightList);

        virtual void OnPostRender();

        virtual void OnRenderPassPreRender(irr::scene::E_SCENE_NODE_RENDER_PASS renderPass);

        virtual void OnRenderPassPostRender(irr::scene::E_SCENE_NODE_RENDER_PASS renderPass);

        virtual void OnNodePreRender(irr::scene::ISceneNode *node);

        virtual void OnNodePostRender(irr::scene::ISceneNode *node);


        void setMRTs(irr::core::array<irr::video::IRenderTarget> &mrts);

        void setRenderTexture(irr::video::ITexture* tex);

        void setDoFinalRenderIntoTexture(bool well);

        bool getDoFinalRenderToTexture() const;

        irr::video::ITexture* getRenderTexture();


        void setLightPointMaterialType(irr::video::E_MATERIAL_TYPE &type);
        void setLightPointCallback(irr::video::IShaderPointLightCallback* callback);
        void setLightSpotMaterialType(irr::video::E_MATERIAL_TYPE &type);
        void setLightSpotCallback(irr::video::IShaderSpotLightCallback* callback);
        void setLightDirectionalMaterialType(irr::video::E_MATERIAL_TYPE &type);
        void setLightDirectionalCallback(irr::video::IShaderDirectionalLightCallback* callback);
        void setLightAmbientMaterialType(irr::video::E_MATERIAL_TYPE &type);
        void setLightAmbientCallback(irr::video::IShaderAmbientLightCallback* callback);


    private:
        irr::IrrlichtDevice* Device;
        irr::core::array<irr::video::IRenderTarget> MRTs;
        bool FinalRenderToTexture;
        irr::video::ITexture* FinalRender;


        irr::scene::IMeshSceneNode* LightSphere, *LightCone;
        irr::scene::IQuadSceneNode* LightQuad;

        bool isAABBinFrustum(irr::core::aabbox3d<irr::f32> box, const irr::scene::SViewFrustum *frustum) const;


        irr::video::E_MATERIAL_TYPE LightPointMaterial;
        irr::video::IShaderPointLightCallback* LightPointCallback;

        irr::video::E_MATERIAL_TYPE LightSpotMaterial;
        irr::video::IShaderSpotLightCallback* LightSpotCallback;

        irr::video::E_MATERIAL_TYPE LightDirectionalMaterial;
        irr::video::IShaderDirectionalLightCallback* LightDirectionalCallback;

        irr::video::E_MATERIAL_TYPE LightAmbientMaterial;
        irr::video::IShaderAmbientLightCallback* LightAmbientCallback;
};

}
}

#endif // ILIGHTMANAGERCUSTOM_H
