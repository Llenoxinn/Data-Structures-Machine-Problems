# Assignment 1: Binary Packet Stream Reconstructor

## Overview

`poem.h` and `poem.cpp` decode simulated network packets stored as binary text lines, verify integrity with a 16-bit one's-complement checksum, deduplicate and group packets by `(sourceIP, destinationIP)`, and reassemble ordered text lines to standard output.

## Files

- [poem.h](poem.h) — Declares the `Packets` class.
- [poem.cpp](poem.cpp) — Implements `Packets` parsing/checksum verification and the `main()` file-processing pipeline.

## Packet Bit Layout

Each valid packet contains at least 112 header bits and has a total bit length divisible by 16:

```text
 0              31 32             63 64       79 80       95 96      111
+-----------------+-----------------+-----------+-----------+-----------+
|   Source IPv4   | Destination IPv4| Seq. Num  | Checksum  | Data Len  |
+-----------------+-----------------+-----------+-----------+-----------+
|                ASCII Payload (Data Len bits, 8 bits/char)             |
+-----------------------------------+-----------------------------------+
|      Zero Padding (0-15 bits)     |
+-----------------------------------+
```

| Field | Width | Details |
| --- | --- | --- |
| Source IPv4 | 32 bits | Parsed into both a 32-bit unsigned integer (`sourceAddress`) and dotted-decimal string (`sourceIP`). |
| Destination IPv4 | 32 bits | Parsed into `destinationAddress` and dotted-decimal `destinationIP`. |
| Sequence Number | 16 bits | Signed two's-complement value: `0` is the title, `1..N` are body lines, and a negative value `-total` marks the total expected packet count. |
| Checksum | 16 bits | 16-bit one's-complement sum over all 16-bit chunks (treating the checksum field itself as `0`), inverted (`65535 - sum`). |
| Data Length | 16 bits | Payload length in bits (`length / 8` ASCII characters). |
| Payload + Padding | variable | Decoded into `data`, with trailing bits stored in `padding`. |

## Checksum & Packet Validation

`Packets::Packets(string s)` marks a packet corrupted (`politiciansAreCorrupt() == true`) if:

- The bit string is shorter than 112 bits or not a multiple of 16 bits.
- The computed 16-bit one's-complement checksum (with end-around carry folding) does not match the stored `checkSum`.
- `112 + length` exceeds the packet's total bit count.

## Reconstruction Pipeline (`main`)

1. Reads a filename from `std::cin` via `getline`.
2. Filters each line of the file down to `'0'` and `'1'` characters and constructs a `Packets` instance.
3. Groups packets into `std::list<std::list<Packets>>` keyed by `(sourceAddress, destinationAddress)` in order of first appearance.
4. Deduplicates packets sharing the same `sequenceNumber`, replacing a corrupted packet if an uncorrupted duplicate arrives later.
5. Prints each poem's title, `<sourceIP>/<destIP>` header, and body lines in sequence order, substituting `[title missing]`, `[line missing]`, `[title corrupted]`, or `[line corrupted]` as needed. Multiple poems are separated by an 80-character `-` rule.

## Build & Run

```bash
g++ -std=c++17 poem.cpp -o poem_reconstructor
./poem_reconstructor
```

When prompted on standard input, enter the path to a text file containing one binary packet per line.

### Minimal Packet Example

A single valid title packet (`seq = 0`) from `10.0.0.1` to `10.0.0.2` carrying `"Hi"` (`16` bits, `01001000 01101001`) has 128 bits total:

```text
00001010000000000000000000000001 00001010000000000000000000000010 0000000000000000 1010001110000011 0000000000010000 0100100001101001
```

(Spaces added above for readability; the file format stores contiguous bits per line.)
