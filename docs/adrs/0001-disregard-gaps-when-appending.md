# ADR 1: Disregard Gaps When Appending

2023-10-25

## Context

When appending to the dynamic array, there may be gaps inbetween some elements of the array. For example:

```
[17, 28, _, 4, _, 2, _, 10]
[12,  3, _, 4, 2, 6, _,  _]
```

When adding or appending to the array we need to decide whether to insert the element at the first found gap, or at the end of the array. The latter, would potentialy trigger a resizing of the array.

## Decision

Append at the end of the array.

## Status

Accepted

## Consequences

Not applicable
