// Last updated: 7/24/2025, 8:23:10 AM
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };

function argumentsLength(...args: JSONValue[]): number {
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */