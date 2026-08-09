import { auth } from "@clerk/nextjs/server";
import { db } from "@/lib/db";
import { notFound, redirect } from "next/navigation";
import { BoardNavBar } from "./_components/board-navbar";

const boardIdLayout = async ({
    children,
    params,
}: {
    children: React.ReactNode;
    params: {
        boardId: string;
    };
}) => {
    const { orgId } = auth();

    if (!orgId) {
        redirect("/select-org");
    }

    const board = await db.board.findUnique({
        where: {
            id: params.boardId,
            orgId,
        },
    });

    if (!board) {
        notFound();
    }

  return (
    <div className="relative h-full w-full" style={{ backgroundColor: board.colorId }}>
        <BoardNavBar data={board} />
        <div className="absolute inset-0 bg-black/10"/>
        <main className="relative pt-28 h-full">
            {children}
        </main>
    </div>
  );
}

export default boardIdLayout;