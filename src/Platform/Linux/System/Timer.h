// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers

#pragma once

#include <chrono>

namespace System
{
    class Dispatcher;

    class Timer
    {
      public:
        Timer();

        explicit Timer(Dispatcher &dispatcher);

        Timer(const Timer &) = delete;

        Timer(Timer &&other);

        ~Timer();

        Timer &operator=(const Timer &) = delete;

        Timer &operator=(Timer &&other);

        void sleep(std::chrono::nanoseconds duration);

      private:
        Dispatcher *dispatcher;

        void *context;

        int timer;
    };

} // namespace System
