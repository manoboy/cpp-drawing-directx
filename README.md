# C++ Drawing Library Using DirectX
## Usage
1. Make sure you have installed [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812);
2. Include the Drawing.h header file in your code with `#include "Drawing.h"`;
3. At this point, you already can access the Drawing object **drawing**;
4. It is time to set the DirectX device object. Suppose you create the device like so:
```
IDirect3DDevice9Ex *device = NULL;
IDirect3D9Ex       *pD3D   = NULL;

if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &pD3D)))
{
  // Do something to deal with this error.
}

D3DPRESENT_PARAMETERS d3dpp;
ZeroMemory(&d3dpp, sizeof(d3dpp));
d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
d3dpp.BackBufferFormat       = D3DFMT_A8R8G8B8;
d3dpp.BackBufferHeight       = /* Your window height */;
d3dpp.BackBufferWidth        = /* Your window width */;
d3dpp.EnableAutoDepthStencil = TRUE;
d3dpp.hDeviceWindow          = /* Your program window */;
d3dpp.MultiSampleQuality     = D3DMULTISAMPLE_NONE;
d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
d3dpp.Windowed               = TRUE;

if (FAILED(pD3D->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, /* Your program window */, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, 0, &device)))
{
  // Do something to deal with this error.
}

// If you get here, your device has been successfully created.
drawing->Device(device);
```

##### Don't forget to include DirectX SDK dir to your project.

### Enjoy!
