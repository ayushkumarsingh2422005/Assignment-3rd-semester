import express from 'express';
import cors from 'cors';
import { McpServer } from "@modelcontextprotocol/sdk/server/mcp.js";
import { z } from 'zod';

const app = express();
const port = 3000;

app.use(cors());
app.use(express.json());

// Create MCP server instance
const server = new McpServer({
    name: "Weather data fetcher",
    version: "1.0.0",
});

// Weather data logic
async function getWeatherByCity(city = '') {
    const lower = city.toLowerCase();
    if (lower === 'patiala') return { temp: '30C', forecast: 'chances of high rain' };
    if (lower === 'delhi') return { temp: '40C', forecast: 'chances of high warm winds' };
    return { temp: null, error: 'Unable to get data' };
}

// Tool registry (we'll manage tools ourselves here)
const toolRegistry = {};

// Register tool and store handler manually
function registerTool(name, schema, handler) {
    toolRegistry[name] = { schema, handler };
    server.tool(name, schema, handler); // still register with MCP
}

registerTool(
    'getWeatherDataByCityName',
    {
        city: z.string(),
    },
    async ({ city }) => {
        const result = await getWeatherByCity(city);
        return {
            content: [{ type: 'text', text: JSON.stringify(result) }]
        };
    }
);

// Express endpoint to mimic MCP HTTP API
app.post('/mcp', async (req, res) => {
    try {
        const { id, tool, input } = req.body;

        if (!toolRegistry[tool]) {
            return res.status(404).json({ id, error: `Tool '${tool}' not found.` });
        }

        const { schema, handler } = toolRegistry[tool];

        // Validate input
        const parsed = z.object(schema).safeParse(input);
        if (!parsed.success) {
            return res.status(400).json({ id, error: "Invalid input", details: parsed.error });
        }

        // Run the handler
        const output = await handler(parsed.data);
        res.json({ id, tool, output });

    } catch (err) {
        console.error(err);
        res.status(500).json({ error: 'Internal server error' });
    }
});

app.listen(port, () => {
    console.log(`✅ MCP server is running at http://localhost:${port}/mcp`);
});
