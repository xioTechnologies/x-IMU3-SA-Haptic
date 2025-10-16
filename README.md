# x-IMU3-SA-Haptic

## Commands

| Name    | Example     | Description                                                                                                                                                           |
|---------|-------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|                                                                                                
| Haptic  | `12\n`      | Plays the specified haptic waveform (effect ID 12). See page 63 of the [DRV2605L dataset](https://www.ti.com/product/DRV2605L) for the waveform library effects list. |
| Test    | `test\n`    | Performs haptic self-test and sends result: `Passed\n`, `ACK failed\n`, `Invalid ID\n`, `Diagnostic failed\n`, `Over temperature\n`, or `Over current\n`.             |
| Version | `version\n` | Responds with firmware version. For example, `v1.0.0\n`.                                                                                                              |
