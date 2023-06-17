let units = [
    `UNIT_EM`,
    `UNIT_EX`,
    `UNIT_CAP`,
    `UNIT_CH`,
    `UNIT_IC`,
    `UNIT_REM`,
    `UNIT_LH`,
    `UNIT_RLH`,
    `UNIT_VW`,
    `UNIT_VH`,
    `UNIT_VI`,
    `UNIT_VB`,
    `UNIT_VMIN`,
    `UNIT_VMAX`,
    `UNIT_CM`,
    `UNIT_MM`,
    `UNIT_Q`,
    `UNIT_IN`,
    `UNIT_PC`,
    `UNIT_PT`,
    `UNIT_PX`,
    `UNIT_DEG`,
    `UNIT_GRAD`,
    `UNIT_RAD`,
    `UNIT_TURN`,
    `UNIT_SEC`,
    `UNIT_MS`,
    `UNIT_HZ`,
    `UNIT_KHZ`,
    `UNIT_FR`,
    `UNIT_DPI`,
    `UNIT_DPCM`,
    `UNIT_DPPX`
];

for (unit in units)
{
    console.log(`if (unit_type == ${units[unit]})\n\t\treturn "${units[unit].split("_")[1].toLowerCase()}";`)
}