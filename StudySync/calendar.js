document.addEventListener("DOMContentLoaded", function () {
    const calendarDiv = document.getElementById("calendar");

    if (!calendarDiv) {
        console.error("Error: #calendar div not found!");
        return;
    }

    console.log("Finalizing calendar layout...");

    const year = 2025;
    const month = 2; // March (0-based index)
    const daysInMonth = new Date(year, month + 1, 0).getDate();
    const monthName = new Date(year, month, 1).toLocaleString("default", { month: "long" });

    // Store tasks
    const tasks = {};

    // Create title
    const title = document.createElement("h2");
    title.innerText = `${monthName} ${year}`;
    title.style.textAlign = "center";
    title.style.fontSize = "20px"; // Slightly smaller
    title.style.marginBottom = "8px";
    calendarDiv.appendChild(title);

    // Create calendar grid
    const grid = document.createElement("div");
    grid.style.display = "grid";
    grid.style.gridTemplateColumns = "repeat(7, 1fr)"; // 7 equal columns for weekdays
    grid.style.gap = "4px"; // Slightly reduced gap for compactness
    grid.style.maxWidth = "500px"; // Shrink width to fit grid
    grid.style.margin = "0 auto"; // Centers it

    for (let i = 1; i <= daysInMonth; i++) {
        const date = new Date(year, month, i);
        const dayName = date.toLocaleString("default", { weekday: "short" }); // e.g., Sun, Mon

        const dayDiv = document.createElement("div");
        dayDiv.style.border = "2px solid black";
        dayDiv.style.padding = "5px"; // Smaller padding
        dayDiv.style.textAlign = "center";
        dayDiv.style.cursor = "pointer";
        dayDiv.style.minHeight = "60px"; // Compact height
        dayDiv.style.display = "flex";
        dayDiv.style.flexDirection = "column";
        dayDiv.style.justifyContent = "center";
        dayDiv.style.alignItems = "center";
        dayDiv.style.fontSize = "12px"; // Smaller font size
        dayDiv.style.backgroundColor = "#d9d9d9"; // Soft background
        dayDiv.style.width = "65px"; // Prevent large boxes

        dayDiv.innerHTML = `<strong>${dayName}</strong><br>${i}`;

        // Click event to add a task
        dayDiv.addEventListener("click", function () {
            const task = prompt(`Enter task for ${dayName}, March ${i}, ${year}:`);
            if (task) {
                tasks[i] = task; // Store task
                dayDiv.innerHTML = `<strong>${dayName}</strong><br>${i}<br><small style="font-size: 10px; color: blue;">${task}</small>`;
            }
        });

        grid.appendChild(dayDiv);
    }

    calendarDiv.appendChild(grid);
});


