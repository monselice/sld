// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers

#include "ErrorMessage.h"

#include <cerrno>
#include <cstring>

namespace System
{
    std::string lastErrorMessage()
    {
        return errorMessage(errno);
    }

    std::string errorMessage(int err)
    {
        return "result=" + std::to_string(err) + ", " + std::strerror(err);
    }

} // namespace System
