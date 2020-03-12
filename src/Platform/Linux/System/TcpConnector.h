// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers

#pragma once

#include <cstdint>
#include <string>

namespace System
{
    class Dispatcher;

    class Ipv4Address;

    class TcpConnection;

    class TcpConnector
    {
      public:
        TcpConnector();

        TcpConnector(Dispatcher &dispatcher);

        TcpConnector(const TcpConnector &) = delete;

        TcpConnector(TcpConnector &&other);

        ~TcpConnector();

        TcpConnector &operator=(const TcpConnector &) = delete;

        TcpConnector &operator=(TcpConnector &&other);

        TcpConnection connect(const Ipv4Address &address, uint16_t port);

      private:
        void *context;

        Dispatcher *dispatcher;
    };

} // namespace System
