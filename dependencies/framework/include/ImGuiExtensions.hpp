#pragma once

namespace ImGui
{
    bool Combo(
        const char* label,
        int* currIndex,
        std::vector<std::string> &values);

    bool ListBox(
        const char* label,
        int* currIndex,
        std::vector<std::string> &values
    );
}
