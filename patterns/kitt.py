LEDS = 3

for hi in range(3):
    for lo in range(3):
        if hi == lo: continue
        hi_pin = 1 << hi
        lo_pin = 1 << lo
        port = hi_pin
        ddr  = hi_pin + lo_pin
        duration = 15
        print '0x%04x, ' % (( duration << 12 ) + ( ddr << 6 ) + port )

print '0x%04x, ' % 10
print '0x%04x, ' % 10
        