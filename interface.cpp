#include "interface.hpp"
#include "provider_module/provider.hpp"
#include <dlfcn.h>
#include <cstdlib>
#include <iostream>

using std::clog;

ProviderInterface::ProviderInterface()
{
    clog << "ProviderInterface::ProviderInterface()\n";
    so_handle_ = dlopen("./provider_module/libprovider.so", RTLD_LAZY);
    char* error = dlerror();
    if (error) {
        std::cout << error << "\n";
        exit(EXIT_FAILURE);
    }

    dlerror();
    Provider* (*get_provider)();
    get_provider = (Provider* (*)())dlsym(so_handle_, "create");
    error = dlerror();
    if (error) {
        std::cout << error << "\n";
        exit(EXIT_FAILURE);
    }

    impl_ = get_provider();
}

string ProviderInterface::GetResource(const string& name)
{
    clog << "ProviderInterface::GetResource()\n";
    return impl_->GetResource(name);
}

ProviderInterface::~ProviderInterface()
{
    clog << "ProviderInterface::~ProviderInterface()\n";
    dlerror();
    void (*destroy_provider)(Provider*);
    destroy_provider = (void (*)(Provider*))dlsym(so_handle_, "destroy");
    char* error = dlerror();
    if (error) {
        std::cout << error << "\n";
        exit(EXIT_FAILURE);
    }

    destroy_provider(impl_);
    dlclose(so_handle_);
}
