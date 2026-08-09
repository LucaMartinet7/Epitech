"use server";

import { auth } from "@clerk/nextjs/server";
import { InputType, ReturnType } from "./types";
import { db } from "@/lib/db";
import { revalidatePath } from "next/cache";
import { createSafeAction } from "@/lib/create-safe-action";
import { DeleteBoard } from "./schema";
import { redirect } from "next/navigation";

const handler = async (data: InputType): Promise<ReturnType> => {
    const { userId, orgId} = auth();

    if (!userId || !orgId) {
        return {
            error: "You must be logged in to update a board",
        } as ReturnType;
    }

    const { id } = data;
    try {
        await db.board.delete({
            where: {
                id,
                orgId,
            },
        });
    } catch {
        return {
            error: "failed to delete board",
        }
    }
    revalidatePath(`/organization/${orgId}`);
    redirect(`/organization/${orgId}`);
}

export const deleteBoard = createSafeAction(DeleteBoard, handler);