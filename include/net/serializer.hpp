#ifndef LIBBITCOIN_NET_SERIALIZER_H
#define LIBBITCOIN_NET_SERIALIZER_H

#include <boost/asio/streambuf.hpp>
#include <string>
#include <vector>

#include "net/messages.hpp"

namespace libbitcoin {
namespace net {

class serializer
{
public:
    typedef typename std::vector<char> stream;

    void write_byte(uint8_t v);
    void write_4_bytes(uint32_t v);
    void write_8_bytes(uint64_t v);
    void write_net_addr(message::net_addr addr);
    void write_command(std::string command);

    stream get_data();
private:
    stream data_;
};

class deserializer
{
public:
    deserializer(const serializer::stream& stream);

    uint32_t read_4_bytes();
    std::string read_fixed_len_str(size_t len);
private:
    const serializer::stream& stream_;
    size_t pointer_;
};

} // net
} // libbitcoin

#endif
