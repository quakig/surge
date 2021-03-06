//-------------------------------------------------------------------------------------------------------
//	Copyright 2005 Claes Johanson & vember|audio
//-------------------------------------------------------------------------------------------------------
#pragma once
#include "shared/vstcontrols.h"
#include "SurgeStorage.h"
#include "CDIBitmap.h"
#include "DspUtilities.h"

class CStepSequencerGUI : public CControl
{
public:
   CStepSequencerGUI(const CRect& size,
                     IControlListener* listener = 0,
                     long tag = 0,
                     LFOStorage* lfodata = 0,
                     SurgeStorage* storage = 0,
                     StepSequencerStorage* ss = 0)
       : CControl(size, listener, tag, 0)
   {
      this->lfodata = lfodata;
      this->storage = storage;
      this->ss = ss;
      cdisurf = new CDIBitmap(size.width(), size.height());
      for (int i = 0; i < 256; i++)
      {
         float x = 1.f - (i / 255.f);
         unsigned int a = limit_range((unsigned int)((float)255.f * powf(x, 1.f / 2.2f)), 0, 255);
         coltable[i] = a | (a << 8) | (a << 16);
      }
   }
   virtual void mouse(CDrawContext* pContext, CPoint& where, long buttons = -1);
   virtual ~CLFOGui()
   {
      delete cdisurf;
   }
   virtual void draw(CDrawContext* dc);

protected:
   LFOStorage* lfodata;
   StepSequencerStorage* ss;
   SurgeStorage* storage;
   unsigned int coltable[256];
   CDIBitmap* cdisurf;
   CRect shaperect[n_lfoshapes];
   CRect steprect[n_stepseqsteps];
   CRect rect_ls, rect_le;
};